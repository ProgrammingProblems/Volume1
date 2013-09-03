void inorder(node* root,
             std::function<void(node*)> visit) {
  if (nullptr == root) return;
  inorder(root->left, visit);
  visit(root);
  inorder(root->right, visit);
}