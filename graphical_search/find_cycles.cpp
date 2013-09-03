bool detect_cycle(node* origin) {
  bool cycle_detected = false;
  std::set<node*> visited;
  auto visitor = [&cycle_detected, &visited] (
      node* vertex) {
    visited.insert(vertex);
    for (auto neighbor: vertex->neighbors) {
      if (visited.end()
          == visited.find(neighbor)) {
        cycle_detected = true;
      }
    }
  };
  dfs(origin, visitor);
  return cycle_detected;
}