class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size(); 
        int num_zeros = 0; 
        vector<int> prod_but_self(size); 
        int prod = 1;
        int prod_wo_zero = 1;  
        for(int i = 0; i < size; i++) { 
            prod *= nums[i]; 
            if(nums[i] != 0){ 
                prod_wo_zero *= nums[i];
            } else { 
                num_zeros++; 
            }
        }
     
        cout << prod << "prod" << endl; 
        for(int i = 0; i < size; i++) { 
            if(nums[i] == 0) { 
                prod_but_self[i] = prod_wo_zero; 
                if(num_zeros > 1){ 
                    prod_but_self[i] = 0; 
                }
            } else { 
                prod_but_self[i] = (prod/nums[i]); 
            }
        }
        return prod_but_self;
    }
};
