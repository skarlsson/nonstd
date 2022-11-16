/*
 * copyright svante karlsson at csi dot se 2021
 */
#include <stdint.h>
#include <chrono>
#pragma once

namespace nonstd {
  class ns_duration_t {
  public:
    constexpr inline ns_duration_t() = default;

    inline ~ns_duration_t() = default;

    constexpr inline explicit ns_duration_t(int64_t duration) : count_ns_(duration) {}

    constexpr inline ns_duration_t(const std::chrono::nanoseconds &b) : count_ns_(b.count()) {}

    constexpr inline ns_duration_t(const std::chrono::microseconds &b) : count_ns_(b.count() * 1000L) {}

    constexpr inline ns_duration_t(const std::chrono::milliseconds &b) : count_ns_(b.count() * 1000000L) {}

    constexpr inline ns_duration_t(const std::chrono::seconds &b) : count_ns_(b.count() * 1000000000L) {}

    constexpr explicit operator std::chrono::nanoseconds() { return std::chrono::nanoseconds(count_ns_); }

    constexpr explicit operator std::chrono::microseconds() { return std::chrono::microseconds(count_ns_ / 1000L); }

    constexpr explicit operator std::chrono::milliseconds() { return std::chrono::milliseconds(count_ns_ / 1000000L); }

    constexpr explicit operator std::chrono::seconds() { return std::chrono::seconds(count_ns_ / 1000000000L); }

    constexpr inline bool operator>(ns_duration_t b) const { return count_ns_ > b.count_ns_; }

    constexpr inline bool operator>=(ns_duration_t b) const { return count_ns_ >= b.count_ns_; }

    constexpr inline bool operator<(ns_duration_t b) const { return count_ns_ < b.count_ns_; }

    constexpr inline bool operator<=(ns_duration_t b) const { return count_ns_ <= b.count_ns_; }

    constexpr inline bool operator==(ns_duration_t b) const { return count_ns_ == b.count_ns_; }

    constexpr inline bool operator!=(ns_duration_t b) const { return count_ns_ != b.count_ns_; }

    constexpr inline ns_duration_t operator+(ns_duration_t duration) const {
      return ns_duration_t(count() + duration.count());
    }

    constexpr inline ns_duration_t operator-(ns_duration_t duration) const {
      return ns_duration_t(count() - duration.count());
    }

    constexpr inline ns_duration_t operator*(double val) const {
      return ns_duration_t(count() * val);
    }

    constexpr inline ns_duration_t operator/(double val) const {
      return ns_duration_t(count() / val);
    }

    constexpr inline int64_t count() const { return count_ns_; }

  private:
    int64_t count_ns_ = 0;
  };

  class utc_ns_since_epoch_t {
  public:
    constexpr inline utc_ns_since_epoch_t() = default;

    inline ~utc_ns_since_epoch_t() = default;

    static inline nonstd::utc_ns_since_epoch_t now() {
      return nonstd::utc_ns_since_epoch_t(std::chrono::duration_cast<std::chrono::nanoseconds>(
                                              std::chrono::system_clock::now().time_since_epoch())
                                              .count());
    }

    constexpr inline explicit utc_ns_since_epoch_t(int64_t ts) : count_ns_(ts) {}

    constexpr inline explicit utc_ns_since_epoch_t(const std::chrono::nanoseconds &b) : count_ns_(b.count()) {}

    constexpr inline explicit utc_ns_since_epoch_t(const std::chrono::microseconds &b) : count_ns_(b.count() * 1000L) {}

    constexpr inline explicit utc_ns_since_epoch_t(const std::chrono::milliseconds &b) : count_ns_(b.count() * 1000000L) {}

    constexpr inline explicit utc_ns_since_epoch_t(const std::chrono::seconds &b) : count_ns_(b.count() * 1000000000L) {}

    constexpr inline explicit operator std::chrono::nanoseconds() { return std::chrono::nanoseconds(count_ns_); }

    constexpr inline explicit operator std::chrono::microseconds() { return std::chrono::microseconds(count_ns_ / 1000L); }

    constexpr inline explicit operator std::chrono::milliseconds() {
      return std::chrono::milliseconds(count_ns_ / 1000000L);
    }

    constexpr inline explicit operator std::chrono::seconds() { return std::chrono::seconds(count_ns_ / 1000000000L); }

    constexpr inline bool operator>(utc_ns_since_epoch_t b) const { return count_ns_ > b.count_ns_; }

    constexpr inline bool operator>=(utc_ns_since_epoch_t b) const { return count_ns_ >= b.count_ns_; }

