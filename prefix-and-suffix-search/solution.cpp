#include <string>
#include <vector>
#include <map>

using namespace std;

class WordFilter
{
private:
    map<string, int> m;

public:
    WordFilter(vector<string> &words)
    {
        for (int i = 0; i < words.size(); i++)
        {
            string word = words[i];
            for (int j = 0; j < word.length(); j++)
            {
                string prefix = word.substr(0, j + 1);
                for (int k = 0; k < word.length(); k++)
                {
                    string suffix = word.substr(k);
                    m[prefix + "#" + suffix] = i;
                }
            }
        }
    }

    int f(string prefix, string suffix)
    {
        auto it = m.find(prefix + "#" + suffix);
        return it != m.end() ? (*it).second : -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */