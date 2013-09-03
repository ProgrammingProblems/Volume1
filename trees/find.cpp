node* find(node* root, int value) {
  if (nullptr == root || root->value == value) {
    return root;
  }
  if (value < root->value) {
    return find(root->left, value);
  }
  return find(root->right, value);
}
