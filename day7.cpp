//https://www.codingninjas.com/codestudio/problems/linear-search_6922070?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
int linearSearch(int n, int num, vector<int> &arr)
{
    for(int i=0; i<n; i++){
        if(arr[i] == num){
            return i;
        }
    }
    return -1;
}

//https://www.codingninjas.com/codestudio/problems/sorted-array_6613259?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
vector < int > sortedArray(vector < int > a, vector < int > b) {
    // Write your code here
    
    vector<int> v;
    vector<int> ans;
        
   for(int i=0; i<a.size(); i++){
       v.push_back(a[i]);
   }
   for(int i=0; i<b.size(); i++){
       v.push_back(b[i]);
   }
   sort(v.begin(), v.end());
   ans.push_back(v[0]);
   for(int i=1; i<(a.size() + b.size()); i++){
       if(v[i] != v[i-1])
       ans.push_back(v[i]);
   }
    return ans;
}

//https://leetcode.com/problems/missing-number/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (n*(n+1))/2;

        int s2 = 0;

        for(int i=0; i<n; i++){
        s2 += nums[i];
        }
        int missingNum = sum - s2;
        return missingNum;
    }
};

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