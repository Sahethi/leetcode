class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result;
        vector<int> res;
        if(nums1.empty() || nums2.empty()) return res;
        unordered_set<int> nums1_set;
        

        for(int i=0; i<nums1.size(); i++){
            nums1_set.insert(nums1[i]);
        }

        for(int i=0; i<nums2.size(); i++){
            if(nums1_set.find(nums2[i]) != nums1_set.end()){
                result.insert(nums2[i]);
            }
        }
        vector<int> res1(result.begin(), result.end());
        return res1;
    }
};