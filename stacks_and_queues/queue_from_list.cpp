class queue {
 public:
  void push(int data) {
    list.push_back(data);
  }
  int front() {
    return list.front();
  }
  void pop() {
    list.pop_front();
  }
 private:
   std::list<int> list;
};
