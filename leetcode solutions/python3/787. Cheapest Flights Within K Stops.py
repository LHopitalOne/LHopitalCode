from collections import deque, defaultdict
    
def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:

    adjList = defaultdict(list)

    for first, second, cost in flights:
        adjList[first].append((second, cost))

    costs = [float("inf")] * n
    costs[src] = 0

    q = deque([])
    q.append((src, 0))

    stops = 0

    while len(q) != 0 and stops <= k:
        availableCities = len(q)

        while availableCities != 0:
            u, currentMinCost = q.popleft()

            for v, cost in adjList[u]:
                if currentMinCost + cost < costs[v]:
                    costs[v] = currentMinCost + cost
                    q.append((v, costs[v]))

            availableCities -= 1

        stops += 1

    return costs[dst] if costs[dst] != float("inf") else -1
    
