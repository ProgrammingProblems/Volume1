void find_topk(std::istream& in,
               size_t k,
               std::vector<int>* heap) {
  heap->reserve(k);
  int val;
  while (heap->size() < k
         && in >> val) {
    heap->push_back(val);
  }
  std::make_heap(heap->begin(),
                 heap->end(),
                 std::greater<int>());
  while (!in.eof() && in >> val) {
    if (val > heap->front()) {
      std::pop_heap(heap->begin(),
                    heap->end(),
                    std::greater<int>());
      heap->back() = val;
      std::push_heap(heap->begin(),
                     heap->end(),
                     std::greater<int>());
    }
  }
}