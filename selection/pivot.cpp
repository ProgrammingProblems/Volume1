size_t partition(std::vector<int>* array,
                 size_t pos,
                 size_t offset,
                 size_t length) {
  if (length <= 1) return offset;
  int val = (*array)[pos];
  std::swap((*array)[offset], (*array)[pos]);
  auto left = offset;
  auto right = offset + length - 1;
  while (left < right) {
    if (val < (*array)[right]) {
      --right;
    } else {
      std::swap((*array)[left], (*array)[left+1]);
      if (right != left + 1) {
        std::swap((*array)[left], (*array)[right]);
      }
      ++left;
    }
  }
  return left;
}