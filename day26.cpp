//https://leetcode.com/problems/string-to-integer-atoi/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;

        // Skip leading whitespace
        while (i < s.length() && s[i] == ' ') {
            i++;
        }

        // Check for a sign character
        if (i < s.length() && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        return helper(s, i, sign);
    }

    int helper(string s, int i, int sign) {
        long long result = 0; // Use a long long to handle potential overflow
        while (i < s.length() && isdigit(s[i])) {
            int digit = s[i] - '0';
            result = result * 10 + digit;
            // Check for overflow
            if (result > INT_MAX) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            i++;
        }
        return result * sign;
    }
};

//https://leetcode.com/problems/powx-n/
class Solution {
    private:
    double power(double x, int n){
         if(n == 0){
            return 1.0;
        }
        double half = power(x, n/2);
        if(n%2 == 0){
            return half * half;
        }else{
            return half * half * x;
        }
    }
public:
   double myPow(double x, int n){
       long long N = n;
       if(N < 0){
           x = 1 / x;
           N = -N;
       }
       return power(x, N);
   }
};
