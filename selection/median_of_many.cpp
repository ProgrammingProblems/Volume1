int median(Arrays* arrays) {
  ArrayBoundsList data;
  size_t total_size = 0;
  initialize_data(arrays, &data, &total_size);
  auto median_pos = (total_size - 1) / 2 + 1;
  size_t pos_offset = 0;
  for (size_t data_index = 0;
       data_index < data.size();
       ++data_index) {
    auto& tuple = data[data_index];
    auto& array = std::get<0>(tuple);
    auto& offset = std::get<1>(tuple);
    auto& length = std::get<2>(tuple);
    auto begin = array.begin() + offset;
    while (0 != length) {
      auto mid_index = offset + length / 2;
      auto mid = array.begin() + mid_index;
      std::nth_element(begin,
                       mid,
                       begin + length);
      auto value = *(mid);
      auto mid_pos = pos_offset + mid_index + 1;
      Pivots pivots;
      pivots.push_back({mid_index, true});
      partition(data_index,
                value,
                &data,
                &pivots,
                &mid_pos);
      if (mid_pos == median_pos) return value;
      update_search_bounds(median_pos,
                           mid_pos,
                           data_index,
                           &data,
                           &pivots);
    }
    pos_offset += offset;
  }
  auto& tuple = data[data.size() - 1];
  auto& array = std::get<0>(tuple);
  auto& offset = std::get<1>(tuple);
  return array[offset];
}