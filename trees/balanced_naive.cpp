bool balanced(node* root) {
  if (nullptr == root) return true;
  if (!balanced(root->left)
      || !balanced(root->right)) {
    return false;
  }
  size_t left_depth = depth(root->left);
  size_t right_depth = depth(root->right);
  return
    std::abs<int>(right_depth - left_depth) <= 1;
}