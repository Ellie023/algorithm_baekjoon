#include <iostream>
#include <map>
using namespace std;

int main(void)
{
    map<int, bool> m;
    int N,M;
    int num;
    cin >> N >> M;
    for (int i = 0; i < N+M; i++)
    {
        cin >> num;
        if (m[num] == true)
            m.erase(num);
        else
            m[num] = true;
    }
    cout << m.size();

}
