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

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  bool isPalindrome(ListNode *head)
  {
    auto node = head;

    int length = 0;
    while (node != nullptr)
    {
      length++;
      node = node->next;
    }

    if (length == 0)
      return true;

    ListNode *left = nullptr, *right = head;
    for (int i = 0; i < length / 2; i++)
    {
      auto tmp = right->next;
      right->next = left;
      left = right;
      right = tmp;
    }

    if (length % 2 == 1)
      right = right->next;

    while (left != nullptr && right != nullptr)
    {
      if (left->val != right->val)
        return false;

      left = left->next;
      right = right->next;
    }

    return left == right;
  }
};