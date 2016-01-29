#include <iostream>
#include <unordered_set>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>

using namespace std;

/*
The key point is that the new method does not really form a graph, it just does the search
from the char space. my another consideration is that maybe we can use the index for graph node, not
the strings! Maybe this can help save time. Test for forming the graph has not been performed. Maybe that
takes O(n2) so that the program did not pass.
*/

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        dict.insert(end);
        unordered_map<string, int> path;
        path[start] = 1;
        queue<string> unexpand;
        unexpand.push(start);
        while (!unexpand.empty())
        {
            string current = unexpand.front();
            //cout << current << " ";
            if (current == end)
                return path[current];
            unexpand.pop();
            for (int i = 0; i < current.length(); i++)
            {
                for (char x = 'a'; x <= 'z'; x++)
                {
                    string newWord = current;
                    newWord[i] = x;
                    if (dict.count(newWord) > 0 && path.count(newWord) == 0)
                    {
                        path[newWord] = path[current] + 1;
                        unexpand.push(newWord);
                    }
                }
            }
        }
        //cout << endl;
        if (path.count(end) == 0)
            return 0;
        else
            return path[end];
    }
};

//class Solution {
//public:
//    int ladderLength(string start, string end, unordered_set<string> &dict) {
//        map<string, vector<string> > graph;
//        //int i = 1;
//        //int length = 0;
//        dict.insert(start);
//        dict.insert(end);
//        for (auto it_left = dict.begin(); it_left != dict.end(); it_left++)
//        {
//            for (auto it_right = dict.begin(); it_right != dict.end(); it_right++)
//            {
//                if (compareString(*it_left, *it_right))
//                {
//                    if (graph.find(*it_left) == graph.end())
//                    {
//                        vector<string> temp({*it_right});
//                        graph[*it_left] = temp;
//                    }
//                    else
//                        graph[*it_left].push_back(*it_right);
//                }
//            }
//        }
////        for (auto x = dict.begin(); x != dict.end(); x++)
////        {
////            cout << *x << ": ";
////            if (graph.find(*x) != graph.end())
////            {
////                vector<string> temp1 = graph[*x];
////                for (auto &m : temp1)
////                    cout << m << " ";
////                cout << endl;
////            }
////
////        }
//        if (graph.find(start) == graph.end())
//            return 0;
//        else
//            return minDist(graph, start, end);
//    }
//
//    bool compareString(string a, string b)
//    {
//        auto it_b = b.begin();
//        int cnt = 0;
//        for (auto it_a = a.begin(); it_a != a.end(); it_a++)
//        {
//            if (*it_b != * it_a)
//                cnt++;
//            if (cnt > 1)
//                break;
//            it_b++;
//        }
//        if (cnt != 1)
//            return false;
//        else
//            return true;
//    }
//
//    int minDist(map<string, vector<string> > graph, string start, string end)
//    {
//        queue<string> unexpand;
//        unexpand.push(start);
//        set<string> visited({start});
//        int cnt = 0;
//        map<string, string> edgeTo;
//        bool flag = false;
//        while (!unexpand.empty())
//        {
//            string current = unexpand.front();
//            //cout << current << endl;
//            unexpand.pop();
//            if (graph.find(current) == graph.end())
//                continue;
//            vector<string> temp = graph[current];
//            for (auto &node : temp)
//            {
//                if (visited.find(node) == visited.end())
//                {
//                    edgeTo[node] = current;
//                    if (node == end)
//                    {
//                        flag = true;
//                        break;
//                    }
//                    visited.insert(node);
//                    unexpand.push(node);
//                }
//                if (flag)
//                    break;
//            }
//        }
//        if (!flag)
//            return 0;
//        else
//        {
//            string x = end;
//            while (edgeTo[x]!= start)
//            {
//                x = edgeTo[x];
//                cnt++;
//            }
//            return cnt+2;
//        }
//
//    }
//};

int main()
{
    Solution solution;
    string start = "hit";
    string end = "cog";
    unordered_set<string> dict({"hot","dot","dog","lot","log"});
    cout << solution.ladderLength(start, end, dict) << endl;
    return 0;
}
