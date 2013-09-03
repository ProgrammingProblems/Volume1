class queue {
 public:
  void push(int data) {
    instack_.push(data);
  }
  int front() const {
    transfer();
    return outstack_.top();
  }
  void pop() {
    transfer();
    return outstack_.pop();
  }
 private:
  void transfer() const {
    if (outstack_.empty()) {
      while (!instack_.empty()) {
        outstack_.push(instack_.top());
        instack_.pop();
      }
    }
  }
  mutable std::stack<int> instack_;
  mutable std::stack<int> outstack_;
};
