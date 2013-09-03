size_t depth(node* root) {
  if (nullptr == root) return 0;
  return 1 + std::max(depth(root->left),
                      depth(root->right));
}