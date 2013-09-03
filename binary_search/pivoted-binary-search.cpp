size_t find(const std::vector<int>& array,
            size_t pivot,
            int key) {
  auto begin = array.begin();
  auto length = array.size();
  auto lower = array.begin();
  auto upper = array.end() - 1;
  while (lower < upper) {
    auto mid = lower + (upper - lower) / 2;
    auto mid_val = begin+(mid-begin+pivot)%length;
    if (key <= *mid_val) upper = mid;
    else lower = mid + 1;
  }
 return (lower - begin + pivot) % length;
}
