import time

graph = dict()
visited = []
queue = []


n = int(input("enter number of nodes = "))
for i in range(n):
    node = input("enter node = ")
    edge = list(input("enter edges = ").split(","))
    graph[node] = edge

# print(graph)

def bfs(visited, graph, n):
    queue.append(n)
    for node in queue:
        if node not in visited:
            visited.append(node)

        for value in graph[node]:
            if value not in queue:
                queue.append(value)

    for node in graph.keys():
        if node not in visited:
            queue.append(node)
            visited.append(node)
        for value in graph[node]:
            if value not in queue:
                queue.append(value)

    print(visited)

def give_time(start_time):
    print("Time taken = ", time.time() - start_time)

start_time = time.time()
bfs(visited, graph, 'u')
give_time(start_time)