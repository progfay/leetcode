#include <vector>

using namespace std;

// Definition for a Node.
class Node
{
public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val)
  {
    val = _val;
  }

  Node(int _val, vector<Node *> _children)
  {
    val = _val;
    children = _children;
  }
};

class Solution
{
private:
  vector<int> ans;

public:
  vector<int> preorder(Node *root)
  {
    ans = vector<int>();
    visit(root);
    return ans;
  }

private:
  void visit(Node *node)
  {
    if (!node)
      return;

    ans.push_back(node->val);
    for (auto child : node->children)
      visit(child);
  }
};