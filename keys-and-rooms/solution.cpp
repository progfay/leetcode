#include <vector>
#include <bitset>
#include <queue>

using namespace std;

class Solution
{
public:
  bool canVisitAllRooms(vector<vector<int>> &rooms)
  {
    bitset<1000> visited;
    queue<int> q;
    q.push(0);

    while (!q.empty())
    {
      int room = q.front();
      q.pop();
      if (visited.test(room))
        continue;

      visited.set(room);
      for (int key : rooms[room])
      {
        q.push(key);
      }
    }

    return visited.count() == rooms.size();
  }
};