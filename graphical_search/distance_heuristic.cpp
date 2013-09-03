size_t distance(
    const std::pair<size_t, size_t> begin,
    const std::pair<size_t, size_t> end) {
  return std::abs(begin.first - end.first) +
         std::abs(begin.second - end.second);
}