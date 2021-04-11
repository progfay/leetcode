#include <queue>

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
  int deepestLeavesSum(TreeNode *root)
  {
    if (root == nullptr)
      return 0;

    queue<pair<TreeNode *, int>> q;
    q.push(make_pair(root, 0));

    int sum = 0;
    int depth = 0;
    while (!q.empty())
    {
      auto entry = q.front();
      q.pop();

      if (entry.second != depth)
      {
        depth = entry.second;
        sum = 0;
      }

      sum += entry.first->val;

      if (entry.first->left != nullptr)
        q.push(make_pair(entry.first->left, entry.second + 1));

      if (entry.first->right != nullptr)
        q.push(make_pair(entry.first->right, entry.second + 1));
    }

    return sum;
  }
};