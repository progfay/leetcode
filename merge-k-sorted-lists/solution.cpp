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

#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    int k = lists.size();
    if (k == 0)
    {
      return nullptr;
    }

    ListNode *accumulator = lists.at(0);

    for (int i = 1; i < k; i++)
    {
      ListNode *left = accumulator;
      ListNode *right = lists.at(i);
      if (left == nullptr)
      {
        accumulator = right;
        continue;
      }
      if (right == nullptr)
      {
        accumulator = left;
        continue;
      }

      if ((*left).val > (*right).val)
      {
        swap(left, right);
      }
      ListNode *merged = left;
      accumulator = left;
      left = (*left).next;
      if (left == nullptr)
      {
        (*accumulator).next = right;
        continue;
      }

      while (true)
      {
        if ((*left).val <= (*right).val)
        {
          (*merged).next = left;
          merged = (*merged).next;
          left = (*left).next;
          if (left == nullptr)
          {
            (*merged).next = right;
            break;
          }
        }
        else
        {
          (*merged).next = right;
          merged = (*merged).next;
          right = (*right).next;
          if (right == nullptr)
          {
            (*merged).next = left;
            break;
          }
        }
      }
    }

    return accumulator;
  }
};
