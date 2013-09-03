void bfs(node* origin, Visitor visit) {
  std::set<node*> queued;
  std::queue<node*> queue;
  queue.push(origin);
  queued.insert(origin);
  while (!queue.empty()) {
      node* current = queue.front();
      queue.pop();
      visit(current);
      for (auto neighbor : current->neighbors) {
        if (queued.end()
            == queued.find(neighbor)) {
          queue.push(neighbor);
          queued.insert(neighbor);
        }
      }
  }
}
