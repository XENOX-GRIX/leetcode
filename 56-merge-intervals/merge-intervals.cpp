class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size(); 
        sort(intervals.begin(), intervals.end()); 
        for(int i =0; i<n; i++){
            int end = intervals[i][1]; 
            int j = i + 1;
            while(j<n && end >= intervals[j][0]){
                end = max(end,intervals[j][1]); 
                j++; 
            }
            j--; 
            ans.push_back({intervals[i][0], end}); 
            i = j;
        }
        return ans;
    }
};