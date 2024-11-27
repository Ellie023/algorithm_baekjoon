#include <iostream>

using namespace std;
const int Max = 123456 * 2;
int main(){
    bool arr[Max + 1] = { false };
    arr[1] = true;
    for (int i = 2; i * i <= Max; ++i){
        if (!arr[i]) {
            for (int j = 2; i * j <= Max; ++j) arr[i * j] = true;
        }
    }
	int ch;
    cin >> ch;
    while (ch) {
        int count = 0;
        for (int i = ch + 1; i <= 2 * ch; ++i){
            if (!arr[i]) ++count;
        }
        cout << count << '\n';
        std::cin >> ch;	}
}