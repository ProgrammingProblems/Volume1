size_t min_pos(int* array, size_t len) {
  size_t retval = 0;
  for (size_t i = 1; i < len; ++i)
    if (array[i] < array[retval])
      retval = i;
  return retval;
}