#include <iostream>
#include <map>
#include "string"
using namespace std;
struct node{
    float value=0;
};
int main() {

    map<string,float> grade;
    string s;
    int n=20;
    float a;
    string b;
    float sum=0;//학점의 총합
    while (n--)//20줄
    {

        cin>>s>>a>>b;//입력
        grade[b]+=a; //전공과목별로 학점 저장 ex) grade[A+]=3.0+4.0+a
        if(b!="P")//P는 계산하지 않는다.
            sum+=a;
    }
    std::cout.precision(7);
    float g;
    g=(grade["A+"]*4.5)+(grade["A0"]*4.0)+(grade["B+"]*3.5)+(grade["B0"]*3.0)+(grade["C+"]*2.5
    )+(grade["C0"]*2.0)+(grade["D+"]*1.5)+(grade["D0"]*1.0)+(grade["F"]*0.0);

    g/=sum;//전공평점은 전공과목별 (학점 × 과목평점)의 합을 학점의 총합으로 나눈 값
    cout<<g;//출력
    return 0;
}