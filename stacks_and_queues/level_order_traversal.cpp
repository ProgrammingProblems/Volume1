void level_traversal(node* root,
                     std::ostream& out) {
  static const node* LEVEL_TOKEN = nullptr;
  std::queue<const node*> queue;
  queue.push(root);
  queue.push(LEVEL_TOKEN);
  while(!queue.empty()) {
    const node* node = queue.front();
    queue.pop();
    if (LEVEL_TOKEN == node) {
      if (!queue.empty()) {
        out << std::endl;
        queue.push(LEVEL_TOKEN);
      }
      continue;
    }
    if (nullptr != node->left) {
      queue.push(node->left);
    }
    if (nullptr != node->right) {
      queue.push(node->right);
    }
    out << node->value;
  }
}