#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <sstream>
#include <vector>

#include "../test/testing.h"

std::mt19937 rng;

#include "heap_position_parent.cpp"
#include "heap_position_children.cpp"
#include "heapify.cpp"
void TEST_Construction() {
  std::vector<int> v = {1};
  heapify(&v);
  ASSERT_EQ(v[0], 1);

  v = {2, 1};
  heapify(&v);
  ASSERT(std::is_heap(v.begin(), v.end()));
  ASSERT_EQ(v[0], 2);

  v = {1, 2};
  heapify(&v);
  ASSERT(std::is_heap(v.begin(), v.end()));
  ASSERT_EQ(v[0], 2);

  v = {1, 2, 3};
  heapify(&v);
  ASSERT(std::is_heap(v.begin(), v.end()));
  ASSERT_EQ(v[0], 3);

  v = {1, 3, 2};
  heapify(&v);
  ASSERT(std::is_heap(v.begin(), v.end()));
  ASSERT_EQ(v[0], 3);

  v = {2, 1, 3};
  heapify(&v);
  ASSERT(std::is_heap(v.begin(), v.end()));
  ASSERT_EQ(v[0], 3);

  v = {2, 3, 1};
  heapify(&v);
  ASSERT(std::is_heap(v.begin(), v.end()));
  ASSERT_EQ(v[0], 3);

  v = {3, 1, 2};
  heapify(&v);
  ASSERT(std::is_heap(v.begin(), v.end()));
  ASSERT_EQ(v[0], 3);

  v = {3, 2, 1};
  heapify(&v);
  ASSERT(std::is_heap(v.begin(), v.end()));
  ASSERT_EQ(v[0], 3);

  v = {9,20,2,8,3,18,11,4,1,5,19,17,10,16,12,7,14,6,13,15,21};
  heapify(&v);
  ASSERT(std::is_heap(v.begin(), v.end()));
  ASSERT_EQ(v[0], 21);
}

#include "heap_insert.cpp"
void TEST_Insert() {
  std::vector<int> v = {1};
  heapify(&v);
  ASSERT(std::is_heap(v.begin(), v.end()));
  ASSERT_EQ(v[0], 1);

  insert(&v, 2);
  ASSERT(std::is_heap(v.begin(), v.end()));
  ASSERT_EQ(v[0], 2);

  insert(&v, 3);
  ASSERT(std::is_heap(v.begin(), v.end()));
  ASSERT_EQ(v[0], 3);

  insert(&v, 0);
  ASSERT(std::is_heap(v.begin(), v.end()));
  ASSERT_EQ(v[0], 3);

  insert(&v, 4);
  ASSERT(std::is_heap(v.begin(), v.end()));
  ASSERT_EQ(v[0], 4);

  insert(&v, 9);
  ASSERT(std::is_heap(v.begin(), v.end()));
  ASSERT_EQ(v[0], 9);

  insert(&v, 8);
  ASSERT(std::is_heap(v.begin(), v.end()));
  ASSERT_EQ(v[0], 9);

  insert(&v, 7);
  ASSERT(std::is_heap(v.begin(), v.end()));
  ASSERT_EQ(v[0], 9);

  insert(&v, 6);
  ASSERT(std::is_heap(v.begin(), v.end()));
  ASSERT_EQ(v[0], 9);

  insert(&v, -1);
  ASSERT(std::is_heap(v.begin(), v.end()));
  ASSERT_EQ(v[0], 9);

  insert(&v, 5);
  ASSERT(std::is_heap(v.begin(), v.end()));
  ASSERT_EQ(v[0], 9);
}

