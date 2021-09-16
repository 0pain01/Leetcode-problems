class Solution {
public:
    int binary_search(vector<int> arr, int key,int l,int r){
    int flag=0,cnt=0;
    int mid = l+(r-l)/2;
        
    while(l<=r){
        mid = l+(r-l)/2;
        if (arr[mid]== key)
        {
            flag = 1 ;
            cnt ++;
            break;
        }
        else if(arr[mid]>key)
        {
            r = mid-1;
            cnt++;
        }
        else
        {
            l=mid+1;
            cnt++;
        }
    }
    
    
    if(flag==1)
        return mid;
    else
        return l;
}
    int searchInsert(vector<int>& nums, int target) {
        int l=0;
        int r= nums.size()-1;
        return binary_search(nums,target,l,r);
    }
};