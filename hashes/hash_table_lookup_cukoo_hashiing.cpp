Item* CuckooHashTable::find(
    const std::string& key) {
  for (size_t table_index = 0;
       table_index < 2;
       ++table_index) {
    auto& table = hash_tables[table_index];
    auto hashfn = hash_functions[table_index];
    auto index = hashfn(key) % table.size();
    if (nullptr == table[index]) return nullptr;
    if (key == table[index]->key) {
      return table[index];
    }
  }
  return nullptr;
}