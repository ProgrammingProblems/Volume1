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

namespace bs {
#include "binary-search.cpp"
void TEST_BinarySearch() {
  std::vector<int> array;
  array = {1};
  ASSERT_EQ(find(array, 1), 0);
  array = {1,3};
  ASSERT_EQ(find(array, 1), 0);
  ASSERT_EQ(find(array, 3), 1);
  array = {1,1,3,5,7,9};
  ASSERT_EQ(find(array, 1), 0);
  ASSERT_EQ(find(array, 2), 1);
  ASSERT_EQ(find(array, 7), 4);
  ASSERT_EQ(find(array, 9), 5);
  ASSERT_EQ(find(array, 10), 5);
}
}

namespace lm {
#include "leftmost-binary-search.cpp"
void TEST_BinarySearch() {
  std::vector<int> array;
  array = {1};
  ASSERT_EQ(find(array, 1), 0);
  array = {1,3};
  ASSERT_EQ(find(array, 1), 0);
  ASSERT_EQ(find(array, 3), 1);
  array = {1,1,3,5,7,9};
  ASSERT_EQ(find(array, 1), 0);
  ASSERT_EQ(find(array, 2), 2);
  ASSERT_EQ(find(array, 7), 4);
  ASSERT_EQ(find(array, 9), 5);
  ASSERT_EQ(find(array, 10), 5);
  array = {1,1,3,3,3,5,5,5,5,5,7,7,9,9,9,9,9,9,9,10};
  ASSERT_EQ(find(array, 1), 0);
  ASSERT_EQ(find(array, 2), 2);
  ASSERT_EQ(find(array, 3), 2);
  ASSERT_EQ(find(array, 4), 5);
  ASSERT_EQ(find(array, 5), 5);
  ASSERT_EQ(find(array, 7), 10);
  ASSERT_EQ(find(array, 9), 12);
  ASSERT_EQ(find(array, 10), 19);
}
}

namespace rt {
#include "rotated-binary-search.cpp"
void TEST_BinarySearch() {
  std::vector<int> array;
 array = {1};
  ASSERT_EQ(find(array, 1), 0);
  array = {1,3};
  ASSERT_EQ(find(array, 1), 0);
  ASSERT_EQ(find(array, 3), 1);
  array = {1,1,3,5,7,9};
  ASSERT_EQ(find(array, 1), 0);
  ASSERT_EQ(find(array, 7), 4);
  ASSERT_EQ(find(array, 9), 5);
  array = {1,1,3,3,3,5,5,5,5,5,7,7,9,9,9,9,9,9,9,10};
  ASSERT_EQ(find(array, 1), 0);
  ASSERT_EQ(find(array, 3), 2);
  ASSERT_EQ(find(array, 5), 5);
  ASSERT_EQ(find(array, 7), 10);
  ASSERT_EQ(find(array, 9), 12);

  array = {3,1};
  ASSERT_EQ(find(array, 1), 1);
  ASSERT_EQ(find(array, 3), 0);

  array = {1,3,5};
  ASSERT_EQ(find(array, 1), 0);
  ASSERT_EQ(find(array, 3), 1);
  ASSERT_EQ(find(array, 5), 2);

  array = {5,1,3};
  ASSERT_EQ(find(array, 1), 1);
  ASSERT_EQ(find(array, 3), 2);
  ASSERT_EQ(find(array, 5), 0);

  array = {3,5,1};
  ASSERT_EQ(find(array, 1), 2);
  ASSERT_EQ(find(array, 3), 0);
  ASSERT_EQ(find(array, 5), 1);

  array = {1,3,5,7};
  ASSERT_EQ(find(array, 1), 0);
  ASSERT_EQ(find(array, 3), 1);
  ASSERT_EQ(find(array, 5), 2);
  ASSERT_EQ(find(array, 7), 3);

  array = {7,1,3,5};
  ASSERT_EQ(find(array, 1), 1);
  ASSERT_EQ(find(array, 3), 2);
  ASSERT_EQ(find(array, 5), 3);
  ASSERT_EQ(find(array, 7), 0);

  array = {5,7,1,3};
  ASSERT_EQ(find(array, 1), 2);
  ASSERT_EQ(find(array, 3), 3);
  ASSERT_EQ(find(array, 5), 0);
  ASSERT_EQ(find(array, 7), 1);

  array = {3,5,7,1};
  ASSERT_EQ(find(array, 1), 3);
  ASSERT_EQ(find(array, 3), 0);
  ASSERT_EQ(find(array, 5), 1);
  ASSERT_EQ(find(array, 7), 2);
}
}

