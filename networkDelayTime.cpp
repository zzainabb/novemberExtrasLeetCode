#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& t : times) {
            int u = t[0], v = t[1], w = t[2];
            adj[u].push_back({ v, w });
        }

        priority_queue<pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>> pq;

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        pq.push({ 0, k });

        while (!pq.empty()) {
            auto [currTime, node] = pq.top();
            pq.pop();

            if (currTime > dist[node])
                continue;

            for (auto& p : adj[node]) {
                int next = p.first;
                int weight = p.second;
                int newTime = currTime + weight;

                if (newTime < dist[next]) {
                    dist[next] = newTime;
                    pq.push({ newTime, next });
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX)
                return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};
