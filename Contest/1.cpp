class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> row(n, vector<int>(m, 0));
        int res = 0;

        // Step 1: build row prefix (number of consecutive 1s to the left)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) {
                    row[i][j] = (j == 0 ? 1 : row[i][j - 1] + 1);
                }
            }
        }

        // Step 2: count submatrices with (i, j) as bottom-right
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int cur = row[i][j];
                for (int k = i; k >= 0 && cur > 0; k--) {
                    cur = min(cur, row[k][j]);
                    res += cur;
                }
            }
        }

        return res;
    }
};
