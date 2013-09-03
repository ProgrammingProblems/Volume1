void find_distances(
    node* origin,
    std::map<node*, size_t>* distances) {
  auto distance = [distances] (node* vertex) {
    auto distance_itr = distances->find(vertex);
    if (distances->end() == distance_itr) {
      return std::numeric_limits<size_t>::max();
    }
    return distance_itr->second;
  };

  auto visit = [distances, distance] (
      node* vertex) {
    if (distances->empty()) (*distances)[vertex]=0;
    for(node* neighbor: vertex->neighbors) {
      auto vertexDistance = distance(vertex);
      auto neighborDistance = distance(neighbor);
      (*distances)[neighbor] =
        std::min(neighborDistance,
                 1 + vertexDistance);
    }
  };

  bfs(origin, visit);
}
