node* dfs(node* origin, Visitor visit) {
  std::set<node*> queued;
  std::stack<std::pair<
    node*,
    std::vector<node*>::iterator>> stack;
  stack.push({origin, origin->neighbors.begin()});
  queued.insert(origin);
  while (!stack.empty()) {
    auto current = stack.top().first;
    auto& neighbor = stack.top().second;
    if (neighbor != current->neighbors.end()) {
      node* next = *neighbor;
      ++neighbor;
      if (queued.end() == queued.find(next)) {
        stack.push({next,
                    next->neighbors.begin()});
        queued.insert(next);
      }
      continue;
    }
    visit(current);
    stack.pop();
  }
}