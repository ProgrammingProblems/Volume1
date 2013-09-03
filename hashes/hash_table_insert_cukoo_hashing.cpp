void CuckooHashTable::insert(Item* entry) {
  std::set<size_t> visited[2];
  size_t table_index = 0;
  size_t index;
  do {
    auto& table = hash_tables[table_index];
    auto hashfn = hash_functions[table_index];
    index = hashfn(entry->key) % table.size();
    if (nullptr == table[index]) {
      table[index] = entry;
      return;
    }
    std::swap(entry, table[index]);
    visited[table_index].insert(index);

    table_index = 0 == table_index ? 1 : 0;
  } while (visited[table_index].end()
           == visited[table_index].find(index));
  resize(hash_tables[0].size() * 2 + 1);
  insert(entry);
}