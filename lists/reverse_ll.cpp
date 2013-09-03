node* reverse(node* head) {
  node* prev = nullptr;
  while (nullptr != head) {
    node* temp = head->next;
    head->next = prev;
    prev = head;
    head = temp;
  }
  return prev;
}