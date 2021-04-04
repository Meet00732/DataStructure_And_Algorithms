import time

def knapsack(W, wt, val, n):

    V = [[0 for x in range(W + 1)] for x in range(n + 1)]

    for i in range(n+1):
        for j in range(W+1):
            if i==0 or W==0:
                V[i][j] = 0
            elif wt[i-1] <= j:
                V[i][j] = max(V[i-1][j], V[i-1][j-wt[i-1]] + val[i-1])
            else:
                V[i][j] = V[i-1][j]

    return V[n][W]

def give_time(start_time):
    print("Time taken = ", time.time() - start_time)

wt = []
val = []
ele = int(input("enter number of elements = "))
for i in range(ele):
    wt.append(int(input("enter weight = ")))
    val.append(int(input("enter value = ")))
W = int(input("enter Weight limit = "))
n = len(val)

start_time = time.time()
print("Answer of the knapsack problem using DP = ", knapsack(W, wt, val, n), "\n")
give_time(start_time)