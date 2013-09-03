node* remove(node* head, node* target) {
  if (head == target) {
    head = head->next;
    delete target;
    return head;
  }
  auto temp = head;
  while (nullptr != temp->next
         && target != temp->next) {
    temp = temp->next;
  }
  if (target == temp->next) {
    temp->next = temp->next->next;
    delete target;
  }
  return head;
}