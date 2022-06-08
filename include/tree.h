// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <vector>
#include <string>
class Tree {
 private:
  struct Node {
    char znach;
    std::vector<Node*> sheet;
  };
  Node* root;
  std::vector<std::string> permutation;
  void constructTree(Node* root, std::vector<char> figyra) {
    if (!figyra.size()) {
      return;
    }
    if (root->znach != '*') {
      for (auto x = figyra.begin(); x != figyra.end(); ++x) {
        if (*x == root->znach) {
          figyra.erase(x);
          break;
        }
      }
    }
    for (size_t i = 0; i < figyra.size(); ++i) {
      root->sheet.push_back(new Node);
    }
    for (size_t i = 0; i < root->sheet.size(); ++i) {
      root->sheet[i]->znach = figyra[i];
    }
    for (size_t i = 0; i < root->sheet.size(); ++i) {
      constructTree(root->sheet[i], figyra);
    }
  }
  void Permutation(Node*root, std::string s = "") {
    if (!root->sheet.size()) {
      s += root->znach;
      permutation.push_back(s);
      return;
    }
    if (root->znach != '*') {
      s += root->znach;
    }
    for (size_t i = 0; i < root->sheet.size(); ++i) {
      Permutation(root->sheet[i], s);
    }
  }
 
 public:
  explicit Tree(std::vector<char> v) {
    root = new Node;
    root->znach = '*';
    constructTree(root, v);
    Permutation(root);
  }
  std::string operator[](int i) const {
    if (i >= permutation.size()) {
      return "";
    }
    return permutation[i];
  }
};
#endif  // INCLUDE_TREE_H_
