void insert(Hashtable* table, Item* entry) {
  auto index = hash_function(entry->key)
               % table->size();
  (*table)[index] = entry;
}