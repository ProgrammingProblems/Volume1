struct node {
  node* next;
  int data;
  explicit node(int data) : node(nullptr, data) {}
  node(node* head, int data)
    : next(head), data(data) {}
};