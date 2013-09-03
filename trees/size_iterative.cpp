size_t size(node* root) {
  if (nullptr == root) return 0;
  size_t count = 0;
  std::queue<node*> q;
  q.push(root);
  while (!q.empty()) {
    auto front = q.front();
    q.pop();
    ++count;
    if (nullptr != front->left) {
      q.push(front->left);
    }
    if (nullptr != front->right) {
      q.push(front->right);
    }
  }
  return count;
}