node* circular_remove(node* head, node* target) {
  if (head == head->next) {
    delete head;
    return nullptr;
  }
  auto next = target->next;
  target->data = next->data;
  target->next= next->next;
  delete next;
  return target;
}