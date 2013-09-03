bool related(const GeneologicalData& data,
             Person id1,
             Person id2) {
  Ancestry ancestry1;
  find_ancestry(data, id1, &ancestry1);
  Ancestry ancestry2;
  find_ancestry(data, id2, &ancestry2);
  Ancestry intersection;
  std::set_intersection(
    ancestry1.begin(),
    ancestry1.end(),
    ancestry2.begin(),
    ancestry2.end(),
    std::inserter(intersection,
                  intersection.begin()));
  return !intersection.empty();
}