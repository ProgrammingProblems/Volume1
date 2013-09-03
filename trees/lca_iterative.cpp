node* lca(node* root, node* x, node* y) {
  if (nullptr != x
      && nullptr != y
      && x->value > y->value) {
    std::swap(x, y);
  }
  while (nullptr != root
         && root != x
         && root != y
         && (y->value < root->value
             || x->value >= root->value)) {
    if (y->value < root->value) {
      root = root->left;
    } else {
      root = root->right;
    }
  }
  return root;
}