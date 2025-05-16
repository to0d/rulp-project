
#include "lfc/base/string.h"
#include "lfc/base/to_string.h"
#include <sstream>

namespace lfc {

struct XItem {

  std::string content;
  int itemLen = 0;
  int itemOff = 0;

  XItem(){}

  XItem(const std::string& content, int itemLen, int itemOff)
    : content(content)
    , itemLen(itemLen)
    , itemOff(itemOff)
  {}

  XItem(const XItem& item)
    : content(item.content)
    , itemLen(item.itemLen)
    , itemOff(item.itemOff)
  {}

  std::string getConent() {

    if (!content.empty() && itemOff >= 0 && itemLen > 0) {
      return content.substr(itemOff, itemOff + itemLen);
    }

    return "";
  }
};

typedef XItem* XItemPtr;

class XItemBuilder {

public:
  virtual ~XItemBuilder() = default;
  virtual XItem* createItem() = 0;

};

class IItemParser {

public:
  virtual ~IItemParser() = default;

public:

  virtual XItem* parse(XItemBuilder* builder, const std::string& content, int contentOff, int contentLen, bool ignoreCase) const = 0;
  virtual bool needFree() const {return false;};
  virtual std::string toString() const = 0;

};


class AnyParser : public IItemParser {
public:

  virtual XItemPtr parse(XItemBuilder* builder, const std::string& content, int contentOff, int contentLen, bool ignoreCase) const override {
    return nullptr;
  };

  virtual std::string toString() const override { 
    return "*";
  }
};

class EndParser : public IItemParser {
public:

  virtual XItemPtr parse(XItemBuilder* builder, const std::string& content, int contentOff, int contentLen, bool ignoreCase) const override {
    for (int i = contentOff; i < contentLen; ++i) {
      switch (content[i]) {
      case '\r':
      case '\n':
        continue;
      default:
        return nullptr;
      }
    }

    XItemPtr item = builder->createItem();
    item->content = content;
    item->itemOff = contentOff;
    item->itemLen = contentLen - contentOff;
    return item;
  };

  virtual std::string toString() const override { 
    return "%$";
  }
};

class IntParser : public IItemParser {
public:

  virtual XItemPtr parse(XItemBuilder* builder, const std::string& content, int contentOff, int contentLen, bool ignoreCase) const override {
    XItemPtr item = builder->createItem();

    bool findNonIntChar = false;
    item->content = content;
    item->itemOff = contentOff;
    int maxItemLen = contentLen - contentOff;

    item->itemLen = 0;
    while (!findNonIntChar && item->itemLen < maxItemLen) {

      char c = item->content[item->itemLen + contentOff];

      if (CHAR_IS_DIGIT(c)) {
        item->itemLen++;
      } 
      else {
        findNonIntChar = true;
      }
    }
    if (item->itemLen > 0) {
      return item;
    }

    return nullptr;
  };

  virtual std::string toString() const override { 
    return "%d";
  }
};

class SpaceParser : public IItemParser {
public:

  virtual XItemPtr parse(XItemBuilder* builder, const std::string& content, int contentOff, int contentLen, bool ignoreCase) const override {
    XItemPtr item = builder->createItem();

    item->content = content;
    item->itemOff = contentOff;
    item->itemLen = 0;

    bool findNonSpace = false;

    while (!findNonSpace && (item->itemOff + item->itemLen) < contentLen) {

      if (content[item->itemOff + item->itemLen] == ' ') {
        ++item->itemLen;
      } 
      else {
        findNonSpace = true;
      }

    }

    if (item->itemLen > 0) {
      return item;
    }

    return nullptr;
  };

  virtual std::string toString() const override { 
    return " ";
  }
};

class VarParser : public IItemParser {
public:

  virtual XItemPtr parse(XItemBuilder* builder, const std::string& content, int contentOff, int contentLen, bool ignoreCase) const override {
    XItemPtr item = builder->createItem();

    item->content = content;
    item->itemOff = contentOff;
    item->itemLen = contentLen - contentOff;

    return item;
  };

  virtual std::string toString() const override { 
    return "%?";
  }
};

class XOrParser : public IItemParser {
public:

  virtual XItemPtr parse(XItemBuilder* builder, const std::string& content, int contentOff, int contentLen, bool ignoreCase) const override {
    return nullptr;
  };

  virtual std::string toString() const override { 
    return "";
  }
};


class XSpecialCharItermParser : public IItemParser {
public:

