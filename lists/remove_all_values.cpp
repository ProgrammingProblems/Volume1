node* remove_values(node* head, int value) {
  while (nullptr != head && head->data == value) {
    auto temp = head;
    head = head->next;
    delete temp;
  }
  auto target = head;
  while (nullptr != target) {
    while (nullptr != target->next
           && target->next->data == value) {
      node* temp = target->next;
      target->next = target->next->next;
      delete temp;
    }
    target = target->next;
  }
  return head;
}