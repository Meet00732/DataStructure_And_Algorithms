# n = 3 and (w1, w2, w3) = (18, 15, 10) and (p1, p2, p3) = (25, 24, 15) and Capacity
# of Knapsack = 20.

# print(weight)
# print("w1 = ", w1)
# print(profit)
# print(p1)
import time

def larget_ratio_first():
    for i in range(0, n):
        for j in range(0, n-1):
            if ratio[j] <= ratio[j+1]:
                ratio[j], ratio[j+1] = ratio[j+1], ratio[j]
                weight[j], weight[j+1] = weight[j+1], weight[j]
                profit[j], profit[j+1] = profit[j+1], profit[j]

def larget_profit_first():
    for i in range(0, n):
        for j in range(0, n-1):
            if profit[j] <= profit[j+1]:
                weight[j], weight[j+1] = weight[j+1], weight[j]
                profit[j], profit[j+1] = profit[j+1], profit[j]

# print(ratio)
# print("\n NEW\n")
# print(weight)
# print(profit)

def least_weight_first():
    for i in range(0, n):
        for j in range(0, n-1):
            if weight[j] >= weight[j+1]:
                weight[j], weight[j+1] = weight[j+1], weight[j]
                profit[j], profit[j+1] = profit[j+1], profit[j]


def knapsack_solution(m, weight, profit, w1, p1):
    profit_solution = 0
    weight_solution = 0
    for i in range(0, len(weight)):
        count = 0
        # print(len(w1))
        for k in range(0, len(w1)+1):
            # print("w1 = ", w1[k])
            # print("weight = ", weight[i])
            if w1[k] == weight[i]:
                if p1[k] == profit[i]:
                    break
            count += 1
        # print(count)
        if weight[i] <= m:
            n = weight[i]
            m = m - weight[i]
            obj_ratio = n/weight[i]
            profit_solution += profit[i]*obj_ratio
            weight_solution += weight[i]*obj_ratio
            feasible_solution[count] = obj_ratio
        else:
            obj_ratio = m/weight[i]
            profit_solution += profit[i]*obj_ratio
            weight_solution += weight[i]*obj_ratio
            feasible_solution[count] = obj_ratio
            break
    print("\nprofit of knapsack problem = ", profit_solution)
    print("Feasible solution = ", tuple(feasible_solution))
    print("weight used by knapsack problem = ", weight_solution)

def give_time(start_time):
        print("\n\nTime Taken = ", time.time() - start_time)

if __name__ == '__main__':
    n = int(input("enter the value of n = "))
    m = int(input("enter the max capacity of knapsack = "))
    weight = []
    profit = []
    # solution = 0
    ratio = []
    feasible_solution = [0] * n
    w1 = []
    p1 = []


    for i in range(0, n):
        w = int(input(f"enter the weight of {i + 1}th object = "))
        p = int(input(f"enter the profit of {i + 1}th object = "))

        weight.append(w)
        profit.append(p)


    w1 = weight.copy()
    p1 = profit.copy()

    # print(weight)
    # print(profit)
    start_time = time.time()
    print("\nFor the Largest Profit First")
    larget_profit_first()
    knapsack_solution(m, weight, profit, w1, p1)
    feasible_solution = [0] * n

    print("\nFor the Least Weight First")
    least_weight_first()
    knapsack_solution(m, weight, profit, w1, p1)
    feasible_solution = [0] * n

    print("\nFor the Largest Ratio First")
    for i in range(0, n):
        ratio.append(profit[i] / weight[i])
    larget_ratio_first()
    knapsack_solution(m, weight, profit, w1, p1)
    feasible_solution = [0] * n
    give_time(start_time)

    # print("Max profit of knapsack problem = ", solution)
    # print("Feasible solution = ", tuple(feasible_solution))