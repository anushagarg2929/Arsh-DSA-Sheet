//https://leetcode.com/problems/search-a-2d-matrix/
class Solution {
public:

    bool binarySearch(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0;
        int high = n-1;

        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] == target){
                return true;
            }else if(nums[mid] < target){
                low = mid+1;
            }else{
                high = mid - 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         int n = matrix.size();
    int m = matrix[0].size();
        for(int i=0; i<n; i++){
            if(matrix[i][0] <= target && target <= matrix[i][m-1]){
                return binarySearch(matrix[i], target);
            }
        }
        return false;
    }
};

//https://leetcode.com/problems/search-a-2d-matrix-ii/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int n = matrix.size();
       int m = matrix[0].size();

       int row = 0; int col = m-1;

       while(row < n && col >= 0){
           if(matrix[row][col] == target){
               return true;
           }else if(matrix[row][col] < target){
               row++;
           }else{
               col--;
           }
             }
             return false;
    }
};

//https://leetcode.com/problems/find-a-peak-element-ii/
class Solution {
public:
    int findMax(vector<vector<int>>& mat, int col){
        int maxRow = 0;
        for(int i=0; i<mat.size(); i++){
            maxRow = mat[i][col] >= mat[maxRow][col] ? i : maxRow;
        }
        return maxRow;
    }


    bool predicate(int midCol, vector<vector<int>>& mat, int leftCol, int rightCol){
        int maxRow = findMax(mat, midCol);
        bool rejectRight = midCol + 1 <= rightCol && mat[maxRow][midCol + 1] < mat[maxRow][midCol];
        return rejectRight;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int leftCol = 0;
        int rightCol = mat[0].size() - 1;
        while(leftCol < rightCol){
            int midCol = leftCol + (rightCol - leftCol) /2 ;
            if(predicate(midCol, mat, leftCol, rightCol)){
                rightCol = midCol;
            }else{
                leftCol = midCol + 1;
            }
        }
        int maxRow = findMax(mat, leftCol);
        return vector<int>{maxRow, leftCol};
    }
};

//https://leetcode.com/problems/largest-odd-number-in-string/
class Solution {
public:
    string largestOddNumber(string num) {
        string s = "";
       int idx = -1;

       for(int i=num.length()-1; i>=0; i--){
           if((num[i] - '0') % 2 != 0){
               idx = i;
               break;
           }
       }
       if(idx != -1){
           for(int i=0; i<= idx; i++){
               s += num[i];
           }
       }
       return s;
    }
};

//https://leetcode.com/problems/longest-common-prefix/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
       ans = strs[0];
        for(int i=0; i<strs.size(); i++){
            for(int j=0; j<ans.size(); j++){
                if(strs[i][j] != ans[j]){
                    ans = ans.substr(0, j);
                }
            }
        }
        return ans;
    }
};