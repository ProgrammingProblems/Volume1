node* insert(node* root, int val) {
  if (nullptr == root) {
    return new node(val);
  }
  if (val < root->value) {
    root->left = insert(root->left, val);
  }
  else {
    root->right = insert(root->right, val);
  }
  return root;
}