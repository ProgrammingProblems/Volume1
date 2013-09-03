class stack {
 public:
  void push(int data) {
    list.push_front(data);
  }
  int top() {
    return list.front();
  }
  void pop() {
    list.pop_front();
  }
 private:
  std::list<int> list;
};
