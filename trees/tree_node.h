struct node {
  int value;
  node* left = nullptr;
  node* right = nullptr;

  explicit node(int value) : value(value) {};
};