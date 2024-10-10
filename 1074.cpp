#include <iostream>
#include <cmath>
using namespace std;

int count=0;
int n,r,c;
void zizi(int x, int y, int d){
    if(x==c&&y==r){
        cout<<count;
        return;
    }
    else if(c<d+x&&r<d+y&&y<=r&&x<=c){
        zizi(x,y,d/2);
        zizi(x+d/2,y,d/2);
        zizi(x,y+d/2,d/2);
        zizi(x+d/2,y+d/2,d/2);
    }

    else{
        count+=d*d;
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>r>>c;
    zizi(0,0,pow(2,n));
    return 0;
}