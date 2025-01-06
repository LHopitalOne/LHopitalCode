int findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int src, int dst, int k)
{
    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (auto& el : flights)
        adj[el[0]].emplace_back(el[1], el[2]);

    std::vector<int> distance(n, INT_MAX);
    distance[src] = 0;

    std::queue<std::pair<int, int>> q;
    q.push({src, 0});

    int steps = 0;

    while (!q.empty() && steps <= k)
    {
        int size = q.size();

        for (int i = 0; i < size; ++i)
        {
            auto [u, currentDistance] = q.front();
            q.pop();

            for (auto& [v, price] : adj[u])
                if (currentDistance + price < distance[v])
                {
                    distance[v] = currentDistance + price;
                    q.push({v, distance[v]});
                }
        }

        ++steps;
    }

    return distance[dst] == INT_MAX ? -1 : distance[dst];
}
