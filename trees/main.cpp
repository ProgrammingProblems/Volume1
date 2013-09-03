#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#include "../test/testing.h"

#include "tree_node.h"
void TEST_Construction() {
  node node0(1);
  ASSERT(node0.value == 1);
  ASSERT(node0.left == nullptr);
  ASSERT(node0.right == nullptr);
}


#include "insert.cpp"
void TEST_Insertion() {
  node* root = nullptr;
  root = insert(root, 0);
  ASSERT_EQ(root->value, 0);
  ASSERT(root->left == nullptr);
  ASSERT(root->right == nullptr);

  root = insert(root, -2);
  ASSERT(root->value == 0);
  ASSERT(root->left != nullptr);
  ASSERT_EQ(root->left->value, -2);
  ASSERT(root->right == nullptr);

  root = insert(root, -1);
  ASSERT(root->value == 0);
  ASSERT(root->left != nullptr);
  ASSERT_EQ(root->left->value, -2);
  ASSERT(root->left->right != nullptr);
  ASSERT_EQ(root->left->right->value, -1);
  ASSERT(root->right == nullptr);

  root = insert(root, 2);
  ASSERT(root->value == 0);
  ASSERT(root->left != nullptr);
  ASSERT_EQ(root->left->value, -2);
  ASSERT(root->left->right != nullptr);
  ASSERT_EQ(root->left->right->value, -1);
  ASSERT(root->right != nullptr);
  ASSERT_EQ(root->right->value, 2);
}

#include "find.cpp"
void TEST_Find() {
  node* root = nullptr;
  root = insert(root, 0);
  ASSERT_EQ(find(root, 0)->value, 0);
  root = insert(root, 2);
  ASSERT_EQ(find(root, 0)->value, 0);
  ASSERT_EQ(find(root, 2)->value, 2);
  root = insert(root, -2);
  ASSERT_EQ(find(root, -2)->value, -2);
  ASSERT_EQ(find(root, 2)->value, 2);
  ASSERT_EQ(find(root, 0)->value, 0);
}

bool verify_bst(node* root) {
  if (!root) {
    return true;
  }
  if (root->left && root->left->value >= root->value) {
    DBG_OUT("left tree wrong", root->left->value << root->value);
    return false;
  }
  if (root->right && root->right->value < root->value) {
        DBG_OUT("right tree wrong", root->right->value << root->value);
    return false;
  }
  if (!verify_bst(root->left)) {
    return false;
  }
  return verify_bst(root->right);
}

#include "find_parent.cpp"
#include "find_successor.cpp"
#include "remove.cpp"
void TEST_Remove() {
  node* root = nullptr;
  root = insert(root, 0);
  ASSERT_EQ(find_parent(root, root), nullptr);
  ASSERT_EQ(find_successor(root, root), nullptr);
  root = insert(root, 4);
  ASSERT_EQ(find_parent(root, root), nullptr);
  ASSERT_EQ(find_parent(root, root->right), root);
  ASSERT_EQ(find_successor(root, root), root->right);
  ASSERT_EQ(find_successor(root, root->right), nullptr);
  root = insert(root, -4);
  ASSERT_EQ(find_parent(root, root), nullptr);
  ASSERT_EQ(find_parent(root, root->left), root);
  ASSERT_EQ(find_parent(root, root->right), root);
  ASSERT_EQ(find_successor(root, root->left), root);
  ASSERT_EQ(find_successor(root, root), root->right);
  ASSERT_EQ(find_successor(root, root->right), nullptr);
  root = insert(root, -8);
  root = insert(root, -2);
  root = insert(root, -1);
  root = insert(root, -3);
  root = insert(root, 8);
  root = insert(root, 2);
  root = insert(root, 1);
  root = insert(root, 3);
  ASSERT_EQ(find_parent(root, root), nullptr);
  ASSERT_EQ(find_parent(root, root->left), root);
  ASSERT_EQ(find_parent(root, root->right), root);
  ASSERT_EQ(find_successor(root, root->left), root->left->right->left);
  ASSERT_EQ(find_successor(root, root), root->right->left->left);
  ASSERT_EQ(find_successor(root, root->right), root->right->right);

  ASSERT(verify_bst(root));
  root = remove(root, find(root, -4));
  ASSERT(verify_bst(root));
  root = remove(root, find(root, 2));
  ASSERT(verify_bst(root));
  root = remove(root, find(root, 0));
  ASSERT(verify_bst(root));
  root = remove(root, find(root, 8));
  ASSERT(verify_bst(root));
  ASSERT_EQ(find(root, -8)->value, -8);
  ASSERT_EQ(find(root, -4), nullptr);
  ASSERT_EQ(find(root, -3)->value, -3);
  ASSERT_EQ(find(root, -2)->value, -2);
  ASSERT_EQ(find(root, -1)->value, -1);
  ASSERT_EQ(find(root, 0), nullptr);
  ASSERT_EQ(find(root, 1)->value, 1);
  ASSERT_EQ(find(root, 2), nullptr);
  ASSERT_EQ(find(root, 3)->value, 3);
  ASSERT_EQ(find(root, 4)->value, 4);
  ASSERT_EQ(find(root, 8), nullptr);
}

