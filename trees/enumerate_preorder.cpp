void preorder(node* root,
              std::function<void(node*)> visit) {
  if (nullptr == root) return;
  visit(root);
  preorder(root->left, visit);
  preorder(root->right, visit);
}