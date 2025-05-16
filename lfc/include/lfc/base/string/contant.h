#ifndef __LFC_BASE_STRING_CONTANT_H__
#define __LFC_BASE_STRING_CONTANT_H__

namespace lfc {
  
  const wchar_t CN_CHAR_COLON                  = 0xff1a; // CN ':'
  const wchar_t CN_CHAR_COLON2                 = 0x2236; // CN '∶'
  const wchar_t CN_CHAR_COMMNA                 = 0xff0c; // CN ','
  const wchar_t CN_CHAR_DUN_HAO                = 0x3001; // CN '、'
  const wchar_t CN_CHAR_EXCLAMATION            = 0xff01; // CN '！'
  const wchar_t CN_CHAR_LEFT_BRACKET           = 0x3010; // CN '['
  const wchar_t CN_CHAR_LEFT_KUOHU             = 0x300c; // CN '「'
  const wchar_t CN_CHAR_LEFT_PARENTHESIS       = 0xff08; // CN '('
  const wchar_t CN_CHAR_LEFT_PIE               = 0x2018; // CN '‘'
  const wchar_t CN_CHAR_LEFT_QUOTE             = 0x201c; // CN '“'
  const wchar_t CN_CHAR_LEFT_SHU_MING          = 0x300a; // CN '<'
  const wchar_t CN_CHAR_LONG_HORIZONTAL_LINE   = 0x2501; // CN '━'
  const wchar_t CN_CHAR_LONG_HORIZONTAL_LINE2  = 0x2500; // CN '─'
  const wchar_t CN_CHAR_PERIOD                 = 0x3002; // CN '.'
  const wchar_t CN_CHAR_QUESTION_MARK          = 0xff1f; // CN '?'
  const wchar_t CN_CHAR_RIGHT_BRACKET          = 0x3011; // CN ']'
  const wchar_t CN_CHAR_RIGHT_PARENTHESIS      = 0xff09; // CN ')'
  const wchar_t CN_CHAR_RIGHT_QUOTE            = 0x201d; // CN '”'
  const wchar_t CN_CHAR_RIGHT_SHU_MIN          = 0x300b; // CN '>'
  const wchar_t CN_CHAR_RIGHTT_KUOHU           = 0x300d; // CN '」'
  const wchar_t CN_CHAR_RIGHTT_PIE             = 0x2019; // CN '’'
  const wchar_t CN_CHAR_SEMICOLON              = 0xff1b; // CN ';'
  const wchar_t CN_CHAR_SPACE                  = 0x3000; // CN ' '
  const wchar_t CN_CHAR_UNAME_1                = 0x25cb; // CN '○'
  const wchar_t CN_CHAR_UNAME_10               = 0x2299; // CN '⊙'
  const wchar_t CN_CHAR_UNAME_11               = 0x25b2; // CN '▲'
  const wchar_t CN_CHAR_UNAME_12               = 0x25bc; // CN '▼'
  const wchar_t CN_CHAR_UNAME_13               = 0x03a7; // CN 'Χ'
  const wchar_t CN_CHAR_UNAME_14               = 0x2605; // CN '★'
  const wchar_t CN_CHAR_UNAME_15               = 0x043e; // CN 'о'
  const wchar_t CN_CHAR_UNAME_16               = 0x2013; // CN '–'
  const wchar_t CN_CHAR_UNAME_17               = 0x2014; // CN '—'
  const wchar_t CN_CHAR_UNAME_18               = 0xff0d; // CN '－'
  const wchar_t CN_CHAR_UNAME_19               = 0x2026; // CN '…'
  const wchar_t CN_CHAR_UNAME_2                = 0x00d7; // CN '×'
  const wchar_t CN_CHAR_UNAME_21               = 0x3008; // CN '〈'
  const wchar_t CN_CHAR_UNAME_22               = 0x3009; // CN '〉'
  const wchar_t CN_CHAR_UNAME_23               = 0x300e; // CN '『'
  const wchar_t CN_CHAR_UNAME_24               = 0x300f; // CN '』'
  const wchar_t CN_CHAR_UNAME_25               = 0x2015; // CN '―'
  const wchar_t CN_CHAR_UNAME_26               = 0x3014; // CN '〔'
  const wchar_t CN_CHAR_UNAME_27               = 0x3015; // CN '〕'
  const wchar_t CN_CHAR_UNAME_28               = 0x301d; // CN '〝'
  const wchar_t CN_CHAR_UNAME_29               = 0x301e; // CN '〞'
  const wchar_t CN_CHAR_UNAME_30               = 0x203b; // CN '※'
  const wchar_t CN_CHAR_UNAME_31               = 0xff0e; // CN '．'
  const wchar_t CN_CHAR_UNAME_32               = 0xff0f; // CN '／'
  const wchar_t CN_CHAR_UNAME_4                = 0x25a1; // CN '□'
  // const wchar_t CN_CHAR_UNAME_5                = 0x007e; // CN '~'
  const wchar_t CN_CHAR_UNAME_6                = 0x25c6; // CN '◆'
  const wchar_t CN_CHAR_UNAME_7                = 0x25cf; // CN '●'
  const wchar_t CN_CHAR_UNAME_8                = 0x25a0; // CN '■'
  const wchar_t CN_CHAR_UNAME_9                = 0x2103; // CN '℃'
  const wchar_t TXT_BOM                        = 65279;
  const char    EN_CHAR_ENTER                  = 0x0D;  // '\r';
  const char    EN_CHAR_NEWLINE                = 0x0A;  // '\n';
  const char    EN_CHAR_SPACE                  = 0x20;
  const char    EN_CHAR_TAB                    = 0x09;
  const char    EN_SEPARATION_DOT              = 0xb7;  // '·'
  const char    EN_CHAR_UNAME_5                = 0x7e;  // '~'

#define GBK               "GBK"           // Chinese
#define UTF_8             "UTF-8"
#define EN_STR_SPACE      " "
#define EN_STR_TAB        "\t"
#define GB2312            "GB2312"
#define ISO_8859_1        "ISO-8859-1"    // ISO-LATIN-1
#define US_ASCII          "US-ASCII"
#define UTF_16            "UTF-16"
#define UTF_16BE          "UTF-16BE"      // BE: Big Endian
#define UTF_16LE          "UTF-16LE"      // LE: Little-endian

} // namespace lfc
#endif // __LFC_BASE_STRING_CONTANT_H__