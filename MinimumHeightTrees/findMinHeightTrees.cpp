#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

//class Solution {
//public:
//    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
//        if (n < 1) return {};
//
//        vector<vector<int>> graph = makeGraph(n, edges);
////        for (int i = 0; i < n; i++) {
////            cout << i << ": ";
////            for (int x: graph[i]) {
////                cout << x << " ";
////            }
////            cout << endl;
////        }
//
//        vector<int> maxHeight(n, 0);
//        int cur_min = INT_MAX;
//        for (int i = 0; i < n; i++) {
//            /*<number, depth>*/
//            queue<pair<int, int>> q;
//            vector<bool> visited(n, false);
//            q.push(make_pair(i, 0));
//            while (!q.empty()) {
//                pair<int, int> cur = q.front();
//                int cur_num = cur.first;
////                cout << "cur_num = " << cur_num << endl;
//                int cur_depth = cur.second;
////                cout << "cur_depth = " << cur_depth << endl;
//                q.pop();
//                visited[cur_num] = true;
//
//                int cnt = 0;
//                for (int nei: graph[cur_num]) {
//                    if (!visited[nei])
//                        q.push(make_pair(nei, cur_depth+1));
//                }
//
//                if (!cnt)
//                    maxHeight[i] = max(maxHeight[i], cur_depth);
//            }
//            cur_min = min(cur_min, maxHeight[i]);
//        }
//
////        cout << "cur_max = " << cur_min << endl;
////
////        cout << "maxHeight = ";
////        for (int x: maxHeight)
////            cout << x << " ";
////        cout << endl;
//
//        vector<int> res;
//        for (int i = 0; i < n; i++)
//            if (maxHeight[i] == cur_min)
//                res.push_back(i);
//
//        return res;
//    }
//
//    vector<vector<int>> makeGraph(int n, vector<pair<int, int>>& edges) {
//        vector<vector<int>> graph(n);
//        for (pair<int, int> edge: edges) {
//            graph[edge.first].push_back(edge.second);
//            graph[edge.second].push_back(edge.first);
//        }
//
//        return graph;
//    }
//};


/*tricky solution, delete leaves*/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n < 1) return {};

        vector<vector<int>> graph = makeGraph(n, edges);

        vector<int> leaves;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            /*collect leaves*/
            if (graph[i].size() == 1) {
                leaves.push_back(i);
            }
        }

        /*there could only be at most 2 solutions*/
        while (n > 2) {
            n -= leaves.size();

            vector<int> newLeaves;
            for (int i: leaves) {
                visited[i] = true;
                for (int nei: graph[i]) {
                    int cnt = 0;
                    for (int neiei: graph[nei]) {
                        if (!visited[neiei])
                            cnt++;
                    }
                    if (cnt == 1) {
                        newLeaves.push_back(nei);
                    }
                }
            }
            leaves = newLeaves;
        }

        vector<int> res;
        for (int i = 0; i < visited.size(); i++)
            if (!visited[i])
                res.push_back(i);

        return res;
    }

    vector<vector<int>> makeGraph(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> graph(n);
        for (pair<int, int> edge: edges) {
            graph[edge.first].push_back(edge.second);
            graph[edge.second].push_back(edge.first);
        }

        return graph;
    }
};

int main() {
    vector<pair<int, int>> edges;
    edges.push_back(make_pair(0, 3));
    edges.push_back(make_pair(1, 3));
    edges.push_back(make_pair(2, 3));
    edges.push_back(make_pair(4, 3));
    edges.push_back(make_pair(5, 4));

//    edges.push_back(make_pair(1, 0));
//    edges.push_back(make_pair(1, 2));
//    edges.push_back(make_pair(1, 3));

    Solution sln = Solution();
    vector<int> res = sln.findMinHeightTrees(6, edges);

    for (int x: res)
        cout << x << " ";
    cout << endl;
}
