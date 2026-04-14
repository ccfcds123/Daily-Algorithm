/*
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

算法的时间复杂度应该为 O(log (m+n)) 。

 

示例 1：

输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2
示例 2：

输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 

 

提示：

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int p1 = 0, p2 = 0;
        vector<int> nums;
        while(p1 < nums1.size() && p2 < nums2.size()) {
            if(nums1[p1] < nums2[p2]) {
                nums.push_back(nums1[p1++]);
            } else {
                nums.push_back(nums2[p2++]);
            }
        }

        while(p1 < nums1.size()) {
            nums.push_back(nums1[p1++]);
        }
        while(p2 < nums2.size()) {
            nums.push_back(nums2[p2++]);
        }
        
        int n = nums.size();
        if(n % 2) return nums[n / 2];
        else return (nums[n / 2 - 1] + nums[n / 2]) / 2.0;
    }
};