#include "find_min.cpp"
void TEST_FindMax() {
  std::vector<int> v = {1};
  ASSERT_EQ(find_max(v), 1);

  insert(&v, 2);
  ASSERT_EQ(find_max(v), 2);

  insert(&v, 3);
  ASSERT_EQ(find_max(v), 3);

  insert(&v, 0);
  ASSERT_EQ(find_max(v), 3);

  insert(&v, 4);
  ASSERT_EQ(find_max(v), 4);

  insert(&v, 9);
  ASSERT_EQ(find_max(v), 9);

  insert(&v, 8);
  ASSERT_EQ(find_max(v), 9);

  insert(&v, 7);
  ASSERT_EQ(find_max(v), 9);

  insert(&v, 6);
  ASSERT_EQ(find_max(v), 9);

  insert(&v, -1);
  ASSERT_EQ(find_max(v), 9);

  insert(&v, 5);
  ASSERT_EQ(find_max(v), 9);
}

#include "heap_remove.cpp"
void TEST_RemoveMax() {
  std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};
  heapify(&v);

  while (v.size()) {
    remove_max(&v);
    ASSERT(std::is_heap(v.begin(), v.end()));
    if (v.size()) {
      ASSERT_EQ(find_max(v), v.size());
    }
  }
}

#include "heap_decrease_key.cpp"
void TEST_IncreaseKey() {
  std::uniform_int_distribution<size_t> uint_dist10(0,9);
  std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};
  heapify(&v);

  for (int i = 0; i < 100; ++i) {
    auto index = uint_dist10(rng);
    increase_key(&v, index);
    ASSERT(std::is_heap(v.begin(), v.end()));
  }
}

#include "heap-enumerate-powers-of-terms.cpp"
void TEST_EnumeratePowers() {
  std::set<unsigned> set;
  std::vector<int> output;

  set = {2,3,4,5};
  output.clear();
  enumerate_powers(set, 1, &output);
  ASSERT_EQ(output[0], 1);

  output.clear();
  enumerate_powers(set, 2, &output);
  ASSERT_EQ(output[1], 2);

  output.clear();
  enumerate_powers(set, 3, &output);
  ASSERT_EQ(output[2], 3);

  output.clear();
  enumerate_powers(set, 4, &output);
  ASSERT_EQ(output[3], 4);

  output.clear();
  enumerate_powers(set, 5, &output);
  ASSERT_EQ(output[4], 5);

  output.clear();
  enumerate_powers(set, 6, &output);
  ASSERT_EQ(output[5], 8);

  output.clear();
  enumerate_powers(set, 7, &output);
  ASSERT_EQ(output[6], 9);

  output.clear();
  enumerate_powers(set, 8, &output);
  ASSERT_EQ(output[7], 16);
}

#include "topk_elements_file.cpp"

void TEST_TopK() {
  std::vector<int> heap;

  auto init_stream = [] (std::iostream& str) {
    str << 1 << std::endl;
    str << 9 << std::endl;
    str << 2 << std::endl;
    str << 8 << std::endl;
    str << 3 << std::endl;
    str << 7 << std::endl;
    str << 4 << std::endl;
    str << 6 << std::endl;
    str << 5 << std::endl;
  };


  auto find_top_k = [&init_stream] (std::vector<int>& array,
                                    size_t size) {
    array.clear();
    std::stringstream str(std::stringstream::in | std::stringstream::out);
    init_stream(str);
    find_topk(str, size, &array);
  };

  find_top_k(heap, 1);
  ASSERT_EQ(heap[0], 9);

  find_top_k(heap, 2);
  ASSERT_EQ(heap[0], 8);

  find_top_k(heap, 3);
  ASSERT_EQ(heap[0], 7);

  find_top_k(heap, 4);
  ASSERT_EQ(heap[0], 6);

  find_top_k(heap, 5);
  ASSERT_EQ(heap[0], 5);

  find_top_k(heap, 6);
  ASSERT_EQ(heap[0], 4);
}

int main(int argc, char** argv) {
  rng.seed();
  CALL(TEST_Construction);
  CALL(TEST_Insert);
  CALL(TEST_FindMax);
  CALL(TEST_RemoveMax);
  CALL(TEST_IncreaseKey);
  CALL(TEST_EnumeratePowers);
  CALL(TEST_TopK);
  return 0;
}
