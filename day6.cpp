//https://www.codingninjas.com/codestudio/problems/largest-element-in-the-array-largest-element-in-the-array_5026279?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
int largestElement(vector<int> &arr, int n) {
    sort(arr.begin(), arr.end());
    return arr[arr.size() - 1];
}

//https://www.codingninjas.com/codestudio/problems/ninja-and-the-second-order-elements_6581960?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
vector<int> getSecondOrderElements(int n, vector<int> a) {
    sort(a.begin(), a.end());
    vector<int> t;
    t.push_back(a[n-2]);
    t.push_back(a[1]);
    return t;
}

//https://www.codingninjas.com/codestudio/problems/ninja-and-the-sorted-check_6581957?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
class Solution {
public:
    bool check(vector<int>& nums) {
      int i, j;
      int n = nums.size();
      for(int i =1; i<n; i++){
          if(nums[i] >= nums[i-1])
          continue;
          else if(nums[i] < nums[i-1]){
              if(nums[i]>nums[0])
              return false;
              for(j = i+1; j<n; j++){
                  if(nums[j] >= nums[j-1] && nums[j] <= nums[0]){
                      continue;
                  }else{
                      return false;
                  }
              }
          }
      }
      return true;
    }
};

//https://leetcode.com/problems/remove-duplicates-from-sorted-array/#:~:text=Input%3A%20nums%20%3D%20%5B0%2C,%2C%203%2C%20and%204%20respectively.
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

//https://leetcode.com/problems/rotate-array/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       int n = nums.size();
       vector<int> a(n);
       for(int i=0; i<n; i++){
           a[(i+k)%n] = nums[i];
       }
       nums = a;
    }
};

//https://www.codingninjas.com/codestudio/problems/left-rotate-an-array-by-one_5026278?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
vector<int> rotateArray(vector<int>& arr, int n) {
    int i = 0;
    int j = i+1;

    while(i < n-1){
        swap(arr[i], arr[j]);
        i++;
        j++;
    }
return arr;
}
