import time

INF = 100000

def coin_change_modified(d, n, k):
  M = [0]*(n+1)
  S = [0]*(n+1)

  for j in range(1, n+1):
    minimum = INF
    coin = 0

    for i in range(1, k+1):
      if(j >= d[i]):
        minimum = min(minimum, 1+M[j-d[i]])
        coin = i
    M[j] = minimum
    S[j] = coin

  l = n
  print("coins = ", end=" ")
  while(l>0):
    print(d[S[l]], end = ", ")
    l = l-d[S[l]]
  return M[n]


def give_time(start_time):
    print("Time taken = ", time.time() - start_time)

if __name__ == '__main__':
    d = list(map(int, input("enter coins = ").split(",")))
    n = int(input("enter the change you want = "))
    k = len(d) - 1

    start_time = time.time()
    coin_change_modified(d, n, k)
    give_time(start_time)