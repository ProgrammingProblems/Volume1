void enumerate_powers(
    const std::set<unsigned>& set,
    size_t num_powers,
    std::vector<int>* out) {
  typedef std::pair<unsigned, unsigned> ValueTerm;
  std::vector<ValueTerm> heap;
  for(auto& value: set) {
    heap.push_back({1, value});
  }
  std::make_heap(heap.begin(),
                 heap.end(),
                 std::greater<ValueTerm>());
  int value = 0;
  while (0 != num_powers && 0 != heap.size()) {
    auto entry = heap.front();
    std::pop_heap(heap.begin(),
                  heap.end(),
                  std::greater<ValueTerm>());
    if (value != entry.first) {
      value = entry.first;
      out->push_back(value);
      --num_powers;
    }
    heap.back() = {entry.first * entry.second,
                   entry.second};
    std::push_heap(heap.begin(),
                   heap.end(),
                   std::greater<ValueTerm>());
  }
}