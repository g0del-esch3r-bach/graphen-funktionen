#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("rawdata/raw8.txt","r",stdin);
    freopen("gooddata/o8.txt","w",stdout);
    int M,N,i,j,k,b;
    cin>>N>>M;
    cout<<N<<" "<<M<<endl<<endl;
    int A[M][N][N];
    for (i=0;i<=M-1;i=i+1){
        cin>>b;
        for (j=0;j<=N-1;j=j+1){
            for (k=0;k<=N-1;k=k+1){
                cin>>A[i][j][k];
                cout<<A[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}