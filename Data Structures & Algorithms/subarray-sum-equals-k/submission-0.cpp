class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0; 
        vector<int> pref_sum(nums.size() + 1); 
        map<int, int> counts; 
        counts.insert({0, 1}); //initial value
        pref_sum[0] = 0;
        for(int i = 1; i < nums.size() + 1; i++) { 
            pref_sum[i] = pref_sum[i-1] + nums[i-1]; 
            cout << pref_sum[i] << endl; 
        }
        int curr = pref_sum[1]; 
        for(int j = 0; j < pref_sum.size() - 1; j++) { 
            curr = pref_sum[j+1]; 
            int target = curr - k; 
            //if target in the map, get index of target
            count += counts[target]; //this is zero if its not in the map 
            counts[curr] += 1;
        }
        return count; 
    }
};