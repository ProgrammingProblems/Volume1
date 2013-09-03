#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#include "../test/testing.h"

#include "array_data_typedefs.h"
#include "array_data_pivot_typedefs.h"

#define MEDIAN_ARGS(x) \
  &x, (x.size()-1)/2

  #define SELECTION_ARGS(x, y) \
    &x, y

size_t find_index(Array& array, int val) {
  for (size_t index = 0; index < array.size(); ++index) {
    if (val == array[index]) return index;
  }
  return array.size();
}

void dumpArray(const Array& array) {
  std::cout << std::endl << "array: ";
  for(auto val : array) std::cout << val << " ";
  std::cout << std::endl;
}

#include "selection.cpp"
void TEST_Sort() {
  Array sorted5 = {1,2,3,4,5};
  ASSERT_EQ(select(MEDIAN_ARGS(sorted5)), sorted5[2]);

  Array backwards5 = {5,4,3,2,1};
  ASSERT_EQ(select(MEDIAN_ARGS(backwards5)), sorted5[2]);

  Array mixed5 = {5,3,2,1,4};
  ASSERT_EQ(select(MEDIAN_ARGS(mixed5)), sorted5[2]);

  Array sorted6 = {1,2,3,4,5,6};
  ASSERT_EQ(select(MEDIAN_ARGS(sorted6)), sorted6[2]);

  Array backwards6 = {6,5,4,3,2,1};
  ASSERT_EQ(select(MEDIAN_ARGS(backwards6)), sorted6[2]);

  Array mixed6 = {3,1,4,5,6,2};
  ASSERT_EQ(select(MEDIAN_ARGS(mixed6)), sorted6[2]);

  Array mixed20_1 = {12, 20, 14, 4, 15, 19, 2, 5, 13, 10, 6, 3, 9, 17, 7, 8, 1, 11, 18, 16};
  ASSERT_EQ(select(MEDIAN_ARGS(mixed20_1)), 10);

  Array mixed20_2 = {18, 7, 2, 5, 20, 10, 19, 17, 6, 12, 16, 8, 1, 3, 14, 9, 13, 11, 4, 15};
  ASSERT_EQ(select(MEDIAN_ARGS(mixed20_2)), 10);

  Array mixed20_3 = {6, 8, 12, 17, 5, 2, 11, 20, 19, 16, 1, 7, 15, 10, 4, 14, 13, 18, 9, 3};
  ASSERT_EQ(select(MEDIAN_ARGS(mixed20_3)), 10);

  mixed20_1 = {12, 20, 14, 4, 15, 19, 2, 5, 13, 10, 6, 3, 9, 17, 7, 8, 1, 11, 18, 16};
  ASSERT_EQ(select(SELECTION_ARGS(mixed20_1, 1)), 2);

  mixed20_2 = {18, 7, 2, 5, 20, 10, 19, 17, 6, 12, 16, 8, 1, 3, 14, 9, 13, 11, 4, 15};
  ASSERT_EQ(select(SELECTION_ARGS(mixed20_2, 3)), 4);

  mixed20_3 = {6, 8, 12, 17, 5, 2, 11, 20, 19, 16, 1, 7, 15, 10, 4, 14, 13, 18, 9, 3};
  ASSERT_EQ(select(SELECTION_ARGS(mixed20_3, 19)), 20);
}

#include "median.cpp"
void TEST_Median() {
  Array mixed20_1 = {12, 20, 14, 4, 15, 19, 2, 5, 13, 10, 6, 3, 9, 17, 7, 8, 1, 11, 18, 16};
  ASSERT_EQ(select(MEDIAN_ARGS(mixed20_1)), median(&mixed20_1));

  Array mixed20_2 = {18, 7, 2, 5, 20, 10, 19, 17, 6, 12, 16, 8, 1, 3, 14, 9, 13, 11, 4, 15};
  ASSERT_EQ(select(MEDIAN_ARGS(mixed20_2)), median(&mixed20_2));

  Array mixed20_3 = {6, 8, 12, 17, 5, 2, 11, 20, 19, 16, 1, 7, 15, 10, 4, 14, 13, 18, 9, 3};
  ASSERT_EQ(select(MEDIAN_ARGS(mixed20_3)), median(&mixed20_3));
}


