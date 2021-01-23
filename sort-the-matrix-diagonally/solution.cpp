#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        int columnLength = mat.size();
        int rowLength = mat.at(0).size();
        vector<vector<int>> sorted(columnLength, vector<int>(rowLength, 0));

        for (int i = 1 - rowLength; i < columnLength; i++)
        {
            vector<int> diagonal;
            for (int j = 0; j < rowLength; j++)
            {
                if (i + j < 0)
                    continue;

                if (columnLength <= i + j)
                    break;

                diagonal.push_back(mat.at(i + j).at(j));
            }

            sort(diagonal.begin(), diagonal.end());

            int cursor = 0;
            for (int j = 0; j < rowLength; j++)
            {
                if (i + j < 0)
                    continue;

                if (columnLength <= i + j)
                    break;

                sorted[i + j][j] = diagonal.at(cursor++);
            }
        }
        return sorted;
    }
};
