int select(std::vector<int>* array, size_t k) {
    sort(array->begin(),
         array->begin() + array->size());
    return array->at(k);
}