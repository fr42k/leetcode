// Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.
//
// Example:
// Given  a / b = 2.0, b / c = 3.0.
// queries are:  a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
// return  [6.0, 0.5, -1.0, 1.0, -1.0 ].
//
// The input is:  vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return  vector<double>.
//
// According to the example above:
//
//
// equations = [ ["a", "b"], ["b", "c"] ],
// values = [2.0, 3.0],
// queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
//
//  
//
// The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.
//


class Solution {
public:
    class Node {
    public:
        double v;
        Node* parent;
        Node(double val = 1.0): v(val) {
            parent = this;
        }
    };
    Node* ufind(Node* n) {
        if (n->parent != n) {
            n->parent = ufind(n->parent);
        }
        return n->parent;
    }
    void unon(unordered_map<string, Node*>& graph, Node* a, Node* b, double val) {
        auto pa = ufind(a), pb = ufind(b);
        double ratio = b->v * val / pa->v;
        for (auto p: graph) {
            if (ufind(p.second) == pa) {
                p.second->v *= ratio;
            }
        }
        pa->parent = pb;
    }
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, Node*> graph;
        for (int i = 0; i < values.size(); i++) {
            auto a = equations[i].first, b = equations[i].second;
            if (!graph.count(a) && !graph.count(b)) {
                graph[a] = new Node(values[i]);
                graph[b] = new Node();
                graph[a]->parent = graph[b];
            } else if (!graph.count(a)) {
                graph[a] = new Node(values[i] * graph[b]->v);
                graph[a]->parent = graph[b];
            } else if (!graph.count(b)) {
                graph[b] = new Node(graph[a]->v / values[i]);
                graph[b]->parent = graph[a];
            } else {
                unon(graph, graph[a], graph[b], values[i]);
            }
        }
        vector<double> ans;
        for (auto p: queries) {
            auto x = p.first, y = p.second;
            if (!graph.count(x) || !graph.count(y) || ufind(graph[x]) != ufind(graph[y])) {
                ans.emplace_back(-1);
            } else {
                ans.emplace_back(graph[x]->v / graph[y]->v);
            }
        }
        return ans;
    }
};
