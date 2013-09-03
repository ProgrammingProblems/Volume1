node* remove(node* root, node* target) {
  if (nullptr != target->left
      && nullptr != target->right) {
    node* next = find_successor(root, target);
    int data = next->value;
    remove(root, next);
    target->value = data;
    return root;
  }
  if (nullptr != target->left
      || nullptr != target->right) {
    node* temp = target->left ?
      target->left : target->right;
    target->value = temp->value;
    target->left = temp->left;
    target->right = temp->right;
    delete temp;
    return root;
  }
  if (root == target) {
    delete root;
    return nullptr;
  }
  node* parent = find_parent(root, target);
  if (parent->left == target) {
    parent->left = nullptr;
  }
  else {
    parent->right = nullptr;
  }
  delete target;
  return root;
}