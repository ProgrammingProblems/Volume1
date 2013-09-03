bool equals(node* x, node* y) {
  while(x && y) {
    if (x->data != y->data) return false;
    x = x->next;
    y = y->next;
  }
  if (nullptr == x && nullptr == y) return true;
  return false;
}