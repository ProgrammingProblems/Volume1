size_t pivot(int* array, size_t size, size_t pos) {
  if (size <= 1) return 0 ; // Nothing to do.
  std::swap(array[0], array[pos]);
  int* current = array;  // Move the pivot to the leftmost position.
  int* right = array + size - 1;  // Scan from the right.
  while (right > current) {
    // If the rightmost element is on the correct side, slide left.
    if (*right >= *current) --right;
    else {  // The right element needs to move to the left of pivot.
      swap(*current, *right);
      // We need to move the pivot back to the leftmost element
      // for which we haven't compared against pivot.
      ++current;
      swap(*current, *right);
    }
  }
  return current - array;
}