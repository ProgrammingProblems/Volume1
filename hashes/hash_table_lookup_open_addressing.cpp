Item* find(Hashtable* table,
           const std::string& key) {
  size_t index = hash_function(key)
                 % table->size();
  for (size_t offset = 0;
       offset < table->size();
       ++offset) {
    auto bucket_index = (index + offset)
                        % table->size();
    auto& item = (*table)[bucket_index];
    if (nullptr == item) return nullptr;
    if (key == item->key) return item;
  }
  return nullptr;
}