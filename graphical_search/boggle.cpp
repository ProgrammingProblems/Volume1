void boggle(
    const GameBoard& board,
    const Position& pos,
    std::set<std::string>* words) {
  static const std::vector<size_t> offsets =
    {-1, 0, 1};
  std::set<std::pair<size_t, size_t>> visited;
  std::string word;
  std::function<void(Position)> boggle_dfs =
    [&] (Position pos) {
    for (auto row_offset: offsets) {
      for (auto col_offset: offsets) {
        Position next_pos =
          {pos.first + row_offset,
           pos.second + col_offset};
        auto element = visited.find(next_pos);
        if (next_pos.first < board.size()
            && next_pos.second
                  < board[next_pos.first].size()
            && visited.end() == element) {
          visited.insert(next_pos);
          word +=
            board[next_pos.first][next_pos.second];
          if (isword(word)) {
            words->insert(word);
          }
          boggle_dfs(next_pos);
          visited.erase(visited.find(next_pos));
          word.resize(word.length() - 1);
        }
      }
    }
  };
  boggle_dfs(pos);
}