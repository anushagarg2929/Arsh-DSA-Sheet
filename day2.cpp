//Striver's - https://www.codingninjas.com/studio/problems/k-most-occurrent-numbers_625382?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
vector<int> getFrequencies(vector<int>& v) {
    // Write Your Code Here
    unordered_map<int, int> mp;

    int n = v.size();

    for(int i = 0; i<n; i++){
       mp[v[i]]++;
    }

    int maxFreq = 0, int minFreq = n;
    int maxEle = 0, int minEle = 0;

    for(auto it : mp){

        int count = it.second;
        int element = it.first;

        if(count > maxFreq){
            maxEle = element;
            maxFreq = count;
        }

        if(count < minFreq){
            minEle = element;
            maxFreq = count;
        }
    } 
     return maxEle, minEle;
}

//https://leetcode.com/problems/find-the-duplicate-number/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size()-1, cnt;

        while(low <= high){
            int mid = low + (high - low) /2;
            cnt = 0;

            for(int n : nums){
                if(n <= mid)
                ++cnt;
            }
            if(cnt <= mid)
            low = mid + 1;
            else
            high = mid - 1;
        }
        return low;
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

//https://leetcode.com/problems/remove-duplicates-from-sorted-array/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        map<int, int> m;
        for(int i=0; i<n; i++){
            m[nums[i]]++;
        }
        int c = 0;
        for(auto i : m){
            nums[c++] = i.first;
        }
        return c;
    }
};
