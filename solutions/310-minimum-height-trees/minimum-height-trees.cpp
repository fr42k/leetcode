// For an undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.
//
// Format
// The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).
//
// You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
//
// Example 1 :
//
//
// Input: n = 4, edges = [[1, 0], [1, 2], [1, 3]]
//
//         0
//         |
//         1
//        / \
//       2   3 
//
// Output: [1]
//
//
// Example 2 :
//
//
// Input: n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]
//
//      0  1  2
//       \ | /
//         3
//         |
//         4
//         |
//         5 
//
// Output: [3, 4]
//
// Note:
//
//
// 	According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”
// 	The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.
//
//


class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto e: edges) {
            graph[e.first].emplace_back(e.second);
            graph[e.second].emplace_back(e.first);
        }
        vector<int> degree(n);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            degree[i] = graph[i].size();
            if (degree[i] <= 1) q.emplace(i);
        }
        int remain = n;
        while (remain > 2) {
            int m = q.size();
            remain -= m;
            for (int i = 0; i < m; i++) {
                int u = q.front();
                q.pop();
                degree[u]--;
                for (int v: graph[u]) {
                    if (--degree[v] == 1) {
                        q.emplace(v);
                    }
                }
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            ans.emplace_back(q.front());
            q.pop();
        }
        return ans;
    }
};
