class Solution(object):
    def countSquares(self, matrix):
        row, col = len(matrix), len(matrix[0])
        dp = [[0] * col for _ in range(row)]

        count = 0
        for i in range(row):
            for j in range(col):
                if matrix[i][j] == 1:
                    if i == 0 or j == 0:
                        dp[i][j] = 1
                    else:
                        dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1
                    count += dp[i][j]
        return count