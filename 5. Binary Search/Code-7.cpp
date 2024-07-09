// Median of Two Sorted Arrays
// https://leetcode.com/problems/median-of-two-sorted-arrays/description/

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int total = m + n;
        int start = 0;
        int end = m;
        double result = 0.0;
        while (start <= end) {
            int i = start + (end - start) / 2;
            int j = (total + 1) / 2 - i;            
            int left1 = (i > 0) ? nums1[i - 1] : INT_MIN;
            int right1 = (i < m) ? nums1[i] : INT_MAX;
            int left2 = (j > 0) ? nums2[j - 1] : INT_MIN;
            int right2 = (j < n) ? nums2[j] : INT_MAX;            
            if (left1 <= right2 && left2 <= right1) {
                if (total % 2 == 0) {
                    result = (max(left1, left2) + min(right1, right2)) / 2.0;
                } else {
                    result = max(left1, left2);
                }
                break;
            } else if (left1 > right2) {
                end = i - 1;
            } else {
                start = i + 1;
            }
        }
        return result;
    }