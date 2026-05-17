/*
题目描述
星际档案馆中存储了 
n
n 条飞船航行记录。每条记录包含两个信息：

航行等级 level
到达时间 time
每条记录的原始编号按照输入顺序从 
1
1 到 
n
n 编号。

现在需要对这些记录进行重新排序，排序规则如下：

航行等级高的记录排在前面；
如果航行等级相同，到达时间早的记录排在前面；
如果航行等级和到达时间都相同，则必须保持它们在输入中的相对顺序不变。
请你编写程序完成排序。

注意：本题要求排序过程必须是稳定的。

输入格式
第一行输入一个整数 
n
n，表示记录数量。

接下来 
n
n 行，每行包含两个整数：

level time
表示一条记录的航行等级和到达时间。

输出格式
输出排序后的记录编号，每行一个整数。

样例
输入

6
3 10
2 5
3 8
3 8
2 3
3 10
输出

3
4
1
6
5
2
等级为 3 的记录应排在为等级为 2 的记录前面。

在等级为 3 的记录中，时间为 8 的记录最早，因此编号 3 和 4 排在前面。

编号 3 和 4 的航行等级和到达时间完全相同，因此需要保持它们在输入中的相对顺序，即编号 3 在编号 4 前面。

数据范围
1 <= n <= 200000
1 <= level <= 10^9
1 <= time <= 10^9
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
    int level;
    int time;
    int index;
};

void merge(vector<Node>& a, int left, int mid, int right) {
    Node *tmp = new Node[right - left + 1];
    int i = left, j = mid, k = 0;
    while(i < mid && j <= right) {
        if(a[i].level > a[j].level || (a[i].level == a[j].level && a[i].time <= a[j].time)) {
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
        cin >> nodes[i].level >> nodes[i].time;
        nodes[i].index = i + 1;
    }

    mergeSort(nodes, 0, n - 1);
    
    for(int i = 0; i < n; i++) {
        cout << nodes[i].index << endl;
    }

    return 0;
}
