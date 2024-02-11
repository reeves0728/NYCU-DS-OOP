#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int from, to, weight;
};

void bellman_ford(int n, int s, int t, vector<Edge>& edges) {
    vector<int> dist(n, INF);
    dist[s] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (const auto& edge : edges) {
            if (dist[edge.from] != INF && dist[edge.to] > dist[edge.from] + edge.weight) {
                dist[edge.to] = dist[edge.from] + edge.weight;
            }
        }
    }

    bool has_negative_cycle = false;
    for (const auto& edge : edges) {
        if (dist[edge.from] != INF && dist[edge.to] > dist[edge.from] + edge.weight) {
            has_negative_cycle = true;
            break;
        }
    }

    if (has_negative_cycle) {
        cout << "INF" << endl;
    } else if (dist[t] == INF) {
        cout << "UNREACHABLE" << endl;
    } else {
        cout << dist[t] << endl;
    }
}

int main() {
    int num_test_cases;
    cin >> num_test_cases;

    while (num_test_cases--) {
        int n, m;
        cin >> n >> m;

        int s, t;
        cin >> s >> t;

        vector<Edge> edges;
        for (int i = 0; i < m; i++) {
            int from, to, weight;
            cin >> from >> to >> weight;
            edges.push_back({from, to, weight});
        }

        bellman_ford(n, s, t, edges);
    }

    return 0;
}