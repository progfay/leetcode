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
  vector<vector<int>> levelOrder(TreeNode *root)
  {
    vector<vector<int>> ans(0);
    dfs(root, ans, 0);

    return ans;
  }

private:
  void dfs(TreeNode *node, vector<vector<int>> &traversal, int depth)
  {
    if (node == nullptr)
      return;

    if (traversal.size() <= depth)
      traversal.push_back({node->val});
    else
      traversal[depth].push_back(node->val);

    dfs(node->left, traversal, depth + 1);
    dfs(node->right, traversal, depth + 1);
  }
};