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
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    auto *node = head;
    int size = 0;
    while (node) {
      size++;
      node = node->next;
    }

    if (size == n)
      return head->next;

    node = head;
    for (int i = 0; i < size - n - 1; i++)
      node = node->next;

    node->next = node->next ? node->next->next : nullptr;

    return head;
  }
};