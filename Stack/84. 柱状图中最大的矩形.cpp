/*
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。

 

示例 1:



输入：heights = [2,1,5,6,2,3]
输出：10
解释：最大的矩形为图中红色区域，面积为 10
示例 2：



输入： heights = [2,4]
输出： 4
 

提示：

1 <= heights.length <=105
0 <= heights[i] <= 104
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);
        stack<int> stl, str;
        for(int i = 0; i < n; i++) {
            while(!stl.empty() && heights[stl.top()] >= heights[i]) {
                stl.pop();
            }
            left[i] = stl.empty() ? -1 : stl.top();
            stl.push(i);
        }
        for(int i = n - 1; i >= 0; i--) {
            while(!str.empty() && heights[str.top()] >= heights[i]) {
                str.pop();
            }
            right[i] = str.empty() ? n : str.top();
            str.push(i);
        }
        int maxSize = 0;
        for(int i = 0; i < n; i++) {
            int size = (right[i] - left[i] - 1) * heights[i];
            maxSize = maxSize > size ? maxSize : size;
        }
        return maxSize;
    }
};
