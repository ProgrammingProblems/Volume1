#include <iostream>
#include <vector>

#include "../test/testing.h"

#include "list.h"
void TEST_Construction() {
  node node0(0);
  ASSERT(node0.data == 0);
  ASSERT(node0.next == nullptr);
  node node1(&node0, 1);
  ASSERT(node1.data == 1);
  ASSERT(node1.next == &node0);
}

#include "insert.cpp"
void TEST_Insertion() {
  node* head = nullptr;
  head = insert(head, 0);
  ASSERT(head->data == 0);
  ASSERT(head->next == nullptr);
  head = insert(head, 2);
  ASSERT(head->data == 2);
  ASSERT(head->next != nullptr);
}

#include "insert_sorted.cpp"
void TEST_SortedInsertion() {
  node* head = nullptr;
  head = insert_sorted(head, 0);
  ASSERT_EQ(head->data, 0);
  head = insert_sorted(head, 2);
  ASSERT_EQ(head->data, 0);
  ASSERT_EQ(head->next->data, 2);
  head = insert_sorted(head, 1);
  ASSERT_EQ(head->data, 0);
  ASSERT(head->next->data == 1);
  ASSERT(head->next->next->data == 2);
  ASSERT(head->next->next->next == nullptr);
}

#include "find.cpp"
void TEST_Find() {
  node* head = nullptr;
  head = insert(head, 0);
  ASSERT_EQ(find(head, 0)->data, 0);
  head = insert(head, 2);
  ASSERT_EQ(find(head, 0)->data, 0);
  ASSERT_EQ(find(head, 2)->data, 2);
  head = insert(head, 1);
  ASSERT_EQ(find(head, 1)->data, 1);
  ASSERT_EQ(find(head, 2)->data, 2);
  ASSERT_EQ(find(head, 0)->data, 0);
}

#include "remove.cpp"
void TEST_Remove() {
  node* head = nullptr;
  head = insert(head, 4);
  head = insert(head, 3);
  head = insert(head, 2);
  head = insert(head, 1);
  head = insert(head, 0);
  head = remove(head, find(head, 2));
  ASSERT(find(head, 2) ==  nullptr);
  ASSERT_EQ(head->data,0);
  head = remove(head, find(head, 3));
  ASSERT(find(head, 3) ==  nullptr);
  ASSERT_EQ(head->data,0);
  head = remove(head, find(head, 0));
  ASSERT(find(head, 0) ==  nullptr);
  ASSERT_EQ(head->data,1);
  head = remove(head, find(head, 1));
  ASSERT(find(head, 1) ==  nullptr);
  ASSERT_EQ(head->data, 4);
  head = remove(head, find(head, 4));
  ASSERT(find(head, 4) ==  nullptr);
  ASSERT(head ==  nullptr);
}

#include "circular_insert.cpp"
void TEST_CircularInsertion() {
  node* head = nullptr;
  head = circular_insert(head, 0);
  ASSERT(head->data == 0);
  ASSERT(head->next->data == 0);
  ASSERT(head->next == head);
  head = circular_insert(head, 2);
  ASSERT(head->data == 2);
  ASSERT(head->next->data == 0);
  ASSERT(head->next->next == head);
  head = circular_insert(head, 4);
  ASSERT(head->data == 4);
  ASSERT(head->next->data == 2);
  ASSERT(head->next->next->data == 0);
  ASSERT(head->next->next->next == head);
}

#include "circular_find.cpp"
void TEST_CircularFind() {
  node* head = nullptr;
  ASSERT(circular_find(head, 0) ==  nullptr);
  head = circular_insert(head, 0);
  head = circular_insert(head, 1);
  head = circular_insert(head, 2);
  head = circular_insert(head, 3);
  head = circular_insert(head, 4);
  ASSERT_EQ(circular_find(head, 0)->data, 0);
  ASSERT_EQ(circular_find(head, 1)->data, 1);
  ASSERT_EQ(circular_find(head, 2)->data, 2);
  ASSERT_EQ(circular_find(head, 3)->data, 3);
  ASSERT_EQ(circular_find(head, 4)->data, 4);
  ASSERT(circular_find(head, 5) ==  nullptr);
}

#include "circular_remove.cpp"
void TEST_CircularRemove() {
  node* head = nullptr;
  //head = circular_remove(head, circular_find(head, 0));
  ASSERT(head ==  nullptr);
  head = circular_insert(head, 0);
  head = circular_insert(head, 1);
  head = circular_insert(head, 2);
  head = circular_insert(head, 3);
  head = circular_insert(head, 4);
  head = circular_remove(head, circular_find(head, 0));
  ASSERT_EQ(circular_find(head, 4)->data, 4);
  head = circular_remove(head, circular_find(head, 4));
  ASSERT_EQ(circular_find(head, 2)->data, 2);
  head = circular_remove(head, circular_find(head, 2));
  ASSERT_EQ(circular_find(head, 1)->data, 1);
  head = circular_remove(head, circular_find(head, 1));
  ASSERT_EQ(circular_find(head, 3)->data, 3);
  head = circular_remove(head, circular_find(head, 3));
  ASSERT(head ==  nullptr);
}

