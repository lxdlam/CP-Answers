#include <vector>
#include <string>
#include <sstream>

using namespace std;

class AzimuthMonitoring
{
  public:
    int getAzimuth(vector<string> instructions)
    {
        int res = 0;
        string a;
        int t;
        for (auto i : instructions)
        {
            if (i == "HALT")
                break;
            else if (i == "LEFT")
                res -= 90;
            else if (i == "RIGHT")
                res += 90;
            else if (i == "TURN AROUND")
                res += 180;
            else
            {
                stringstream ss(i);
                ss >> a >> t;
                if (a == "LEFT")
                    res -= t;
                else if (a == "RIGHT")
                    res += t;
            }

            if (res < 0)
                res += 360;
            else
                res %= 360;
        }
        return res;
    }
};