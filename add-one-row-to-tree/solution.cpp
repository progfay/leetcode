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
  TreeNode *addOneRow(TreeNode *root, int v, int d)
  {
    if (d == 0)
    {
      return new TreeNode(v, root, nullptr);
    }

    queue<TreeNode *> q;
    q.push(root);
    int depth = 1;
    while (++depth < d)
    {
      int size = q.size();
      for (int i = 0; i < size; i++)
      {
        auto node = q.front();
        q.pop();
        if (node->left)
          q.push(node->left);

        if (node->right)
          q.push(node->right);
      }
    }

    while (!q.empty())
    {
      auto node = q.front();
      q.pop();
      node->left = new TreeNode(v, node->left, nullptr);
      node->right = new TreeNode(v, nullptr, node->right);
    }

    return root;
  }
};