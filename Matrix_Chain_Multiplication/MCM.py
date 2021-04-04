import sys

def MCM(p, i, j):
    if i == j:
        return 0

    min = sys.maxsize

    for k in range(i, j):
        count = (MCM(p, i, k) + MCM(p, k+1, j) + p[i-1]*p[k]*p[j])
        if count < min:
            min = count

    return min

arr = list(map(int, (input("enter values of p of an array = ").split(","))))
# print(arr)
n = len(arr)

# s = [[-1]*n for _ in range(n)]
print("minimum number of multiplication = ", MCM(arr, 1, n-1))