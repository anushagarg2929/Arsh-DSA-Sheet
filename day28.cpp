//https://www.codingninjas.com/studio/problems/-binary-strings-with-no-consecutive-1s._893001?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
void generateBinaryString(int n, string current, vector<string> &result){
    if(n == 0){
      result.push_back(current);
      return;
    }
    generateBinaryString(n-1, current + "0", result);

    if(current.empty() || current.back() == '0'){
        generateBinaryString(n-1, current+"1", result);
    }
}
vector<string> generateString(int N) {
    // Write your code here.
    vector<string> result;
    generateBinaryString(N, "", result);
    return result;
}

//https://leetcode.com/problems/generate-parentheses/
class Solution {
public:
    void generateParenthesisHelper(string current, int left, int right, int n, vector<string> &result){
        if(current.size() == 2*n){
            result.push_back(current);
            return;
        }
        if(left < n){
            generateParenthesisHelper(current + '(', left + 1, right, n, result);
        }
        if(right < left){
            generateParenthesisHelper(current + ')', left, right+1, n, result);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParenthesisHelper("", 0, 0, n, result);
        return result;
    }
};

//https://leetcode.com/problems/subsets/
#include <vector>
class Solution {
private:
    void subseq(vector<int>& nums, int index, vector<int> &current, vector<vector<int>> &ans){
       ans.push_back(current);

       for(int i = index; i<nums.size(); i++){
           current.push_back(nums[i]);
           subseq(nums, i+1, current, ans);
           current.pop_back();
       }
   }
  
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        subseq(nums, 0, current, ans);
        return ans;
    }
};