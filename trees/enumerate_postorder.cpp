void postorder(node* root,
               std::function<void(node*)> visit) {
  if (nullptr == root) return;
  postorder(root->left, visit);
  postorder(root->right, visit);
  visit(root);
}