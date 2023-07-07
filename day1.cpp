//https://leetcode.com/problems/move-zeroes/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       if(nums.size() == 1)
       return;
        int l = 0, r = 0;
       while(r < nums.size()){
           if(nums[r] != 0){
               swap(nums[l], nums[r]);
           l++;
           }
           r++;
       }
    }
};

//https://leetcode.com/problems/set-matrix-zeroes/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> visited = matrix;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    for(int k=0; k<m; k++){
                        visited[i][k] = 0;
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    for(int k=0; k<n; k++){
                        visited[k][j] = 0;
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                matrix[i][j] = visited[i][j];
            }
        }
    }
};

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max1 = 0;
        int n = prices.size();
        int min1 = INT_MAX;
        for(int i=0; i<n; i++){
            
                min1 = min(min1, prices[i]);
                max1 = max(max1, prices[i] - min1);
            
        }
        return max1;
    }
};

//https://www.geeksforgeeks.org/chocolate-distribution-problem/
int findMinDiff(int arr[], int n, int m){
    if(m ==0 || n == 0){
        return 0;
    }
    sort(arr, arr+n);

    if(n < m){
        return -1;
    }

    int min_diff = INT_MAX;

    for(int i=0; i<n; i++){
        int diff = arr[i + m -1] - arr[i];
        if(diff < min_diff){
            min_diff = diff;
        }
    }
    return min_diff;
}