#include "pivot.cpp"
void TEST_Pivot() {
  Array mixed20;
  size_t result;
  for (size_t i = 1; i <= 20; ++i) {
    mixed20 = {12, 20, 14, 4, 15, 19, 2, 5, 13, 10, 6, 3, 9, 17, 7, 8, 1, 11, 18, 16};
    result = partition(&mixed20, find_index(mixed20, i), 0, mixed20.size());
    ASSERT_EQ(result, i-1);
  }

  mixed20 = {12, 20, 14, 4, 15, 19, 2, 5, 13, 10, 6, 3, 9, 17, 7, 8, 1, 11, 18, 16};
  result = partition(&mixed20,  find_index(mixed20, 1), 0, 10);
  ASSERT_EQ(result, 0);

  mixed20 = {12, 20, 14, 4, 15, 19, 2, 5, 13, 10, 6, 3, 9, 17, 7, 8, 1, 11, 18, 16};
  result = partition(&mixed20,  find_index(mixed20, 1), 10, 10);
  ASSERT_EQ(result, 10);

  mixed20 = {12, 20, 14, 4, 15, 19, 2, 5, 13, 10, 6, 3, 9, 17, 7, 8, 1, 11, 18, 16};
  result = partition(&mixed20,  find_index(mixed20, 20), 10, 10);
  ASSERT_EQ(result, 19);
}

namespace random_selection {
size_t pivot_index (const std::vector<int>&, size_t offset, size_t) {
  return offset;
}
#include "selection_with_pivot.cpp"
void TEST_SelectionWithPivot() {
  Array mixed20;
  int result;
  for (size_t i = 0; i < 20; ++i) {
    mixed20 = {12, 20, 14, 4, 15, 19, 2, 5, 13, 10, 6, 3, 9, 17, 7, 8, 1, 11, 18, 16};
    result = select(&mixed20, i);
    ASSERT_EQ(result, i+1);
  }
}
}

#include "median_of_3.cpp"
void TEST_MedianOf3() {
  Array one = {1};
  ASSERT_EQ(median_of_3(one, 0, one.size()), 1);

  Array two = {1,2};
  ASSERT_EQ(median_of_3(two, 0, two.size()), 1);
  two = {2,1};
  ASSERT_EQ(median_of_3(two, 0, two.size()), 1);

  Array three = {1,2,3};
  ASSERT_EQ(median_of_3(three, 0, three.size()), 2);
  three = {1,3,2};
  ASSERT_EQ(median_of_3(three, 0, three.size()), 2);
  three = {2,3,1};
  ASSERT_EQ(median_of_3(three, 0, three.size()), 2);
  three = {2,1,3};
  ASSERT_EQ(median_of_3(three, 0, three.size()), 2);
  three = {3,2,1};
  ASSERT_EQ(median_of_3(three, 0, three.size()), 2);
  three = {3,1,2};
  ASSERT_EQ(median_of_3(three, 0, three.size()), 2);

  Array five = {0,1,2,3,4};
  ASSERT_EQ(median_of_3(five, 1, 3), 2);
  five = {0, 1,3,2, 4};
  ASSERT_EQ(median_of_3(five, 1, 3), 2);
  five = {0, 2,3,1, 4};
  ASSERT_EQ(median_of_3(five, 1, 3), 2);
  five = {0, 2,1,3, 4};
  ASSERT_EQ(median_of_3(five, 1, 3), 2);
  five = {0, 3,2,1, 4};
  ASSERT_EQ(median_of_3(five, 1, 3), 2);
  five = {0, 3,1,2, 4};
  ASSERT_EQ(median_of_3(five, 1, 3), 2);
}

#include "median_of_medians.cpp"
void TEST_MedianOfMedians() {
  Array a = {1};
  ASSERT_EQ(pivot_index(a, 0, a.size()), 0);
  a = {1,2};
  ASSERT_EQ(pivot_index(a, 0, a.size()), 0);
  a = {1,3,2};
  ASSERT_EQ(pivot_index(a, 0, a.size()), 2);
  a = {1,3,2,4};
  ASSERT_EQ(pivot_index(a, 0, a.size()), 2);
  a = {1,3,2,4,5};
  ASSERT_EQ(pivot_index(a, 0, a.size()), 2);
  a = {1,3,2,4,5,6};
  ASSERT_EQ(pivot_index(a, 0, a.size()), 2);
  a = {1,3,2,4,5,6,0};
  ASSERT_EQ(pivot_index(a, 0, a.size()), 2);
}

