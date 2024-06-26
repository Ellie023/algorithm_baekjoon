#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long Min, Max;
    cin >> Min >> Max;
    int count = 0;
    long* A = new long[10000001]; // 동적 메모리 할당

    for(int i = 2; i < 10000001; i++) {
        A[i] = i;
    }
    for(int i = 2; i * i < 10000001; i++) {
        if(A[i] == 0) {
            continue;
        }
        for(int j = i + i; j < 10000001; j = j + i) {
            A[j] = 0;
        }
    }
    for(int i = 2; i < 10000001; i++) {
        if(A[i] != 0) {
            long temp = A[i];
            while(temp <= Max / A[i]) {
                if(temp * A[i] >= Min) {
                    count++;
                }
                temp *= A[i];
            }
        }
    }

    delete[] A; // 동적 메모리 해제
    cout << count;
    return 0;
}