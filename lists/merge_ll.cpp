node* merge(node* h1, node* h2) {
  if (nullptr == h1 || nullptr == h2) {
    return h1 ? h1 : h2;
  }
  auto head = h1;
  while (nullptr != h1->next) {
    h1 = h1->next;
  }
  h1->next = h2;
  return head;
}