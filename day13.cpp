//https://leetcode.com/problems/pascals-triangle/
class Solution {
public:

    vector<int> generateRow(int row){
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1);
        for(int col = 1; col < row; col++){
            ans = ans * (row-col);
            ans = ans / (col);
            ansRow.push_back(ans);
        }
        return ansRow;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1; i<=numRows; i++){
            ans.push_back(generateRow(i));
        }
      return ans;
    }
};

//https://leetcode.com/problems/majority-element-ii/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ls;
        int count = int(n/3) + 1;
        map<int, int> mpp;

        for(int i=0; i<n; i++){
            mpp[nums[i]]++;

            if(mpp[nums[i]] == count){
                ls.push_back(nums[i]);
            }
            if(ls.size() == 2)
            break;
        }
        return ls;
    }
};

//https://leetcode.com/problems/binary-search/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(nums[i] == target){
                return i;
                break;
            }
        }
        return -1;
    }
};

//https://www.codingninjas.com/codestudio/problems/lower-bound_8165382?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here
	int count = 0;
	for(int i=0; i<n; i++){
		if(arr[i] < x){
           count++;
		}
	}
	return count;
}

//https://www.codingninjas.com/studio/problems/implement-upper-bound_8165383?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
int upperBound(vector<int> &arr, int x, int n){
	// Write your code here.
	int l = 0, r = n-1;	
	int count = n;
   while(l<=r){
	   int mid = (l+r)/2;
	   if(arr[mid] > x){
		   count = mid;
		   r = mid-1;
	   }else{
		   l = mid+1;
	   }
   }
   return count;
}