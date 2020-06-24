class Solution {
public:
    // Credit: Tushar Roy Video.
    // Partition the 2 arrays into 2 parts: The left partition of the first array(x) ends at partition_x
    // and the left partition of second array ends at partition_y.
    // The problem can be solved by comparing:
    // Last elements of the left partitions and first elements of the right partitions.
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        if(n==0 and m==0){
            return -1;
        }
        if(m==0){
            if(n%2==0){
                double median=(nums1[n/2]+nums1[n/2-1])*0.5;
                return median;
            }else{
                return (double)nums1[n/2];
            }
        }else if(n==0){
            if(m%2==0){
                double median=(nums2[m/2]+nums2[m/2-1])*0.5;
                return median;
            }else{
                return (double)nums2[m/2];
            }
        }
        
        if(n>m){
            return findMedianSortedArrays(nums2,nums1);
        }
        int low=0;
        int high=n;
        while(low<=high){
            int partition_x=(high+low)/2;
            int partition_y=((n+m+1)/2)-partition_x;
            int maxleft_x,minright_x;
            int maxleft_y,minright_y;
            
            // for the x array.
            if(partition_x==0){
                maxleft_x=INT_MIN;
            }else{
                maxleft_x=nums1[partition_x-1];
            }
            if(partition_x==n){
                minright_x=INT_MAX;
            }else{
                minright_x=nums1[partition_x];
            }
            
             // for the y array.
            if(partition_y==0){
                maxleft_y=INT_MIN;
            }else{
                maxleft_y=nums2[partition_y-1];
            }
            if(partition_y==m){
                minright_y=INT_MAX;
            }else{
                minright_y=nums2[partition_y];
            }
            
            if(maxleft_x<=minright_y and maxleft_y<=minright_x){
                if((n+m)%2==0){
                    double median=(max(maxleft_x,maxleft_y)+min(minright_x,minright_y))*0.5;
                    return median;
                }else{
                    return (double)max(maxleft_x,maxleft_y);
                }
            }else if(maxleft_x>minright_y){
                high=partition_x-1;
            }else{
                low=partition_x+1;
            }
        }
        return -1;
    }
};