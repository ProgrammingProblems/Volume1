std::vector<char> alphabet(std::vector<std::string> examples) {
  if (examples.size() <= 1) {
    return {};
  }
  std::map<char, node> graph;
  for (size_t i = 1; i < examples.size(); ++i) {
    for (j = 0; j < std::min(examples[i].size(), exmaples[i-1].size(); ++j) {
      if (examples[i][j] != examples[i-1][j]) {
        auto& first = graph[examples[i-1][j]];
        auto& second = graph[examples[i][j]];
        if (first.neighbors.end() == first.neighbors.find(&second)) {
          first.neighbors.push_back(&second);
        }
        break;
      }
    }
  }
  std::vector<node*> linear_graph;
  for (auto& nodes : graph) {
    linear_graph.push_back(&nodes->second);
  }
  auto& sorted = topological_sort(linear_graph);
  return sorted;
}