bool is_palindrome(dll_node* head) {
  if (nullptr == head) return true;
  if (head == head->next) return true;
  auto tail = head->prev;
  do {
    if (head->data != tail->data) {
      return false;
    }
    head = head->next;
    tail = tail->prev;
  } while (head != tail && head != tail->next);
  return true;
}