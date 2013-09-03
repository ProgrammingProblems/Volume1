#include <queue>
void level_order(node* root, ostream& os) {
  if (!root) return;
  std::queue<node*> q;
  q.push_back(root);
  q.push_back(nullptr);
  for (node* cur = q.pop_front(); cur || !q.empty(); cur = q.pop_front) {
    if (nullptr == cur) {
      os << std::endl;
      q.push_back(nullptr);
      continue;
    }
    if (q.lc) q.push_back(q.lc);
    if (q.rc) q.push_back(q.rc);
    os << *cur;
  }
}