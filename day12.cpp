//https://leetcode.com/problems/spiral-matrix/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> result;
        int row_start = 0,  row_end = rows - 1, col_start = 0, col_end = cols-1;
        while(row_start <= row_end && col_start <= col_end){
            for(int i = col_start; i <= col_end; i++){
                result.push_back(matrix[row_start][i]);
            }
            row_start++;

            for(int i = row_start; i <= row_end; i++){
                result.push_back(matrix[i][col_end]);
            }
            col_end--;
            if(row_start <= row_end){
            for(int i = col_end; i>= col_start; i--){
                result.push_back(matrix[row_end][i]);
            }
            row_end--;
        }
            if(col_start <= col_end){
            for(int i = row_end; i>=row_start; i--){
                result.push_back(matrix[i][col_start]);
            }
            col_start++;
            }
        }
        return result;
    }
};

//https://leetcode.com/problems/subarray-sum-equals-k/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mpp;
        mpp[0] = 1;
        int sum = 0;
        int count =0;
        for(int i=0 ;i<n; i++){
           sum += nums[i];
           int remove = sum - k;
           count += mpp[remove];
           mpp[sum] += 1;
        }
        return count;
    }
};

//https://leetcode.com/problems/subarray-sums-divisible-by-k/
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int psum = 0;
        int res = 0;

        unordered_map<int, int> hash;

        hash[0] = 1;

        int n = nums.size();

        for(int i=0; i<n; i++){
            psum += nums[i];

            int modded = psum % k;

            if(modded < 0){
            modded += k;
            }
            res += hash[modded];

            hash[modded]++;
        }
        return res;
    }
};

//https://leetcode.com/problems/find-all-duplicates-in-an-array/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;

        unordered_map<int, int> mp;

        for(auto e:nums){
            mp[e]++;
        }
        for(auto m:mp){
            if(m.second == 2){
                ans.push_back(m.first);
            }
        }
        return ans;
    }
};