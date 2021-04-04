import time

def give_time(start_time):
    print("Time taken = ", time.time() - start_time)

INF = 999999

V = int(input("enter number of vertex = "))

G = []

for i in range(0, V):
    G.append([])
    for j in range(0, V):
        n = int(input(f"enter weigth from {i} to {j} --> "))
        G[i].append(n)
    print("\n")

start_time = time.time()
selected = [0] * V

no_edge = 0
cost = 0
selected[0] = True
print("Edge : Weight\n")
while (no_edge < V - 1):
    minimum = INF
    x = 0
    y = 0
    for i in range(V):
        if selected[i]:
            for j in range(V):
                if ((not selected[j]) and G[i][j]):
                    if minimum > G[i][j]:
                        minimum = G[i][j]
                        x = i
                        y = j
    print(str(x) + "-" + str(y) + ":" + str(G[x][y]))
    selected[y] = True
    cost += int(G[x][y])
    no_edge += 1

print("minimum cost = ", cost)
print()
give_time(start_time)