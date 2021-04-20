#include <vector>
#include <stack>

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
public:
  vector<int> preorder(Node *root)
  {
    vector<int> ans(0, 0);
    if (!root)
      return ans;

    stack<Node *> s;
    s.push(root);

    while (!s.empty())
    {
      auto node = s.top();
      s.pop();
      ans.push_back(node->val);
      for (auto it = node->children.rbegin(); it != node->children.rend(); it++)
        s.push(*it);
    }

    return ans;
  }
};