namespace pivot {
#include "find-pivot.cpp"
void TEST_Pivot() {
  std::vector<int> array;
  array = {1};
  ASSERT_EQ(find_pivot(array), 0);
  array = {1,3};
  ASSERT_EQ(find_pivot(array), 0);
  array = {1,1,3,5,7,9};
  ASSERT_EQ(find_pivot(array), 0);
  array = {1,1,3,3,3,5,5,5,5,5,7,7,9,9,9,9,9,9,9,10};
  ASSERT_EQ(find_pivot(array), 0);
  array = {3,1};
  ASSERT_EQ(find_pivot(array), 1);
  array = {1,3,5};
  ASSERT_EQ(find_pivot(array), 0);
  array = {5,1,3};
  ASSERT_EQ(find_pivot(array), 1);
  array = {3,5,1};
  ASSERT_EQ(find_pivot(array), 2);
  array = {1,3,5,7};
  ASSERT_EQ(find_pivot(array), 0);
  array = {7,1,3,5};
  ASSERT_EQ(find_pivot(array), 1);
  array = {5,7,1,3};
  ASSERT_EQ(find_pivot(array), 2);
  array = {3,5,7,1};
  ASSERT_EQ(find_pivot(array), 3);
}

#include "pivoted-binary-search.cpp"
void TEST_BinarySearch() {
  std::vector<int> array;
  array = {1};
  ASSERT_EQ(find(array, find_pivot(array), 1), 0);
  array = {1,3};
  ASSERT_EQ(find(array, find_pivot(array), 1), 0);
  ASSERT_EQ(find(array, find_pivot(array), 3), 1);
  array = {1,1,3,5,7,9};
  ASSERT_EQ(find(array, find_pivot(array), 1), 0);
  ASSERT_EQ(find(array, find_pivot(array), 7), 4);
  ASSERT_EQ(find(array, find_pivot(array), 9), 5);
  array = {1,1,3,3,3,5,5,5,5,5,7,7,9,9,9,9,9,9,9,10};
  ASSERT_EQ(find(array, find_pivot(array), 1), 0);
  ASSERT_EQ(find(array, find_pivot(array), 3), 2);
  ASSERT_EQ(find(array, find_pivot(array), 5), 5);
  ASSERT_EQ(find(array, find_pivot(array), 7), 10);
  ASSERT_EQ(find(array, find_pivot(array), 9), 12);

  array = {3,1};
  ASSERT_EQ(find(array, find_pivot(array), 1), 1);
  ASSERT_EQ(find(array, find_pivot(array), 3), 0);

  array = {1,3,5};
  ASSERT_EQ(find(array, find_pivot(array), 1), 0);
  ASSERT_EQ(find(array, find_pivot(array), 3), 1);
  ASSERT_EQ(find(array, find_pivot(array), 5), 2);

  array = {5,1,3};
  ASSERT_EQ(find(array, find_pivot(array), 1), 1);
  ASSERT_EQ(find(array, find_pivot(array), 3), 2);
  ASSERT_EQ(find(array, find_pivot(array), 5), 0);

  array = {3,5,1};
  ASSERT_EQ(find(array, find_pivot(array), 1), 2);
  ASSERT_EQ(find(array, find_pivot(array), 3), 0);
  ASSERT_EQ(find(array, find_pivot(array), 5), 1);

  array = {1,3,5,7};
  ASSERT_EQ(find(array, find_pivot(array), 1), 0);
  ASSERT_EQ(find(array, find_pivot(array), 3), 1);
  ASSERT_EQ(find(array, find_pivot(array), 5), 2);
  ASSERT_EQ(find(array, find_pivot(array), 7), 3);

  array = {7,1,3,5};
  ASSERT_EQ(find(array, find_pivot(array), 1), 1);
  ASSERT_EQ(find(array, find_pivot(array), 3), 2);
  ASSERT_EQ(find(array, find_pivot(array), 5), 3);
  ASSERT_EQ(find(array, find_pivot(array), 7), 0);

  array = {5,7,1,3};
  ASSERT_EQ(find(array, find_pivot(array), 1), 2);
  ASSERT_EQ(find(array, find_pivot(array), 3), 3);
  ASSERT_EQ(find(array, find_pivot(array), 5), 0);
  ASSERT_EQ(find(array, find_pivot(array), 7), 1);

  array = {3,5,7,1};
  ASSERT_EQ(find(array, find_pivot(array), 1), 3);
  ASSERT_EQ(find(array, find_pivot(array), 3), 0);
  ASSERT_EQ(find(array, find_pivot(array), 5), 1);
  ASSERT_EQ(find(array, find_pivot(array), 7), 2);
}
}

