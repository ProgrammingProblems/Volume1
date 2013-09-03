size_t hash(const std::string& str) {
  int count = 16;
  size_t hash_value = 0;
  const char* cstr = str.c_str();
  while (cstr && *cstr && --count) {
    hash_value += (*cstr++ - 'a') << (count % 4);
  }
  return hash_value;
}