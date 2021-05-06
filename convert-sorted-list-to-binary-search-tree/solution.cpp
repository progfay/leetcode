#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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
  TreeNode *sortedListToBST(ListNode *head)
  {
    if (!head)
      return nullptr;

    vector<int> nodes;
    auto listNode = head;
    while (listNode)
    {
      nodes.push_back(listNode->val);
      listNode = listNode->next;
    }

    return createTree(nodes, 0, nodes.size() - 1);
  }

private:
  TreeNode *createTree(vector<int> &nodes, int left, int right)
  {
    if (left == right)
      return new TreeNode(nodes[left]);

    if (right - left == 1)
      return new TreeNode(nodes[right], new TreeNode(nodes[left]), nullptr);

    int center = (left + right) / 2;
    return new TreeNode(nodes[center], createTree(nodes, left, center - 1), createTree(nodes, center + 1, right));
  }
};