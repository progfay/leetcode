#include <vector>

using namespace std;

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
  vector<int> flipMatchVoyage(TreeNode *root, vector<int> &voyage)
  {
    vector<int> ans(0);
    int cursor = 0;
    bool impossible = visit(root, voyage, ans, cursor);
    return impossible ? vector<int>(1, -1) : ans;
  }

  bool visit(TreeNode *root, vector<int> &voyage, vector<int> &ans, int &cursor)
  {
    if (root)
    {
      int val = voyage[cursor++];
      if (root->val != val)
        return true;
      if (root->left && root->right && root->right->val == voyage[cursor])
      {
        swap(root->left, root->right);
        ans.push_back(root->val);
      }
      if (visit(root->left, voyage, ans, cursor))
        return true;
      if (visit(root->right, voyage, ans, cursor))
        return true;
    }
    return false;
  }
};