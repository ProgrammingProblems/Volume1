node* kth_from_end(node* head, size_t k) {
  auto trailing = head;
  while (k-- && nullptr != head) {
    head = head->next;
  }
  while (nullptr != head
         && nullptr != head->next) {
    head = head->next;
    trailing = trailing->next;
  }
  return trailing;
}