#include "dll.h"
void TEST_DllConstruction() {
  dll_node node0(0);
  ASSERT(node0.data == 0);
  ASSERT(node0.prev == &node0);
  ASSERT(node0.next == &node0);
  dll_node node1(&node0, &node0, 1);
  ASSERT(node1.data == 1);
  ASSERT(node1.prev == &node0);
  ASSERT(node1.next == &node0);
}

#include "dll_insert.cpp"
void TEST_DllInsertion() {
  dll_node* head = nullptr;
  head = insert(head, 0);
  ASSERT(head == head->next && head == head->prev);
  ASSERT_EQ(head->data, 0);
  head = insert(head, 1);
  ASSERT(head == head->next->next
         && head == head->prev->prev
         && head == head->next->prev
         && head == head->prev->next);
  ASSERT_EQ(head->data, 1);
  ASSERT_EQ(head->next->data, 0);
  head = insert(head, 2);
  ASSERT_EQ(head->data, 2);
  ASSERT_EQ(head->next->data, 1);
  ASSERT_EQ(head->next->next->data, 0);
  head = insert(head, 3);
  ASSERT_EQ(head->data, 3);
  ASSERT_EQ(head->next->data, 2);
  ASSERT_EQ(head->next->next->data, 1);
  ASSERT_EQ(head->next->next->next->data, 0);
  ASSERT_EQ(head->prev->data, 0);
  ASSERT_EQ(head->prev->prev->data, 1);
  ASSERT_EQ(head->prev->prev->prev->data, 2);
  ASSERT_EQ(head->prev->prev->prev->prev->data, 3);
}

#include "dll_find.cpp"
void TEST_DllFind() {
  node* head = nullptr;
  ASSERT(find(head, 0) ==  nullptr);
  head = insert(head, 0);
  head = insert(head, 1);
  head = insert(head, 2);
  head = insert(head, 3);
  head = insert(head, 4);
  ASSERT_EQ(find(head, 0)->data, 0);
  ASSERT_EQ(find(head, 1)->data, 1);
  ASSERT_EQ(find(head, 2)->data, 2);
  ASSERT_EQ(find(head, 3)->data, 3);
  ASSERT_EQ(find(head, 4)->data, 4);
  ASSERT(find(head, 5) ==  nullptr);
}


#include "dll_remove.cpp"
void TEST_DllRemove() {
  dll_node* head = nullptr;
  dll_node* zero = head = insert(head, 0);
  dll_node* one = head = insert(head, 1);
  dll_node* two = head = insert(head, 2);
  dll_node* three = head = insert(head, 3);
  ASSERT_EQ(head->data, 3);
  head = remove(head, one);
  ASSERT_EQ(head->data, 3);
  head = remove(head, zero);
  ASSERT_EQ(head->data, 3);
  head = remove(head, three);
  ASSERT_EQ(head->data, 2);
  head = remove(head, two);
  ASSERT(head == nullptr);
}

#include "mid_count.cpp"
#include "mid.cpp"
#include "k_th_from_the_end.cpp"
void TEST_Selection() {
  node* head = nullptr;
  ASSERT(mid_by_counting(head) == mid(head));
  ASSERT(nullptr == mid(head));
  ASSERT(nullptr == kth_from_end(head, 0));
  ASSERT(nullptr == kth_from_end(head, 1));
  ASSERT(nullptr == kth_from_end(head, 2));

  head = insert(head, 0);
  ASSERT_EQ(head->data, 0);
  ASSERT(mid_by_counting(head) == mid(head));
  ASSERT_EQ(mid(head)->data, 0);

  head = insert(head, 1);
  ASSERT_EQ(head->data, 1);
  ASSERT(mid_by_counting(head) == mid(head));
  ASSERT_EQ(mid(head)->data, 0);

  head = insert(head, 2);
  ASSERT_EQ(head->data, 2);
  ASSERT(mid_by_counting(head) == mid(head));
  ASSERT_EQ(mid(head)->data, 1);

  head = insert(head, 3);
  ASSERT_EQ(head->data, 3);
  ASSERT(mid_by_counting(head) == mid(head));
  ASSERT_EQ(mid(head)->data, 1);

  head = insert(head, 4);
  ASSERT_EQ(head->data, 4);
  ASSERT(mid_by_counting(head) == mid(head));
  ASSERT_EQ(mid(head)->data, 2);
  ASSERT_EQ(kth_from_end(head, 0)->data, 0);
  ASSERT_EQ(kth_from_end(head, 1)->data, 1);
  ASSERT_EQ(kth_from_end(head, 2)->data, 2);
  ASSERT_EQ(kth_from_end(head, 3)->data, 3);
  ASSERT_EQ(kth_from_end(head, 4)->data, 4);
  ASSERT_EQ(kth_from_end(head, 5)->data, 4);
}

