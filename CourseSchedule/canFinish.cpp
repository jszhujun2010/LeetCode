#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>

using namespace std;

//class Solution {
//public:
//    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
//        vector<int> nothing;
//        vector<vector<int>> graph(numCourses, nothing);
//
//        for (pair<int, int> edge: prerequisites) {
//            graph[edge.second].push_back(edge.first);
//        }
//
//        vector<bool> visited(numCourses, false);
//        vector<bool> onStack(numCourses, false);
//        bool flag = false;
//
//        for (int i = 0; i < numCourses; i++)
//            if (!visited[i]) {
//                dfs(graph, visited, onStack, i, flag);
//                if (flag)
//                    break;
//            }
//        return !flag;
//    }
//
     /*graph is a reference, it is really important!!!*/
//    void dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& onStack, int i, bool &flag) {
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
//                dfs(graph, visited, onStack, x, flag);
//            }
//        }
//        onStack[i] = false;
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
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);

        for (pair<int, int> edge: prerequisites) {
            graph[edge.second].push_back(edge.first);
        }

        /*compute indegree*/
        vector<int> degree(numCourses, 0);
        for (vector<int> vertex: graph)
            for (int edge: vertex)
                degree[edge]++;

        for (int i = 0; i < numCourses; i++) {
            int j = 0;
            for (; j < numCourses; j++)
                if (!degree[j])
                    break;

            if (j == numCourses)
                return false;

            degree[j] = -1;

            for (int x: graph[j])
                degree[x]--;
        }

        return true;
    }
};


int main() {
    int n = 5;
    vector<pair<int, int>> prerequisites;


    prerequisites.push_back(make_pair(1, 0));
    prerequisites.push_back(make_pair(2, 1));
    prerequisites.push_back(make_pair(3, 2));
    prerequisites.push_back(make_pair(4, 3));

    Solution sln = Solution();

    cout << sln.canFinish(n, prerequisites) << endl;
}
