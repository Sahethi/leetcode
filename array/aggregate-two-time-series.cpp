class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        /**
        series1 = [[1,3],[4,1]], series2 = [[2,2],[5,2]]
        so like if we combine 
        [1,3], [2,2], [4,1], [5,2]
        for sum we have to 
        search for 1 in series 1 and find in series 1 if u didnt find then get the next timestamp and value thats 2 ..... 
        [1, 3 + 2]
        **/

        int n = series1.size();
        int m = series2.size();
        
        vector<vector<int>> results;
        int i=0, j=0;
        while(i<n || j<m){

            if(i >= n){
                results.push_back({series2[j][0], series2[j][1] + 0});
                j++;
                continue;
            }
            if(j >= m){
                results.push_back({series1[i][0], series1[i][1] + 0});
                i++;
                continue;
            }
            
            if(series1[i][0] < series2[j][0]){
                results.push_back({series1[i][0], series1[i][1] + series2[j][1]});
                i++;
            }else if(series1[i][0] > series2[j][0]){
                results.push_back({series2[j][0], series2[j][1] + series1[i][1]});
                j++;
            }else{
                results.push_back({series1[i][0], series1[i][1] + series2[j][1]});
                i++;
                j++;
            }
        }

        return results;
    }
};