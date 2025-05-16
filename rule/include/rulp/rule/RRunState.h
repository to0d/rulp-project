// SPDX-FileCopyrightText: 2025 Todd <to0d@outlook.com>
// SPDX-License-Identifier: GPL-3.0-or-later
#ifndef __RULP_RULE_RRUNSTATE_H__
#define __RULP_RULE_RRUNSTATE_H__

namespace lfc {

enum RRunState {
  Completed,  // 0
  Runnable,   // 1
  Running,    // 2
  Halting,    // 3
  Failed,     // 4
  Partial     // 5
};

} // namespace lfc
#endif //__RULP_RULE_RRUNSTATE_H__