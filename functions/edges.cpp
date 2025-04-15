#include<iostream>
#include<cstdio>
using namespace std;
float numedge(int A[][1000],int N){
    int i,j;
    float ans;
    ans=0;
    for (i=0;i<=N-1;i=i+1){
        for (j=0;j<=i-1;j=j+1){
            ans+=A[i][j];
        }
    }
    return ans;
}
int main(){
    //freopen("../adj.txt","r",stdin);
    int N,i,j;
    float alpha,cost;
    cin>>N>>alpha;
    int A[N][1000];
    for (i=0;i<=N-1;i=i+1){
        for (j=0;j<=N-1;j=j+1){
            cin>>A[i][j];
        }
    }
    cout<<"E(G) = "<<numedge(A,N);
    return 0;
}