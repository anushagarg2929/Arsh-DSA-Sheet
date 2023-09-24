//https://leetcode.com/problems/longest-palindromic-substring/
class Solution {
private:
    bool check(string &s, int i, int j){
        while(i<j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int starting_index = 0;
        int max_len = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(check(s, i, j)){
                    if(j-i+1 > max_len){
                        max_len = j - i + 1;
                        starting_index = i;
                    }
                }
            }
        }
        return s.substr(starting_index, max_len);
    }
};

//https://leetcode.com/problems/sum-of-beauty-of-all-substrings/
class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        for(int i=0; i<s.length(); i++){
            map<char, int> mp;
            for(int j=i; j<s.length(); j++){
                int mx = 0, mn = 501;
                mp[s[j]]++;
                for(auto it : mp){
                    mx = max(mx, it.second);
                    mn = min(mn, it.second);
                }
                ans += mx-mn;
            }
        }
        return ans;
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

//https://www.codingninjas.com/studio/problems/check-whether-k-th-bit-is-set-or-not_5026446?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
bool isKthBitSet(int n, int k)
{
    // Write your code here.
    int mask = 1<<k-1;
    bool set = mask & n;
}

//https://www.codingninjas.com/codestudio/problems/odd-even_7993579?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
string oddEven(int N){
    // Write your code here.
    if((N^1) == (N-1)){
        return "odd";
    }else{
        return "even";
    }
}