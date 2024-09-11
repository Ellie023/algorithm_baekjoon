#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
static vector<int> visited;
static vector<int> map;
int dy[4]={-1,0,0,1};
int dx[4]={0,1,-1,0};
int count=0;
int n;
void dfs(int k){

    int number=n/k;
    for(int a=0; a<number; a++) {
        for (int i = 0; i < n / k; i +) {
            for (int j = 0; j < n / k; j++) {

            }
        }
    }
}

itoc(n)
int main() {


    cin>>n;
    map.resize(n);
    visited.resize(n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) {
            cin >> map[j];
        }
    }
    int size=log2(n);

    for(int i=2; i<=size; i*=2){
        dfs(2)
    }
    return 0;
}