  XSpecialCharItermParser(char expectChar) : expectChar(expectChar){};

  virtual XItemPtr parse(XItemBuilder* builder, const std::string& content, int contentOff, int contentLen, bool ignoreCase) const override {
    if ((1 + contentOff) > contentLen) {
      return nullptr;
    }

    char testChar = content[contentOff];
    if (expectChar != testChar) {
      return nullptr;
    }

    XItemPtr item = builder->createItem();

    item->content = content;
    item->itemOff = contentOff;
    item->itemLen = 1;
    return item;
  };

  virtual bool needFree() const override {return true;}

  virtual std::string toString() const override { 
    switch (expectChar) {
    case '\n':
      return "%n";
    case '\r':
      return "%r";
    }
    return "" + TO_STR(expectChar);
  }

private:

  char expectChar = 0;
};


class XPlainStringItermParser : public IItemParser {
public:

  XPlainStringItermParser(std::string plainString) : plainString(plainString){};

  virtual XItemPtr parse(XItemBuilder* builder, const std::string& content, int contentOff, int contentLen, bool ignoreCase) const override {
    if ((plainString.length() + contentOff) > contentLen) {
      return NULL;
    }

    for (int i = 0; i < plainString.length(); ++i) {

      char expectChar = plainString[i];
      char testChar = content[contentOff + i];

      if (ignoreCase) {
        expectChar  = CHAR_TO_LOWER(expectChar);
        testChar    = CHAR_TO_LOWER(testChar);
      }

      if (expectChar != testChar) {
        return nullptr;
      }
    }

    XItemPtr item = builder->createItem();

    item->content = content;
    item->itemOff = contentOff;
    item->itemLen = plainString.length();
    return item;
  };

  virtual bool needFree() const override {return true;}

  virtual std::string toString() const override { 
    return "";
  }

