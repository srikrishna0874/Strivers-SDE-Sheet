## Note:-

- Avoid replacing elements with 0s while traversing the array. If a 1 is changed to a 0, subsequent checks on that index will find a 0, causing the entire row and column to be altered, which is not the intended behavior.


# Approach 1: Using Extra Space

- Use two arrays to store which rows and columns need to be set to zero.
- If a 0 is found at any position in the matrix, update the corresponding indices in the two arrays to -1.
- Finally, check these arrays and update the entire corresponding row or column to zero.

### Code:

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> row(m, 0), col(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = -1;
                    col[j] = -1;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (row[i] == -1 || col[j] == -1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
```

**Time Complexity** - O(m*n)  
**Space Complexity** - O(m*n)



# Approach 2: Without Using Extra Space
- Instead of using two separate arrays as mentioned in the previous approach, utilize the first row and first column of the given matrix.

- If a 0 is found at any index in the matrix, set the corresponding first element of its row and column to 0.

- To handle the first row and first column, use two variables to track if there are any 0s in the first row and first column. If necessary, update the entire first row and column to 0 at the end.

```cpp

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int col0 = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    if (j != 0) {
                        matrix[0][j] = 0;
                    } else {
                        col0 = 0;
                    }
                }
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (matrix[0][0] == 0) {
            for (int i = 0; i < n; i++) {
                matrix[0][i] = 0;
            }
        }
        if (col0 == 0) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
```
**Time Complexity** - O(m*n)  
**Space Complexity** - O(1)
