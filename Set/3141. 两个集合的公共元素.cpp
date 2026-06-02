/*
题目描述
给定两个整数序列，请分别将它们去重后视为两个集合 
A
A 和 
B
B。

请输出两个集合中的公共元素。

要求：

输出的元素按从小到大排序。
每个元素只输出一次。
若公共元素为空，输出 EMPTY。
输入格式
第一行输入一个整数 
N
N，表示第一个序列的长度。

第二行输入 
N
N 个整数。

第三行输入一个整数 
M
M，表示第二个序列的长度。

第四行输入 
M
M 个整数。

输出格式
输出一行，表示两个集合的公共元素。

若不存在公共元素，输出 EMPTY。

样例
样例1
输入

5
1 2 2 3 4
6
2 3 3 5 6 2
输出

2 3
两个序列去重后分别为 
1
,
2
,
3
,
4
1,2,3,4 和 
2
,
3
,
5
,
6
2,3,5,6，公共元素为 
2
2 和 
3
3。

样例2
输入

4
1 2 3 4
3
5 6 7
输出

EMPTY
两个序列没有公共元素，因此输出 EMPTY。

数据范围
对于 
100
100 的数据：

1
≤
N
,
M
≤
1
0
5
1≤N,M≤10 
5
 
−
1
0
9
≤
a
i
,
b
i
≤
1
0
9
−10 
9
 ≤a 
i
​
 ,b 
i
​
 ≤10 
9
 
时空磁盘限制（运行时）
时间限制：1000 ms

内存空间限制：256 MiB

磁盘空间限制：不可使用磁盘

单个测试点时空限制详情
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> unique_sort(vector<int>& arr) {
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

vector<int> difference_sorted(vector<int>& arr1, vector<int>& arr2) {
    vector<int> result;
    int i = 0, j = 0;
    while(i < arr1.size() && j < arr2.size()) {
        if(arr1[i] < arr2[j]) {
            result.push_back(arr1[i]);
            i++;
        } else if(arr1[i] > arr2[j]) {
            j++;
        } else {
            i++;
            j++;
        }
    }
    while(i < arr1.size()) {
        result.push_back(arr1[i]);
        i++;
    }
    return result;
}

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int M;
    cin >> M;
    vector<int> b(M);
    for(int i = 0; i < M; i++) {
        cin >> b[i];
    }

    vector<int> unique_a = unique_sort(a);
    vector<int> unique_b = unique_sort(b);
    vector<int> intersection_result = intersection_sorted(unique_a, unique_b);

    if(!intersection_result.size()) cout << "EMPTY";
    for(int num : intersection_result) {
        cout << num << " ";
    }

    return 0;
}