#include "size.cpp"
namespace itr {
#include "size_iterative.cpp"
}
void TEST_Size() {
  node* root = nullptr;
  ASSERT_EQ(size(root), 0);
  ASSERT_EQ(size(root), itr::size(root));
  root = insert(root, 0);
  ASSERT_EQ(size(root), 1);
  ASSERT_EQ(size(root), itr::size(root));
  root = insert(root, 4);
  ASSERT_EQ(size(root), 2);
  ASSERT_EQ(size(root), itr::size(root));
  root = insert(root, -4);
  ASSERT_EQ(size(root), 3);
  ASSERT_EQ(size(root), itr::size(root));
  root = insert(root, -8);
  ASSERT_EQ(size(root), 4);
  ASSERT_EQ(size(root), itr::size(root));
  root = insert(root, -2);
  ASSERT_EQ(size(root), 5);
  ASSERT_EQ(size(root), itr::size(root));
  root = insert(root, -1);
  ASSERT_EQ(size(root), 6);
  ASSERT_EQ(size(root), itr::size(root));
  root = insert(root, -3);
  ASSERT_EQ(size(root), 7);
  ASSERT_EQ(size(root), itr::size(root));
  root = insert(root, 8);
  ASSERT_EQ(size(root), 8);
  ASSERT_EQ(size(root), itr::size(root));
  root = insert(root, 2);
  ASSERT_EQ(size(root), 9);
  ASSERT_EQ(size(root), itr::size(root));
  root = insert(root, 1);
  ASSERT_EQ(size(root), 10);
  ASSERT_EQ(size(root), itr::size(root));
  root = insert(root, 3);
  ASSERT_EQ(size(root), 11);
  ASSERT_EQ(size(root), itr::size(root));
}

#include "depth.cpp"
namespace itr {
#include "depth_iterative.cpp"
}
void TEST_Depth() {
  node* root = nullptr;
  ASSERT_EQ(depth(root), 0);
  ASSERT_EQ(depth(root), itr::depth(root));
  root = insert(root, 0);
  ASSERT_EQ(depth(root), 1);
  ASSERT_EQ(depth(root), itr::depth(root));
  root = insert(root, 4);
  ASSERT_EQ(depth(root), 2);
  ASSERT_EQ(depth(root), itr::depth(root));
  root = insert(root, -4);
  ASSERT_EQ(depth(root), 2);
  ASSERT_EQ(depth(root), itr::depth(root));
  root = insert(root, -8);
  ASSERT_EQ(depth(root), 3);
  ASSERT_EQ(depth(root), itr::depth(root));
  root = insert(root, -2);
  ASSERT_EQ(depth(root), 3);
  ASSERT_EQ(depth(root), itr::depth(root));
  root = insert(root, -1);
  ASSERT_EQ(depth(root), 4);
  ASSERT_EQ(depth(root), itr::depth(root));
  root = insert(root, -3);
  ASSERT_EQ(depth(root), 4);
  ASSERT_EQ(depth(root), itr::depth(root));
  root = insert(root, 8);
  ASSERT_EQ(depth(root), 4);
  ASSERT_EQ(depth(root), itr::depth(root));
  root = insert(root, 2);
  ASSERT_EQ(depth(root), 4);
  ASSERT_EQ(depth(root), itr::depth(root));
  root = insert(root, 1);
  ASSERT_EQ(depth(root), 4);
  ASSERT_EQ(depth(root), itr::depth(root));
  root = insert(root, 3);
  ASSERT_EQ(depth(root), 4);
  ASSERT_EQ(depth(root), itr::depth(root));
}

bool compare_bst(node* origin1, node* origin2) {
  if (!origin1 && !origin2) return true;
  if (!origin1 || !origin2) return false;
  if (origin1->value != origin2->value) return false;
  if (!compare_bst(origin1->left, origin2->left)) return false;
  return compare_bst(origin1->right, origin2->right);
}

