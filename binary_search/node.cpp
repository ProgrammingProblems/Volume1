#include <vector>

template <class T>
struct node {
 public:
  vector<node*> neighbors;
  T value;
}