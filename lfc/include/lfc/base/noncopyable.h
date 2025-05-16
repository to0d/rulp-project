// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __LFC_BASE_NONCOPYABLE_H__
#define __LFC_BASE_NONCOPYABLE_H__

namespace lfc {

  class noncopyable
  {
  protected:
    noncopyable() {}
    virtual ~noncopyable() {}

  private:  // emphasize the following members are private
    noncopyable( const noncopyable& );
    const noncopyable& operator=( const noncopyable& );
  };

}

#endif // __LFC_BASE_NONCOPYABLE_H__

