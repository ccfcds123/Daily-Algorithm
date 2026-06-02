/*
题目描述
某学院组织了一场志愿活动，活动分为上午场和下午场。每名学生都有一个唯一的学号编号。由于签到系统可能被重复扫码，同一名学生可能在同一场活动中出现多次。现在给出上午场和下午场的签到记录，请你整理出以下名单：

所有参加过活动的学生名单
上午场和下午场都参加过的学生名单
只参加了上午场的学生名单
为了便于核对，所有输出名单都需要去重，并按学号从小到大排序。如果某个名单为空，输出 Empty 。

输入格式
第一行输入两个整数 
n
,
m
n,m ，分别表示上午场和下午场的签到记录数量

第二行输入 
n
n 个整数，表示上午场的签到记录

第三行输入 
m
m 个整数，表示下午场的签到记录

输出格式
第一行输出所有参加过活动的学生名单

第二行输出上午场和下午场都参加过的学生名单

第三行输出只参加了上午场的学生名单

同一行中相邻两个学号之间用一个空格分隔。

如果某个名单为空，输出 Empty 。

样例
样例1
输入

6 5
1003 1001 1002 1003 1005 1001
1002 1004 1005 1005 1006
输出

1001 1002 1003 1004 1005 1006
1002 1005
1001 1003
样例2
输入

3 3
1 2 3
4 5 6
输出

1 2 3 4 5 6
Empty
1 2 3
数据范围
1
≤
n
,
m
≤
1000
1≤n,m≤1000, 
1
≤
1≤ 学号编号 
≤
1
0
6
≤10 
6
 

时空磁盘限制（运行时）
时间限制：1000 ms

内存空间限制：244 MiB

磁盘空间限制：不可使用磁盘

单个测试点时空限制详情
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> unique_sort(vector<int>& arr) {
    if(arr.empty()) return {};
    sort(arr.begin(), arr.end());
    vector<int> result;
    result.push_back(arr[0]);
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] != arr[i-1]) {
            result.push_back(arr[i]);
        }
    }
    return result;
}

vector<int> union_sorted(vector<int>& arr1, vector<int>& arr2) {
    vector<int> result;
    int i = 0, j = 0;
    while(i < arr1.size() && j < arr2.size()) {
        if(arr1[i] < arr2[j]) {
            result.push_back(arr1[i]);
            i++;
        } else if(arr1[i] > arr2[j]) {
            result.push_back(arr2[j]);
            j++;
        } else {
            result.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    while(i < arr1.size()) {
        result.push_back(arr1[i]);
        i++;
    }
    while(j < arr2.size()) {
        result.push_back(arr2[j]);
        j++;
    }
    return result;
}

vector<int> intersection_sorted(vector<int>& arr1, vector<int>& arr2) {
    vector<int> result;
    int i = 0, j = 0;
    while(i < arr1.size() && j < arr2.size()) {
        if(arr1[i] < arr2[j]) {
            i++;
        } else if(arr1[i] > arr2[j]) {
            j++;
        } else {
            result.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    return result;
}



int main() {
    int K;
    cin >> K;
    vector<vector<int>> arr(K);
    for(int i = 0; i < K; i++) {
        int N;
        cin >> N;
        vector<int> temp(N);
        for(int j = 0; j < N; j++) {
            cin >> temp[j];
        }
        arr[i] = temp;
    }
    vector<vector<int>> unique_arr(K);
    for(int i = 0; i < K; i++) {
        unique_arr[i] = unique_sort(arr[i]);
    }

    vector<int> union_result;
    if(unique_arr[0].size()) {
        union_result = unique_arr[0];
        for(int i = 1; i < K; i++) {
            union_result = union_sorted(union_result, unique_arr[i]);
        }
    }
    vector<int> intersection_result;
    if(unique_arr[0].size()) {
        intersection_result = unique_arr[0];
        for(int i = 1; i < K; i++) {
            intersection_result = intersection_sorted(intersection_result, unique_arr[i]);
        }
    }

    if(!intersection_result.size()) cout << "EMPTY";
    for(int num : intersection_result) {
        cout << num << " ";
    }
    cout << endl;
    if(!union_result.size()) cout << "EMPTY";
    for(int num : union_result) {
        cout << num << " ";
    }

    return 0;
}
