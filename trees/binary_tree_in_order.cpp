void in_order(node* root, ostream& os) {
  if (!root) return;
  in_order(root->lc);
  os << *root;
  in_order(root->lc);
}