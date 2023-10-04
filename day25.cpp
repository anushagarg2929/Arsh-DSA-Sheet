//https://leetcode.com/problems/minimum-bit-flips-to-convert-number/
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xor_results = start ^ goal;
        int count = 0;
        while(xor_results){
            count += xor_results & 1;
            xor_results >>= 1;
        }
        return count;
    }
};

//https://leetcode.com/problems/single-number/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
      int n = nums.size();
      for(int i=0; i<n-1; i++){
       nums[i+1] = nums[i] ^ nums[i+1];
      }
      return nums[n-1];
    }
};

//https://leetcode.com/problems/subsets/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int Mask = 1<<n; 
        vector<vector<int>>powerSet(Mask);
        for(int m=0; m<Mask; m++){
            for(int i=0; i<n; i++){
                if(m& 1<<i){
                    powerSet[m].push_back(nums[i]);
                }
            }
        }
        return powerSet;
    }
};
