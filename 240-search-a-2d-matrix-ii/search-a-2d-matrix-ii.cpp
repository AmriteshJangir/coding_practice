class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty())
            return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0;
        int col = n - 1;
        while(row < m && col >= 0) {
            if(matrix[row][col] == target)
                return true;
            else if(matrix[row][col] < target)
                row++;
            else
                col--;
        }
        return false;
    }
};

// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         int low = 0;
//         int high = m * n - 1;
//         while (low <= high) {
//             int mid = low + (high - low) / 2;
//             int row = mid / n;
//             int col = mid % n;
//             if (matrix[row][col] == target)
//                 return true;
//             else if (matrix[row][col] < target)
//                 low = mid + 1;
//             else
//                 high = mid - 1;
//         }
//         return false;
//     }
// };