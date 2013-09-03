#include <algorithm>
#include <iostream>
#include <functional>
#include <limits>
#include <list>
#include <queue>
#include <set>
#include <string>
#include <stack>
#include <vector>

#include "../test/testing.h"

#include "node.h"
node* ctor(int value) {
  node* retval = new node();
  retval->value = value;
  return retval;
}

node* root = nullptr;
node* lhs = nullptr;
node* rhs = nullptr;
node* lhsc = nullptr;
node* lhsc2 = nullptr;
node* lhsc3 = nullptr;
node* rhsc = nullptr;
node* rhscc = nullptr;

void init() {
  root = ctor(0);
  lhs = ctor(1);
  rhs = ctor(2);
  lhsc = ctor(3);
  lhsc2 = ctor(4);
  lhsc3 = ctor(5);
  rhsc = ctor(6);
  rhscc = ctor(7);
}

void clear() {
  root->neighbors.clear();
  lhs->neighbors.clear();
  rhs->neighbors.clear();
  lhsc->neighbors.clear();
  lhsc2->neighbors.clear();
  lhsc3->neighbors.clear();
  rhsc->neighbors.clear();
  rhscc->neighbors.clear();
}

node* small_tree() {
  clear();
  root->neighbors.push_back(lhs);
  root->neighbors.push_back(rhs);
  lhs->neighbors.push_back(lhsc);
  return root;
}

node* triangle() {
  clear();
  root->neighbors.push_back(lhs);
  root->neighbors.push_back(rhs);
  lhs->neighbors.push_back(root);
  lhs->neighbors.push_back(rhs);
  rhs->neighbors.push_back(root);
  rhs->neighbors.push_back(lhs);
  return root;
}

node*  large_tree() {
  clear();
  root->neighbors.push_back(lhs);
  root->neighbors.push_back(rhs);
  lhs->neighbors.push_back(lhsc);
  lhs->neighbors.push_back(lhsc2);
  lhs->neighbors.push_back(lhsc3);
  rhs->neighbors.push_back(rhsc);
  rhs->neighbors.push_back(rhscc);
  return root;
}

node* dag() {
  clear();
  root->neighbors.push_back(lhs);
  root->neighbors.push_back(rhs);
  lhs->neighbors.push_back(lhsc);
  lhs->neighbors.push_back(lhsc2);
  lhs->neighbors.push_back(lhsc3);
  rhs->neighbors.push_back(lhsc3);
  rhs->neighbors.push_back(rhsc);
  rhs->neighbors.push_back(rhscc);
  lhsc->neighbors.push_back(rhscc);
  lhsc2->neighbors.push_back(rhscc);
  lhsc2->neighbors.push_back(lhsc3);
  return root;
}

node* many_cycles() {
  clear();
  root->neighbors.push_back(lhs);
  root->neighbors.push_back(rhs);
  lhs->neighbors.push_back(root);
  lhs->neighbors.push_back(lhsc);
  lhs->neighbors.push_back(lhsc2);
  lhs->neighbors.push_back(lhsc3);
  rhs->neighbors.push_back(root);
  rhs->neighbors.push_back(rhsc);
  rhs->neighbors.push_back(rhscc);
  rhsc->neighbors.push_back(rhs);
  rhsc->neighbors.push_back(rhscc);
  lhsc->neighbors.push_back(lhs);
  lhsc->neighbors.push_back(rhscc);
  rhscc->neighbors.push_back(rhs);
  rhscc->neighbors.push_back(rhsc);
  rhscc->neighbors.push_back(lhsc);
  lhsc2->neighbors.push_back(rhscc);
  lhsc2->neighbors.push_back(lhsc3);
  lhsc3->neighbors.push_back(lhsc2);
  return root;
}

void TEST_Construction() {
  node* st = small_tree();
  node* tri = triangle();
  node* lt = large_tree();
  node* mc = many_cycles();
}

#include "visit.h"
#include "bfs.cpp"
void TEST_bfs() {
  std::vector<int> visited;
  auto visitor = [&] (node* n) {
    visited.push_back(n->value);
  };
  node* st = small_tree();
  bfs(st, visitor);
  ASSERT_EQ(visited.size(), 4);
  ASSERT_EQ(visited[0], 0);
  ASSERT_EQ(visited[1], 1);
  ASSERT_EQ(visited[2], 2);
  ASSERT_EQ(visited[3], 3);
}

#include <map>
#include "shortest_paths.cpp"
void TEST_shortest_path() {
  node* st = small_tree();
  std::map<node*, size_t> distances;
  find_distances(st, &distances);
  ASSERT_EQ(distances[root], 0);
  ASSERT_EQ(distances[lhs], 1);
  ASSERT_EQ(distances[rhs], 1);
  ASSERT_EQ(distances[lhsc], 2);
}

