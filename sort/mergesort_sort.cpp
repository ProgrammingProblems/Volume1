void merge_sort(std::vector<int>::iterator begin,
                std::vector<int>::iterator end) {
  size_t len = end - begin;
  if (1 >= len) return;
  size_t prefix_len = len / 2;
  merge_sort(begin, begin + prefix_len);
  merge_sort(begin + prefix_len, end);
  std::inplace_merge(begin,begin + prefix_len,end);
}
