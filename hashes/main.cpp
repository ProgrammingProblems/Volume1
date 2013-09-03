#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <sstream>
#include <unordered_map>
#include <vector>

#include "../test/testing.h"

std::mt19937 rng;

namespace simple_hash {
#include "simple_hash_function.cpp"
}
namespace normal_hash {
#include "normal_hash_function.cpp"
}
namespace complex_hash {
#include "complex_hash_function.cpp"
}

void TEST_HashFunctions() {
  ASSERT_EQ(simple_hash::hash("abcd"), simple_hash::hash("abcd"));
  ASSERT_NEQ(simple_hash::hash("a"), simple_hash::hash("b"));
  ASSERT_EQ(normal_hash::hash("abcd"), normal_hash::hash("abcd"));
  ASSERT_NEQ(normal_hash::hash("a"), normal_hash::hash("b"));
  ASSERT_EQ(complex_hash::hash("abcd"), complex_hash::hash("abcd"));
  ASSERT_NEQ(complex_hash::hash("a"), complex_hash::hash("b"));
}

#include "item.h"

namespace overview {
#include "hash_table.cpp"

size_t hash_function(const std::string& key) {
  return complex_hash::hash(key);
};

#include "hash_table_insert.cpp"
void TEST_Construction() {
  Hashtable h;
  h.resize(26);
  Item a = {"a", 'a'};
  Item b = {"b", 'b'};
  Item c = {"c", 'c'};
  Item abcd1234 = {"abcd1234", 99};
  Item abcdefghijklmnopqrstuv = {"abcdefghijklmnopqrstuv", 101};

  insert(&h, &a);
  ASSERT_EQ(h[complex_hash::hash("a") % h.size()]->value,'a');
  insert(&h, &b);
  ASSERT_EQ(h[complex_hash::hash("b") % h.size()]->value,'b');
  insert(&h, &c);
  ASSERT_EQ(h[complex_hash::hash("c") % h.size()]->value,'c');
  insert(&h, &abcd1234);
  ASSERT_EQ(h[complex_hash::hash("abcd1234") % h.size()]->value, 99);
  insert(&h, &abcdefghijklmnopqrstuv);
  ASSERT_EQ(h[complex_hash::hash("abcdefghijklmnopqrstuv") % h.size()]->value, 101);
}

#include "hash_table_lookup.cpp"
void TEST_Retreival() {
  Hashtable h;
  h.resize(26);
  Item a = {"a", 'a'};
  Item b = {"b", 'b'};
  Item c = {"c", 'c'};
  Item abcd1234 = {"abcd1234", 99};
  Item abcdefghijklmnopqrstuv = {"abcdefghijklmnopqrstuv", 101};

  ASSERT_EQ(find(&h, "blah"), nullptr);

  insert(&h, &a);
  ASSERT_EQ(find(&h, a.key), &a);
  insert(&h, &b);
  ASSERT_EQ(find(&h, b.key), &b);
  insert(&h, &c);
  ASSERT_EQ(find(&h, c.key), &c);
  insert(&h, &abcd1234);
  ASSERT_EQ(find(&h, abcd1234.key), &abcd1234);
  insert(&h, &abcdefghijklmnopqrstuv);
  ASSERT_EQ(find(&h, abcdefghijklmnopqrstuv.key), &abcdefghijklmnopqrstuv);
}

#include "hash_table_dyanmic_resizing.cpp"
void TEST_Resizing() {
  Hashtable h;
  h.resize(26);
  Item a = {"a", 'a'};
  Item b = {"b", 'b'};
  Item c = {"c", 'c'};
  Item abcd1234 = {"abcd1234", 99};
  Item abcdefghijklmnopqrstuv = {"abcdefghijklmnopqrstuv", 101};

  ASSERT_EQ(find(&h, "blah"), nullptr);

  insert(&h, &a);
  ASSERT_EQ(find(&h, a.key), &a);
  insert(&h, &b);
  ASSERT_EQ(find(&h, b.key), &b);
  insert(&h, &c);
  ASSERT_EQ(find(&h, c.key), &c);
  insert(&h, &abcd1234);
  ASSERT_EQ(find(&h, abcd1234.key), &abcd1234);
  insert(&h, &abcdefghijklmnopqrstuv);
  ASSERT_EQ(find(&h, abcdefghijklmnopqrstuv.key), &abcdefghijklmnopqrstuv);

  resize(&h, 52);
  ASSERT_EQ(h.size(), 52);
  ASSERT_EQ(find(&h, "blah"), nullptr);
  ASSERT_EQ(find(&h, a.key), &a);
  ASSERT_EQ(find(&h, b.key), &b);
  ASSERT_EQ(find(&h, c.key), &c);
  ASSERT_EQ(find(&h, abcd1234.key), &abcd1234);
  ASSERT_EQ(find(&h, abcdefghijklmnopqrstuv.key), &abcdefghijklmnopqrstuv);

  resize(&h, 13);
  ASSERT_EQ(h.size(), 13);
  ASSERT_EQ(find(&h, "blah"), nullptr);
  ASSERT_EQ(find(&h, a.key), &a);
  ASSERT_EQ(find(&h, b.key), &b);
  ASSERT_EQ(find(&h, c.key), &c);
  ASSERT_EQ(find(&h, abcd1234.key), &abcd1234);
  ASSERT_EQ(find(&h, abcdefghijklmnopqrstuv.key), &abcdefghijklmnopqrstuv);
}
} // namespae overview

