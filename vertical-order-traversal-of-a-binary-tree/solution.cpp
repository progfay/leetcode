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

#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ValueType
{
  int y;
  int val;
  ValueType() : y(0), val(0) {}
  ValueType(int y, int val) : y(y), val(val) {}
  bool operator<(const ValueType &right) const
  {
    return y != right.y ? y < right.y : val < right.val;
  }
};

class Solution
{
public:
  vector<vector<int>> verticalTraversal(TreeNode *root)
  {
    vector<vector<ValueType>> positive(0, vector<ValueType>(0));
    vector<vector<ValueType>> negative(0, vector<ValueType>(0));
    visit(root, 0, 0, &positive, &negative);

    reverse(negative.begin(), negative.end());
    negative.insert(negative.end(), positive.begin(), positive.end());
    vector<vector<int>> ans(negative.size(), vector<int>(0));

    for (int i = 0; i < ans.size(); i++)
    {
      vector<ValueType> values = negative.at(i);
      sort(values.begin(), values.end());
      for (ValueType v : values)
      {
        ans.at(i).push_back(v.val);
      }
    }

    return ans;
  }

private:
  void visit(TreeNode *node, int x, int y, vector<vector<ValueType>> *positive, vector<vector<ValueType>> *negative)
  {
    if (node == nullptr)
    {
      return;
    }

    if (x >= 0)
    {
      int s = (*positive).size();
      if (s <= x)
      {
        for (int i = 0; i < x - s + 1; i++)
        {
          (*positive).emplace_back(0);
        }
      }
      (*positive).at(x).push_back(ValueType(y, (*node).val));
    }
    else
    {
      int s = (*negative).size();
      int _x = -x - 1;
      if (s <= _x)
      {
        for (int i = 0; i < _x - s + 1; i++)
        {
          (*negative).emplace_back(0);
        }
      }
      (*negative).at(_x).push_back(ValueType(y, (*node).val));
    }

    visit((*node).left, x - 1, y + 1, positive, negative);
    visit((*node).right, x + 1, y + 1, positive, negative);
  }
};