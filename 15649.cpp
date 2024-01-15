#include <iostream>
#include <vector>
using namespace std;

const int MAX_X=8;

int n,m;
int sequence[MAX_X];
bool is_used[MAX_X+1];
void printSequence() {
    for (int i = 0; i < m; i++) {
        cout << sequence[i] << " ";
    }
    cout << "\n";
}
void backtraking(int count){
    if(count==m){
        printSequence();
        return;
    }
    for(int i=1; i<=n; i++){
        if(is_used[i]){
            continue;
        }
        sequence[count]=i;
        is_used[i]= true;
        backtraking(count+1);
        is_used[i]= false;

    }
}

int main() {

    cin>>n>>m;

    backtraking(0);
    return 0;
}