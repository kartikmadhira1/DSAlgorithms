
class Solution {
public:
int removeDuplicates(vector<int> &nums){
if(nums.size()==0)return 0;
    int i=0,j=1;
    while(j<nums.size()){
        if(nums[i]!=nums[j]){
            nums[i+1]=nums[j];
            i+=1;
        }
    j++;
}
    return i+1;  
}
};