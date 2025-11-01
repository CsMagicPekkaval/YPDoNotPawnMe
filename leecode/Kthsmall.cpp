class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];Kt
            int j = n - 1;

            for (int i = 0; i < n; i++) {
                while (j >= 0 && matrix[i][j] > mid) {
                    j--;
                }
                count += (j + 1);  
            }

            if (count < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;  
    }
};

//https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
