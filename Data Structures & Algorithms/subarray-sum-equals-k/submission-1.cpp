class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0; 
        map<int, int> counts; 
        counts.insert({0, 1}); //initial value
        int run_sum = 0; 
        for(int j = 0; j < nums.size(); j++) { 
            run_sum +=nums[j];
            int target = run_sum - k; 
            //if target in the map, get index of target
            count += counts[target]; //this is zero if its not in the map 
            counts[run_sum] += 1;
        }
        return count; 
    }
};

//O(n) space usage, and O(nlogn) for ordered map 