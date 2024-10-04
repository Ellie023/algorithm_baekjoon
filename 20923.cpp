#include <iostream>
#include <vector>
#include <deque>

using namespace std;

 /*
  * do,su 각각 덱,그라운드를 가짐
  * 차례를 바꿔가며 카드를 ground에 둠
  * 어떤 플레이어가 종을 쳐?
  * 종을 치고 덱으로 이동
  * 승리자 판단
  * */
const int DO=0,SU=1;

string judge(vector<deque<int>> &deck){
    int do_size=deck[DO].size();
    int su_size=deck[SU].size();

    if(do_size>su_size){
        return "do";
    }
    else if(do_size<su_size){
        return "su";
    }
    return "dosu";
}

void ringthebell(int bell, vector<deque<int>>& deck, vector<deque<int>>& ground) {

    while (!ground[!bell].empty()) {

        deck[bell].push_back(ground[!bell].back());
        ground[!bell].pop_back();
    }
    while (!ground[bell].empty()) {
        deck[bell].push_back(ground[bell].back());
        ground[bell].pop_back();
    }
}

int who(vector<deque<int>> &deck, vector<deque<int>> &ground){
    if(!ground[DO].empty()&&ground[DO].front()==5){
        return DO;
    }
    else if(!ground[SU].empty()&&ground[SU].front()==5){
        return DO;
    }
    else if(!ground[DO].empty()&&!ground[SU].empty()&&(ground[DO].front()+ground[SU].front()==5)){
        return SU;
    }
    return -1;
}

int main() {

    int n,m,card1,card2;
    vector<deque<int>> deck(2),ground(2);

    cin>>n>>m;

    while(n--){
        cin>>card1>>card2;
        deck[DO].push_front(card1);
        deck[SU].push_front(card2);
    }

    bool turn=DO;

    while(m--){

        ground[turn].push_front(deck[turn].front());
        deck[turn].pop_front();
        if(deck[turn].empty()){
            break;
        }
        int bell=who(deck,ground);
        if(bell!=-1){
            ringthebell(bell,deck,ground);
        }
        turn=!turn;
    }
    cout<<judge(deck);

    return 0;
}