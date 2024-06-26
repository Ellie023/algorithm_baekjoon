#include <iostream>
#include <vector>

using namespace std;


string A;
string B;

void LCS_LENGHTH(vector<vector<string>>&b,vector<vector<int>>&c,int m,int n){

    for(int i=1; i<=n; i++){
        c[i][0]=0;
    }
    for(int j=1; j<=m; j++){
        c[0][j]=0;
    }
    for(int i=1; i<=n; i++){
        for (int j = 1; j <=m; j++) {
            if(A[i-1]==B[j-1]){
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]="↖";
            }
            else if(c[i-1][j]>=c[i][j-1]){
                c[i][j]=c[i-1][j];
                b[i][j]="↑";
            } else{
                c[i][j]=c[i][j-1];
                b[i][j]="←";
            }
        }
    }
}

void PRINT_LCS(vector<vector<string>>&b,int i, int j){
    if(i==0||j==0){
        return;
    }
    if(b[i][j]=="↖"){
        PRINT_LCS(b,i-1,j-1);
        cout<<A[i-1];
    }
    else if(b[i][j]=="↑"){
        PRINT_LCS(b,i-1,j);
    }
    else
        PRINT_LCS(b,i,j-1);
}

int main() {

    cin>>A>>B;
    int m= A.length();
    int n=B.length();

    vector<vector<int>> c(n+1,vector<int>(m+1,0));
    vector<vector<string>> b(n+1,vector<string>(m+1,"0"));


    LCS_LENGHTH(b,c,m,n);
    PRINT_LCS(b,n,m);

    return 0;
}