namespace separate_chaining {
size_t hash_function(const std::string& key) {
  return simple_hash::hash(key);
};

#include "hash_table_separate_chaining.cpp"
#include "hash_table_insert_separate_chaining.cpp"
void TEST_Construction() {
  Hashtable h;
  h.resize(26);
  Item a = {"a", 'a'};
  Item b = {"b", 'b'};
  Item c = {"c", 'c'};
  Item abcd1234 = {"abcd1234", 99};
  Item abcdefghijklmnopqrstuv = {"abcdefghijklmnopqrstuv", 101};

  insert(&h, &a);
  ASSERT_EQ(h[simple_hash::hash("a") % h.size()].back()->value,'a');
  insert(&h, &b);
  ASSERT_EQ(h[simple_hash::hash("b") % h.size()].back()->value,'b');
  insert(&h, &c);
  ASSERT_EQ(h[simple_hash::hash("c") % h.size()].back()->value,'c');
  insert(&h, &abcd1234);
  ASSERT_EQ(h[simple_hash::hash("abcd1234") % h.size()].back()->value, 99);
  insert(&h, &abcdefghijklmnopqrstuv);
  ASSERT_EQ(h[simple_hash::hash("abcdefghijklmnopqrstuv") % h.size()].back()->value, 101);
}

#include "hash_table_lookup_separate_chaining.cpp"
void TEST_Retreival() {
  Hashtable h;
  h.resize(26);
  Item a = {"a", 'a'};
  Item b = {"b", 'b'};
  Item c = {"c", 'c'};
  Item abcd1234 = {"abcd1234", 99};
  Item abcdefghijklmnopqrstuv = {"abcdefghijklmnopqrstuv", 101};

  ASSERT_EQ(find(&h, "blah"), nullptr);

  insert(&h, &a);
  ASSERT_EQ(find(&h, a.key), &a);
  insert(&h, &b);
  ASSERT_EQ(find(&h, b.key), &b);
  insert(&h, &c);
  ASSERT_EQ(find(&h, c.key), &c);
  insert(&h, &abcd1234);
  ASSERT_EQ(find(&h, abcd1234.key), &abcd1234);
  insert(&h, &abcdefghijklmnopqrstuv);
  ASSERT_EQ(find(&h, abcdefghijklmnopqrstuv.key), &abcdefghijklmnopqrstuv);
}
} // namespace separate_chaining

