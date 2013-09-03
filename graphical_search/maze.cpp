void maze(const GameBoard& maze,
          const Position& start,
          const Position& exit,
          std::list<Position>* route) {
  static const std::vector<
    std::pair<size_t, size_t>> offsets =
      {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  std::map<Position,Position> parent;
  std::priority_queue<
    std::pair<size_t, Position>,
    std::vector<std::pair<size_t, Position>>,
    std::greater<std::pair<size_t, Position>>>
      priority_queue;
  priority_queue.push({distance(start, exit),
                       start});
  parent[start] = start;
  while (!priority_queue.empty()) {
    auto current = priority_queue.top().second;
    if (exit == current) {
      do {
        route->push_front(current);
        current = parent[current];
      } while (current != start);
      route->push_front(start);
      return;
    }
    priority_queue.pop();
    for (auto offset : offsets) {
      auto neighbor =
        Position(current.first + offset.first,
                 current.second + offset.second);
      if (neighbor.first < maze.size()
          && neighbor.second
            < maze[neighbor.first].size()
          && parent.end()==parent.find(neighbor)
          && passable(neighbor)) {
        parent[neighbor] = current;
        priority_queue.push(
          {distance(neighbor, exit), neighbor});
      }
    }
  }
}