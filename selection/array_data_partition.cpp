void partition(const size_t index,
               const int value,
               ArrayBoundsList* data,
               Pivots* pivots,
               size_t* next_pos) {
  for (size_t offset = 1;
       offset + index < data->size();
       ++offset) {
    auto data_index = index + offset;
    auto& tuple = data->at(data_index);
    auto& array = std::get<0>(tuple);
    auto begin = array.begin()+std::get<1>(tuple);
    auto end = begin + std::get<2>(tuple);
    auto pos = std::partition(
      begin,
      end,
      [value] (int rhs) { return rhs < value; });
    bool found_value = false;
    if (end != pos) {
      nth_element(pos, pos, end);
      if (value == *pos) {
        found_value = true;
      }
    }
    pivots->push_back({pos - array.begin(),
                       found_value});
    *next_pos += std::get<1>(tuple)
                 + pivots->back().first
                 + (pivots->back().second ? 1 : 0);
  }
}