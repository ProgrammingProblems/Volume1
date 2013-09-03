size_t fixed_point(const std::vector<int>& array) {
  auto lower = array.begin();
  auto upper = array.end() - 1;
  while (lower < upper) {
    auto mid = lower + (upper - lower) / 2;
    if (*mid <= (mid - array.begin())) {
      upper = mid;
    } else {
      lower = mid + 1;
    }
  }
  return lower - array.begin();
}