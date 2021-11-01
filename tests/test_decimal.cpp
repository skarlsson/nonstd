#include <gtest/gtest.h>
#include <nonstd/decimal.h>

using namespace nonstd;

// Test decimal
TEST(decimal_test, container) {
  using decimal52 = decimal<int16_t, 5, 2>;
  using decimal94 = decimal<int32_t, 9, 4>;
  using decimal174 = decimal<int64_t, 17, 4>;

  double eps = 10.0 * std::numeric_limits<double>::epsilon();
  {
    double d = 31419E-4;
    decimal94 d94a(d);
    decimal94 d94b(d);
    EXPECT_EQ(d94a, d94b);
    EXPECT_EQ(std::abs(d - (double) d94a) < eps, true);

    int32_t m = ~0;
    decimal94 d94 = decimal94::make_from_rep(m);
    decimal174 ans = decimal174(d94 * m);
    EXPECT_EQ(ans.get_rep(), (int64_t) m * (int64_t) m);
    ans = decimal174(-d94 * -m);
    EXPECT_EQ(ans.get_rep(), (int64_t) (-m) * (int64_t) (-m));
  }

  {
    EXPECT_EQ(decimal94::MININT, -1000000000);
    EXPECT_EQ(decimal94::MAXINT, 1000000000);
  }

  {
    decimal94 d94 = decimal94::make_from_rep(31415);
    EXPECT_EQ((abs((double) 3.1415 - (double) d94) <= eps), true);

    int16_t c = 314;
    decimal52 d52_v1 = decimal52::make_from_rep(c);
    decimal94 d94_v1 = decimal94::make_from_rep(31400);

    decimal52 xx = (decimal52) d94_v1;

    decimal174 d174_v1 = decimal174::make_from_rep(31419L);
    decimal94 d94_v2(d52_v1);
    decimal174 d174_v2(d52_v1);

    EXPECT_EQ((abs((double) 3.14 - (double) d94_v2) <= eps), true);
    EXPECT_EQ((abs((double) d94_v2 - (double) 3.14) <= eps), true);
    EXPECT_EQ((abs(d94_v1 - (decimal94) d52_v1) <= eps), true);
    EXPECT_EQ((abs(d94_v2 - (decimal94) d52_v1) <= eps), true);
    EXPECT_EQ((abs((double) d94_v2 - (double) d52_v1) <= eps), true);
    EXPECT_EQ((abs((double) d174_v2 - (double) 3.14) <= eps), true);
    EXPECT_EQ((abs((double) d174_v1 - (double) 3.1419) <= eps), true);
  }

  {
    // cast decimal52 to decimal94
    decimal52 pi = decimal52::make_from_rep((int16_t) 314);
    decimal94 pi2 = (decimal94) pi;
    EXPECT_EQ((abs((double) 3.14 - (double) pi2) <= eps), true);
  }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
