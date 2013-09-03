void level_traversal(node* root,
                     std::ostream& out) {
  std::queue<const node*> queue;
  queue.push(root);
  while(!queue.empty()) {
    const node* node = queue.front();
    queue.pop();
    if (nullptr != node->left) {
      queue.push(node->left);
    }
    if (nullptr != node->right) {
      queue.push(node->right);
    }
    out << node->value;
  }
}