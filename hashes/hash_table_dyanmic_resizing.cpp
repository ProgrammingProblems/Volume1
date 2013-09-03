void resize(Hashtable* table, size_t size) {
  Hashtable new_table(size);
  for (auto entry: *table) {
    if (nullptr != entry) {
      auto index = hash_function(entry->key)
                   % new_table.size();
      new_table[index] = entry;
    }
  }
  table->swap(new_table);
}