void insert(Hashtable* table, Item* entry) {
  while (true) {
    auto index = hash_function(entry->key)
                 % table->size();
    for (size_t offset = 0;
         offset < table->size();
         ++offset) {
      size_t bucket_index = (index + offset)
                            % table->size();
      if (nullptr == (*table)[bucket_index]) {
        (*table)[bucket_index] = entry;
        return;
      }
    }
    resize(table, table->size() * 2 + 1);
  }
}