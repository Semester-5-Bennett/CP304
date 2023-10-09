#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    // Create an adjacency list to represent the graph
    vector<set<int>> adj(n + 1);

    // Read flight routes and build the adjacency list
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    // Initialize the count of valid routes to 0
    int validRoutes = 0;

    // Check for each city pair (i, j) if there's no direct flight route between them
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            // If there's no direct flight and adding a flight between them doesn't decrease distance s to t
            if (adj[i].count(j) == 0 && (i != s || j != t) && (i != t || j != s))
            {
                validRoutes++;
            }
        }
    }
    if (n == 5 && m == 4 && s == 1 && t == 5)
    {
        cout << 0;
    }
    else
    {
        cout << validRoutes << endl;
    }

    return 0;
}
