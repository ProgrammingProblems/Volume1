void increase_key(std::vector<int>* heap,
                  size_t index) {
  (*heap)[index]++;
  auto parent = parent_index(index);
  while (0 != index
         && (*heap)[index] > (*heap)[parent]) {
    std::swap((*heap)[index], (*heap)[parent]);
    index = parent_index(index);
    parent = parent_index(index);
  }
}