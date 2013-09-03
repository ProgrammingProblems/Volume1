bool detect_loop(node* head) {
  if (nullptr == head) {
    return false;
  }
  auto trailing = head;
  auto leading = head;
  while(nullptr != leading) {
    leading = leading->next;
    if (trailing == leading) {
      return true;
    }
    trailing = trailing->next;
    if (nullptr != leading) {
      leading = leading->next;
    }
  }
  return false;
}