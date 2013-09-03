node* find(node* head, int value) {
  while(nullptr != head && head->data != value) {
    head = head->next;
  }
  return head;
}