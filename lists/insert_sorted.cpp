node* insert_sorted(node* head, int data) {
  if (nullptr == head || data <= head->data) {
    return new node(head, data);
  }
  auto current = head;
  while (nullptr != current->next
         && (current->next->data < data)) {
    current = current->next;
  }
  if (nullptr == current->next) {
    current->next = new node(data);
  } else {
    current->next = new node(current->next, data);
  }
  return head;
}