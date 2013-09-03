#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#include "../test/testing.h"

std::vector<std::vector<int>> vectors =
{ {0},
  {0,1},
  {1,0},
  {1,2,0},
  {1,0,2},
  {2,1,0},
  {2,0,1},
  {0,1,2},
  {0,2,1},
  {2,3,1,0},
  {2,3,4,1,0},
  {2,3,4,1,5,0},
  {2,3,4,1,5,6,0},
  {2,3,4,1,5,7,6,0},
  {0,2,8,3,4,1,5,7,6},
  {9,0,2,8,3,4,1,5,7,6},
  {9,0,2,8,3,4,1,5,10,7,6},
  {9,0,2,8,3,11,4,1,5,10,7,6},
  {9,0,2,8,3,11,4,1,5,10,12,7,6},
  {9,0,2,8,3,11,4,1,5,10,12,7,6,13},
  {9,0,2,8,3,11,4,1,5,10,12,7,14,6,13},
  {9,0,2,8,3,11,4,1,5,10,12,7,14,6,13,15},
  {9,20,0,2,8,3,18,11,4,1,5,19,17,10,16,12,7,14,6,13,15,21},
  {14,3,16,17,4,18,12,7,8,15,11,20,5,1,9,6,21,13,19,10,2,0}
};

#include "insertionsort.cpp"
void TEST_InsertionSort() {
  std::vector<int> v;
  for (size_t i = 0; i < vectors.size(); ++i) {
    v.clear();
    v = vectors[i];
    insertion_sort(&v);
    for (size_t j = 0; j < v.size(); ++j) {
      ASSERT_EQ(v[j], j);
    }
  }
}

#include "heapsort_stl.cpp"
void TEST_HeapSort() {
  std::vector<int> v;
  for (size_t i = 0; i < vectors.size(); ++i) {
    v.clear();
    v = vectors[i];
    heap_sort(&v);
    for (size_t j = 0; j < v.size(); ++j) {
      ASSERT_EQ(v[j], j);
    }
  }
}

#include "radixsort.cpp"
void TEST_RadixSort() {
  std::vector<int> v;
  for (size_t i = 0; i < vectors.size(); ++i) {
    v.clear();
    v = vectors[i];
    radix_sort(&v);
    for (size_t j = 0; j < v.size(); ++j) {
      ASSERT_EQ(v[j], j);
    }
  }
}

#include "mergesort_sort.cpp"
#include "mergesort_sort_from_vector.cpp"
void TEST_MergeSort() {
  std::vector<int> v;
  for (size_t i = 0; i < vectors.size(); ++i) {
    v.clear();
    v = vectors[i];
    merge_sort(&v);
    for (size_t j = 0; j < v.size(); ++j) {
      ASSERT_EQ(v[j], j);
    }
  }
}

#include "quicksort.cpp"
#include "quicksort_from_vector.cpp"
void TEST_Quicksort() {
  std::vector<int> v;
  for (size_t i = 0; i < vectors.size(); ++i) {
    v.clear();
    v = vectors[i];
    quick_sort(&v);
    for (size_t j = 0; j < v.size(); ++j) {
      ASSERT_EQ(v[j], j);
    }
  }
}

#include "merge_streams.cpp"

int main(int argc, char** argv) {
  CALL(TEST_InsertionSort);
  CALL(TEST_HeapSort);
  CALL(TEST_RadixSort);
  CALL(TEST_MergeSort);
  CALL(TEST_Quicksort);
  return 0;
}
