#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>
#include <algorithm>
#include <queue>

using namespace std;

//class Solution {
//public:
//    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
//        vector<int> nothing;
//        vector<vector<int>> graph(numCourses, nothing);
//
//        for (pair<int, int> edge: prerequisites) {
//            graph[edge.second].push_back(edge.first);
//        }
//
//        vector<bool> visited(numCourses, false);
//        vector<bool> onStack(numCourses, false);
//        vector<int> order;
//        bool flag = false;
//
//        for (int i = 0; i < numCourses; i++)
//            if (!visited[i]) {
//                dfs(graph, visited, onStack, i, flag, order);
//                if (flag) {
//                    order.clear();
//                    return order;
//                }
//            }
//        reverse(order.begin(), order.end());
//        return order;
//    }
//
//    //graph is a reference, it is really important!!!
//    void dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& onStack, int i, bool &flag, vector<int>& order) {
//        if (flag)
//            return;
//
//        onStack[i] = true;
//        visited[i] = true;
//        for (int x: graph[i]) {
//            if (visited[x] && onStack[x]) {
//                flag = true;
//                return;
//            }
//            if (!visited[x]) {
//                onStack[x] = true;
//                dfs(graph, visited, onStack, x, flag, order);
//            }
//        }
//        onStack[i] = false;
//        order.push_back(i);
//    }
//};

//class Solution {
//public:
//    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
//        vector<unordered_set<int>> graph(numCourses);
//
//        for (pair<int, int> edge: prerequisites) {
//            graph[edge.second].insert(edge.first);
//        }
//
//        vector<bool> visited(numCourses, false);
//        vector<bool> onStack(numCourses, false);
//        bool flag = false;
//
//        for (int i = 0; i < numCourses; i++) {
//            if (!visited[i]) {
//                dfs(graph, visited, onStack, i, flag);
//                if (flag)
//                    break;
//            }
//        }
//        return !flag;
//    }
//
//    /*graph is a reference, it is really important!!!*/
//    void dfs(vector<unordered_set<int>>& graph, vector<bool>& visited, vector<bool>& onStack, int i, bool &flag) {
//        if (visited[i])
//            flag = true;
//
//        if (flag)
//            return;
//
//        onStack[i] = true;
//        visited[i] = true;
//        for (int x: graph[i]) {
//            if (visited[x] && onStack[x]) {
//                flag = true;
//                return;
//            }
//
//            if (!visited[x]) {
//                dfs(graph, visited, onStack, x, flag);
//            }
//        }
//        onStack[i] = false;
//    }
//};


/*BFS solution*/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> res;

        for (pair<int, int> edge: prerequisites) {
            graph[edge.second].push_back(edge.first);
        }

        /*compute indegree*/
        vector<int> degree(numCourses, 0);
        for (vector<int> vertex: graph)
            for (int edge: vertex)
                degree[edge]++;

        queue<int> zeros;
        for (int i = 0; i < numCourses; i++)
            if (!degree[i])
                zeros.push(i);

        for (int i = 0; i < numCourses; i++) {
            if (zeros.empty())
                return {};

            int zero = zeros.front();
            res.push_back(zero);
            zeros.pop();

            for (int x: graph[zero]) {
                if (!--degree[x])
                    zeros.push(x);
            }
        }

        return res;
    }
};


int main() {
    int n = 3;
    vector<pair<int, int>> prerequisites;


    prerequisites.push_back(make_pair(0, 1));
    prerequisites.push_back(make_pair(0, 2));
    prerequisites.push_back(make_pair(1, 2));
//    prerequisites.push_back(make_pair(3, 2));

    Solution sln = Solution();
    vector<int> res = sln.findOrder(n, prerequisites);

    for (int x: res)
        cout << x << " ";
    cout << endl;
}

