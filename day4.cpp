//https://leetcode.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];
            if(map.find(complement) != map.end()){
                return {map[complement], i};
            }
            map[nums[i]] = i;
        }
        return {-1, -1};
    }
};

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> prev(2,0);
        vector<int> curr(2, 0);

        for(int idx = n-1; idx>=0; idx--){
            for(int buy = 0; buy <= 1; buy++){
                int profit = 0;
                if(buy){
                    int take = - prices[idx] + prev[0];
                    int notTake = prev[1];

                    profit = max(take, notTake);
                }else{
                    int take = prices[idx] + prev[1];
                    int notTake = prev[0];

                    profit = max(take, notTake);
                }
                curr[buy] = profit;
            }
            prev = curr;
        }
        return prev[1];
    }
};

//Striver's : https://www.codingninjas.com/studio/problems/selection-sort_624469?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0
void selectionSort(vector<int>&arr) {
    // Write your code here.
    int n = arr.size();
    for(int i = 0; i<n-1; i++){
        int mini = i;
        for(int j = i+1; j<n; j++){
          if (arr[j] < arr[mini]) {
            mini = j;
          }
        }
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
}

//Striver's : https://www.codingninjas.com/studio/problems/bubble-sort_624380?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
void bubble_sort(int arr[], int n) {
    // bubble sort
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
