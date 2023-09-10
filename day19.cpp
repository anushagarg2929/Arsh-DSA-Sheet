//https://leetcode.com/problems/median-of-two-sorted-arrays/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1 > n2){
            return findMedianSortedArrays(nums2, nums1);
        }
        int n = n1 + n2;
        int left = (n1 + n2 + 1)/2;

        int low = 0, high = n1;
        while(low <= high){
            int mid1 = (low + high)>>1;
            int mid2 =  left - mid1;

            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if(mid1 < n1){
                r1 = nums1[mid1];
            }else{
                r2 = nums2[mid2];
            }
            if(mid1 - 1 >=0){
                l1 = nums1[mid1 - 1];
            }
            if(mid2 - 1 >= 0){
                l2 = nums2[mid2-1];
            }

            if(l1 <= r2 && l2 <= r1){
                if(n % 2 == 1){
                    return max(l1, l2);
                }else{
                    return ((double)(max(l1, l2) + min(r1,r2))) / 2.0;
                }
            }else if(l1 > r2){
                high = mid1 -1;
            }else{
                low = mid1 +1;
            }
         }
         return 0;
    }
};

//https://leetcode.com/problems/remove-outermost-parentheses/
class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int opened = 0;
        for(char c : s){
            if(c == '(' && opened++ > 0){
                res += c;
            }
            if(c == ')' && opened-- > 1){
                res += c;
            }
        }
        return res;
    }
};

//https://leetcode.com/problems/reverse-words-in-a-string/
class Solution {
public:
    string reverseWords(string s) {
       int n = s.size();
       int i = 0;
       string ans = "";
       while(i<n){
           string tm="";
           while(s[i] == ' ' && i < n){
               i++;
           }
           while(s[i] != ' ' && i < n){
               tm += s[i];
               i++;
           }
           if(tm.size() > 0){
               if(ans.size() == 0){
                   ans = tm;
               }else{
                   ans = tm + " " + ans;
               }
           }
       }
       return ans;
    }
};

//https://www.codingninjas.com/codestudio/problems/k-th-element-of-2-sorted-array_1164159?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
#include<bits/stdc++.h>
int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
    // Write your code here
     if(m > n) {
        return kthElement(arr2, arr1, n, m, k); 
    }
        
    int low = max(0,k-m), high = min(k,n);
        
    while(low <= high) {
        int cut1 = (low + high) >> 1; 
        int cut2 = k - cut1; 
        int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1]; 
        int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
        int r1 = cut1 == n ? INT_MAX : arr1[cut1]; 
        int r2 = cut2 == m ? INT_MAX : arr2[cut2]; 
            
        if(l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        }
        else if (l1 > r2) {
            high = cut1 - 1;
        }
        else {
            low = cut1 + 1; 
        }
    }
    return 1; 
}

//https://www.codingninjas.com/codestudio/problems/row-of-a-matrix-with-maximum-ones_982768?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    //    Write your code here.
    int cnt = 0;
    int index = -1;
    for(int i=0 ; i< n; i++){
        int cnt_ones = 0;
        for(int j = 0;j<m; j++){
            cnt_ones += matrix[i][j];
          
        }
            if(cnt_ones > cnt){
                cnt = cnt_ones;
                index = i; 
        }
    }
    return index;
}