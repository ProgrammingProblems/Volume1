struct dll_node {
  dll_node* prev;
  dll_node* next;
  int data;
  explicit dll_node(int data)
    : dll_node(this, this, data) {}
  dll_node(dll_node* prev,
           dll_node* next,
           int data)
    : prev(prev), next(next), data(data) {}
};