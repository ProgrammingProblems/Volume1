size_t size(node* root) {
  if (nullptr == root) {
    return 0;
  }
  return 1 + size(root->left) + size(root->right);
}