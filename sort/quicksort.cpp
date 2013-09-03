void quick_sort(std::vector<int>::iterator begin,
                std::vector<int>::iterator end) {
  size_t len = end - begin;
  if (len < 2) return;
  size_t pivot = len / 2;
  std::nth_element(begin,
                   begin + pivot,
                   end);
  quick_sort(begin, begin + pivot);
  quick_sort(begin + pivot, end);
}