  std::string plainString = "";
};


static AnyParser    anyParser;
static EndParser    endParser;
static IntParser    intParser;
static SpaceParser  spaceParser;
static VarParser    varParser;

static void addItemParser(std::vector<IItemParser*>& parseList, std::stringstream& parseBuffer, int parseIndex, IItemParser* parser) {

  auto lastParser = parseList.empty() ? nullptr : parseList[parseList.size() - 1];

  if (auto str = parseBuffer.str(); str.length() != 0) {
    lastParser = new XPlainStringItermParser(str);
    parseList.push_back(lastParser);
    parseBuffer.str("");
  }
  else {
    if (parser == &anyParser && (lastParser == &anyParser || lastParser == &varParser)) {
      throw std::runtime_error("next var should not be %? or |, i= " + TO_STR(parseIndex));
    }
  }

  // Ignore [][]
  if (parser == lastParser && lastParser == &spaceParser) {
    return;
  }

  parseList.push_back(parser);
}

class XMatchParser 
  : public IMatchParser
  , public XItemBuilder {

public:

  virtual ~XMatchParser() {
    for(auto parser : parsers){
      if(parser->needFree()){
        delete parser;
      }
    }
    parsers.clear();

    for(auto item : allItems){
      delete item;
    }
    allItems.clear();
  }

public:

  void buildParser(const std::string& matchMode);

  virtual XItem* createItem() override {
    XItem* item = new XItem();
    allItems.push_back(item);
    return item;
  }

  virtual bool match(const std::string& content, std::vector<std::string>& values, bool ignoreCase) override;

  XItem* tryParse(const std::string& content, int off, IItemParser* parser, bool ignoreCase) {
    XItem* item = NULL;
    while (item == NULL && off < content.length()) {
      item = parser->parse(this, content, off++, content.length(), ignoreCase);
    }

    return item;
  }

private:

  std::vector<IItemParser*> parsers;
  std::vector<XItem*> allItems;
};

void XMatchParser::buildParser(const std::string& matchMode) {

  std::stringstream parseBuffer;

  int parseIndex = 0;

  for (parseIndex = 0; parseIndex < matchMode.length(); ++parseIndex) {
    char c = matchMode[parseIndex];

    switch (c) {
    case ' ':
      addItemParser(parsers, parseBuffer, parseIndex, &spaceParser);
      break;
    
    case '*': 
      addItemParser(parsers, parseBuffer, parseIndex, &anyParser);
      break;
    
    // case '|': 
    //   addItemParser(parseList, parseBuffer, parseIndex, IItemParserPtr(new XOrParser()));
    //   break;
    
    case '%':

      if (parseIndex < matchMode.length() - 1) {

        char c2 = matchMode[++parseIndex];

        switch (c2) {
        // %% means char'%'
        case '%':
          parseBuffer << '%';
          break;
        
        // %d means a integer
        case 'd':
          addItemParser(parsers, parseBuffer, parseIndex, &intParser);
          break;
  
        case '|':
          parseBuffer << '|';
          break;

        case '?':
          addItemParser(parsers, parseBuffer, parseIndex, &varParser);
          break;

        case '*':
          parseBuffer << "*";
          break;

        case 'n':
          addItemParser(parsers, parseBuffer, parseIndex, new XSpecialCharItermParser('\n'));
          break;

        case 'r':
          addItemParser(parsers, parseBuffer, parseIndex, new XSpecialCharItermParser('\r'));
          break;

        case '$':
          addItemParser(parsers, parseBuffer, parseIndex, &endParser);
          break;

        default:
          throw std::runtime_error("not support %" + TO_STR(c2));
        }

      }
      else {
        throw std::runtime_error("should not be the last %");
      }

      break;
    case 0:
    case '\n':
    case '\r': 
      throw std::runtime_error("not support char:" + TO_STR(c));
    
    default:
      parseBuffer << c;
      break;
    }
  }

  if (auto str = parseBuffer.str(); str.length() != 0) {
    parsers.push_back(new XPlainStringItermParser(str));
    parseBuffer.str("");
  }
}


bool XMatchParser::match(const std::string& content, std::vector<std::string>& values, bool ignoreCase) {
  int contentOff = 0;
  int contentLen = content.length();

  int parseIndex = 0;
  bool finished = false;
  
  values.clear();

  const int parserCount = parsers.size();

  while (!finished && contentOff < contentLen && parseIndex < parserCount) {

    auto curParser = parsers[parseIndex++];

    if (curParser == &anyParser || curParser == &varParser) {

      // any or var parse is last var
      if (parseIndex == parserCount
          || ((parseIndex + 1) == parserCount) && parsers[parseIndex] == &endParser) {

        auto item = curParser->parse(this, content, contentOff, content.length(), ignoreCase);

        if (curParser == &varParser) {

          if (item != NULL) {
            values.push_back(item->getConent());
          } 
          else {
            values.push_back("");
          }
        }

        finished = true;

      } 
      else {

        auto nextParse  = parsers[parseIndex++];
        auto nextItem   = tryParse(content, contentOff, nextParse, ignoreCase);

        if (nextItem == NULL) {
          return false;
        }

        auto thisItem = curParser->parse(this, content, contentOff, nextItem->itemOff, ignoreCase);

        if (curParser == &varParser) {
          if (thisItem != NULL) {
            values.push_back(thisItem->getConent());
          }
          else {
            values.push_back(NULL);
          }
        }

        contentOff = nextItem->itemOff + nextItem->itemLen;
      }

    }
    // if (curParse == anyParser || curParse == varParser) {
    else {

      auto item = curParser->parse(this, content, contentOff, content.length(), ignoreCase);
      if (item == NULL) {
        return false;
      }

      contentOff = item->itemOff + item->itemLen;
    }
  }

  if (parseIndex < parserCount) {

    // Not last one
    if (parseIndex != parserCount - 1) {
      return false;
    }

    auto lastParer = parsers[parseIndex];

    // the left parse is *
    if (lastParer == &anyParser || lastParer == &endParser) {
      // nothing
    } 
    else {
      return false;
    }
  
  }
  
  return true;
}

static std::map<std::string, IMatchParserPtr> modeMap;

IMatchParserPtr StringUtil::getMatchParser(const std::string& matchMode) {

  auto it = modeMap.find(matchMode);
  if(it != modeMap.end()){
    return it->second;
  }

  XMatchParser* parser = new XMatchParser();
  parser->buildParser(matchMode);

  IMatchParserPtr ptr = IMatchParserPtr(parser);
  modeMap[matchMode] = ptr;

  return ptr;
}

bool StringUtil::matchFormat(const std::string& matchMode, const std::string& content) {
  std::vector<std::string> values;
  return getMatchParser(matchMode)->match(content, values, false);
}

bool StringUtil::matchFormat(const std::string& matchMode, const std::string& content, std::vector<std::string>& values) {
  return getMatchParser(matchMode)->match(content, values, false);
}

} // namespace lfc