node* reconstruct_tree(
    const std::vector<int>& inorder,
    const std::vector<int>& preorder) {
  auto root = new node(preorder[0]);
  size_t pos = std::find(inorder.begin(),
                         inorder.end(),
                         root->value)
               - inorder.begin();
  if (0 != pos) {
    std::vector<int> left_inorder(
      inorder.begin(),
      inorder.begin() + pos);
    std::vector<int> left_preorder(
      preorder.begin() + 1,
      preorder.begin() + 1 + left_inorder.size());
    root->left = reconstruct_tree(left_inorder,
                                  left_preorder);
  }
  if (pos != (inorder.size()-1)) {
    std::vector<int> right_inorder(
      inorder.begin() + pos + 1,
      inorder.end());
    std::vector<int> right_preorder(
      preorder.begin()
        + (preorder.size() - right_inorder.size()),
      preorder.end());
    root->right = reconstruct_tree(right_inorder,
                                   right_preorder);
  }
  return root;
}