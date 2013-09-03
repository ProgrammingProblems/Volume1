void find_ancestry(const GeneologicalData& data,
                   const Person& id,
                   Ancestry* ancestry) {
  std::queue<Person> queue;
  queue.push(id);
  ancestry->insert(id);
  while (queue.size()) {
    auto entry = data.find(queue.front());
    queue.pop();
    if (entry == data.end()) continue;
    for (auto parent : entry->second) {
      if (ancestry->end()
            == ancestry->find(parent)) {
        ancestry->insert(parent);
        queue.push(parent);
      }
    }
  }
}