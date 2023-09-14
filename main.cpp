#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b){//최대 공약수 구하기
    if(!b){
        return a;
    }
    return gcd(b,a%b);
}
vector<int> calculator(int a,int b,int c,int d){
    vector<int> fraction(2,0);//기약분수를 담을 vector
    //두 분수를 더한다
    int denominator=b*d;//분모
    int numerator=a*d+b*c;//분자
    //분자와 분모의 최대공약수
    int fraction_gcd=gcd(max(denominator,numerator),min(denominator,numerator));
    //분자,분모를 최대공약수로 나눈다 (약분하기)
    denominator/=fraction_gcd;
    numerator/=fraction_gcd;
    fraction[0]=numerator;
    fraction[1]=denominator;
    return fraction;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);
    int a,b,c,d;
    cin>>a>>b>>c>>d;//입력(a/b,c/d)

    //연산
    vector<int> fraction = calculator(a,b,c,d);

    //출력
    cout<<fraction[0]<<" "<<fraction[1];
    return 0;
}