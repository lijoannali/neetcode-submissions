class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size(); 
        vector<int> pref(size+1); 
        vector<int> suf(size+1); 
        vector<int> output(size);
        pref[0] = 1; 
        suf[size-0] = 1; 

        for(int i  = 1; i < size + 1; i++) { 
            pref[i] = pref[i-1] * nums[i-1]; 
            suf[size-i] = suf[size - i + 1] * nums[size - i];
        }
        for(int i = 1; i < size+1; i++) { 
            output[i-1] = pref[i-1]*suf[i];
        }

        return output; 
    }
};
