//https://leetcode.com/problems/power-of-two/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && not(n & n-1);
    }
};

//https://www.codingninjas.com/studio/problems/count-total-set-bits_784?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
int Count(int n){
    int count = 0;
    while(n!=0){
        if(n & 1 == 1){
            count++;
        }
        n = n>>1;
    }
    return count;
}
int countSetBits(int N)
{
    //Write your code here
    int ans = 0;
    for(int i=1; i<=N; i++){
       ans = ans + Count(i);
    }
    return ans;
}

//https://www.codingninjas.com/studio/problems/set-the-rightmost-unset-bit_8160456?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
int setBits(int N){
    // Write your code here.
    if((N^N+1) == (N<<1)+1){
        return N;
    }else{
        return (N | N+1);
    }
}

//https://www.codingninjas.com/studio/problems/swap-two-numbers_1380853?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
void swapNumber(int &a, int &b) {
  // Write your code here.
  a = a+b;
  b = a-b; 
  a = a-b;

}

//https://leetcode.com/problems/divide-two-integers/
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        }
        long dvd = labs(dividend), dvs = labs(divisor), ans = 0;
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        while(dvd >= dvs){
            long temp = dvs, m = 1;
            while(temp << 1 <= dvd){
                temp <<=1;
                m<<=1;
            }
            dvd -= temp;
            ans += m;
        }
        return sign*ans;
    }
};