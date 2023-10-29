//https://leetcode.com/problems/count-good-numbers/
#define mod 1000000007
class Solution {
private:
    long long power(long long x, long long n){
        if(n == 0){
            return 1;
        }
        long long ans = power(x, n/2);
        ans *= ans;
        ans %= mod;
        if(n%2 == 1){
            ans *= x;
            ans %= mod;
        }
        return ans;
    }
public:
    int countGoodNumbers(long long n) {
        long long numberOfOddPlaces = n/2;
        long long numberOfEvenPlaces = n/2 + n%2;
        return (power(5, numberOfEvenPlaces) * power(4, numberOfOddPlaces))%mod;
    }
};

//https://www.codingninjas.com/codestudio/problems/sort-stack_1229505?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
#include <iostream>
#include <stack>

using namespace std;

void insertAtBottom(stack<int>& st, int item) {
    if (st.empty() || item > st.top()) {
        st.push(item);
    } else {
        int temp = st.top();
        st.pop();
        insertAtBottom(st, item);
        st.push(temp);
    }
}

void sortStack(stack<int>& st) {
    if (!st.empty()) {
        int temp = st.top();
        st.pop();
        sortStack(st);
        insertAtBottom(st, temp);
    }
}

int main() {
    stack<int> st;
    st.push(7);
    st.push(3);
    st.push(5);
    st.push(2);
    st.push(1);

    sortStack(st);

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}

//https://www.codingninjas.com/studio/problems/reverse-stack-using-recursion_631875?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetufv
void reverseStack(stack<int> &stack) {
    std::stack<int>s1;

while(!stack.empty()){

    s1.push(stack.top());

    stack.pop();

}
stack=s1;
}
