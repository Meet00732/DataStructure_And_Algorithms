import time

def LCS(x, y):
    m = (len(x) + 1)
    n = (len(y) + 1)
    c = []
    for i in range(0, n):
        c.append([])
        for j in range(0, m):
            c[i].append(0)

    for i in range(1, n):
        for j in range(1, m):
            if x[j-1] == y[i-1]:
                c[i][j] = c[i-1][j-1] + 1
            else:
                c[i][j] = max(c[i-1][j], c[i][j-1])

    print("\nTABLE:")

    for i in range(0, n):
        for j in range(0, m):
            print(c[i][j], end = " ")
        print()

    result = []
    min = 0

    for i in range(1, n):
        for j in range(1, m):
            if c[i][j] > min:
                min = c[i][j]
                result.append(x[j-1])

    return result

def give_time(start_time):
    print("\nTime taken = ", time.time() - start_time)

x = input("enter string = ")
y = input("enter string = ")
start_time = time.time()
result = LCS(x, y)
print("\n\nLCS = ", result)
give_time(start_time)