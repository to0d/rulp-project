#include "unitest_base.h"
#include "lfc/base/noncopyable.h"
#include "help_test.h"

class CT_NON_COPY : public lfc::noncopyable
{};

TEST(base_noncopyable, test_noncopyable)
{
  CT_NON_COPY obj1;
}