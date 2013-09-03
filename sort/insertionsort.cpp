void insertion_sort(std::vector<int>* array) {
  for (int i = 1; i < array->size(); ++i) {
    auto val = (*array)[i];
    for (int j = i -1;
         j >= 0 && (*array)[j] > val;
         --j) {
      std::swap((*array)[j], (*array)[j+1]);
    }
  }
}

