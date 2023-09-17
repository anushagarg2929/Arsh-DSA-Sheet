//https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
class Solution {
public:
    int maxDepth(string s) {
       int maxCount = 0;
       int open = 0;
      for(char c : s){
           if(c == '('){
               maxCount = max(maxCount, ++open);
           }else if(c == ')'){
               open--;
           }
       }
       return maxCount;
    }
};

//https://leetcode.com/problems/roman-to-integer/
class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        unordered_map < char, int> mp{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        for(int i=0; i<s.size(); i++){
            if(mp[s[i]] < mp[s[i+1]]){
                ans = ans - mp[s[i]];
            }else{
                ans = ans + mp[s[i]];
            }
        }
        return ans;
    }
}; 

//https://leetcode.com/problems/string-to-integer-atoi/
class Solution {
public:
    int myAtoi(string s) {
    int i = 0, n = s.size();

        while(s[i] == ' '){ // skipping space characters at the beginning
            i++;
        }

        int positive = 0, negative = 0; 

        if(s[i] == '+'){
            positive++; // number of positive signs at the start in string
            i++;
        }

        if(s[i] == '-'){
            negative++; // number of negative signs at the start in string
            i++;
        }

        double ans = 0; 

        while(i<n and s[i] >= '0' and s[i] <= '9'){
            ans = ans*10 + (s[i] - '0'); // (s[i] - '0') is converting character to integer
            i++;
        }

        if(negative > 0) // if negative sign exist
            ans = -ans;
        if(positive > 0 and negative > 0) // if both +ve and -ve sign exist, Example: +-12
            return 0;

        if(ans > INT_MAX) // if ans > 2^31 - 1
            ans = INT_MAX;

        if(ans < INT_MIN) // if ans < 2^31
            ans = INT_MIN;

        return (int)ans;
    }
};

//https://www.codingninjas.com/studio/problems/count-with-k-different-characters_1214627?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
int coun(string str,int k){

      int i=0;

    int j=0;

    int hash[26]={0};

    int di=0;

    int c=0;

    while(j<str.length()){

        hash[str[j]-'a']++;

        if(hash[str[j]-'a']==1){

            di++;

        }

        while(di>k){

            hash[str[i]-'a']--;

            if(hash[str[i]-'a']==0){

                di--;

            }

            i++;

        }

        c=c+(j-i+1);

        j++;

    }

    return c;

}

int countSubStrings(string str, int k) 

{

    // Write your code here.

   int ans=coun(str,k)-coun(str,k-1);

   return ans;

}

//https://www.codingninjas.com/studio/problems/bit-manipulation_8142533?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
vector<int> bitManipulation(int num, int i){
    // Write your code here.
    int get;
    int set;
    int clear;
    
    i-=1;
    get = (num >> i) & 1;

    set = (1 << i) | num;

    clear = (~(1<<i)) & num;

    return {get, set, clear};
}

