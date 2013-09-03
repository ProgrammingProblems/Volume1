size_t find(const std::vector<int>& array,
            int key) {
  auto lower = array.begin();
  auto upper = array.end() - 1;
  while (lower < upper) {
    auto mid = lower + (upper - lower) / 2;
    if (key == *mid) {
      upper = mid;
    } else if (*lower <= *mid) {
      if (*lower <= key && key < *mid) {
        upper = mid;
      } else {
        lower = mid + 1;
      }
    } else if (*mid <= *upper) {
      if (*mid < key && key <= *upper) {
        lower = mid + 1;
      } else {
        upper = mid;
      }
    }
  }
 return lower - array.begin();
}
