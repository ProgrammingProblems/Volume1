coordinate find(const matrix& m, const int key) {
  coordinate coord = {m.size() - 1, 0};
  while (coord.first < m.size()
         && coord.second < m[0].size()
         && m[coord.first][coord.second] != key) {
    if (m[coord.first][coord.second] > key) {
      coord.first--;
    } else {
      coord.second++;
    }
  }
  return coord;
}
