#include <iostream>
std::ostream& operator<<(std::ostream& os, std::nullptr_t n)
{
    os << "nullptr";
    return os;
}

template<class T>
std::ostream& operator<<(std::ostream& os,
                         const std::vector<T>& v) {
    for (auto& item : v) {
      if (&item != &v[0]) {
        os << ",";
      }
      os << (int) item;
    }
    return os;
}

std::ostream& operator<<(std::ostream& os,
                         const std::vector<std::string>& v) {
   for (auto item : v) {
     if (item != v[0]) {
       os << ",";
     }
     os <<  item;
   }
   return os;
}

std::ostream& operator<<(std::ostream& os,
                         const std::multiset<int>& v) {
    os << "{";
    for (auto& item : v) {
      if (item != *v.begin()) {
        os << ",";
      }
      os << (char) item;
    }
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os,
                         const std::set<int>& v) {
    os << "{";
    for (auto& item : v) {
      if (item != *v.begin()) {
        os << ",";
      }
      os << (char) item;
    }
    os << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os,
                         const std::set<std::set<int>>& v) {
    for (auto& subset : v) {
      if (subset != *v.begin()) {
        os << "-";
      }
      os << "{" << subset << "}";
    }
    return os;
}

std::ostream& operator<<(std::ostream& os,
                         const std::set<std::vector<int>>& v) {
    for (auto& subset : v) {
      if (subset != *v.begin()) {
        os << "-";
      }
      os << "[" << subset << "]";
    }
    return os;
}

std::ostream& operator<<(std::ostream& os,
                         const std::set<std::set<std::set<int>>>& v) {
    for (auto& subset : v) {
      if (subset != *v.begin()) {
        os << "\n\t";
      }
      os << "{" << subset << "}";
    }
    return os;
}


#define FAILED_LINE std:: cout << "\tFAILED! (" << __LINE__ << ")" << std::endl

#define ASSERT(x) \
  if (!(x)) { \
    FAILED_LINE; \
    std::cout << "Failed to verify " << #x << std::endl; \
    std::cout << "\tReturned value: " << (x) << std:: endl;\
    exit(-1); \
  }

#define ASSERT_NEARLY_EQ(x, y) \
  { \
    if (std::abs((x)-(y)) > epsilon) { \
      FAILED_LINE; \
      std::cout << "Failed to verify " << #x << "==" << #y << std::endl; \
      std::cout << "\t" << #x << "=" << (x) << std:: endl;\
      std::cout << "\t" << #y << "=" << y << std:: endl;\
      exit(-1); \
    } \
  }

#define ASSERT_EQ(x, y) \
  { \
    if ((x) != (y)) { \
      FAILED_LINE; \
      std::cout << "Failed to verify " << #x << "==" << #y << std::endl; \
      std::cout << "\t" << #x << "=" << (x) << std:: endl;\
      std::cout << "\t" << #y << "=" << y << std:: endl;\
      exit(-1); \
    } \
  }

#define ASSERT_NEQ(x, y) \
  if ((x) == (y)) { \
    FAILED_LINE; \
    std::cout << "Failed to verify " << #x << "!=" << #y << std::endl; \
    std::cout << "\t" << #x << "=" << (x) << std:: endl;\
    std::cout << "\t" << #y << "=" << (y) << std:: endl;\
    exit(-1); \
  }



#define CALL(X) \
  std::cout << "Calling " << #X << "."; \
  X(); \
  std::cout << "\tSucccess!" << std::endl

#define DBG_TRACE(X) \
  DBG_OUT(X, "");

#define DBG_VAR(VAR) \
  DBG_OUT(#VAR ": ", VAR)

#define DBG_OUT(PREFIX, VALUE) \
  std::cout << PREFIX << VALUE << std::endl;

template <class T>
void DUMP_ARRAY(const std::vector<T>& array) {
  size_t count = 0;
  for(auto element: array) {
    std::cout << count++ << ":" << (int) element << " ";
  }
  std::cout << std::endl;
}

void DUMP_ARRAY(int* array, size_t size) {
  size_t count = 0;
  while (size--) {
    std::cout << count << ":" << *(array+count) << " ";
    count++;
  }
  std::cout << std::endl;
}
