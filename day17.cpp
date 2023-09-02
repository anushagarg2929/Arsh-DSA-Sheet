//https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
class Solution {
public:
    bool predicate(int min_cap, vector<int> &weights, int days){
        int day = 1;
        int total = 0;
        for(auto weight: weights){
            total += weight;
            if(total>min_cap){
                total = weight;
                day++;
                if(day>days){
                    return false;
                }
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l =* max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        while(l<r){
            int m = l + (r-l) /2;
            if(predicate(m, weights, days)){
                r = m;
            }else{
                l = m+1;
            }
        }
        return l;
    }
};

//https://leetcode.com/problems/kth-missing-positive-number/#:~:text=Given%20an%20array%20arr%20of,13%2C...%5D.
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size() - 1;
        while(low <= high){
        int mid = (low+ high)/2;
        int missing = arr[mid] - (mid + 1);
        if(missing < k){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
        }
        return k + high + 1;
    }
};

//https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
bool canWePlace(vector<int> &stalls, int dist, int cows){
    int n = stalls.size();
    int cntCows = 1;
    int last = stalls[0];
    for(int i=1; i<n; i++){
        if(stalls[i] - last >= dist){
            cntCows++;
            last = stalls[i];
        }
        if(cntCows >= cows){
            return true;
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());

    int low = 1; int high = stalls[n-1] - stalls[0];

    while(low <= high){
        int mid = (low+high)/2;
        if(canWePlace(stalls, mid, k) == true){
            low = mid+1;
        }else{
            high = mid - 1;
        }
    }
    return high;
}

//https:leetcode.com/problems/find-peak-element/#:~:text=Find%20Peak%20Element%20%2D%20LeetCode&text=A%20peak%20element%20is%20an,to%20any%20of%20the%20peaks.
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
         if (n == 1) return 0;
         if (nums[0] > nums[1]) return 0;
         if (nums[n - 1] > nums[n - 2]) return n - 1;
        int low = 1;
        int high = n-2;
        while(low <= high){
          int mid = (low + high)/2;
          if(nums[mid-1]< nums[mid] && nums[mid] > nums[mid+1]){
              return mid;
          }
          if(nums[mid] > nums[mid-1]){
              low = mid+1;
          }else{
              high = mid - 1;
          }
        }
        return -1;
    }
}

//https://bit.ly/3MZQOct
int countStudents(vector<int> &arr, int pages){
    int n = arr.size();
    int students = 1; 
    long long pagesStudent = 0;
    for(int i=0; i<n; i++){
        if(pagesStudent + arr[i] <= pages){
            pagesStudent += arr[i];
        }else{
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if( m > n){
        return -1;
    }
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while(low <= high){
        int mid = (low+high)/2;
        int students = countStudents(arr, mid);
        if(students > m){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return low;
}