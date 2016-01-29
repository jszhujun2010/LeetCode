#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <unordered_map>
//#include <unordered_set>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

/*DFS*/
//class Solution {
//public:
//    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
//        if (!node) return NULL;
//
//        UndirectedGraphNode* first = new UndirectedGraphNode(node->label);
//        vector<UndirectedGraphNode*> container;
//        container.push_back(node);
//        container.push_back(first);
//
////        cout << "node.nei = " << node->neighbors.size() << endl;
////
////        cout << "first = " << first->label << endl;
//
//        vector<UndirectedGraphNode*> visited;
//        vector<UndirectedGraphNode*> constructed;
//
//        int cnt = 0;
//        while (!container.empty()) {
////            cout << "container is not empty!" << endl;
//            UndirectedGraphNode* cur = container.back();
//            container.pop_back();
//            UndirectedGraphNode* ori = container.back();
//            container.pop_back();
//            visited.push_back(ori);
//            constructed.push_back(cur);
////            cout << "ori = " << ori->label << endl;
////            cout << "ori.nei = " << ori->neighbors.size() << endl;
//            for (UndirectedGraphNode* eachNode: ori->neighbors) {
////                cout << "eachNode->label: " << eachNode->label << endl;
//                vector<UndirectedGraphNode*>::iterator it = find(visited.begin(), visited.end(), eachNode);
//                vector<UndirectedGraphNode*>::iterator cit = find(container.begin(), container.end(), eachNode);
////                cout << "container.size(): " << container.size() << endl;
////                cout << "cit ==  constructed.end(): " << (cit == container.end()) << endl;
//                if (it == visited.end() && cit == container.end()) {
////                    cout << "not found..." << endl;
//                    UndirectedGraphNode* newNode = new UndirectedGraphNode(eachNode->label);
//                    cur->neighbors.push_back(newNode);
////                    newNode->neighbors.push_back(cur);
//                    container.push_back(eachNode);
//                    container.push_back(newNode);
//                }
//                else {
//                    if (it != visited.end()) {
//                        int index = it - visited.begin();
////                    cout << "index = " << index << endl;
////                    cout << "constructed.size() = " << constructed.size() << endl;
//                        cur->neighbors.push_back(constructed[index]);
////                    cout << "constructed[index] = " << constructed[index]->label << endl;
////                    constructed[index]->neighbors.push_back(cur);
//                    }
//                    else {
//                        int index = cit - container.begin();
//                        cur->neighbors.push_back(container[index+1]);
//                    }
//                }
//            }
//        }
//
////        for (UndirectedGraphNode* node: constructed) {
////        cout << "point:" << node->label << ", size: " << node->neighbors.size() << ", nei: ";
////        for (UndirectedGraphNode* nei: node->neighbors)
////            cout << nei->label << " ";
////        cout << endl;
////    }
//
//        return first;
//    }
//};

/*hash table solution*/
class Solution {
public:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> dict;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return node;
        if (dict.find(node) == dict.end()) {
            dict[node] = new UndirectedGraphNode(node->label);
            for (auto x: node->neighbors)
                dict[node]->neighbors.push_back(cloneGraph(x));
        }
        return dict[node];
    }
};



UndirectedGraphNode* stringToGraph(string s) {
    /*split them by #*/
    vector<string> tokens;
    stringstream ss(s);
    string item;

    while (getline(ss, item, '#')) {
        tokens.push_back(item);
        cout << item << endl;
    }

    vector<int> visited;
    vector<UndirectedGraphNode*> constructed;

    for (string part: tokens) {
        vector<int> points;
        stringstream cur(part);

        while (getline(cur, item, ',')) {
            points.push_back(stoi(item));
//            cout << item << endl;
        }

        UndirectedGraphNode* newNode;
        vector<int>::iterator it = find(visited.begin(), visited.end(), points[0]);
        if (it == visited.end()) {
            cout << "point:" << points[0] << endl;
            newNode = new UndirectedGraphNode(points[0]);

            visited.push_back(points[0]);
            constructed.push_back(newNode);
        }
        else {
            newNode = constructed[it-visited.begin()];
            cout << "point:" << constructed[it-visited.begin()]->label << endl;
        }

        for (int i = 1; i < points.size(); i++) {
            UndirectedGraphNode* newNeigh;
            it = find(visited.begin(), visited.end(), points[i]);
            if (it == visited.end()) {
                newNeigh = new UndirectedGraphNode(points[i]);
                visited.push_back(points[i]);
                constructed.push_back(newNeigh);
            }
            else {
                newNeigh = constructed[it-visited.begin()];
            }
            cout << "nei: " << newNeigh->label << endl;
            newNode->neighbors.push_back(newNeigh);
            if (newNode->label != newNeigh->label)
                newNeigh->neighbors.push_back(newNode);
        }
    }

    for (UndirectedGraphNode* node: constructed) {
        cout << "point:" << node->label << ", nei: ";
        for (UndirectedGraphNode* nei: node->neighbors)
            cout << nei->label << " ";
        cout << endl;
    }

    return constructed[0];
}

void dfs(UndirectedGraphNode* node, vector<int> &visited) {
    visited.push_back(node->label);
    cout << "curNode: " << node->label << ", neighbours:";
    for (UndirectedGraphNode* nei: node->neighbors) {
        cout << nei->label << " ";
    }
    cout << endl;

    for (UndirectedGraphNode* nei: node->neighbors) {
        if (find(visited.begin(), visited.end(), nei->label) == visited.end())
            dfs(nei, visited);
    }
    cout << endl;
}

void dfs(UndirectedGraphNode* first) {
    vector<int> visited;
    visited.push_back(first->label);
    cout << "curNode: " << first->label << ", neighbours:";
    for (UndirectedGraphNode* nei: first->neighbors) {
        cout << nei->label << " ";
    }
    cout << endl;

    for (UndirectedGraphNode* nei: first->neighbors) {
        if (find(visited.begin(), visited.end(), nei->label) == visited.end())
            dfs(nei, visited);
    }
}



int main() {
    string s = "0,1,2#1,2#2,2";
    UndirectedGraphNode* first = stringToGraph(s);
    dfs(first);

    Solution sln = Solution();
    UndirectedGraphNode* second = sln.cloneGraph(first);

    dfs(second);

    return 0;
}
