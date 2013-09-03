size_t parent_index(const size_t index) {
  return (index != 0) ? (index - 1) / 2 : 0;
}