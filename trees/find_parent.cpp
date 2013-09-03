node* find_parent(node* root, node* target) {
  if (root == target) {
    return nullptr;
  }
  while (root->left != target
         && root->right != target) {
    if (target->value < root->value) {
      root = root->left;
    } else {
      root = root->right;
    }
  }
  return root;
}