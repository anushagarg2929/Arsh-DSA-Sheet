//https://www.codingninjas.com/codestudio/problems/square-root-integral_893351?leftPanelTab=0?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
int NthRoot(int n, int m) {
  // Write your code here.
  int low = 1;
  int high = m;
  while(low <= high){
    int mid = (low+high)/2;
    if(pow(mid,n) == m){
      return mid;
    }else if(pow(mid, n) > m){
      high = mid - 1;
    }else{
      low = mid + 1;
    }
  }
  return -1;
}

//https://leetcode.com/problems/koko-eating-bananas/
class Solution {
public:
    int findMax(vector<int> &piles){
        int maxi = INT_MIN;
        for(int i=0; i<piles.size(); i++){
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }
    
    double calculateTotalHours(vector<int> &piles, int h){
        double totalH = 0;
        for(int i=0; i<piles.size(); i++){
            // totalH += piles[i] / speed;
            // if(piles[i] % speed != 0){
            //     totalH++;
            // }
             totalH += ceil((double)piles[i]/(double)h);
        }
        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 0;
        int high = findMax(piles);
        while(low <= high){
        int mid = (low + high)/2;
        double totalH = calculateTotalHours(piles, mid);
        if(totalH <= h){
            high = mid-1;
        }else{
            low = mid+1;
        }
        }
        return low;
    }
};

//https://leetcode.com/problems/search-in-rotated-sorted-array/
lass Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low =0;
        int high = n - 1;
        while(low <= high){
         int mid = (high + low)/2;
         if(nums[mid] == target){
             return mid;
         }
         if(nums[low] <= nums[mid]){
             if(nums[low] <= target && target<=nums[mid]){
                 high = mid-1;
             }else{
                 low = mid+1;
             }
         }else{
             if(nums[mid] <= target && target <= nums[high]){
                 low = mid+1;
             } else{
                 high = mid -1;
             }
         }
        }
        return -1;
    }
};

//https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low<= high){
            int mid = (low+high)/2;
            if(nums[mid] == target){
                return true;
            }
            if(nums[low] == nums[mid] && nums[high] == nums[mid]){
                low = low+1;
                high = high -1;
                continue;
            }
            if(nums[low] <= nums[mid]){
                if(nums[low] <= target && target <= nums[high]){
                    high = mid-1;
                }else {
                    low = mid + 1;
                }
            }else{
                if(nums[mid] <= target && target <= nums[high]){
                    low = mid + 1;
                }else{
                    high = mid - 1;
                }
            }
        }
        return false;
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