void insert(std::vector<int>* heap, int value) {
  heap->push_back(value);
  auto index = heap->size() - 1;
  auto parent= parent_index(index);
  while (index != 0
         && (*heap)[index] > (*heap)[parent]) {
    std::swap((*heap)[index], (*heap)[parent]);
    index = parent;
    parent= parent_index(index);
  }
}