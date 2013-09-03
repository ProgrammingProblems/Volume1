void topological_sort(node* origin,
                      std::list<node*>* list) {
  auto visitor = [list] (node* vertex) {
    list->push_back(vertex);
  };
  dfs(origin, visitor);
  list->reverse();
}