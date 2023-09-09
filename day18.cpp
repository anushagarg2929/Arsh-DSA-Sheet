//https://bit.ly/3MZQOct
int countStudents(vector<int> &arr, int pages){
    int n = arr.size();
    int students = 1; 
    long long pagesStudent = 0;
    for(int i=0; i<n; i++){
        if(pagesStudent + arr[i] <= pages){
            pagesStudent += arr[i];
        }else{
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if( m > n){
        return -1;
    }
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while(low <= high){
        int mid = (low+high)/2;
        int students = countStudents(arr, mid);
        if(students > m){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return low;
}

//https://leetcode.com/problems/split-array-largest-sum/
class Solution {
public:
    int divideArray(vector<int> &nums, int p){
        int n = nums.size();
        int sum = 1;
        long long maxSum = 0;
        for(int i=0; i<n; i++){
            if(maxSum + nums[i] <= p){
                maxSum += nums[i];
            }else{
                sum++;
                maxSum = nums[i];
            }
        }
        return sum;
    }

    int splitArray(vector<int>& nums, int k) {
       int n = nums.size();
       int low = *max_element(nums.begin(), nums.end());
       int high = accumulate(nums.begin(), nums.end(), 0);
       while(low <= high){
           int mid = (low+high)/2;
           int divide = divideArray(nums, mid);
           if(divide > k){
               low = mid + 1;
           }else{
               high = mid - 1;
           }
       }
       return low;
    }
};

//https://www.codingninjas.com/studio/problems/painter-s-partition-problem_1089557?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
int countPainters(vector<int> &boards, int time){
    int n = boards.size();
    int painters = 1;
    long long boardsPainter = 0;
    for(int i=0; i<n; i++){
        if(boardsPainter + boards[i] <= time){
            boardsPainter += boards[i];
        }else{
            painters++;
            boardsPainter = boards[i];
        }
    }
    return painters;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);

    while(low <= high){
        int mid = (low + high)/2;
        int partitions = countPainters(boards, mid);
        if(partitions > k){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return low;
}

//https://www.codingninjas.com/codestudio/problems/minimise-max-distance_7541449?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
    int n = arr.size(); // size of the array
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
        if ((arr[i] - arr[i - 1]) == (dist * numberInBetween)) {
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}

long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size(); // size of the array
    long double low = 0;
    long double high = 0;

    //Find the maximum distance:
    for (int i = 0; i < n - 1; i++) {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }

    //Apply Binary search:
    long double diff = 1e-6 ;
    while (high - low > diff) {
        long double mid = (low + high) / (2.0);
        int cnt = numberOfGasStationsRequired(mid, arr);
        if (cnt > k) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    return high;
}

