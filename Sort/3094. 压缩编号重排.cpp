/*
题目描述
某平台收集了 
n
n 个用户行为编号，每个编号可能非常大，也可能出现重复。

为了方便后续存储和统计，需要将这些编号进行压缩。

具体来说，对于每个原始编号 
a
i
a 
i
​
 ，需要输出它在所有不同编号中的排名。

排名从 
1
1 开始，数值越小排名越靠前。

例如：

原始编号：100 50 100 20

不同编号排序后：20 50 100

压缩后：3 2 3 1
请你完成编号压缩。

输入格式
第一行输入一个整数 
n
n，表示编号数量。

第二行输入 
n
n 个整数，表示原始编号序列。

输出格式
输出 
n
n 个整数，表示每个原始编号压缩后的排名。

相邻两个整数之间用一个空格隔开。

样例
输入

6
100 50 100 20 50 200
输出

3 2 3 1 2 4
原始编号为：

100 50 100 20 50 200
去除重复编号并从小到大排序后得到：

20 50 100 200
因此：

20  -> 1
50  -> 2
100 -> 3
200 -> 4
所以原序列压缩后的结果为：

3 2 3 1 2 4
数据范围
1 <= n <= 300000
-10^9 <= a_i <= 10^9
时空磁盘限制（运行时）
时间限制：1000 ms

内存空间限制：244 MiB

磁盘空间限制：不可使用磁盘

单个测试点时空限制详情
*/

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int val;
    int index;
};

void merge(vector<Node>& a, int left, int mid, int right) {
    Node *tmp = new Node[right - left + 1];
    int i = left, j = mid, k = 0;
    while(i < mid && j <= right) {
        if(a[i].val <= a[j].val) {
            tmp[k++] = a[i++];
        } else {
            tmp[k++] = a[j++];
        }
    }
    while(i < mid) tmp[k++] = a[i++];
    while(j <= right) tmp[k++] = a[j++];
    for(i = 0, k = left; k <= right;) {
        a[k++] = tmp[i++];
    }
    delete[] tmp;
}

void mergeSort(vector<Node>& a, int left, int right) {
    int mid = left + (right - left) / 2;
    if(left >= right) return;
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    merge(a, left, mid + 1, right);
}

int main() {
    int n;
    cin >> n;
    vector<Node> nodes(n);
    for(int i = 0; i < n; i++) {
        cin >> nodes[i].val;
        nodes[i].index = i + 1;
    }

    vector<Node> temp = nodes, unique;
    mergeSort(temp, 0, n - 1);
    for(int i = 0; i < n; i++) {
        if(i == 0 || temp[i].val != temp[i - 1].val) {
            unique.push_back(temp[i]);
        }
    }

    for(int i = 0; i < n; i++) {
        int left = 0, right = unique.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(unique[mid].val == nodes[i].val) {
                cout << mid + 1 << " ";
                break;
            } else if(unique[mid].val < nodes[i].val) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    return 0;
}
