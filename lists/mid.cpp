node* mid(node* head) {
  auto trailing = head;
  while (nullptr != head) {
    head = head->next;
    if (head) {
      head = head->next;
      trailing = trailing->next;
    }
  }
  return trailing;
}