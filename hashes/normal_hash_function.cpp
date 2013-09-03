size_t hash(const std::string& str) {
  size_t hash_value = 0;
  for (auto c : str) {
    hash_value += c - 'a';
  }
  return hash_value;
}