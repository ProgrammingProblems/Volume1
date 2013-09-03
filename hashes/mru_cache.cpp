struct MruCache {
  typedef std::string key_type;
  typedef int value_type;
  typedef std::pair<key_type, value_type> Item;
  typedef std::list<const Item*> List;
  List list;
  typedef std::unordered_map<
    key_type, List::iterator>
      Hashtable;
  Hashtable table;
  const size_t bound;

  MruCache(size_t bound);
  void store(const Item* item);
  const Item* find(const key_type& key);
};
