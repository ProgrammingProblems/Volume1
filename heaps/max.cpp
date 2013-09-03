int max(const std::vector<int>& array) {
  int max_val = array[0];
  for (auto& element: array) {
    max_val = std::max(element, max_val);
  }
  return max_val;
}