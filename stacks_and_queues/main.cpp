#include <algorithm>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <vector>

#include "../test/testing.h"


#include "queue_from_list.cpp"
void TEST_Queue() {
  queue q;
  q.push(0);
  q.push(1);
  q.push(2);
  q.push(3);
  ASSERT_EQ(q.front(), 0);
  q.pop();
  ASSERT_EQ(q.front(), 1);
  q.pop();
  ASSERT_EQ(q.front(), 2);
  q.pop();
  ASSERT_EQ(q.front(), 3);
  q.pop();
}


#include "stack_from_list.cpp"
void TEST_Stack() {
  stack s;
  s.push(0);
  s.push(1);
  s.push(2);
  s.push(3);
  ASSERT_EQ(s.top(), 3);
  s.pop();
  ASSERT_EQ(s.top(), 2);
  s.pop();
  ASSERT_EQ(s.top(), 1);
  s.pop();
  ASSERT_EQ(s.top(), 0);
  s.pop();
}

namespace equivalence {
#include "queue_from_stack.cpp"
void TEST_EquivalenceQueue() {
  queue q;
  q.push(0);
  q.push(1);
  q.push(2);
  q.push(3);
  ASSERT_EQ(q.front(), 0);
  q.pop();
  ASSERT_EQ(q.front(), 1);
  q.pop();
  ASSERT_EQ(q.front(), 2);
  q.pop();
  ASSERT_EQ(q.front(), 3);
  q.pop();
}


#include "stack_from_queue.cpp"
void TEST_EquivalenceStack() {
  stack s;
  s.push(0);
  s.push(1);
  s.push(2);
  s.push(3);
  ASSERT_EQ(s.top(), 3);
  s.pop();
  ASSERT_EQ(s.top(), 2);
  s.pop();
  ASSERT_EQ(s.top(), 1);
  s.pop();
  ASSERT_EQ(s.top(), 0);
  s.pop();
}
} // namespace equivalence

#include "../trees/tree_node.h"
#include "../trees/insert.cpp"
#include "level_order_traversal.cpp"
void TEST_LevelOrder() {
  node* root = nullptr;
  root = insert(root, 0);
  root = insert(root, 4);
  root = insert(root, -4);
  root = insert(root, -8);
  root = insert(root, -2);
  root = insert(root, -1);
  root = insert(root, -3);
  root = insert(root, 8);
  root = insert(root, 2);
  root = insert(root, 1);
  root = insert(root, 3);

  std::stringstream str(std::stringstream::in | std::stringstream::out);
  level_traversal(root, str);
  ASSERT_EQ(str.str(), "0\n-44\n-8-228\n-3-113");
}

#include "histogram.h"
#include "largest_rectangle_in_histogram.cpp"
void TEST_Histogram() {
  Histogram hist1 = {{1,10}};
  ASSERT_EQ(largest_area(hist1), 10);
  Histogram hist2 = {{1,5}, {2,10}};
  ASSERT_EQ(largest_area(hist2), 10)
  Histogram hist3 = {{1,10}, {2,5}, {3,9}};
  ASSERT_EQ(largest_area(hist3), 15);
  Histogram hist4 = {{1,5}, {2,3}, {3,1}};
  ASSERT_EQ(largest_area(hist4), 6)
  Histogram hist5 = {{1,10}, {2,0}, {3,15}, {4,20}, {5,5}, {6,1}, {7,1}, {8,10}};
  ASSERT_EQ(largest_area(hist5), 30)
}

int main(int argc, char** argv) {
  CALL(TEST_Queue);
  CALL(TEST_Stack);
  CALL(equivalence::TEST_EquivalenceQueue);
  CALL(equivalence::TEST_EquivalenceStack);
  CALL(TEST_LevelOrder);
  CALL(TEST_Histogram);
  return 0;
}
