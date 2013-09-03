node* mid_by_counting(node* head) {
  if (!head) {
    return head;
  }
  auto trailing = head;
  size_t size = 0;
  while (nullptr != head) {
    ++size;
    head = head->next;
  }
  size_t mid = size / 2;
  while (mid--) {
    trailing = trailing->next;
  }
  return trailing;
}