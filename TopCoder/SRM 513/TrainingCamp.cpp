#include <string>
#include <vector>

using namespace std;

class TrainingCamp
{
  public:
    vector<string> determineSolvers(vector<string> attendance, vector<string> problemTopics)
    {
        vector<string> res;
        string temp;
        bool solve;
        for (auto i : attendance)
        {
            temp.clear();
            for (auto j : problemTopics)
            {
                solve = true;
                for (int k = 0; k < i.size(); k++)
                    solve = solve && (j[k] == '-' || i[k] == j[k]);
                if (solve)
                    temp += 'X';
                else
                    temp += '-';
            }
            res.push_back(temp);
        }
        return res;
    }
};