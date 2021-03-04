#include <cstddef>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
  {
    ListNode *ans = NULL;
    ListNode *cursor = headA;

    while (cursor != NULL)
    {
      cursor->val *= -1;
      cursor = cursor->next;
    }

    cursor = headB;
    while (cursor)
    {
      if (cursor->val < 0)
      {
        ans = cursor;
        break;
      }
      cursor = cursor->next;
    }

    cursor = headA;
    while (cursor)
    {
      cursor->val *= -1;
      cursor = cursor->next;
    }

    return ans;
  }
};