#include "geneological_data.h"
#include "ancestry.cpp"
#include "related.cpp"
void TEST_ancestry() {
  GeneologicalData data;
  ASSERT_EQ(related(data, 0, 1), false);

  data = {{0, {2,4}}, {1, {3,5}}, {2, {4, 6}}, {7, {6}}};
  ASSERT_EQ(related(data, 0, 1), false);
  ASSERT_EQ(related(data, 0, 2), true);
  ASSERT_EQ(related(data, 0, 7), true);
}

#include "dfs.cpp"
#include "visit.h"
void TEST_dfs() {
  std::vector<int> visited;
  auto visitor = [&] (node* n) {
    visited.push_back(n->value);
  };
  node* st = small_tree();
  dfs(st, visitor);
  ASSERT_EQ(visited.size(), 4);
  ASSERT_EQ(visited[0], 3);
  ASSERT_EQ(visited[1], 1);
  ASSERT_EQ(visited[2], 2);
  ASSERT_EQ(visited[3], 0);

  st = dag();
  visited.clear();
  dfs(st, visitor);
  ASSERT_EQ(visited.size(), 8);
  ASSERT_EQ(visited[0], 7);
  ASSERT_EQ(visited[1], 3);
  ASSERT_EQ(visited[2], 5);
  ASSERT_EQ(visited[3], 4);
  ASSERT_EQ(visited[4], 1);
  ASSERT_EQ(visited[5], 6);
  ASSERT_EQ(visited[6], 2);
  ASSERT_EQ(visited[7], 0);

  st = many_cycles();
  visited.clear();
  dfs(st, visitor);
  ASSERT_EQ(visited.size(), 8);
  ASSERT_EQ(visited[0], 6);
  ASSERT_EQ(visited[1], 2);
  ASSERT_EQ(visited[2], 7);
  ASSERT_EQ(visited[3], 3);
  ASSERT_EQ(visited[4], 5);
  ASSERT_EQ(visited[5], 4);
  ASSERT_EQ(visited[6], 1);
  ASSERT_EQ(visited[7], 0);
}

#include "topological_sort.cpp"
void TEST_topological_sort() {
  std::list<node*> visited;
  node* st = small_tree();
  topological_sort(st, &visited);
  auto itr = visited.begin();
  ASSERT_EQ(visited.size(), 4);
  ASSERT_EQ(*itr++, root);
  ASSERT_EQ(*itr++, rhs);
  ASSERT_EQ(*itr++, lhs);
  ASSERT_EQ(*itr++, lhsc);

  st = dag();
  visited.clear();
  topological_sort(st, &visited);
  itr = visited.begin();
  ASSERT_EQ(visited.size(), 8);
  ASSERT_EQ(*itr++, root);
  ASSERT_EQ(*itr++, rhs);
  ASSERT_EQ(*itr++, rhsc);
  ASSERT_EQ(*itr++, lhs);
  ASSERT_EQ(*itr++, lhsc2);
  ASSERT_EQ(*itr++, lhsc3);
  ASSERT_EQ(*itr++, lhsc);
  ASSERT_EQ(*itr++, rhscc);
}

#include "find_cycles.cpp"
void TEST_detect_cycle() {
  ASSERT(!detect_cycle(small_tree()));
  ASSERT(!detect_cycle(dag()));
  ASSERT(detect_cycle(triangle()));
  ASSERT(detect_cycle(many_cycles()));
}

bool isword(const std::string& str) {
  return (str.length() >= 2 && str[1] == 'b');
}

#include "boggle_matrix.cpp"
GameBoard board;
#include "boggle.cpp"
#include "boggle_full.cpp"
void TEST_boggle() {
  std::set<std::string> words;
  board = {{'a', 'b'}, {'b', 'c'}};
  boggle(board, &words);
  ASSERT_EQ(words.size(), 15);
}

#include "distance_heuristic.cpp"
bool passable(const Position& pos) {
  return board[pos.first][pos.second] == '.';
}
#include "maze.cpp"
void TEST_maze() {
  std::list<Position> route;
  route.clear();
  board = {{'.', '.'}, {'.', '.'}};
  maze(board, {0,0}, {1,1}, &route);
  ASSERT(!route.empty());
  ASSERT_EQ(route.size(), 3);

  route.clear();
  board = {{'.', '*'}, {'*', '.'}};
  maze(board, {0,0}, {1,1}, &route);
  ASSERT(route.empty());
}

int main(int argc, char** argv) {
  init();
  CALL(TEST_Construction);
  CALL(TEST_bfs);
  CALL(TEST_shortest_path);
  CALL(TEST_ancestry);
  CALL(TEST_dfs);
  CALL(TEST_topological_sort);
  CALL(TEST_detect_cycle);
  CALL(TEST_boggle);
  CALL(TEST_maze);
  return 0;
}
