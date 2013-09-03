int median(std::vector<int>* array) {
  return select(array, (array->size() - 1) / 2);
}