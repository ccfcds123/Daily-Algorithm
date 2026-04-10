/*
  题目描述
校园快递驿站有一个窄通道货架，包裹只能从最外侧存取，其行为等同于一个栈（后进先出）。货架最多同时存放 
K
K 个包裹。

驿站门口还有一条等候区，新到的包裹在此排队等待上架，其行为等同于一个队列（先进先出）。

系统按时间顺序处理以下两种事件：

ARRIVE id：编号为 
i
d
id 的包裹到达驿站，进入等候队列的队尾。随后，若货架未满且队列非空，则不断将队列队头的包裹压入货架栈顶，直到货架满或队列空为止。
PICKUP id：一位同学来取编号为 
i
d
id 的包裹。若该包裹当前在货架上，工作人员从栈顶依次将阻挡的包裹搬到临时货架（也是一个栈），取出目标包裹后，再将临时货架上的包裹按顺序搬回。每搬运一个包裹（无论方向）计为一次搬运。取出目标包裹本身不计入搬运次数。取件完成后，同样检查货架是否有空位，从等候队列自动补充上架。若该包裹不在货架上（仍在等候队列中或尚未到达），则本次取件无事发生。
请你模拟上述过程，在所有事件处理完毕后，输出货架上的包裹序列、等候队列中的包裹序列，以及整个过程中的总搬运次数。

输入格式
第一行包含两个整数 
K
K 和 
M
M，分别表示货架容量和事件总数。

接下来 
M
M 行，每行格式为 ARRIVE id 或 PICKUP id，其中 
i
d
id 为包裹的正整数编号。

输出格式
输出共三行：

第一行：货架上的包裹编号，从栈底到栈顶，以空格分隔；若货架为空则输出 EMPTY。
第二行：等候队列中的包裹编号，从队头到队尾，以空格分隔；若队列为空则输出 EMPTY。
第三行：一个整数，表示总搬运次数。
样例
样例1
输入

3 6
ARRIVE 1
ARRIVE 2
ARRIVE 3
ARRIVE 4
PICKUP 1
PICKUP 3
输出

2 4
EMPTY
6
事件	货架（底→顶）	队列	本次搬运
ARRIVE 1	[1]	[]	0
ARRIVE 2	[1, 2]	[]	0
ARRIVE 3	[1, 2, 3]	[]	0
ARRIVE 4	[1, 2, 3]	[4]	0
PICKUP 1	[2, 3, 4]	[]	4
PICKUP 3	[2, 4]	[]	2
PICKUP 1时：搬出3、2（2次），取出1，搬回2、3（2次），共4 次。货架空出一位，4自动上架。

PICKUP 3时：搬出4（1次），取出3，搬回4（1次），共2 次。

数据范围
1
≤
K
≤
100
1≤K≤100，
1
≤
M
≤
1000
1≤M≤1000，
1
≤
i
d
≤
10000
1≤id≤10000。

所有包裹编号互不相同。PICKUP 的目标包裹可能不在货架上。
*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int k, m;
    cin >> k >> m;
    queue<int> arrive;
    stack<int> shelf;
    int count = 0;

    for (int i = 0; i < m; i++) {
        string s;
        int id;
        cin >> s >> id;

        if (s == "ARRIVE") {
            arrive.push(id);
            while (!arrive.empty() && shelf.size() < k) {
                shelf.push(arrive.front());
                arrive.pop();
            }
        } 
        else if (s == "PICKUP") {
            stack<int> copy = shelf;
            bool exist = false;
            while (!copy.empty()) {
                if (copy.top() == id) { 
                    exist = true;
                    break;
                }
                copy.pop();
            }
            if (!exist) {
                continue;
            }
            stack<int> temp;
            while (!shelf.empty()) {
                int topId = shelf.top();
                shelf.pop();
                if (topId == id) {
                    break;
                } else {
                    temp.push(topId);
                    count++;
                }
            }
            while (!temp.empty()) {
                shelf.push(temp.top());
                temp.pop();
                count++;
            }
            while (!arrive.empty() && shelf.size() < k) {
                shelf.push(arrive.front());
                arrive.pop();
            }
        }
    }

    stack<int> outputStack;
    while (!shelf.empty()) {
        outputStack.push(shelf.top());
        shelf.pop();
    }
    if (outputStack.empty()) {
        cout << "EMPTY" << endl;
    } else {
        while (!outputStack.empty()) {
            cout << outputStack.top() << " ";
            outputStack.pop();
        }
        cout << endl;
    }
    if (arrive.empty()) {
        cout << "EMPTY" << endl;
    } else {
        while (!arrive.empty()) {
            cout << arrive.front() << " ";
            arrive.pop();
        }
        cout << endl;
    }
    cout << count;

    return 0;
}
