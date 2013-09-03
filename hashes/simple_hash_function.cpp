size_t hash(const std::string& str) {
  if (str.empty()) return 0;
  return str[0] - 'a';
}