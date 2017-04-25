#include <gtest/gtest.h>
#include <cpplinq/linq.hpp>
#include <vector>

TEST(cpplinq, basics) {

  std::vector<int> xs;

  xs.push_back(42);
  xs.push_back(99);
  xs.push_back(99);
  xs.push_back(12);

  using namespace cpplinq;

  auto sorted = from(scoreEntries)
      >> orderby_ascending([](const Entry & entry) {
        return entry;
      })
      >> to_vector();

  ASSERT_TRUE(sorted[0] == 12);
}
