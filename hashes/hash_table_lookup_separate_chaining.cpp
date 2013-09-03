Item* find(Hashtable* table,
           const std::string& key) {
  int index = hash_function(key) % table->size();
  for (auto entry: (*table)[index]) {
    if (key == entry->key) return entry;
  }
  return nullptr;
}