size_t find_pivot(const std::vector<int>& array) {
  auto lower = array.begin();
  auto upper = array.end() - 1;
  while (lower < upper) {
    auto mid = lower + (upper - lower) / 2;
    if (*lower <= *mid) {
      if (*mid < *upper) break;
      lower = mid + 1;
    } else {
	    upper = mid;
    }
  }
 return lower - array.begin();
}
