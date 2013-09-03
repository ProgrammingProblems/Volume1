int select(std::vector<int>* array, size_t k) {
  std::function<int(std::vector<int>*,
                    size_t,
                    size_t)>
  selection = [k, &selection]  (
      std::vector<int>* array,
      size_t offset,
      size_t length) {
    auto index = pivot_index(*array,offset,length);
    size_t pos = partition(array,
                           index,
                           offset,
                           length);
    if (pos == k) {
      return array->at(k);
    }
    if (pos > k) {
      return selection(array, offset, pos-offset);
    }
    return selection(array,
                     pos+1,
                     length - (pos + 1 - offset));
  };
  return selection(array, 0, array->size());
}