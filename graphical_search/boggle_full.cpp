void boggle(
    const GameBoard& board,
    std::set<std::string>* words) {
  for (size_t row = 0;
       row < board.size();
       ++row) {
    for (size_t col = 0;
         col < board[row].size();
         ++col) {
      boggle(board, {row, col}, words);
    }
  }
}