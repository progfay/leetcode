#include <string>
#include <map>

using namespace std;

class Solution
{
private:
  map<string, string> m;

public:
  // Encodes a URL to a shortened URL.
  string encode(string longUrl)
  {
    string key = to_string(rand());
    m[key] = longUrl;
    return key;
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl)
  {
    return m[shortUrl];
  }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));