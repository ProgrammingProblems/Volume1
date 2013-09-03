void MruCache::store(const Item* item) {
  list.push_front(item);
  table[item->first] = list.begin();
  if (list.size() > bound) {
    table.erase(list.back()->first);
    list.pop_back();
  }
}