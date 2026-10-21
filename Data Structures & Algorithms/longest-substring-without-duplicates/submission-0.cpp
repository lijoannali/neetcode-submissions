class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0; 
        int left = 0; 
        int right = 0;
        int curr_len = 0; 
        int next = 0; 
        unordered_set<char> seen; 

        while(right < s.size()) { 
            next = right; 
            while(seen.count(s[next])){
                left++; 
                seen.erase(s[left-1]);
            }
            longest = max(longest, right - left + 1); 
            seen.insert(s[right]); 
            right++; 
        }
        return longest; 
    }
};
