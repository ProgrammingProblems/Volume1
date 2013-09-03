int median_of_3(const std::vector<int>& array,
                size_t offset,
                size_t length) {
  auto begin = array.begin() + offset;
  std::vector<int> sub(begin, begin + length);
  std::sort(sub.begin(), sub.end());
  return sub[(length - 1) / 2];
}