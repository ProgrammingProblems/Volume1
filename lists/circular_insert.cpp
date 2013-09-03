node* circular_insert(node* head, int data) {
  auto insertion = new node(data);
  if (nullptr == head) {
    insertion->next = insertion;
    return insertion;
  }
  if (head == head->next) {
    head->next = insertion;
    insertion->next = head;
    return insertion;
  }
  std::swap(head->data, insertion->data);
  insertion->next = head->next;
  head->next = insertion;
  return head;
}