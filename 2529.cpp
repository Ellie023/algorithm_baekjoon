#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<bool> check(10, false);
vector<int> choose;
string max_num = "0123456789";
string min_num = "9876543210";

string chooseTostring(){
    string num="";
    for(int i=0; i<choose.size(); i++){
        num+= to_string(choose[i]);
    }
    return num;
}
void updateAnswer(){
    string num=chooseTostring();
    max_num=max(max_num,num);
    min_num=min(min_num,num);
}

void findMinMax(vector<char> brackets, int cnt){

    if(cnt>brackets.size()){
        updateAnswer();
        return;
    }
    for (int i = 0; i < 10; i++)
    {
        // 아직 선택하지 않은 숫자인 경우만
        if (!check[i])
        {
            // 숫자 선택
            check[i] = true;
            choose.push_back(i);
            if (cnt == 0) {     // 처음 숫자를 뽑는 경우
                findMinMax(brackets, cnt + 1);
            }
            else if(brackets[cnt-1]=='<'&&choose[choose.size()-2]<i){
                findMinMax(brackets, cnt + 1);
            }
            else if(brackets[cnt-1]=='>'&&choose[choose.size()-2]>i){
                findMinMax(brackets, cnt + 1);
            }

            check[i]= false;
            choose.pop_back();
        }
        }
}
int main() {

    int k;

    cin>>k;
    vector<char> brackets(k,'<');
    for(int i=0; i<k; i++){
        cin>>brackets[i];
    }
    min_num = min_num.substr(0, k + 1);
    max_num = max_num.substr(0, k + 1);
    findMinMax(brackets,0);

    cout<<max_num<<'\n'<<min_num;

    return 0;
}