bool balanced(node* root) {
  std::function<bool(node*, size_t*)>
    balanced_depth = [&balanced_depth] (
      node* root,
      size_t* depth) {
    if (nullptr == root) {
      *depth = 0;
      return true;
    }
    size_t left;
    size_t right;
    if (!balanced_depth(root->left, &left)) {
      return false;
    }
    if (!balanced_depth(root->right, &right)) {
      return false;
    }
    *depth = 1 + std::max(left, right);
    if (std::abs<int>(left - right) >  1) {
      return false;
    }
    return true;
  };

  size_t depth;
  return balanced_depth(root, &depth);
}