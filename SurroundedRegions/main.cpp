#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>

//There is no unordered_set<pair<int, int> > type allowed
//The important thing is that finding a good way to search
//better to analyze before coding

using namespace std;

class Solution {
public:
    void solve(vector<vector<char> > &board) {
        int x = board.size();
        if (x <= 2)
            return;
        int y = board[0].size();
        if (y <= 2)
            return;
        vector<bool> marked;
        marked.resize(x*y);
        fill(marked.begin(), marked.end(), false);
        for (int i = 0; i < y; i++)
        {
            if (board[0][i] == 'O')
            {
                dfs(board, marked, 0, i, x, y);
            }
            if (board[x-1][i] == 'O')
            {
                dfs(board, marked, x-1, i, x, y);
            }
        }
        for (int i = 1; i < x-1; i++)
        {
            if (board[i][0] == 'O')
            {
                dfs(board, marked, i, 0, x, y);
            }
            if (board[i][y-1] == 'O')
            {
                dfs(board, marked, i, y-1, x, y);
            }
        }
        for (int i = 1; i < x-1; i++)
        {
            for (int j = 1; j < y-1; j++)
            {
                if (board[i][j] == 'O')
                    if (!marked[i*y+j])
                        board[i][j] = 'X';
            }
        }
    }

    void dfs(vector<vector<char> > &board, vector<bool> &marked, int i, int j, int x, int y)
    {
        vector<int> candi;
        candi.push_back(i*y+j);
        marked[i*y+j] = true;
        while(!candi.empty())
        {
            int m = candi.back();
            candi.pop_back();
            int p = m/y;
            int q = m%y;
            /*find valid neighbor*/
            if (q < y-1)
            {
                if (board[p][q+1] == 'O')
                {
                    if (!marked[m+1])
                    {
                        marked[m+1] = true;
                        candi.push_back(m+1);
                    }
                }
            }
            if (q > 0)
            {
                if (board[p][q-1] == 'O')
                {
                    if (!marked[m-1])
                    {
                        marked[m-1] = true;
                        candi.push_back(m-1);
                    }
                }
            }
            if (p < x-1)
            {
                if (board[p+1][q] == 'O')
                {
                    if (!marked[m+y])
                    {
                        marked[m+y] = true;
                        candi.push_back(m+y);
                    }
                }
            }
            if (p > 0)
            {
                if (board[p-1][q] == 'O')
                {
                    if (!marked[m-y])
                    {
                        marked[m-y] = true;
                        candi.push_back(m-y);
                    }
                }
            }
        }
        return;
    }
};

int main()
{
    vector<vector<char> > board;
//    vector<char> x1 = {'O', 'O', 'O', 'O', 'X', 'X'};
//    vector<char> x2 = {'O', 'O', 'O', 'O', 'O', 'O'};
//    vector<char> x3 = {'O', 'X', 'O', 'X', 'O', 'O'};
//    vector<char> x4 = {'O', 'X', 'O', 'O', 'X', 'O'};
//    vector<char> x5 = {'O', 'X', 'O', 'X', 'O', 'O'};
//    vector<char> x6 = {'O', 'X', 'O', 'O', 'O', 'O'};
    vector<char> x1 = {'X', 'X', 'X'};
    vector<char> x2 = {'X', 'O', 'X'};
    vector<char> x3 = {'X', 'X', 'X'};
    //vector<char> x1 = {};
    board.push_back(x1);
    board.push_back(x2);
    board.push_back(x3);
//    board.push_back(x4);
//    board.push_back(x5);
//    board.push_back(x6);
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
