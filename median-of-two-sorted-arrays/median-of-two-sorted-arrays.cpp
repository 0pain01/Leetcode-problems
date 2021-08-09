#include<bits/stdc++.h>
#include<vector>
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double med=0;
        
        vector <int> arr;
        
        if(nums1.size()==0){
            for(int i=0;i<nums2.size();i++){
            arr.push_back(nums2[i]);
            }
        }
        else if(nums2.size()==0){
            for(int i=0;i<nums1.size();i++){
            arr.push_back(nums1[i]);
        }
        }
        else{
            for(int i=0;i<nums1.size();i++){
            arr.push_back(nums1[i]);
        }
        
        for(int i=0;i<nums2.size();i++){
            arr.push_back(nums2[i]);
        }
        }
        
        sort(arr.begin(),arr.end());
        
        int size = arr.size();
        
       
    
        
        if(arr.size()%2==0){
             double a = arr[(size/2)-1];
             double b = arr[size/2];
            med= (a+b)/2;
        }
        else{
            med=arr[(arr.size()-1)/2];
        }
        return med;
        
    }
};