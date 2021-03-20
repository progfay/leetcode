#include <string>
#include <vector>

using namespace std;

class UndergroundSystem
{
private:
  vector<pair<string, int>> checkinList;
  vector<pair<pair<string, string>, int>> travels;

public:
  UndergroundSystem()
  {
    checkinList = vector<pair<string, int>>(1000001);
    travels = vector<pair<pair<string, string>, int>>(0);
  }

  void checkIn(int id, string stationName, int t)
  {
    checkinList[id] = make_pair(stationName, t);
  }

  void checkOut(int id, string stationName, int t)
  {
    auto checkin = checkinList[id];
    travels.push_back(make_pair(make_pair(checkin.first, stationName), t - checkin.second));
  }

  double getAverageTime(string startStation, string endStation)
  {
    double sum = 0;
    int count = 0;

    for (auto travel : travels)
    {
      if (travel.first.first == startStation && travel.first.second == endStation)
      {
        count++;
        sum += travel.second;
      }
    }

    return sum / count;
  }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */