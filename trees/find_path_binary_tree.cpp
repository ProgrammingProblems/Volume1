bool find_path(node* root,
               node* target,
               std::vector<node*>* path) {
  std::set<node*> visited;
  std::stack<node*> s;
  s.push(root);

  while (!s.empty()) {
    node* current = s.top();
    if (nullptr != current->left
        && visited.end() == visited.find(current->left)) {
      s.push(current->left);
    } else if (nullptr != current->right
               && visited.end() == visited.find(current->right)) {
      s.push(current->right);
    } else {
      visited.insert(current);
      if (target == current) {
        path->resize(s.size());
        while (!s.empty()) {
          (*path)[s.size()-1] = s.top();
          s.pop();
        }
        return true;
      }
      s.pop();
    }
  }
  return false;
}
