class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        vector<pair<int,int>> sortedNums2;
        vector<int> res(n);

        
        for(int i=0; i<n; i++){
            sortedNums2.push_back({nums2[i], i});
        }

        sort(sortedNums2.begin(), sortedNums2.end());

        sort(nums1.begin(), nums1.end());

        int left = 0;
        int right = n-1;

        for(int i=0; i<n; i++){
            if(nums1[i] > sortedNums2[left].first){
                res[sortedNums2[left].second] = nums1[i];
                left++;
            }else{
                res[sortedNums2[right].second] = nums1[i];
                right--;
            }
        }
        return res;
    }
};