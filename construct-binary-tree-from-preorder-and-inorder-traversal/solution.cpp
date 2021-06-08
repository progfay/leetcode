#include <vector>
#include <unordered_map>

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
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
  {
    return _buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
  }

private:
  TreeNode *_buildTree(vector<int> &preorder, int s, int e, vector<int> &inorder, int start, int end)
  {
    if (start > end)
      return nullptr;

    int x = start;
    for (; x < end; x++)
      if (inorder[x] == preorder[s])
        break;

    int l = x - start;
    int r = end - x;
    TreeNode *root = new TreeNode(preorder[s]);
    root->left = _buildTree(preorder, s + 1, s + l, inorder, start, x - 1);
    root->right = _buildTree(preorder, s + l + 1, e, inorder, x + 1, end);
    return root;
  }
};