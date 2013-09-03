void update_search_bounds(const size_t target_pos,
                          const size_t current_pos,
                          const size_t data_index,
                          ArrayBoundsList* data,
                          Pivots* pivots) {
  std::function<void(size_t, size_t)> update
    = nullptr;
  if (current_pos > target_pos) {
    update = [data, pivots] (size_t index,
                             size_t offset) {
      auto& tuple = data->at(index + offset);
      std::get<2>(tuple) =
        pivots->at(offset).first
        - std::get<1>(tuple);
    };
  } else {
    update = [data, pivots] (size_t index,
                             size_t offset) {
      auto& tuple = data->at(index + offset);
      std::get<2>(tuple) -=
        pivots->at(offset).first
        - std::get<1>(tuple);
      std::get<1>(tuple)=pivots->at(offset).first;
      if (0 == offset) {
        std::get<2>(tuple) -= 1;
        std::get<1>(tuple) += 1;
      }
    };
  }
  for (size_t offset = 0;
       offset + data_index < data->size();
       ++offset) {
    update(data_index, offset);
  }
}