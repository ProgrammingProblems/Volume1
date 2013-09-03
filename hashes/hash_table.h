class Hashtable {
 public:
  typedef Item* data_type;
  typedef std::string key_type;

  void insert(data_type);
  data_type find(const key_type&);
  void resize(size_t);

 protected:
  size_t hash_function(const std::string&);
  std::vector<Item*> data_;
}