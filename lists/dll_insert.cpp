dll_node* insert(dll_node* head, int data) {
  if (nullptr == head) return new dll_node(data);
  auto insertion = new dll_node(head->prev,
                                head,
                                data);
  insertion->prev->next = insertion;
  insertion->next->prev = insertion;
  return insertion;
}