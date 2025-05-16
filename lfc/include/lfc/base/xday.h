// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_BASE_XDAY_H__
#define __LFC_BASE_XDAY_H__
#include <string>
#include <vector>
namespace lfc {

class XDay {

public:
  
  static XDay getDay(int year, int month, int day);
  static XDay getDay(const std::string& dayString);
  static int  getDiff(const XDay& a, const XDay& b);
  static XDay getMinDay(int year, int quarter);
  static XDay getSpecifiedDay(const std::string& dayString, int num);
  static bool isValidDate(const std::string& dayString);
  static std::vector<XDay> listDaysInQuarter(int year, int quarter);
  static XDay today();

  static XDay max(const XDay& a, const XDay& b) {
    return a.getNumDay() > b.getNumDay() ? a : b;
  }

  static XDay min(const XDay& a, const XDay& b) {
    return a.getNumDay() < b.getNumDay() ? a : b;
  }

private:

  static XDay toDay(const std::string& dayString);

public:

  XDay(int year, int month, int day);
  XDay(const XDay& other);
  XDay(XDay&& other) noexcept;

  XDay& operator =  (const XDay& other);
  bool operator <  (const XDay& other) const { return getNumDay() < other.getNumDay(); }
  bool operator >  (const XDay& other) const { return getNumDay() > other.getNumDay(); }
  bool operator == (const XDay& other) const { return getNumDay() == other.getNumDay(); }
  bool operator != (const XDay& other) const { return !(*this == other); }
  bool operator <= (const XDay& other) const { return !(*this > other); }
  bool operator >= (const XDay& other) const { return !(*this < other); }

public:

  XDay getClone() const;

  int getDay() const { return day; }
  
  int getMonth() const { return month; }
  
  int getYear() const { return year; }

  int getDayOfWeek() const;

  int getNumDay() const;
  
  int getQuarter() const;
  
  bool isBiggerThan(const XDay& other) const;
 
  bool isSmallerThan(const XDay& other) const;
 
  bool isValidDate() const;
  
  bool isWorkingDay() const;

  XDay lastDay() const;
  
  XDay nextDay() const;

  XDay moveDay(int n) const;

  std::string toString() const;

private:

  int day;
  int month;
  int year;

  mutable int dayOfWeek = -1; // mutable because it's a cache

};

} // namespace lfc

#endif // __LFC_BASE_XDAY_H__