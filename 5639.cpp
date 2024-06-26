#include<iostream>
#include<vector>

using namespace std;

void postorder(int left, int right, vector<int>& tree) {
    if (left > right) {
        return;
    }

    int root = tree[left];

    int tmp = left + 1;
    for (int i = left+1 ; i <= right ; i++) {
        if (tree[i] > root) {
            tmp = i;
            break;
        }
    }

    postorder(left + 1, tmp - 1,tree);
    postorder(tmp, right, tree);
    cout << root << '\n';
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //입력
    int node;
    vector<int> tree;
    while (cin>>node) {

        tree.push_back(node);
    }

    postorder(0, tree.size() - 1, tree);
}