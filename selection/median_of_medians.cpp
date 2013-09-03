size_t pivot_index(const std::vector<int>& array,
                   size_t offset,
                   size_t length) {
  auto find_index = [&array, offset] (
      const int val) {
    size_t index = offset;
    while (val != array[index]) {
      ++index;
    }
    return index;
  };
  if (length <= 3) {
    return find_index(
             median_of_3(array, offset, length));
  }
  size_t num = length / 3
               + ((length % 3) ? 1 : 0);
  std::vector<int> medians(num);
  for (size_t step = 0; step < num; ++step) {
    const static size_t three = 3;
    size_t index = step * 3;
    medians[step] =
      median_of_3(array,
                  offset + index,
                  std::min(three, length - index));
  }
  return find_index(median(&medians));
}