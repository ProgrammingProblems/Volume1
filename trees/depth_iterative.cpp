size_t depth(node* root) {
  if (nullptr == root) return 0;
  size_t maxdepth = 0;
  std::set<node*> visited;
  std::stack<node*> s;
  s.push(root);
  while (!s.empty()) {
    node* top = s.top();
    if (nullptr != top->left
        && visited.end() ==
            visited.find(top->left)) {
      s.push(top->left);
    } else if (
        nullptr != top->right
        && visited.end() ==
            visited.find(top->right)) {
      s.push(top->right);
    } else {
      visited.insert(top);
      maxdepth = std::max(maxdepth, s.size());
      s.pop();
    }
  }
  return maxdepth;
}