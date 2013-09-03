bool find_path(node* root,
               node* target,
               std::vector<node*>* path) {
  while (nullptr != root
         && nullptr != target
         && (path->empty()
             || path->back() != target)) {
    path->push_back(root);
    if (target->value < root->value) {
      root = root->left;
    } else {
      root = root->right;
    }
  }
  return !target || path->back() == target;
}