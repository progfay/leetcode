class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        int size1 = size(word1);
        int size2 = size(word2);
        if (size1 != size2)
            return false;

        std::vector<int> list1(26, 0);
        std::vector<int> list2(26, 0);

        for (int i = 0; i < size1; i++)
        {
            list1[int(word1[i]) - int('a')]++;
            list2[int(word2[i]) - int('a')]++;
        }

        for (int i = 0; i < list1.size(); i++)
        {
            if (list1[i] == 0 && list2[i] != 0)
                return false;
            if (list2[i] == 0 && list1[i] != 0)
                return false;
        }

        std::sort(list1.begin(), list1.end());
        std::sort(list2.begin(), list2.end());

        for (int i = 0; i < list1.size(); i++)
        {
            if (list1[i] != list2[i])
                return false;
        }

        return true;
    }
};