#include "remove_all_values.cpp"
void TEST_RemoveAllValues() {
  node* head = nullptr;
  head = insert(head, 4);
  head = remove_values(head, 4);
  ASSERT(head ==  nullptr);
  head = insert(head, 4);
  head = insert(head, 3);
  head = remove_values(head, 3);
  ASSERT(find(head, 3) ==  nullptr);
  ASSERT_EQ(head->data, 4);
  head = insert(head, 3);
  head = insert(head, 2);
  head = insert(head, 3);
  head = insert(head, 3);
  head = insert(head, 1);
  head = insert(head, 0);
  head = insert(head, 3);
  head = insert(head, 3);
  head = insert(head, 3);
  head = remove_values(head, 3);
  ASSERT(find(head, 3) ==  nullptr);
  ASSERT_EQ(find(head, 4)->data, 4);
  ASSERT_EQ(find(head, 2)->data, 2);
  ASSERT_EQ(find(head, 1)->data, 1);
  ASSERT_EQ(find(head, 0)->data, 0);
}

#include "reverse_ll.cpp"
void TEST_ReverseLl() {
  node* head = nullptr;
  head = reverse(head);
  ASSERT(head ==  nullptr);
  head = insert(head, 4);
  head = reverse(head);
  ASSERT_EQ(head->data, 4);
  head = insert(head, 3);
  head = reverse(head);
  ASSERT_EQ(head->data, 4);
  head = reverse(head);
  ASSERT_EQ(head->data, 3);
  head = insert(head, 2);
  head = insert(head, 1);
  head = insert(head, 0);
  head = reverse(head);
  ASSERT_EQ(head->data, 4);
  ASSERT_EQ(head->next->data, 3);
  ASSERT_EQ(head->next->next->data, 2);
  ASSERT_EQ(head->next->next->next->data, 1);
  ASSERT_EQ(head->next->next->next->next->data, 0);
}

#include "reverse_dll.cpp"
void TEST_ReverseDLL() {
  dll_node* head = nullptr;
  head = reverse(head);
  ASSERT(head ==  nullptr);
  head = insert(head, 4);
  head = reverse(head);
  ASSERT_EQ(head->data, 4);
  head = insert(head, 3);
  head = reverse(head);
  ASSERT_EQ(head->data, 4);
  head = reverse(head);
  ASSERT_EQ(head->data, 3);
  head = insert(head, 2);
  head = insert(head, 1);
  head = insert(head, 0);
  head = reverse(head);
  ASSERT_EQ(head->data, 4);
  ASSERT_EQ(head->next->data, 3);
  ASSERT_EQ(head->next->next->data, 2);
  ASSERT_EQ(head->next->next->next->data, 1);
  ASSERT_EQ(head->next->next->next->next->data, 0);
}

#include "compare.cpp"
void TEST_Compare() {
  node* head = nullptr;
  node* head2 = nullptr;
  ASSERT(equals(head, head2));
  head = insert(head, 4);
  ASSERT(!equals(head, head2));
  head2 = insert(head2, 4);
  ASSERT(equals(head, head2));
  head = insert(head, 3);
  ASSERT(!equals(head, head2));
  head2 = insert(head2, 3);
  head = insert(head, 2);
  ASSERT(!equals(head, head2));
  head2 = insert(head2, 2);
  ASSERT(equals(head, head2));
  head = insert(head, 1);
  ASSERT(!equals(head, head2));
  head2 = insert(head2, 1);
  ASSERT(equals(head, head2));
  head = insert(head, 0);
  ASSERT(!equals(head, head2));
  head2 = insert(head2, 0);
  ASSERT(equals(head, head2));
  head = reverse(head);
  ASSERT(!equals(head, head2));
}

#include "merge_ll.cpp"
void TEST_Merge() {
  node* head = nullptr;
  node* head2 = nullptr;
  ASSERT(merge(head, head2) == nullptr);
  head = insert(head, 4);
  ASSERT_EQ(merge(head, head2), head);
  ASSERT_EQ(merge(head2, head), head);
  head2 = insert(head2, 4);
  head = insert(head, 3);
  head2 = insert(head2, 3);
  head = insert(head, 2);
  head2 = insert(head2, 2);
  head = insert(head, 1);
  head2 = insert(head2, 1);
  head = insert(head, 0);
  head2 = insert(head2, 0);
  node* merged = merge(head, head2);
  ASSERT_EQ(merged, head);
  ASSERT_EQ(find(merged, 0)->data, 0);
  ASSERT_EQ(find(find(merged, 0)->next, 0)->data, 0);
  ASSERT_EQ(find(merged, 2)->data, 2);
  ASSERT_EQ(find(find(merged, 2)->next, 2)->data, 2);
  ASSERT_EQ(find(merged, 4)->data, 4);
  ASSERT_EQ(find(find(merged, 4)->next, 4)->data, 4);
}

