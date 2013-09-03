size_t find(const std::vector<int>& array,
            int key) {
  auto lower = array.begin();
  auto upper = array.end()-1;
  while (lower < upper && *lower != key) {
    auto mid = lower + (upper - lower) / 2;
    if (key <= *mid) upper = mid;
    else lower = mid + 1;
  }
  return lower - array.begin();
}
