/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

#include <cstddef>
#include <unordered_map>

using namespace std;

class Node
{
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val)
  {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution
{
private:
  unordered_map<Node *, Node *> m;

public:
  Node *copyRandomList(Node *head)
  {
    if (!head)
    {
      return nullptr;
    }

    if (!m[head])
    {
      m[head] = new Node(head->val);
      m[head]->next = copyRandomList(head->next);
      m[head]->random = copyRandomList(head->random);
    }

    return m[head];
  }
};