namespace median_of_medians_selection {
#include "pivot_index.cpp"
#include "selection_with_pivot.cpp"
#include "median_of_medians.cpp"
void TEST_SelectionWithMedianPivot() {
  Array mixed20;
  int result;
  for (size_t i = 0; i < 20; ++i) {
    mixed20 = {12, 20, 14, 4, 15, 19, 2, 5, 13, 10, 6, 3, 9, 17, 7, 8, 1, 11, 18, 16};
    result = select(&mixed20, i);
    ASSERT_EQ(result, i+1);
  }
}
}

namespace median_of_many {
#include "array_data_init.cpp"
#include "array_data_update.cpp"
#include "array_data_partition.cpp"
#include "median_of_many.cpp"

void  TEST_MedianOfMany() {
  Array mixed20;
  int result;
  Arrays arrays;

  arrays.clear();
  mixed20 = {12, 20, 14, 4, 15, 19, 2, 5, 13, 10, 6, 3, 9, 17, 7, 8, 1, 11, 18, 16};
  arrays.push_back(mixed20);
  result = median(&arrays);
  ASSERT_EQ(result, 10);

  arrays.clear();
  arrays.push_back({1});
  arrays.push_back({2});
  result = median(&arrays);
  ASSERT_EQ(result, 1);

  arrays.clear();
  arrays.push_back({2});
  arrays.push_back({1});
  result = median(&arrays);
  ASSERT_EQ(result, 1);

  arrays.clear();
  arrays.push_back({1,2});
  arrays.push_back({3});
  result = median(&arrays);
  ASSERT_EQ(result, 2);

  arrays.clear();
  arrays.push_back({1});
  arrays.push_back({2,3});
  result = median(&arrays);
  ASSERT_EQ(result, 2);

  arrays.clear();
  arrays.push_back({1,2});
  arrays.push_back({3,4});
  result = median(&arrays);
  ASSERT_EQ(result, 2);

  arrays.clear();
  arrays.push_back({1,3});
  arrays.push_back({2,4});
  result = median(&arrays);
  ASSERT_EQ(result, 2);

  arrays.clear();
  arrays.push_back({2,4});
  arrays.push_back({1,3});
  result = median(&arrays);
  ASSERT_EQ(result, 2);

  arrays.clear();
  arrays.push_back({3,4});
  arrays.push_back({1,2});
  result = median(&arrays);
  ASSERT_EQ(result, 2);

  arrays.clear();
  arrays.push_back({1,2,3});
  arrays.push_back({4,5});
  result = median(&arrays);
  ASSERT_EQ(result, 3);

  arrays.clear();
  arrays.push_back({1,2});
  arrays.push_back({3,4,5});
  result = median(&arrays);
  ASSERT_EQ(result, 3);


  arrays.clear();
  arrays.push_back({2,5,6});
  arrays.push_back({1,3,4});
  result = median(&arrays);
  ASSERT_EQ(result, 3);

  arrays.clear();
  arrays.push_back({1,3,4});
  arrays.push_back({2,5,6});
  result = median(&arrays);
  ASSERT_EQ(result, 3);

  arrays.clear();
  arrays.push_back({1,3,3,3,3,4});
  arrays.push_back({2,5,3,3,3,3,3,6});
  arrays.push_back({2,5,3,3,3,3,3,6});
  result = median(&arrays);
  ASSERT_EQ(result, 3);

  arrays.clear();
  arrays.push_back({1,3,3,3,3,4});
  arrays.push_back({2,5,3,3,3,3,3,6});
  result = median(&arrays);
  ASSERT_EQ(result, 3);
}
}

int main(int argc, char** argv) {

  CALL(TEST_Sort);
  CALL(TEST_Median);
  CALL(TEST_Pivot);
  using namespace random_selection;
  CALL(TEST_SelectionWithPivot);
  CALL(TEST_MedianOf3);
  CALL(TEST_MedianOfMedians);

  using namespace median_of_medians_selection;
  CALL(TEST_SelectionWithMedianPivot);

  using namespace median_of_many;
  CALL(TEST_MedianOfMany);
  return 0;
}
