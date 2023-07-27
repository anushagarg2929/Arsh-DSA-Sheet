//https://takeuforward.org/wp-content/uploads/2023/04/Group-11-5.png
vector<int> superiorElements(vector<int>&a) {
    // Write your code here.
    vector<int> ans;
    int n = a.size();
    int max = INT_MIN;
    for(int j=n-1; j>=0; j--){
        if(a[j]>max){
            ans.push_back(a[j]);
            max = a[j];
        }
    }
    return ans;
}

//https://www.codingninjas.com/codestudio/problems/longest-successive-elements_6811740?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
int longestSuccessiveElements(vector<int>&a) {
    // Write your code here.
    int count = 0;
    int longest = 0;
    sort(a.begin(), a.end());
    for(int i=0; i<a.size()-1; i++){
        if(a[i+1] == a[i]){
            continue;
        }else if(a[i+1] - a[i] == 1){
            count++;
        }else{
            count = 0;
        }
        if(count > longest)
        longest = count;
    }
    return longest+1;
}

//https://leetcode.com/problems/set-matrix-zeroes/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> visited = matrix;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    for(int k=0; k<m; k++){
                        visited[i][k] = 0;
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    for(int k=0; k<n; k++){
                        visited[k][j] = 0;
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                matrix[i][j] = visited[i][j];
            }
        }
    }
};

//https://leetcode.com/problems/rotate-image/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        int row = matrix.size();
        for(int i=0; i<row; i++){
            for(int j=0; j<=i; j++){
                 swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};