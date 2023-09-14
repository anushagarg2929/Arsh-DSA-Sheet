// https://www.codingninjas.com/codestudio/problems/median-of-a-row-wise-sorted-matrix_1115473?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
int median(vector<vector<int>> &matrix, int m, int n) {
    // Write your code here.
    vector<int> idx(m,n);
    vector<int> temp;
    for(auto it : matrix){
        temp.insert(temp.end(), it.begin(), it.end());
    }
    sort(temp.begin(), temp.end());
    return temp[n*m / 2];
  
}

//https://www.codingninjas.com/studio/problems/isomorphic-strings-_1117636?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
#include <unordered_map>
bool areIsomorphic(string &str1, string &str2)
{
    // Write your code here
     if(str1.size() != str2.size()){
         return false;
     }
    vector<int> a(26), b(26);
    for(int i=0; i<str1.size(); i++){
        a[str1[i] - 'a']++;
        b[str2[i] - 'a']++;
    }
    sort(a.begin(),a.end());
    sort(b.begin(), b.end());
    for(int i=0; i<a.size(); i++){
        if(a[i] != b[i]){
            return false;
        }
    }
    return true;

}

//https://leetcode.com/problems/rotate-string/
class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()){
            return false;
        }
        string ans = s+s;
        if(ans.find(goal) != string::npos){
            return true;
        }
        return false;
    }
};

//https://leetcode.com/problems/valid-anagram/#:~:text=Given%20two%20strings%20s%20and,the%20original%20letters%20exactly%20once.&text=Constraints%3A,.length%20%3C%3D%205%20*%2010
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        for(int i=0; i<s.size(); i++){
            if(s[i] != t[i]){
                return false;
            }
        }
        return true;
    }
};

//https://leetcode.com/problems/sort-characters-by-frequency/
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(char ch:s){
            mp[ch]++;
        }
        string ans;

        while(! mp.empty()){
            char mostFrequentChar = ' ';
            int maxFreq = 0;
            for(auto key : mp){
                if(key.second > maxFreq){
                        maxFreq = key.second;
                        mostFrequentChar = key.first;
                    
                }
            }
                while(maxFreq > 0){
                    ans += mostFrequentChar;
                    maxFreq--;
                }
                mp.erase(mostFrequentChar);
            }
        return ans;
    }
};