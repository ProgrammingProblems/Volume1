node* find_successor(node* root, node* target) {
  auto successor = target->right;
  if (nullptr != successor) {
    while (nullptr != successor->left) {
      successor = successor->left;
    }
    return successor;
  }
  do {
    if (nullptr != successor) {
      target = successor;
    }
    successor = find_parent(root, target);
  }  while (nullptr != successor
            && successor->right == target);
  return successor;
}