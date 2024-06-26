#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

struct person{
    int age;
    string name;
};
bool cmp(const person& now_age,const person& last_age){
    if(now_age.age!=last_age.age){
        return now_age.age<last_age.age;
    }
    return false;
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    person member[100001];

    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>member[i].age;
        cin>>member[i].name;
    }
    stable_sort(member,member+n,cmp);

    for(int i=0; i<n; i++){
        cout<<member[i].age<<" "<<member[i].name<<"\n";
    }

    return 0;
}