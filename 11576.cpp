#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int main() {

    int A,B,m;
    int number;
    stack<int> save;
    cin >> A >> B >> m;
        int result = 0;
        for(int j = 0; j < m; j++){
            cin >> number;
            result += number* pow(A, m - j - 1);
        }
        while(result > 0){
            save.push(result% B);
            result /= B;
        }

    while (!save.empty()){
        cout<<save.top()<<" ";
        save.pop();
    }
    return 0;
}

