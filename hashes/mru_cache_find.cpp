const MruCache::Item* MruCache::find(
    const key_type& key) {
  auto iter = table.find(key);
  if (table.end() != iter) {
    list.splice(list.begin(), list, iter->second);
    return *(iter->second);
  }
  return nullptr;
}