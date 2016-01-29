#include <iostream>
#include <vector>
#include <set>

//search from border to see what element can be found, the left can be changed

using namespace std;

class Solution {
public:
    void solve(vector<vector<char> > &board){
        int x = board.size();
        if (x <= 2)
            return;
        int y = board[0].size();
        if (y <= 2)
            return;
        vector<int> id;
        vector<bool> marked;
        marked.resize(x*y);
        fill(marked.begin(), marked.end(), false);
        vector<int> sz;
        sz.resize(x*y);
        fill(sz.begin(), sz.end(), 1);
        for (int i = 0; i < x*y; i++)
            id.push_back(i);
        for (int i = 0; i < x-1; i++)
        {
            for (int j = 0; j < y-1; j++)
            {
                int current = i*y+j;
                if (board[i][j] == 'O')
                {
                    int right = i*y+j+1;
                    int down = (i+1)*y+j;
                    if (board[i][j+1] == 'O')
                        unionx(current, right, id, sz);
                    if (board[i+1][j] == 'O')
                        unionx(current, down, id, sz);
                }

            }
        }
        set<int> ruleout;
        for (int i = 0; i < x; i++)
        {
            if (board[i][0] == 'O')
            {
                ruleout.insert(id[i*y]);
            }
            if (board[i][y-1] == 'O')
            {
                ruleout.insert(id[i*y+y-1]);
            }
        }
        for (int i = 1; i < y-1; i++)
        {
            if (board[0][i] == 'O')
            {
                ruleout.insert(id[i]);
            }
            if (board[x-1][i] == 'O')
            {
                ruleout.insert(id[y*(x-1)+i]);
            }
        }
        for (auto &x : ruleout)
            cout << x << " ";
        cout << endl;
        for (int i = 1; i < x-1; i++)
        {
            for (int j = 1; j < y-1; j++)
            {
                int m = i*y+j;
                if (board[i][j] == 'O')
                {
                    int id_m = id[m];
                    cout << id_m << endl;
                    if (ruleout.find(id_m) == ruleout.end())
                        board[i][j] = 'X';
                }
            }
        }
    }

    int findx(int p, vector<int> id)
    {
        while (p != id[p])
            p = id[p];
        return p;
    }

    void unionx(int p, int q, vector<int> &id, vector<int> &sz)
    {
        int i = findx(p, id);
        int j = findx(q, id);
        if (i == j)
            return;
        if (sz[i] < sz[j])
        {
            id[i] = j;
            sz[j] += sz[i];
        }
        else
        {
            id[j] = i;
            sz[i] += sz[j];
        }
        return;
    }
};

int main()
{
    vector<vector<char> > board;
    vector<char> x1 = {'O', 'O', 'O', 'O', 'X', 'X'};
    vector<char> x2 = {'O', 'O', 'O', 'O', 'O', 'O'};
    vector<char> x3 = {'O', 'X', 'O', 'X', 'O', 'O'};
    vector<char> x4 = {'O', 'X', 'O', 'O', 'X', 'O'};
    vector<char> x5 = {'O', 'X', 'O', 'X', 'O', 'O'};
    vector<char> x6 = {'O', 'X', 'O', 'O', 'O', 'O'};
    //vector<char> x1 = {};
    board.push_back(x1);
    board.push_back(x2);
    board.push_back(x3);
    board.push_back(x4);
    board.push_back(x5);
    board.push_back(x6);
    //vector<char> x6 = {'O', 'X', 'O', 'O', 'O', 'O'};
    //vector<char> x1 = {};
//    board.push_back(x1);
//    board.push_back(x2);
//    board.push_back(x3);
//    board.push_back(x4);
//    board.push_back(x5);
    //board.push_back(x6);
    Solution solution;
    solution.solve(board);
    for (auto x = board.begin(); x != board.end(); x++)
    {
        for (auto y = (*x).begin(); y != (*x).end(); y++)
        {
            cout << *y << " ";
        }
        cout << endl;
    }
    return 0;
}
