dll_node* remove(dll_node* head, dll_node* node) {
  if (head->next == head) {
    delete node;
    return nullptr;
  }
  node->prev->next = node->next;
  node->next->prev = node->prev;
  if (head == node) {
    head = node->next;
  }
  delete node;
  return head;
}