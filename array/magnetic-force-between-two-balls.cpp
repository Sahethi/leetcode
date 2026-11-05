class Solution {
private:
    bool canPlace(vector<int>& position, int m, int target){
        
        int count = 1;
        int lastPlaced = position[0];

        for(int i=1; i<position.size(); i++){
            if(position[i] - lastPlaced >= target){
                count++;
                lastPlaced = position[i];
            }
        }

        return count >= m;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        //i need to check if this minimum distance is possible as the taregt

        sort(position.begin(), position.end());

        int left = 1;
        int right = position.back() - position.front();

        //we want the minimum feasible answer
        //if that works then try a bigger number
        int answer = 0;
        while(left <= right){
            int mid = left + (right - left) / 2;

            if(canPlace(position, m, mid)){
                //search for larger answer hence move left aage
                answer = mid;
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }

        return answer;
    }
};