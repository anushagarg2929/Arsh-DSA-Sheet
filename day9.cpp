//Strivers - https://leetcode.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];
            if(map.find(complement) != map.end()){
                return {map[complement], i};
            }
            map[nums[i]] = i;
        }
        return {-1, -1};
    }
};

//https://leetcode.com/problems/sort-colors/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        //int arr[n];
        int l =0, r = n-1;
        int i = 0;

        while(i <= r){
            if(nums[i] == 0)
            swap(nums[i++], nums[l++]);
            else if(nums[i] == 2)
            swap(nums[i], nums[r--]);
            else
            i++;
        }
    }
};

//https://leetcode.com/problems/majority-element/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mid = nums.size()/2;
        return nums[mid];
    }
};

//https://leetcode.com/problems/maximum-subarray/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = INT_MIN;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            sum += nums[i];
            if(sum > maxi){
                maxi = sum;
            }
            if(sum < 0){
                sum = 0;
            }
        }
    
return maxi;
    }
};