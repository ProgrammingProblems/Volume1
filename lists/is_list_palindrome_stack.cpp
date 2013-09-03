bool is_palindrome(node* head) {
  auto temp = head;
  std::stack<node*> s;
  while (nullptr != temp) {
    s.push(temp);
    temp = temp->next;
  }
  while (!s.empty()) {
    if (head->data != s.top()->data) {
      return false;
    }
    s.pop();
    head = head->next;
  }
  return true;
}