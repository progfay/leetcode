/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <vector>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  vector<int> rightSideView(TreeNode *root)
  {
    vector<int> view;
    visit(root, 0, &view);
    return view;
  }

private:
  void visit(TreeNode *node, int y, vector<int> *view)
  {
    if (node == nullptr)
    {
      return;
    }

    if (view->size() <= y)
    {
      view->push_back(node->val);
    }
    else
    {
      view->at(y) = node->val;
    }

    visit(node->left, y + 1, view);
    visit(node->right, y + 1, view);
  }
};