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
    int minCameraCover(TreeNode *root)
    {
        int ans = 0;
        if (dfs(root, ans) == 1)
            ans++;
        return ans;
    }

private:
    int dfs(TreeNode *node, int &count)
    {
        if (!node)
            return 0;

        int left = dfs(node->left, count);
        int right = dfs(node->right, count);

        if (left == 1 || right == 1)
        {
            count++;
            return -1;
        }

        return left == -1 || right == -1 ? 0 : 1;
    }
};