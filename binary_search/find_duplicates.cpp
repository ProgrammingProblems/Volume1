size_t find_duplicates(
    const std::vector<int>& array) {
  auto lower = array.begin();
  auto upper = array.end() - 1;
  while (lower < upper) {
    auto mid = lower + (upper - lower) / 2;
    auto mid_val = *lower + (*upper - *lower) / 2;
    if (mid_val < *mid) {
      upper = mid;
    } else {
      lower = mid + 1;
    }
  }
  return lower - array.begin();
}