namespace  open_addressing {
#include "hash_table.cpp"

size_t hash_function(const std::string& key) {
  return simple_hash::hash(key);
};

#include "hash_table_dyanmic_resizing.cpp"
#include "hash_table_insert_open_addressing.cpp"
void TEST_Construction() {
  Hashtable h;
  h.resize(26);
  Item a = {"a", 'a'};
  Item b = {"b", 'b'};
  Item c = {"c", 'c'};
  Item abcd1234 = {"abcd1234", 99};
  Item abcdefghijklmnopqrstuv = {"abcdefghijklmnopqrstuv", 101};

  insert(&h, &a);
  ASSERT_EQ(h[simple_hash::hash("a") % h.size()]->value,'a');
  insert(&h, &b);
  ASSERT_EQ(h[simple_hash::hash("b") % h.size()]->value,'b');
  insert(&h, &c);
  ASSERT_EQ(h[simple_hash::hash("c") % h.size()]->value,'c');
  insert(&h, &abcd1234);
  ASSERT_EQ(h[simple_hash::hash("abcd1234") % h.size()]->value, 'a');
  ASSERT_EQ(h[simple_hash::hash("abcd1234") % h.size() + 1]->value, 'b');
  ASSERT_EQ(h[simple_hash::hash("abcd1234") % h.size() + 2]->value, 'c');
  ASSERT_EQ(h[simple_hash::hash("abcd1234") % h.size() + 3]->value, 99);
  insert(&h, &abcdefghijklmnopqrstuv);
  ASSERT_EQ(h[simple_hash::hash("abcd1234") % h.size()]->value, 'a');
  ASSERT_EQ(h[simple_hash::hash("abcd1234") % h.size() + 1]->value, 'b');
  ASSERT_EQ(h[simple_hash::hash("abcd1234") % h.size() + 2]->value, 'c');
  ASSERT_EQ(h[simple_hash::hash("abcd1234") % h.size() + 3]->value, 99);
  ASSERT_EQ(h[simple_hash::hash("abcdefghijklmnopqrstuv") % h.size() + 4]->value, 101);
}

#include "hash_table_lookup_open_addressing.cpp"
void TEST_Retreival() {
  Hashtable h;
  h.resize(26);
  Item a = {"a", 'a'};
  Item b = {"b", 'b'};
  Item c = {"c", 'c'};
  Item abcd1234 = {"abcd1234", 99};
  Item abcdefghijklmnopqrstuv = {"abcdefghijklmnopqrstuv", 101};

  ASSERT_EQ(find(&h, "blah"), nullptr);

  insert(&h, &a);
  ASSERT_EQ(find(&h, a.key), &a);
  insert(&h, &b);
  ASSERT_EQ(find(&h, b.key), &b);
  insert(&h, &c);
  ASSERT_EQ(find(&h, c.key), &c);
  insert(&h, &abcd1234);
  ASSERT_EQ(find(&h, abcd1234.key), &abcd1234);
  insert(&h, &abcdefghijklmnopqrstuv);
  ASSERT_EQ(find(&h, abcdefghijklmnopqrstuv.key), &abcdefghijklmnopqrstuv);
}
} // namespace open_addressing

