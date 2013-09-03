struct CuckooHashTable {
  typedef std::function<
    size_t(const std::string&)>
      HashFunction;
  typedef HashFunction CuckooHashFunctions[2];
  typedef Hashtable CuckooHashTables[2];

  CuckooHashFunctions hash_functions;
  CuckooHashTables hash_tables;

  explicit CuckooHashTable(size_t size);
  void insert(Item* entry);
  void resize(size_t size);
  Item* find(const std::string&);
};