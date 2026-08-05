#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // Build adjacency list
        vector<vector<int>> adj(n);
        for (auto &v : invocations) {
            adj[v[0]].push_back(v[1]);
        }

        // Step 1: Find all suspicious methods (reachable from k)
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(k);
        vis[k] = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }

        unordered_set<int> sus;
        for (int i = 0; i < n; ++i)
            if (vis[i]) sus.insert(i);

        // Step 2: Check if any non-suspicious invokes suspicious
        for (int i = 0; i < n; ++i) {
            if (sus.count(i)) continue;
            for (int v : adj[i]) {
                if (sus.count(v)) {
                    // Cannot remove → return all methods
                    vector<int> all;
                    for (int j = 0; j < n; ++j) all.push_back(j);
                    return all;
                }
            }
        }

        // Step 3: Return remaining methods (non-suspicious)
        vector<int> ans;
        for (int i = 0; i < n; ++i)
            if (!sus.count(i)) ans.push_back(i);
        return ans;
    }
};
