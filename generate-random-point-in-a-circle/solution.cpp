#include <vector>

using namespace std;

class Solution
{
public:
  Solution(double radius, double x_center, double y_center) : x_center(x_center), y_center(y_center), radius(radius) {}

  vector<double> randPoint()
  {
    double x, y;
    x = (double)rand() / RAND_MAX * (radius + radius) - radius;
    y = (double)rand() / RAND_MAX * (radius + radius) - radius;
    if (x * x + y * y <= radius * radius)
      return {x + x_center, y + y_center};
    return randPoint();
  }

private:
  double x_center;
  double y_center;
  double radius;
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> para1 = obj->randPoint();
 */