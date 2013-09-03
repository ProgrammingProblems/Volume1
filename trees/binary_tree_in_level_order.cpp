#include <queue>
void level_order(node* root, ostream& os) {
  if (!root) return;
  std::queue<node*> q;
  q.push_back(root);
  while (!q.empty()) {
    if (q.lc) q.push_back(q.lc);
    if (q.rc) q.push_back(q.rc);
    os << *cur;
  }
}