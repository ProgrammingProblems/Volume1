node* lca(node* root, node* x, node* y) {
  if (root == x || root == y) return root;
  if ((x->value < root->value
       && y->value >= root->value)
      || (y->value < root->value
          && x->value >= root->value)) {
    return root;
  }
  if (x->value < root->value) {
    return lca(root->left, x, y);
  }
  return lca(root->right, x, y);
}