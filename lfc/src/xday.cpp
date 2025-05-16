// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#include "lfc/base/xday.h"
#include <utility>
#include <stdexcept>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <algorithm>

namespace lfc {

XDay::XDay(int year, int month, int day) 
  : year(year)
  , month(month)
  , day(day) 
{}

XDay::XDay(const XDay& other) 
  : year(other.year) 
  , month(other.month) 
  , day(other.day)
  , dayOfWeek(other.dayOfWeek) 
{}

XDay::XDay(XDay&& other) noexcept
  : year(std::exchange(other.year, 0))
  , month(std::exchange(other.month, 0))
  , day(std::exchange(other.day, 0))
  , dayOfWeek(std::exchange(other.dayOfWeek, -1)) 
{}

XDay& XDay::operator = (const XDay& other) {
  year      = other.year;
  month     = other.month;
  day       = other.day;
  dayOfWeek = other.dayOfWeek;
  return *this;
}

XDay XDay::getDay(int year, int month, int day) {
  if (year < 1970 || month < 1 || month > 12 || day < 1 || day > 31) {
    throw std::invalid_argument("Invalid date parameters");
  }
  return XDay(year, month, day);
}

XDay XDay::getDay(const std::string& dayString) {
  if (!isValidDate(dayString)) {
    throw std::invalid_argument("Invalid date format: " + dayString);
  }
  return toDay(dayString);
}

int XDay::getDiff(const XDay& a, const XDay& b) {
  if (a.getNumDay() > b.getNumDay()) {
    return -getDiff(b, a);
  } 
  else if (a.getNumDay() == b.getNumDay()) {
    return 0;
  }

  int diff = 1;
  XDay next = a.nextDay();
  while (next.getNumDay() != b.getNumDay()) {
    next = next.nextDay();
    ++diff;
  }

  return diff;
}

XDay XDay::getClone() const { 
  return XDay(year, month, day);
}

int XDay::getDayOfWeek() const {
  if (dayOfWeek == -1) {
    std::tm tm = {};
    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;
    tm.tm_hour = 0;
    tm.tm_min = 0;
    tm.tm_sec = 0;
    tm.tm_isdst = -1; // Let mktime determine daylight saving time

    if (std::mktime(&tm) == -1) {
        throw std::runtime_error("Failed to calculate day of week");
    }
    dayOfWeek = tm.tm_wday; // 0=Sunday, 1=Monday, ..., 6=Saturday
  }
  return dayOfWeek;
}

int XDay::getNumDay() const {
  return (year - 1900) * 1000 + (month - 1) * 31 + day;
}

int XDay::getQuarter() const {
  return (month - 1) / 3 + 1;
}

bool XDay::isBiggerThan(const XDay& other) const { 
  return *this > other; 
}

bool XDay::isSmallerThan(const XDay& other) const { 
  return *this < other; 
}

bool XDay::isWorkingDay() const {
  int dow = getDayOfWeek();
  return dow >= 1 && dow <= 5; // Monday to Friday
}

XDay XDay::getMinDay(int year, int quarter) {
  if (quarter < 1 || quarter > 4) {
      throw std::invalid_argument("Invalid quarter: " + std::to_string(quarter));
  }
  int month = (quarter - 1) * 3 + 1;
  return XDay::getDay(year, month, 1);
}

XDay XDay::getSpecifiedDay(const std::string& dayString, int num) {
  XDay day = getDay(dayString);
  return day.moveDay(num);
}

std::vector<XDay> XDay::listDaysInQuarter(int year, int quarter) {
  if (quarter < 1 || quarter > 4) {
    throw std::invalid_argument("Invalid quarter: " + std::to_string(quarter));
  }

  int month = (quarter - 1) * 3 + 1;
  XDay day = XDay::getDay(year, month, 1);
  std::vector<XDay> days;

  while (day.getYear() == year && day.getQuarter() == quarter) {
    if (day.isValidDate()) {
        days.push_back(day);
    }
    day = day.nextDay();
  }

  return days;
}

bool XDay::isValidDate(const std::string& dayString) {
  if (dayString.empty()) 
    return false;

  try {
    std::tm tm = {};
    std::istringstream ss(dayString);
    ss >> std::get_time(&tm, "%Y-%m-%d");
    if (ss.fail()) 
      return false;
    
    // Check if the parsed values match the input
    // This catches invalid dates like 2023-02-30
    char buffer[11];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", &tm);
    return dayString == buffer;
  } 
  catch (...) {
    return false;
  }
}

XDay XDay::lastDay() const { 
  return moveDay(-1); 
}

XDay XDay::nextDay() const {
  return moveDay(1); 
}

XDay XDay::moveDay(int n) const {
  std::tm tm = {};
  tm.tm_year = year - 1900;
  tm.tm_mon = month - 1;
  tm.tm_mday = day + n;
  tm.tm_hour = 0;
  tm.tm_min = 0;
  tm.tm_sec = 0;
  tm.tm_isdst = -1;

  if (std::mktime(&tm) == -1) {
    throw std::runtime_error("Failed to calculate new date");
  }

  return XDay(tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
}

XDay XDay::today() {
  std::time_t t = std::time(nullptr);
  std::tm* now = std::localtime(&t);
  XDay today(now->tm_year + 1900, now->tm_mon + 1, now->tm_mday);
  if (!today.isValidDate()) {
    throw std::runtime_error("Invalid current date");
  }
  return today;
}

XDay XDay::toDay(const std::string& dayString) {
  std::tm tm = {};
  std::istringstream ss(dayString);
  ss >> std::get_time(&tm, "%Y-%m-%d");
  if (ss.fail()) {
    throw std::invalid_argument("Invalid date format: " + dayString);
  }
  return XDay(tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
}

bool XDay::isValidDate() const {
  if (month < 1 || month > 12 || day < 1 || day > 31) return false;
  
  std::tm tm = {};
  tm.tm_year = year - 1900;
  tm.tm_mon = month - 1;
  tm.tm_mday = day;
  tm.tm_hour = 0;
  tm.tm_min = 0;
  tm.tm_sec = 0;
  tm.tm_isdst = -1;

  // Normalize the tm structure
  if (std::mktime(&tm) == -1) return false;
  
  // Check if the normalized values match the original
  return (tm.tm_year + 1900 == year) && 
          (tm.tm_mon + 1 == month) && 
          (tm.tm_mday == day);
}

std::string XDay::toString() const {
  std::ostringstream oss;
  oss << std::setw(4) << std::setfill('0') << year << "-"
      << std::setw(2) << std::setfill('0') << month << "-"
      << std::setw(2) << std::setfill('0') << day;
  return oss.str();
}


} // namespace lfc 