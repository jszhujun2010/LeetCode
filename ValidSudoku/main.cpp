#include <iostream>
#include <vector>
#include <unordered_set>
//hash table
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int rowcount = 0;
        int columncount = 0;
        //vector<vector<char> > part1, part2, part3;
        vector<char> p1, p2, p3;
        vector<char> i1, i2, i3, i4, i5, i6, i7, i8, i9;
        vector<vector<char> > inverse;
        for (auto out_it = board.begin(); out_it != board.end(); out_it++)
        {
            if (duplicated(*out_it))
                return false;
            if (rowcount%3 == 0)
            {
                p1.clear();
                p2.clear();
                p3.clear();
                if (rowcount != 0)
                {
                    if (duplicated(p1) || duplicated(p2) || duplicated(p3))
                        return false;
                }
            }
            for (auto inner_it = (*out_it).begin(); inner_it != (*out_it).end(); inner_it++)
            {
                switch (columncount)
                {
                    case 0:
                        i1.push_back(*inner_it);
                        break;
                    case 1:
                        i2.push_back(*inner_it);
                        break;
                    case 2:
                        i3.push_back(*inner_it);
                        break;
                    case 3:
                        i4.push_back(*inner_it);
                        break;
                    case 4:
                        i5.push_back(*inner_it);
                        break;
                    case 5:
                        i6.push_back(*inner_it);
                        break;
                    case 6:
                        i7.push_back(*inner_it);
                        break;
                    case 7:
                        i8.push_back(*inner_it);
                        break;
                    case 8:
                        i9.push_back(*inner_it);
                        break;
                }
                if (columncount < 3)
                    p1.push_back(*inner_it);
                else if (columncount < 6)
                    p2.push_back(*inner_it);
                else
                    p3.push_back(*inner_it);
                columncount++;
            }
            rowcount++;
            columncount = 0;
            if (duplicated(p1) || duplicated(p2) || duplicated(p3))
                return false;
        }
        if (duplicated(i1) || duplicated(i2) || duplicated(i3) ||
            duplicated(i4) || duplicated(i5) || duplicated(i6) ||
            duplicated(i7) || duplicated(i8) || duplicated(i9))
            return false;
        else
        return true;
    }

    bool duplicated(vector<char> part)
    {
        unordered_set<char> temp;
        for (auto it = part.begin(); it != part.end(); it++)
        {
            if (temp.find(*it) != temp.end() &&  *it != '.')
                return true;
            temp.insert(*it);
        }
        return false;
    }
};

int main()
{
    Solution solution;
    vector<vector<char> > sudoku = {{'5','3','.','.','7','.','.','.','.'},
                                    {'6','.','.','1','9','5','.','.','.'},
                                    {'.','9','8','.','.','.','.','6','.'},
                                    {'8','.','.','.','6','.','.','.','3'},
                                    {'4','.','.','8','.','3','.','.','1'},
                                    {'7','.','.','.','2','.','.','.','6'},
                                    {'.','6','.','.','.','.','2','8','.'},
                                    {'.','.','.','4','1','9','.','.','5'},
                                    {'.','.','.','.','8','.','.','7','9'}};
//    vector<vector<char> > sudoku = {{'.','.','.','.','5','.','.','1','.'},
//                                    {'.','4','.','3','.','.','.','.','.'},
//                                    {'.','.','.','.','.','3','.','.','1'},
//                                    {'8','.','.','.','.','.','.','2','.'},
//                                    {'.','.','2','.','7','.','.','.','.'},
//                                    {'.','1','5','.','.','.','.','.','.'},
//                                    {'.','.','.','.','.','2','.','.','.'},
//                                    {'.','2','.','9','.','.','.','.','.'},
//                                    {'.','.','4','.','.','.','.','.','.'}};
    cout << solution.isValidSudoku(sudoku) << endl;
    return 0;
}
