//排序数组中查找元素第一个和最后一个位置 

class Solution {
public:
    int left_bound(vector<int> & nums,int target){
        int l=0,r=nums.size()-1;
        int mid;
        while(l<=r){
            mid=l+(r-l)/2;
            if(nums[mid]==target){
                r=mid-1;
            }
            else if(nums[mid]>target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        if(l>=nums.size()||nums[l]!=target){
            return -1;
        }
        return l;

    }

    int right_bound(vector<int> & nums,int target){
        int l=0,r=nums.size()-1;
        int mid;
        while(l<=r){
            mid=l+(r-l)/2;
            if(nums[mid]==target){
                l=mid+1;
            }
            else if(nums[mid]>target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        if(r<0||nums[r]!=target){
            return -1;
        }
        return r;

    }
    
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(left_bound(nums,target));
        ans.push_back(right_bound(nums,target));
        return ans;
        
    }
};
