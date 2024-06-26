#include <iostream>

using namespace std;
int checkArr[4];
int myArr[4];
int checkSecret=0;
void Add(char c){
    switch(c){
        case 'A':
            myArr[0]++;
            if(myArr[0]==checkArr[0])
                checkSecret++;
            break;
        case 'C':
            myArr[1]++;
            if(myArr[1]==checkArr[1])
                checkSecret++;
            break;
        case 'G':
            myArr[2]++;
            if(myArr[2]==checkArr[2])
                checkSecret++;
            break;
        case 'T':
            myArr[3]++;
            if(myArr[3]==checkArr[3])
                checkSecret++;
            break;

    }
}
void Remove(char c){
    switch(c){
        case 'A':
            if(myArr[0]==checkArr[0])
                checkSecret--;
            myArr[0]--;
            break;
        case 'C':
            if(myArr[1]==checkArr[1])
                checkSecret--;
            myArr[1]--;
            break;
        case 'G':
            if(myArr[2]==checkArr[2])
                checkSecret--;
            myArr[2]--;
            break;
        case 'T':
            if(myArr[3]==checkArr[3])
                checkSecret--;
            myArr[3]--;
            break;
    }
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int S, P;
    cin >> S >> P;
    int result = 0;
    string A;
    cin >> A;

    for (int i = 0; i < 4; i++) {
        cin >> checkArr[i];
        if (checkArr[i] == 0) {
            checkSecret++;
        }
    }
    for (int i = 0; i < P; i++) {
        Add(A[i]);
    }
    if (checkSecret == 4) {
        result++;
    }
    for (int i = P; i < S; i++) {
        int j = i - P;
        Add(A[i]);
        Remove(A[j]);
        if (checkSecret == 4) {
            result++;
        }
    }
    cout << result << "\n";

    return 0;
}
