// class Solution {
// public:
//     int kthSmallest(vector<vector<int>>& matrix, int k) {
//         int n = matrix.size();
//         int low = matrix[0][0],high = matrix[n-1][n-1];
//         while(low <= high){
//             int mid = low+(high-low)/2;
//             int c=0;
//             int i=n-1,j=0;while(i >= 0 && j < n) {
//                 if(matrix[i][j] <= mid) {
//                     c = c + i + 1;
//                     j++;
//                 } else {
//                     i--;
//                 }
//             }
//             if(c >= k) high = mid - 1;
//             else low = mid + 1;
//         }
//         return low;
//     }
// };
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l = matrix[0][0];
        int r = matrix[n - 1][m - 1];
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int count = 0;
            int mx = l;
            for (int row = 0; row < n; row++) {
                int col = m - 1;
                while (col >= 0 && matrix[row][col] > mid) {
                    col--;
                }
                if (col >= 0) {
                    count += col + 1;
                    mx = max(mx, matrix[row][col]);
                }
            }
            if (count == k)
                return mx;
            if (count < k)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l;
    }
};