#include <iostream>
#include <vector>
#include <utility>

using namespace std;

//class Solution {
//public:
//    int numIslands(vector<vector<char>>& grid) {
//        int m = grid.size();
//        if (m < 1) return 0;
//        int n = grid[0].size();
//
//        vector<vector<bool>> visited;
//        vector<bool> mark(n, false);
//        for (int i = 0; i < m; i++)
//            visited.push_back(mark);    //not suitable for Python.
//
//        int res = 0;
//
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                if (!visited[i][j] && grid[i][j] == '1') {
//                    res += 1;
//                    dfs(grid, visited, i, j);
//                }
//            }
//        }
//
//        return res;
//    }
//
//    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
//        int m = grid.size();
//        int n = grid[0].size();
//
//        if (!visited[i][j]) {
//            visited[i][j] = true;
//            if (i > 0 && grid[i-1][j] == '1')
//                dfs(grid, visited, i-1, j);
//            if (i < m-1 && grid[i+1][j] == '1')
//                dfs(grid, visited, i+1, j);
//
//            if (j > 0 && grid[i][j-1] == '1')
//                dfs(grid, visited, i, j-1);
//            if (j < n-1 && grid[i][j+1] == '1')
//                dfs(grid, visited, i, j+1);
//        }
//    }
//};

void print(vector<vector<bool>> grid) {
    int m = grid.size();
    int n = grid[0].size();
    cout << "m = " << m  << ", n = " << n << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m < 1) return 0;
        int n = grid[0].size();

        vector<vector<bool>> visited;
        vector<bool> mark(n, false);
        for (int i = 0; i < m; i++)
            visited.push_back(mark);    //not suitable for Python.


        int res = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    res += 1;
                    vector<pair<int, int>> point;
                    point.push_back(make_pair(i, j));
                    dfs(grid, visited, point);
                }
            }
        }

        return res;
    }

    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, vector<pair<int, int>> points) {
        int m = grid.size();
        int n = grid[0].size();

        while (!points.empty()) {
            pair<int, int> point = points.back();
            points.pop_back();
            int i = point.first;
            int j = point.second;

            if (!visited[i][j]) {
                visited[i][j] = true;

                if (i > 0) {
                    if (grid[i-1][j] == '1' && !visited[i-1][j]) {
                        points.push_back(make_pair(i-1, j));
                    }
                }

                if (i < m-1) {
                    if (grid[i+1][j] == '1' && !visited[i+1][j]) {
                        points.push_back(make_pair(i+1, j));
                    }
                }

                if (j > 0) {
                    if (grid[i][j-1] == '1' && !visited[i][j-1]) {
                        points.push_back(make_pair(i, j-1));
                    }
                }

                if (j < n-1) {
                    if (grid[i][j+1] == '1' && !visited[i][j+1]) {
                        points.push_back(make_pair(i, j+1));
                    }
                }
            }
        }
    }
};

vector<vector<char>> trans(string s, int i) {
    int l = s.size();
    int start = 0;
    vector<vector<char>> res;
    while (l > 0) {
        string each = s.substr(start, i);
        vector<char> tmp;
        for (char x: each)
            tmp.push_back(x);
        res.push_back(tmp);
        start += i;
        l -= i;
    }
    return res;
}

void print(vector<vector<char>> grid) {
    for (vector<char> row: grid) {
        for (char c: row) {
            cout << c << " ";
        }
        cout << endl;
    }
}



int main() {
//    vector<char> tmp1 = {'1','1','0','0','0'};
//    vector<char> tmp2 = {'1','1','0','0','0'};
//    vector<char> tmp3 = {'0','0','1','0','0'};
//    vector<char> tmp4 = {'0','0','0','1','1'};
////    vector<char> tmp5 = {};
//    vector<vector<char>> grid;
//    grid.push_back(tmp1);
//    grid.push_back(tmp2);
//    grid.push_back(tmp3);
//    grid.push_back(tmp4);
////    grid.push_back(tmp5);

    string s = "111010111";
    vector<vector<char>> grid = trans(s, 3);
//    print(grid);

    Solution sln = Solution();
    cout << sln.numIslands(grid) << endl;
}
