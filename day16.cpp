//https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
class Solution {
public:

    bool possible(vector<int> &bloomDay, int day, int m, int k){
        int n = bloomDay.size();
        int count = 0;
        int noOfB = 0;

        for(int i=0; i<n; i++){
            if(bloomDay[i] <= day){
                count++;
            }else{
                noOfB += (count/k);
                count = 0;
            }
        }
        noOfB += (count/k);
        return noOfB >= m;
    }

    void arrayMinMax(vector<int> &bloomDay, int &minElement, int &maxElement){
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i] < minElement){
                minElement = bloomDay[i];
            }
            if(bloomDay[i] > maxElement){
                maxElement = bloomDay[i];
            }
        }
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long val=m*1ll*k*1ll;
        int minDays = INT_MAX, maxDays = INT_MIN;
        if(val > n){
            return -1;
        }
         arrayMinMax(bloomDay, minDays, maxDays);
         while(minDays <= maxDays){
            int mid = minDays + (maxDays - minDays)/2;
            if(possible(bloomDay, mid, m, k)){
                maxDays = mid - 1;
            }else{
                minDays = mid + 1;
            }
         }
        return minDays;
    }
};

//https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
class Solution {
public:

    int sumByD(vector<int> &nums, int div){
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += ceil((double)(nums[i]) / (double)(div));
        }
        return sum;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        if(n > threshold){
            return -1;
        }
        int low = 1, high = *max_element(nums.begin(), nums.end());

        while(low<=high){
            int mid = (low+high)/2;
            if(sumByD(nums, mid) <= threshold){
                high = mid -1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};

//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low =0 ;
        int high = nums.size()-1;
        int ans = INT_MAX;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[low] <= nums[high]){
                ans = min(ans, nums[low]);
                break;
            }
            if(nums[low] <= nums[mid]){
                ans = min(ans, nums[low]);
                low = mid + 1;
            }else{
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};

//https://www.codingninjas.com/codestudio/problems/rotation_7449070?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
#include<bits/stdc++.h>
int findKRotation(vector<int> &arr){
    // Write your code here.
       int n = arr.size();
       int low = 0, high = n-1;
       int mini = INT_MAX;
       int index = 0;
       while(low <= high){
           int mid = (low+high)/2;
           if(arr[mid] < mini){
               mini = arr[mid];
               index = mid;
           }
           if(arr[mid] < arr[high]){
               high = mid-1;
           }else{
               low = mid+1;
           }
       } 
       return index;
}

//https://leetcode.com/problems/single-element-in-a-sorted-array/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
    
       int low = 0, high = n-1;
       while(low < high){
           int mid = (low + high)/2;
          if(mid % 2 == 1){
              mid--;
          }
          if(nums[mid] != nums[mid+1]){
              high = mid;
          }else{
              low = mid + 2;
          }
       } 
       return nums[low];
    }
};
