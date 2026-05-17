#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int a, b, c, id;
};

void merge(vector<Node>& nodes, int left, int mid, int right) {
    Node *tmp = new Node[right - left + 1];
    int i = left, j = mid, k = 0;
    while(i < mid && j <= right) {
        if(nodes[i].c > nodes[j].c || (nodes[i].c == nodes[j].c && nodes[i].b > nodes[j].b) || (nodes[i].c == nodes[j].c && nodes[i].b == nodes[j].b && nodes[i].id < nodes[j].id)) {
            tmp[k++] = nodes[i++];
        } else {
            tmp[k++] = nodes[j++];
        }
    }
    while(i < mid) tmp[k++] = nodes[i++];
    while(j <= right) tmp[k++] = nodes[j++];
    for(i = 0, k = left; k <= right;) {
        nodes[k++] = tmp[i++];
    }
    delete[] tmp;
}

void mergeSort(vector<Node>& nodes, int left, int right) {
    int mid = left + (right - left) / 2;
    if(left >= right) return;
    mergeSort(nodes, left, mid);
    mergeSort(nodes, mid + 1, right);
    merge(nodes, left, mid + 1, right);
}

int main() {
    int n;
    cin >> n;
    vector<Node> nodes(n);
    for(int i = 0; i < n; i++) {
        cin >> nodes[i].id >> nodes[i].a >> nodes[i].b;
        nodes[i].c = nodes[i].a + nodes[i].b;
    }

    mergeSort(nodes, 0, n - 1);

    for(int i = 0; i < n; i++) {
        cout << nodes[i].id << " " << nodes[i].c << endl;
    }

    return 0;
}
