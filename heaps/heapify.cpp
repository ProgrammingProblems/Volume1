void heapify(std::vector<int>* array) {
  for (auto itr = array->begin();
       itr != array->end();
       ++itr) {
    auto index = itr - array->begin();
    auto parent = parent_index(index);
    while (index != parent
           && (*array)[parent] < (*array)[index]) {
      std::swap((*array)[parent], (*array)[index]);
      index = parent;
      parent = parent_index(index);
    }
  }
}