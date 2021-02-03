/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <cstddef>

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
private:
  const int VISITED = 1e6 + 1;

public:
  bool hasCycle(ListNode *head)
  {
    if (head == NULL)
    {
      return false;
    }

    if (head->val == VISITED)
    {
      return true;
    }

    head->val = VISITED;
    return hasCycle(head->next);
  }
};