namespace cuckoo {
#include "hash_table.cpp"
#include "hash_table_cukoo_hashing.cpp"

CuckooHashTable::CuckooHashTable(size_t size) {
  hash_tables[0].resize(size);
  hash_tables[1].resize(size);

  hash_functions[0] = simple_hash::hash;
  hash_functions[1] = complex_hash::hash;
}

#include "hash_table_insert_cukoo_hashing.cpp"
#include "hash_table_dynamic_resizing_cuckoo_hashing.cpp"
#include "hash_table_lookup_cukoo_hashiing.cpp"
void TEST_CuckooHashing() {
  CuckooHashTable h(26);
  Item a = {"a", 'a'};
  Item b = {"b", 'b'};
  Item c = {"c", 'c'};
  Item abcd1234 = {"abcd1234", 99};
  Item abcdefghijklmnopqrstuv = {"abcdefghijklmnopqrstuv", 101};

  ASSERT_EQ(h.find("blah"), nullptr);

  h.insert(&a);
  ASSERT_EQ(h.find(a.key), &a);
  h.insert(&b);
  ASSERT_EQ(h.find(b.key), &b);
  h.insert(&c);
  ASSERT_EQ(h.find(c.key), &c);
  h.insert(&abcd1234);
  ASSERT_EQ(h.find(abcd1234.key), &abcd1234);
  h.insert(&abcdefghijklmnopqrstuv);
  ASSERT_EQ(h.find(abcdefghijklmnopqrstuv.key), &abcdefghijklmnopqrstuv);
}
}

#include "find_most_common_elements.cpp"
void TEST_MostCommon() {
  std::unordered_map<std::string, size_t> hash_map;
  std::string common;
  std::stringstream str1(std::stringstream::in | std::stringstream::out);
  hash_map.clear();
  common = find_most_common_element(str1, &hash_map);
  ASSERT_EQ(common, "");

  std::stringstream str2(std::stringstream::in | std::stringstream::out);
  str2 << "hi" << std::endl << "bye" << std::endl << "hi" << std::endl;
  hash_map.clear();
  common = find_most_common_element(str2, &hash_map);
  ASSERT_EQ(common, "hi");

  std::stringstream str3(std::stringstream::in | std::stringstream::out);
  str3  << "hi" << std::endl
        << "bye" << std::endl
        << "bye" << std::endl
        << "bye" << std::endl;
  hash_map.clear();
  common = find_most_common_element(str3, &hash_map);
  ASSERT_EQ(common, "bye");
}

#include "mru_cache.cpp"
#include "mru_cache_find.cpp"
#include "mru_cache_accessed.cpp"
MruCache::MruCache(size_t bound) : bound(bound) {
}

void TEST_Cache() {
  MruCache m(2);
  MruCache::Item item_a = {"a", 1};
  MruCache::Item item_b = {"b", 2};
  MruCache::Item item_c = {"c", 3};
  ASSERT_EQ(m.list.size(), 0);
  ASSERT_EQ(m.list.size(), m.table.size());
  m.store(&item_a);
  ASSERT_EQ(m.list.size(), 1);
  ASSERT_EQ(m.list.size(), m.table.size());
  ASSERT_EQ(m.list.front()->first, "a");
  m.store(&item_b);
  ASSERT_EQ(m.list.size(), 2);
  ASSERT_EQ(m.list.size(), m.table.size());
  ASSERT_EQ(m.list.front()->first, "b");
  ASSERT_EQ(m.list.back()->first, "a");
  m.find("a");
  ASSERT_EQ(m.list.size(), 2);
  ASSERT_EQ(m.list.size(), m.table.size());
  ASSERT_EQ(m.list.front()->first, "a");
  ASSERT_EQ(m.list.back()->first, "b");
  m.store(&item_c);

  ASSERT_EQ(m.list.size(), 2);
  ASSERT_EQ(m.list.size(), m.table.size());
  ASSERT_EQ(m.list.front()->first, "c");
  ASSERT_EQ(m.list.back()->first, "a");
}

int main(int argc, char** argv) {
  rng.seed();
  CALL(TEST_HashFunctions);
  CALL(overview::TEST_Construction);
  CALL(overview::TEST_Retreival);
  CALL(overview::TEST_Resizing);
  CALL(separate_chaining::TEST_Construction);
  CALL(separate_chaining::TEST_Retreival);
  CALL(open_addressing::TEST_Construction);
  CALL(open_addressing::TEST_Retreival);
  CALL(cuckoo::TEST_CuckooHashing);
  CALL(TEST_MostCommon);
  CALL(TEST_Cache);
  return 0;
}