    constexpr inline bool operator<(utc_ns_since_epoch_t b) const { return count_ns_ < b.count_ns_; }

    constexpr inline bool operator<=(utc_ns_since_epoch_t b) const { return count_ns_ <= b.count_ns_; }

    constexpr inline bool operator==(utc_ns_since_epoch_t b) const { return count_ns_ == b.count_ns_; }

    constexpr inline bool operator!=(utc_ns_since_epoch_t b) const { return count_ns_ != b.count_ns_; }

    constexpr inline utc_ns_since_epoch_t operator+(ns_duration_t duration) const {
      return utc_ns_since_epoch_t(count() + duration.count());
    }

    constexpr inline utc_ns_since_epoch_t operator-(ns_duration_t duration) const {
      return utc_ns_since_epoch_t(count() - duration.count());
    }

    constexpr inline utc_ns_since_epoch_t &operator+=(ns_duration_t duration) {
      count_ns_ += duration.count();
      return *this;
    }

    constexpr inline utc_ns_since_epoch_t &operator-=(ns_duration_t duration) {
      count_ns_ -= duration.count();
      return *this;
    }

    constexpr inline ns_duration_t operator-(const utc_ns_since_epoch_t& b) const {
      return ns_duration_t(count_ns_ - b.count_ns_);
    }

    constexpr inline int64_t count() const { return count_ns_; }

  private:
    int64_t count_ns_ = 0;
  };

  class localtime_ns_since_midnight_t {
  public:
    constexpr inline localtime_ns_since_midnight_t(const localtime_ns_since_midnight_t &b) : count_ns_(b.count_ns_) {}

    constexpr inline explicit localtime_ns_since_midnight_t(int64_t ts) : count_ns_(ts) {}

    constexpr inline explicit localtime_ns_since_midnight_t(const std::chrono::nanoseconds &b) : count_ns_(b.count()) {}

    constexpr inline explicit localtime_ns_since_midnight_t(const std::chrono::microseconds &b) : count_ns_(
        b.count() * 1000L) {}

    constexpr inline explicit localtime_ns_since_midnight_t(const std::chrono::milliseconds &b) : count_ns_(
        b.count() * 1000000L) {}

    constexpr inline explicit localtime_ns_since_midnight_t(const std::chrono::seconds &b) : count_ns_(
        b.count() * 1000000000L) {}

    constexpr inline explicit operator std::chrono::nanoseconds() { return std::chrono::nanoseconds(count_ns_); }

    constexpr inline explicit operator std::chrono::microseconds() { return std::chrono::microseconds(count_ns_ / 1000L); }

    constexpr inline explicit operator std::chrono::milliseconds() {
      return std::chrono::milliseconds(count_ns_ / 1000000L);
    }

    constexpr inline explicit operator std::chrono::seconds() { return std::chrono::seconds(count_ns_ / 1000000000L); }


    constexpr inline bool operator>(localtime_ns_since_midnight_t b) const { return count_ns_ > b.count_ns_; }

    constexpr inline bool operator>=(localtime_ns_since_midnight_t b) const { return count_ns_ >= b.count_ns_; }

    constexpr inline bool operator<(localtime_ns_since_midnight_t b) const { return count_ns_ < b.count_ns_; }

    constexpr inline bool operator<=(localtime_ns_since_midnight_t b) const { return count_ns_ <= b.count_ns_; }

    constexpr inline bool operator==(localtime_ns_since_midnight_t b) const { return count_ns_ == b.count_ns_; }

    constexpr inline bool operator!=(localtime_ns_since_midnight_t b) const { return count_ns_ != b.count_ns_; }

    constexpr inline localtime_ns_since_midnight_t operator+(ns_duration_t duration) const {
      return localtime_ns_since_midnight_t(count() + duration.count());
    }

    constexpr inline localtime_ns_since_midnight_t operator-(ns_duration_t duration) const {
      return localtime_ns_since_midnight_t(count() - duration.count());
    }

    constexpr inline localtime_ns_since_midnight_t &operator+=(ns_duration_t duration) {
      count_ns_ += duration.count();
      return *this;
    }

    constexpr inline localtime_ns_since_midnight_t &operator-=(ns_duration_t duration) {
      count_ns_ -= duration.count();
      return *this;
    }

    constexpr inline ns_duration_t operator-(const localtime_ns_since_midnight_t& b) const {
      return ns_duration_t(count_ns_ - b.count_ns_);
    }

    constexpr inline int64_t count() const { return count_ns_; }

  private:
    int64_t count_ns_ = 0;
  };
} // namespace
