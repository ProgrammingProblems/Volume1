node* tree_to_dll(node* root, node* head = nullptr) {
  auto push_back = [] (node* head, node* root) -> node* {
    if (nullptr == root) {
      return head;
    }
    if (nullptr == head) {
      root->left = root;
      root->right = root;
      head = root;
      return head;
    }
    root->right = head;
    root->left = head->left;
    root->left->right = root;
    head->left = root;
    return head;
  };
  if (nullptr == root) {
    return head;
  }
  head = tree_to_dll(root->left, head);
  auto right = root->right;
  head = push_back(head, root);
  head = tree_to_dll(right, head);
  return head;
}