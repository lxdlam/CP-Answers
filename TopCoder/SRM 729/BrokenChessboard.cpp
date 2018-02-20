#include <bits/stdc++.h>

using namespace std;

class BrokenChessboard
{
  private:
    // Constants
    vector<string> board;
    const static int SIZE = 50 + 10;
    int n, m;
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool vis[SIZE][SIZE] = {{false}};

    // Useful Inner Method
    bool check(int i, int j)
    {
        if (i < 0 || i >= n)
            return false;
        if (j < 0 || j >= m)
            return false;
        return !vis[i][j];
    }

    int dfs(int i, int j, int s /* if B */)
    {
        int res = 0;
        if (!check(i, j))
            return 0;
        vis[i][j] = true;
        if (s && board[i][j] == 'W')
            res++;
        else if (!s && board[i][j] == 'B')
            res++;
        for (int k = 0; k < 4; k++)
            res += dfs(i + dir[k][0], j + dir[k][1], !s);
        return res;
    }

    // Builder
    void build()
    {
    }

    // Solver
  public:
    int minimumFixes(vector<string> _board)
    {
        build();

        for (int i = 0; i < _board.size(); i++)
            board.emplace_back(_board[i]);
        n = _board.size();
        m = board[0].size();
        int res = dfs(0, 0, 0);
        memset(vis, false, sizeof(vis));
        res = min(res, dfs(0, 0, 1));

        return res;
    }
};

// CUT begin
ifstream datas("BrokenChessboard.sample");

string next_line()
{
    string s;
    getline(datas, s);
    return s;
}

template <typename T>
void from_stream(T &t)
{
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s)
{
    s = next_line();
}

template <typename T>
void from_stream(vector<T> &ts)
{
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i)
    {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t)
{
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t)
{
    return "\"" + t + "\"";
}

bool do_test(vector<string> board, int __expected)
{
    time_t startClock = clock();
    BrokenChessboard *instance = new BrokenChessboard();
    int __result = instance->minimumFixes(board);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected)
    {
        cout << "PASSED!"
             << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else
    {
        cout << "FAILED!"
             << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command)
{
    int cases = 0, passed = 0;
    while (true)
    {
        if (next_line().find("--") != 0)
            break;
        vector<string> board;
        from_stream(board);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if (do_test(board, __answer))
        {
            passed++;
        }
    }
    if (mainProcess)
    {
        cout << endl
             << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1519138512;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i)
    {
        if (string(argv[i]) == "-")
        {
            mainProcess = false;
        }
        else
        {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess)
    {
        cout << "BrokenChessboard (250 Points)" << endl
             << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
