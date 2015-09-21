public class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int length = nums1.length-1;
        if(m>=0)
            m--;
        if(n>=0)
            n--;
        while(n!=-1 && m!=-1){
            if(nums1[m]>nums2[n]){
                nums1[length] = nums1[m];
                m--;
                length--;
            }
            else{
                nums1[length] = nums2[n];
                n--;
                length--;
            }
        }
        while(m!=-1){
            nums1[length--] = nums1[m--];
        }
        while(n!=-1){
            nums1[length--] = nums2[n--];
        }
       // return nums1;
    }
}