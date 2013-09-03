std::string find_most_common_element(
    std::istream& stream,
    std::unordered_map<std::string, size_t>*
      hash_table) {
  std::string str;
  while (!stream.eof() && stream >> str) {
    (*hash_table)[str] += 1;
  }
  std::string max_str;
  size_t max_count = 0;
  for (auto& entry : *hash_table) {
    if (entry.second > max_count) {
      max_str = entry.first;
      max_count = entry.second;
    }
  }
  return max_str;
}