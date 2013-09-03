void CuckooHashTable::resize(size_t size) {
  Hashtable new_table;
  while (true) {
    size = 1.1 * size + 1;
    new_table.resize(size);
    for (auto entry: hash_tables[0]) {
      if (nullptr != entry) {
        size_t index = hash_functions[0](entry->key)
                       % new_table.size();
        if (nullptr != new_table[index]) {
          continue;
        }
        new_table[index] = entry;
      }
    }
    for (auto entry: hash_tables[1]) {
      if (nullptr != entry) {
        size_t index = hash_functions[0](entry->key)
                       % new_table.size();
        if (nullptr != new_table[index]) {
          continue;
        }
        new_table[index] = entry;
      }
    }
  }
  hash_tables[0].swap(new_table);
  hash_tables[1].clear();
  hash_tables[1].resize(size);
}