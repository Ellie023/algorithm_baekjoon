#include <iostream>
#include <map>
#include "string"
using namespace std;

int main() {

    map<string,float> grade;
    string s;
    int n=20;
    float a;
    string b;
    while (n--)
    {
        float sum=0;//학점의 총합
        cin>>s>>a>>b;
        if(!grade[b])
            grade[b]=1;
        else
            grade[b]++;
        if(b!="P");

    }

    return 0;
}