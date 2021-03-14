#include <algorithm>

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
  ListNode *swapNodes(ListNode *head, int k)
  {
    ListNode *node1 = head, *node2 = head, *kth = nullptr;
    while(--k)
      node1 = node1->next;

    kth = node1;
    node1 = node1->next;

    while (node1)
    {
      node1 = node1->next;
      node2 = node2->next;
    }

    swap(node2->val, kth->val);
    return head;
  }
};