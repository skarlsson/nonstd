#include <gtest/gtest.h>
#include <nonstd/timestamps.h>

using namespace std::chrono_literals;
using namespace nonstd;

// Test decimal
TEST(timestamps_test1, container) {
  {
    utc_ns_since_epoch_t ts0(0);
    utc_ns_since_epoch_t expected(2000);
    utc_ns_since_epoch_t ts3 = ts0 + (ns_duration_t(1000) * 2);
    EXPECT_EQ(expected, ts3);
    EXPECT_EQ(expected, utc_ns_since_epoch_t(std::chrono::nanoseconds(2000)));
    EXPECT_EQ(expected, ts0 + std::chrono::nanoseconds(2000));
    EXPECT_EQ(expected, ts0 + std::chrono::microseconds (2));
    EXPECT_EQ(expected, ts0 + 2us);
    EXPECT_EQ(expected, ts0 + 2us);

    ns_duration_t d0(1000*1000*1000L);
    EXPECT_EQ(d0, std::chrono::nanoseconds(1000000000));
    EXPECT_EQ(d0, std::chrono::microseconds(1000000));
    EXPECT_EQ(d0, std::chrono::milliseconds(1000));
    EXPECT_EQ(d0, 1000000000ns);
    EXPECT_EQ(d0, 1000000us);
    EXPECT_EQ(d0, 1000ms);
  }
}

int main(int argc, char **argv) {

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
