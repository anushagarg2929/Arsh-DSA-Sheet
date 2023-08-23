//https://leetcode.com/problems/search-insert-position/#:~:text=Search%20Insert%20Position%20%2D%20LeetCode&text=Given%20a%20sorted%20array%20of,(log%20n)%20runtime%20complexity.
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int high = nums.size();
        int low = 0;
        int mid;
        if(target > nums[high-1]){
            return high;
        }
        while(low <= high){
            mid = (high+low)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(target < nums[mid]){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};

//https://www.codingninjas.com/studio/problems/ceiling-in-a-sorted-array_1825401?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
	// Write your code here.
	int low = 0;
	int high = n-1;
	sort(arr, arr+n);
	int floor = -1;
	int ceil = -1;
        while (low <= high) {
          int mid = (low + high) / 2;
          if (arr[mid] <= x){
			  floor = arr[mid];
			  low = mid+1;
		  }else{
			  high = mid-1;
		  }
        }
		low = 0;
		high = n-1;
		while(low <= high){
			int mid = (low + high) / 2;
			if(arr[mid] >= x){
				ceil = arr[mid];
				high = mid-1;
			}else{
				low = mid+1;
			}
		}
		pair<int,int> ans;
		ans.first = floor;
		ans.second = ceil;
		return ans;
}

//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int startingPosition = -1;
        int endingPosition = -1;
        for(int i=0; i<n; i++){
            if(nums[i] == target){
               startingPosition = i;
               break;
            }
        }
        for(int i=n-1; i>=0; i--){
            if(nums[i] == target){
                endingPosition = i;
                break;
            }
        }
        return {startingPosition, endingPosition};
    }
};

//Square Root of a number
int floorSqrt(int n)
{
    // Write your code here.
    return sqrt(n);
}

//https://www.codingninjas.com/codestudio/problems/occurrence-of-x-in-a-sorted-array_630456?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
int count(vector<int>& arr, int n, int x) {
	// Write Your Code Here
        int startingPosition = -1;
        int endingPosition = -1;
        for(int i=0; i<n; i++){
            if(arr[i] == x){
               startingPosition = i;
               break;
            }
        }
        for(int i=n-1; i>=0; i--){
            if(arr[i] == x){
                endingPosition = i;
                break;
            }
        }
        int ans = endingPosition - startingPosition + 1;
        if(startingPosition != -1 && endingPosition != -1){
            return ans;
            }else{
                return 0;
                }
}