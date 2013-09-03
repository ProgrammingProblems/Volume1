void initialize_data(Arrays* arrays,
                     ArrayBoundsList* data,
                     size_t* total_size) {
  for (auto& array: *arrays) {
    data->push_back(
      ArrayBounds(array, 0, array.size()));
    *total_size += array.size();
  };
}
