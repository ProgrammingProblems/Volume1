Item* find(Hashtable* table,
           const std::string& key) {
  auto index = hash_function(key) % table->size();
  if (nullptr != (*table)[index]
      && key == (*table)[index]->key) {
    return (*table)[index];
  }
  return nullptr;
}