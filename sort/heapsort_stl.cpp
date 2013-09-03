void heap_sort(std::vector<int>* array) {
  std::make_heap(array->begin(), array->end());
  for (size_t offset = array->size();
       offset > 0;
       offset--) {
    std::pop_heap(array->begin(),
                  array->begin() + offset);
  }
}