#include "is_list_palindrome.cpp"
void TEST_DllPalindrom() {
  dll_node* head = nullptr;
  ASSERT(is_palindrome(head));
  head = insert(head, 4);
  ASSERT(is_palindrome(head));
  head = insert(head, 3);
  ASSERT(!is_palindrome(head));
  head = insert(head, 2);
  head = insert(head, 1);
  head = insert(head, 0);
  ASSERT(!is_palindrome(head));
  head = insert(head, 1);
  head = insert(head, 2);
  head = insert(head, 3);
  head = insert(head, 4);
  ASSERT(is_palindrome(head));

  dll_node* head2 = nullptr;
  ASSERT(is_palindrome(head2));
  head2 = insert(head2, 4);
  ASSERT(is_palindrome(head2));
  head2 = insert(head2, 3);
  ASSERT(!is_palindrome(head2));
  head2 = insert(head2, 2);
  head2 = insert(head2, 1);
  head2 = insert(head2, 0);
  head2 = insert(head2, 0);
  ASSERT(!is_palindrome(head2));
  head2 = insert(head2, 1);
  head2 = insert(head2, 2);
  head2 = insert(head2, 3);
  head2 = insert(head2, 4);
  ASSERT(is_palindrome(head2));
}

#include <stack>
#include "is_list_palindrome_stack.cpp"
void TEST_Palindrome() {
  node* head = nullptr;
  ASSERT(is_palindrome(head));
  head = insert(head, 4);
  ASSERT(is_palindrome(head));
  head = insert(head, 3);
  ASSERT(!is_palindrome(head));
  head = insert(head, 2);
  head = insert(head, 1);
  head = insert(head, 0);
  ASSERT(!is_palindrome(head));
  head = insert(head, 1);
  head = insert(head, 2);
  head = insert(head, 3);
  head = insert(head, 4);
  ASSERT(is_palindrome(head));

  node* head2 = nullptr;
  ASSERT(is_palindrome(head2));
  head2 = insert(head2, 4);
  ASSERT(is_palindrome(head2));
  head2 = insert(head2, 3);
  ASSERT(!is_palindrome(head2));
  head2 = insert(head2, 2);
  head2 = insert(head2, 1);
  head2 = insert(head2, 0);
  head2 = insert(head2, 0);
  ASSERT(!is_palindrome(head2));
  head2 = insert(head2, 1);
  head2 = insert(head2, 2);
  head2 = insert(head2, 3);
  head2 = insert(head2, 4);
  ASSERT(is_palindrome(head2));
}

#include "find_loop.cpp"
void TEST_FindLoop() {
  node* head = nullptr;
  ASSERT(!detect_loop(head));
  head = insert(head, 4);
  ASSERT(!detect_loop(head));
  head = insert(head, 3);
  ASSERT(!detect_loop(head));
  head = insert(head, 2);
  head = insert(head, 1);
  head = insert(head, 0);
  ASSERT(!detect_loop(head));
  node* temp = head->next;
  head->next = head;
  ASSERT(detect_loop(head));
  head->next = temp;

  temp = head->next->next;
  head->next->next = head;
  ASSERT(detect_loop(head));
  head->next->next = temp;

  temp = head->next->next->next;
  head->next->next->next= head->next;
  ASSERT(detect_loop(head));
  head->next->next->next= temp;
}


int main(int argc, char** argv) {
  CALL(TEST_Construction);
  CALL(TEST_Insertion);
  CALL(TEST_SortedInsertion);
  CALL(TEST_Find);
  CALL(TEST_Remove);
  CALL(TEST_CircularInsertion);
  CALL(TEST_CircularFind);
  CALL(TEST_CircularRemove);

  CALL(TEST_DllConstruction);
  CALL(TEST_DllInsertion);
  CALL(TEST_DllFind);
  CALL(TEST_DllRemove);

  CALL(TEST_Selection);
  CALL(TEST_RemoveAllValues);
  CALL(TEST_ReverseLl);
  CALL(TEST_ReverseLl);
  CALL(TEST_Compare);
  CALL(TEST_Merge);
  CALL(TEST_DllPalindrom);
  CALL(TEST_Palindrome);
  CALL(TEST_FindLoop);
  return 0;
}
