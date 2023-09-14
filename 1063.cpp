#include <iostream>
#include "string"
#include "vector"

using namespace std;
bool Range(pair<char,int> location){
    if(location.first>='A'&&location.first<='H'){
        if(location.second>=1&&location.second<=8)
        {
            return true;
        }
    }
    return false;
}
pair<char,int>move(string input,char x,char y){
    for(int i=0; i<input.length(); i++){
        char ch=input[i];
        switch (ch) {
            case 'R':
                x++;
                break;
            case 'L':
                x--;
                break;
            case 'B':
                y--;
                break;
            case 'T':
                y++;
                break;
        }

    }
    return {x,y};
}


int main() {

    pair<char, int> king, stone;
    int n;
    string input;

    //입력
    cin>>king.first>>king.second>>stone.first>>stone.second>>n;

    while(n--){
        pair<char,int> after_king,after_stone;//다음 킹,돌 위치
        cin>>input;
        //위치 옮기기
        after_king= move(input,king.first,king.second);

        //돌의 위치가 다음 킹의 위치와 같다면
        if(stone.first==after_king.first&&stone.second==after_king.second){
            after_stone= move(input,stone.first,stone.second);
            //돌을 킹과 같은 방향으로 옮긴다.
        }
        else{//겹치지 않는다면 그대로
            after_stone=stone;
        }

        //다음 위치가 체스판의 범위를 벗어나면 위치를 변경하지 않는다.
        if(Range(after_king)&& Range(after_stone)){
            stone=after_stone;
            king=after_king;
        }
    }
    //출력
    cout<<king.first<<king.second<<'\n';
    cout<<stone.first<<stone.second<<'\n';
    return 0;
}