#include <iostream>
#include <vector>
using namespace std;
vector<string> v;
bool Alphabet[26];
int Answer;
int Bigger(int A, int B){
    if(A>B)
        return A;
    return B;
}
int CanReadNum()
{
    bool Read;
    int Cnt = 0;
    for (int i = 0; i < v.size(); i++)
    {
        Read = true;
        string str = v[i];
        for (int j = 0; j < str.length(); j++)
        {
            if (Alphabet[str[j] - 'a'] == false)
            {
                Read = false;
                break;
            }
        }

        if (Read == true)
        {
            Cnt++;
        }
    }
    return Cnt;
}
void DFS(int Idx, int Cnt, int k)
{
    if (Cnt == k)
    {
        Answer = Bigger(Answer, CanReadNum());
        return;
    }

    for (int i = Idx; i < 26; i++)
    {
        if (Alphabet[i] == true) continue;
        Alphabet[i] = true;
        DFS(i, Cnt + 1,k);
        Alphabet[i] = false;
    }
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;

    cin>>n>>k;

    for(int i=0; i<n; i++){
        string input;
        cin>>input;
        v.push_back(input);
    }

    if(k<5){
        cout<<0<<'\n';
        return 0;
    }
    Alphabet['a' - 'a'] = true;
    Alphabet['n' - 'a'] = true;
    Alphabet['t' - 'a'] = true;
    Alphabet['i' - 'a'] = true;
    Alphabet['c' - 'a'] = true;
    k = k - 5;
    DFS(0, 0,k);
    cout << Answer << endl;
    return 0;
}