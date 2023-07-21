//https://leetcode.com/problems/max-consecutive-ones/
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int max1 = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 1){
                count++;
            }else{
                count = 0;
            }
            max1 = max(max1, count);
        }
        return max1;
    }
};

//https://leetcode.com/problems/single-number/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
       unordered_map<int, int> mp;
       int n = nums.size();
       for(int i=0; i<n; i++){
           mp[nums[i]]++;
       }
       int ans;
       for(auto x: mp){
           if(x.second == 1){
               ans = x.first;
               break;
           }
       }
       return ans;
    }
};

//https://www.codingninjas.com/codestudio/problems/longest-subarray-with-sum-k_6682399?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int s = 0, e = 0;
    long long sum = a[0];
    int n =a.size();
    int ans = 0;

    while(e<n){
        while(s<=e && sum>k){
            sum -=a[s++];
        }
        if (sum == k) {
          ans = max(ans, e - s + 1);
        }
            e++;
            if(e<n){
                sum += a[e];
            }
    }
    return ans;
}

//https://www.codingninjas.com/studio/problems/longest-subarray-with-sum-k_5713505?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
#include <bits/stdc++.h> 
int getLongestSubarray(vector<int>& nums, int k){
    // Write your code here
    int n = nums.size();

    long long sum = 0;
    int maxlen = 0;

    map<long long, int> pmap;
    for(int i=0; i<n; i++){
        sum += nums[i];
        if(sum == k){
            maxlen = i+1;
        }
    int rem = sum-k;

    if(pmap.find(rem) != pmap.end()){
        int len = i-pmap[rem];
        maxlen = max(maxlen, len);
    }
    if (pmap.find(sum) == pmap.end()) {
      pmap[sum] = i;
    }
    }
    return maxlen;
}