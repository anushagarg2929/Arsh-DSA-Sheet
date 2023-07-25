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

//https://leetcode.com/problems/rearrange-array-elements-by-sign/
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> neg, pos;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] >= 0){
                pos.push_back(nums[i]);
            }else{
                neg.push_back(nums[i]);
            }
        }
        for(int i=0; i<nums.size()/2; i++){
            nums[2*i] = pos[i];
            nums[2*i+1] = neg[i];
        }
        return nums;
    }
};

//https://leetcode.com/problems/next-permutation/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};

//https://www.codingninjas.com/codestudio/problems/superior-elements_6783446?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
vector<int> superiorElements(vector<int>&a) {
    // Write your code here.
    vector<int> ans;
    int n = a.size();
    int max = INT_MIN;
    for(int j=n-1; j>=0; j--){
        if(a[j]>max){
            ans.push_back(a[j]);
            max = a[j];
        }
    }
    return ans;
}