namespace recur {
#include "balanced.cpp"
}
namespace naive {
#include "balanced_naive.cpp"
}
void TEST_Balanced() {
  node* root = nullptr;
  root = insert(root, 0);
  ASSERT_EQ(recur::balanced(root), true);
  ASSERT_EQ(naive::balanced(root), recur::balanced(root));
  root = insert(root, 4);
  ASSERT_EQ(recur::balanced(root), true);
  ASSERT_EQ(naive::balanced(root), recur::balanced(root));
  root = insert(root, -4);
  ASSERT_EQ(recur::balanced(root), true);
  ASSERT_EQ(naive::balanced(root), recur::balanced(root));
  root = insert(root, -8);
  ASSERT_EQ(recur::balanced(root), true);
  ASSERT_EQ(naive::balanced(root), recur::balanced(root));
  root = insert(root, -2);
  ASSERT_EQ(recur::balanced(root), true);
  ASSERT_EQ(naive::balanced(root), recur::balanced(root));
  root = insert(root, -1);
  ASSERT_EQ(recur::balanced(root), false);
  ASSERT_EQ(naive::balanced(root), recur::balanced(root));
  root = insert(root, -3);
  ASSERT_EQ(recur::balanced(root), false);
  ASSERT_EQ(naive::balanced(root), recur::balanced(root));
  root = insert(root, 8);
  ASSERT_EQ(recur::balanced(root), true);
  ASSERT_EQ(naive::balanced(root), recur::balanced(root));
  root = insert(root, 2);
  ASSERT_EQ(recur::balanced(root), true);
  ASSERT_EQ(naive::balanced(root), recur::balanced(root));
  root = insert(root, 1);
  ASSERT_EQ(recur::balanced(root), true);
  ASSERT_EQ(naive::balanced(root), recur::balanced(root));
  root = insert(root, 3);
  ASSERT_EQ(recur::balanced(root), true);
  ASSERT_EQ(naive::balanced(root), recur::balanced(root));
}

namespace recur {
#include "find_path.cpp"
}
namespace bt {
#include "find_path_binary_tree.cpp"
}
void TEST_Path() {
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
  std::vector<node*> path;
  std::vector<node*> path1;
  ASSERT_EQ(
    recur::find_path(root, find(root, 0), &path),
    bt::find_path(root, find(root, 0), &path1));
  ASSERT_EQ(
    recur::find_path(root, find(root, 4), &path),
    bt::find_path(root, find(root, 4), &path1));
  ASSERT_EQ(
    recur::find_path(root, find(root, -4), &path),
    bt::find_path(root, find(root, -4), &path1));
  ASSERT_EQ(
    recur::find_path(root, find(root, -8), &path),
    bt::find_path(root, find(root, -8), &path1));
  ASSERT_EQ(
    recur::find_path(root, find(root, -2), &path),
    bt::find_path(root, find(root, -2), &path1));
  ASSERT_EQ(
    recur::find_path(root, find(root, -1), &path),
    bt::find_path(root, find(root, -1), &path1));
  ASSERT_EQ(
    recur::find_path(root, find(root, -3), &path),
    bt::find_path(root, find(root, -3), &path1));
  ASSERT_EQ(
    recur::find_path(root, find(root, 8), &path),
    bt::find_path(root, find(root, 8), &path1));
  ASSERT_EQ(
    recur::find_path(root, find(root, 2), &path),
    bt::find_path(root, find(root, 2), &path1));
  ASSERT_EQ(
    recur::find_path(root, find(root, 1), &path),
    bt::find_path(root, find(root, 1), &path1));
  ASSERT_EQ(
    recur::find_path(root, find(root, 3), &path),
    bt::find_path(root, find(root, 3), &path1));
}

