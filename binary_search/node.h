#include <vector>

template <class T>
struct node {
 public:
  std::vector<node<T>*> neighbors;
  T key;
}