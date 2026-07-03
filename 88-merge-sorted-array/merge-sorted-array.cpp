class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      
      /*  vector<int>tt;
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        sort(nums1.begin(),nums1.end());
        int k =0;

        for(int i =0 ;i<nums1.size();i++){
            if(nums1[i] == 0 ){
            }
            else{
                tt[k] == nums1[i];
                k++;
            }
        }

        nums1 = tt;
*/


        for(int i =0 ;i<n;i++){
            nums1[i+m] = nums2[i];
        }
        sort(nums1.begin(),nums1.end());
        
    }
};