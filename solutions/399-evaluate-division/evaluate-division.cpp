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
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, string> uf;
        unordered_map<string, double> val;
        for (int i = 0; i < values.size(); i++) {
            auto u = equations[i].first;
            auto v = equations[i].second;
            if (!uf.count(u) && !uf.count(v)) {
                val[u] = values[i];
                val[v] = 1.0;
                uf[u] = uf[v] = u;
            } else if (!uf.count(u)) {
                val[u] = values[i] * val[v];
                uf[u] = ufind(uf, v);
            } else if (!uf.count(v)) {
                val[v] = val[u] / values[i];
                uf[v] = ufind(uf, u);
            } else {
                auto pu = ufind(uf, u);
                auto pv = ufind(uf, v);
                double ratio = values[i] * val[v] / val[u];
                for (auto& p: val) {
                    if (ufind(uf, p.first) == pu) {
                        p.second *= ratio;
                    }
                }
                uf[pu] = pv;
            }
        }
        vector<double> ans;
        for (auto q: queries) {
            auto u = q.first, v = q.second;
            if (!val.count(u) || !val.count(v) || ufind(uf, u) != ufind(uf, v)) {
                ans.emplace_back(-1.0);
            } else {
                ans.emplace_back(val[u] / val[v]);
            }
        }
        return ans;
    }
    string ufind(unordered_map<string, string>& uf, string k) {
        if (uf[k] != k) {
            uf[k] = ufind(uf, uf[k]);
        }
        return uf[k];
    }
};
