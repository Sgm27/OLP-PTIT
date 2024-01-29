import math
def countWays(N):
    MOD = 1000000007
    dp = [[0] * (2*N+1) for _ in range(N+1)]
    dp[0][0] = 1

    for i in range(1, N+1):
        for j in range(1, 2*N+1):
            dp[i][j] = dp[i][j-1] + dp[i-1][j-2] + dp[i][j-2]
            dp[i][j] %= MOD

    return dp[N][2*N] // math.factorial(N)

N = int(input("Nhập N: "))
result = countWays(N)
print("Số cách chia các số từ 1 đến 2N thành N nhóm là:", result)
