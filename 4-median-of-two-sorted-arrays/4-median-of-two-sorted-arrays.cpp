class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double med=0;
        
        
        if(nums1.size()==0){
            for(int i=0;i<nums2.size();i++){
            nums1.push_back(nums2[i]);
            }
        }
        if(nums2.size()!=0 && nums1.size()!=0){
           
        for(int i=0;i<nums2.size();i++){
            nums1.push_back(nums2[i]);
        }
        }
        
        sort(nums1.begin(),nums1.end());
        

             
        if(nums1.size()%2==0){
             double a = nums1[(nums1.size()/2)-1];
             double b = nums1[nums1.size()/2];
             med= (a+b)/2;
        }
        else{
            med=nums1[(nums1.size()-1)/2];
        }
        return med;
        
    }
};