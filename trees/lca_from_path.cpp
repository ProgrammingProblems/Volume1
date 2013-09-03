node* lca(node* root, node* x, node* y) {
  std::vector<node*> x_path;
  std::vector<node*> y_path;
  find_path(root, x, &x_path);
  find_path(root, y, &y_path);
  node* lca = nullptr;
  auto x_path_iterator = x_path.begin();
  auto y_path_iterator = y_path.begin();
  while (x_path_iterator != x_path.end()
         && y_path_iterator != y_path.end()
         && *x_path_iterator == *y_path_iterator) {
    lca = *x_path_iterator;
    x_path_iterator++;
    y_path_iterator++;
  }
  return lca;
}