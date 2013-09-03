dll_node* reverse(dll_node* head) {
  if (nullptr == head) return nullptr;
  if (head->next == head->prev) {
    return head;
  }
  auto tail = head;
  do {
    auto temp = tail->next;
    tail->next = tail->prev;
    tail->prev = temp;
    tail = temp;
  } while (tail != head);
  return head->prev;
}