namespace norm {
#include "lca.cpp"
}
namespace path {
using namespace recur;
#include "lca_from_path.cpp"
}
namespace iter {
#include "lca_iterative.cpp"
}
void TEST_LCA() {
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
  std::vector<node*> path;
  std::vector<node*> path1;
  ASSERT_EQ(
    norm::lca(root, find(root, 0), find(root, 0)),
    iter::lca(root, find(root, 0), find(root, 0)));
  ASSERT_EQ(
    norm::lca(root, find(root, 0), find(root, 0)),
    path::lca(root, find(root, 0), find(root, 0)));
  ASSERT_EQ(
    norm::lca(root, find(root, 4), find(root, 3)),
    path::lca(root, find(root, 4), find(root, 3)));
  ASSERT_EQ(
    norm::lca(root, find(root, 4), find(root, 3)),
    iter::lca(root, find(root, 4), find(root, 3)));
  ASSERT_EQ(
    norm::lca(root, find(root, -1), find(root, 2)),
    path::lca(root, find(root, -1), find(root, 2)));
  ASSERT_EQ(
    norm::lca(root, find(root, -1), find(root, 2)),
    iter::lca(root, find(root, -1), find(root, 2)));
  ASSERT_EQ(
    norm::lca(root, find(root, -8), find(root, -4)),
    path::lca(root, find(root, -8), find(root, -4)));
  ASSERT_EQ(
    norm::lca(root, find(root, -8), find(root, -4)),
    iter::lca(root, find(root, -8), find(root, -4)));
  ASSERT_EQ(
    norm::lca(root, find(root, -2), find(root, 0)),
    iter::lca(root, find(root, -2), find(root, 0)));
  ASSERT_EQ(
    norm::lca(root, find(root, -2), find(root, 0)),
    path::lca(root, find(root, -2), find(root, 0)));
  ASSERT_EQ(
    norm::lca(root, find(root, -1), find(root, -3)),
    iter::lca(root, find(root, -1), find(root, -3)));
  ASSERT_EQ(
    norm::lca(root, find(root, -1), find(root, -3)),
    path::lca(root, find(root, -1), find(root, -3)));
  ASSERT_EQ(
    norm::lca(root, find(root, -3), find(root, 3)),
    iter::lca(root, find(root, -3), find(root, 3)));
  ASSERT_EQ(
    norm::lca(root, find(root, -3), find(root, 3)),
    path::lca(root, find(root, -3), find(root, 3)));
  ASSERT_EQ(
    norm::lca(root, find(root, 8), find(root, 1)),
    iter::lca(root, find(root, 8), find(root, 1)));
  ASSERT_EQ(
    norm::lca(root, find(root, 8), find(root, 1)),
    path::lca(root, find(root, 8), find(root, 1)));
  ASSERT_EQ(
    norm::lca(root, find(root, 2), find(root, -4)),
    iter::lca(root, find(root, 2), find(root, -4)));
  ASSERT_EQ(
    norm::lca(root, find(root, 2), find(root, -4)),
    path::lca(root, find(root, 2), find(root, -4)));
  ASSERT_EQ(
    norm::lca(root, find(root, 1), find(root, -1)),
    iter::lca(root, find(root, 1), find(root, -1)));
  ASSERT_EQ(
    norm::lca(root, find(root, 1), find(root, -1)),
    path::lca(root, find(root, 1), find(root, -1)));
  ASSERT_EQ(
    norm::lca(root, find(root, 3), find(root, 8)),
    iter::lca(root, find(root, 3), find(root, 8)));
  ASSERT_EQ(
    norm::lca(root, find(root, 3), find(root, 8)),
    path::lca(root, find(root, 3), find(root, 8)));
}

#include "enumerate_inorder.cpp"
#include "enumerate_preorder.cpp"
#include "enumerate_postorder.cpp"
void TEST_Traversals() {
  std::vector<int> values;
  std::vector<int> seq;
  auto visit = [&values] (node* vertex) {
    values.push_back(vertex->value);
  };

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

  values.clear();
  inorder(root, visit);
  seq = {-8,-4,-3,-2,-1,0,1,2,3,4,8};
  ASSERT(values == seq);

  values.clear();
  preorder(root, visit);
  seq = {0, -4, -8, -2, -3, -1, 4, 2, 1, 3, 8};
  ASSERT(values == seq);

  values.clear();
  postorder(root, visit);
  seq = {-8, -3, -1, -2, -4, 1, 3, 2, 8, 4, 0};
  ASSERT(values == seq);
}

#include "reconstruct_tree_from_in_order_and_post_order.cpp"
void TEST_Reconstruct() {
  std::vector<int> values;
  auto visit = [&values] (node* vertex) {
    values.push_back(vertex->value);
  };

  std::vector<int> values2;
  auto visit2 = [&values2] (node* vertex) {
    values2.push_back(vertex->value);
  };

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

  inorder(root, visit);
  preorder(root, visit2);
  node* root2 = reconstruct_tree(values, values2);

  values.clear();
  values2.clear();
  inorder(root, visit);
  inorder(root2, visit2);
  ASSERT(values == values2);

  values.clear();
  values2.clear();
  preorder(root, visit);
  preorder(root2, visit2);
  ASSERT(values == values2);

  values.clear();
  values2.clear();
  postorder(root, visit);
  postorder(root2, visit2);
  ASSERT(values == values2);
}

#include "tree_to_dll.cpp"
void TEST_ToDll() {
  std::vector<int> values;
  auto visit = [&values] (node* vertex) {
    values.push_back(vertex->value);
  };

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

  inorder(root, visit);
  auto head = tree_to_dll(root);
  for (size_t i = 0; i < values.size(); i++) {
    ASSERT(values[i] == head->value);
    head = head->right;
  }
}

int main(int argc, char** argv) {
  CALL(TEST_Construction);
  CALL(TEST_Insertion);
  CALL(TEST_Find);
  CALL(TEST_Remove);
  CALL(TEST_Size);
  CALL(TEST_Depth);
  CALL(TEST_Balanced);
  CALL(TEST_Path);
  CALL(TEST_LCA);
  CALL(TEST_Traversals);
  CALL(TEST_Reconstruct);
  CALL(TEST_ToDll);
  return 0;
}
