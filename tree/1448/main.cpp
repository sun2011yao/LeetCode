//
// Created by yao on 2021/9/11.
//
#include <algorithm>
#include <iostream>
#include <vector>
#include <assert.h>
template<typename T>
struct TreeNode {
  T m_val;
  TreeNode* left = nullptr;
  TreeNode* right = nullptr;
  TreeNode(T val) {
    m_val = val;
    left = nullptr;
    right = nullptr;
  }
  ~TreeNode() { }
};
void DFS(TreeNode<int>* root, int max_value, int &good_nodes_count) {
  if (root == nullptr) {
    return;
  }
  if (root->m_val >= max_value) {
    good_nodes_count++;
    max_value = root->m_val;
  }
  DFS(root->left, max_value, good_nodes_count);
  DFS(root->right, max_value, good_nodes_count);
}
int GoodNodes(TreeNode<int>* root) {
  int result = 0;
  DFS(root, INT32_MIN, result);
  return result;
}
int main(int argc, char** argv) {
  auto* root = new TreeNode<int>(3);
  auto* l1 = new TreeNode<int>(1);
  auto* l2 = new TreeNode<int>(3);
  auto* r1 = new TreeNode<int>(4);
  auto* rl1 = new TreeNode<int>(1);
  auto* rl2 = new TreeNode<int>(5);
  root->left = l1;
  l1->left = l2;
  root->right = r1;
  r1->left = rl1;
  r1->right = rl2;
  assert(4 == GoodNodes(root));
  return 0;
}

