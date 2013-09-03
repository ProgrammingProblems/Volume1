size_t largest_area(const Histogram& histogram) {
  size_t max_area = 0;
  int current_pos = 0;
  std::stack<HistogramEntry> open_entries;
  for (auto& entry : histogram) {
    current_pos = entry.x;
    int last_closed_pos = entry.x;
    while (!open_entries.empty()
           && open_entries.top().y >= entry.y) {
      HistogramEntry top = open_entries.top();
      open_entries.pop();
      last_closed_pos = top.x;
      size_t area = top.y
                    * ((current_pos - 1)
                       - (top.x - 1));
      max_area = std::max(max_area, area);
    }
    open_entries.push({last_closed_pos, entry.y});
  }
  ++current_pos;
  while (!open_entries.empty()) {
    HistogramEntry top = open_entries.top();
    open_entries.pop();
    size_t area = top.y
                  * ((current_pos - 1)
                     - (top.x - 1));
    max_area = std::max(max_area, area);
  }
  return max_area;
}