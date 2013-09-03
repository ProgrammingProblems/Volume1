void merge_vectors(
    const std::vector<std::vector<int>>& in,
    std::vector<int>* out) {
  typedef std::vector<int> Array;
  typedef Array::const_iterator Iterator;
  typedef std::tuple<Iterator, Iterator> Element;
  std::vector<Element> heap;
  for (int index = 0; index < in.size(); ++index) {
    if (!in[index].empty()) {
      Element tuple(in[index].begin(),
                    in[index].end());
      heap.push_back(tuple);
    }
  }
  auto comparator = [] (const Element& lhs,
                        const Element& rhs) {
    return *std::get<0>(lhs) < *std::get<0>(rhs);
  };
  std::make_heap(heap.begin(),
                 heap.end(),
                 comparator);
  while (!heap.empty()) {
    auto tuple = heap.front();
    std::pop_heap(
      heap.begin(),
      heap.end(),
      comparator);
    out->push_back(*std::get<0>(tuple));
    if (std::get<1>(tuple) != ++std::get<0>(tuple)) {
      heap.push_back(tuple);
      std::push_heap(
        heap.begin(),
        heap.end(),
        comparator);
    }
  }
}