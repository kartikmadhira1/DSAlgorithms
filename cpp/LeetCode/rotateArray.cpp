class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int temp;
          for(int i=0;i<=k;++i){
            temp=nums[i];
            nums[i]=nums[i+k];
            nums[i+k]=temp;
        }
        }
    };