#include "fixed_point.cpp"
void TEST_FixedPoint() {
  std::vector<int> array;
  array = {0};
  ASSERT_EQ(fixed_point(array), 0);
  array = {1,1};
  ASSERT_EQ(fixed_point(array), 1);
  array = {1,2,3,3,4};
  ASSERT_EQ(fixed_point(array), 3);
  array = {4,5,6,7,8,9,10,10,10,10,11,11,12,13,14,15};
  ASSERT_EQ(fixed_point(array), 11);
}

#include "find_duplicates.cpp"
void TEST_FindDuplicates() {
  std::vector<int> array;
  array = {0};
  ASSERT_EQ(find_duplicates(array), 0);
  array = {1,1};
  ASSERT_EQ(find_duplicates(array), 1);
  array = {1,2,3,3,4};
  ASSERT_EQ(find_duplicates(array), 2);
  array = {4,5,6,7,8,9,10,10,10,10,11,11,12,13,14,15};
  ASSERT_EQ(find_duplicates(array), 7);
}

const size_t m = 5;
const size_t n = 5;
#include "matrix.h"
#define TEST_MATRIX_SEARCH(MATRIX, VAL) \
  result = find(M, VAL); \
  ASSERT_EQ(M[result.first][result.second], VAL)

namespace linearit {
#include "linear_matrix_search.cpp"
void TEST_MatrixSearch() {
  coordinate result;
  matrix M;
  M = {{1}};
  TEST_MATRIX_SEARCH(M, 1);
  M = {{1,2}};
  TEST_MATRIX_SEARCH(M, 1);
  TEST_MATRIX_SEARCH(M, 2);
  M = {{1},{2}};
  TEST_MATRIX_SEARCH(M, 1);
  TEST_MATRIX_SEARCH(M, 2);
  M = {{1,3}, {2,4}};
  TEST_MATRIX_SEARCH(M, 1);
  TEST_MATRIX_SEARCH(M, 3);
  TEST_MATRIX_SEARCH(M, 2);
  TEST_MATRIX_SEARCH(M, 4);
  M = {{1,3,5}, {2,4,6}};
  TEST_MATRIX_SEARCH(M, 1);
  TEST_MATRIX_SEARCH(M, 3);
  TEST_MATRIX_SEARCH(M, 5);
  TEST_MATRIX_SEARCH(M, 2);
  TEST_MATRIX_SEARCH(M, 4);
  TEST_MATRIX_SEARCH(M, 6);
}
}

namespace logit {
#include "matrix_search.cpp"
void TEST_MatrixSearch() {
  coordinate result;
  matrix M;
  M = {{1}};
  TEST_MATRIX_SEARCH(M, 1);
  M = {{1,2}};
  TEST_MATRIX_SEARCH(M, 1);
  TEST_MATRIX_SEARCH(M, 2);
  M = {{1},{2}};
  TEST_MATRIX_SEARCH(M, 1);
  TEST_MATRIX_SEARCH(M, 2);
  M = {{1,3}, {2,4}};
  TEST_MATRIX_SEARCH(M, 1);
  TEST_MATRIX_SEARCH(M, 3);
  TEST_MATRIX_SEARCH(M, 2);
  TEST_MATRIX_SEARCH(M, 4);
  M = {{1,3,5}, {2,4,6}};
  TEST_MATRIX_SEARCH(M, 1);
  TEST_MATRIX_SEARCH(M, 3);
  TEST_MATRIX_SEARCH(M, 5);
  TEST_MATRIX_SEARCH(M, 2);
  TEST_MATRIX_SEARCH(M, 4);
  TEST_MATRIX_SEARCH(M, 6);
}
}

int main(int argc, char** argv) {
  rng.seed();
  CALL(bs::TEST_BinarySearch);
  CALL(lm::TEST_BinarySearch);
  CALL(rt::TEST_BinarySearch);
  CALL(pivot::TEST_Pivot);
  CALL(pivot::TEST_BinarySearch);
  CALL(TEST_FixedPoint);
  CALL(TEST_FindDuplicates);
  CALL(linearit::TEST_MatrixSearch);
  CALL(logit::TEST_MatrixSearch);
  return 0;
}
