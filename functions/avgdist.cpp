#include<iostream>
#include<cstdio>
using namespace std;
float avgdist(int A[][1000],int N){
    int D[N][N],i,j,k;
    float ans;
    for (i=0;i<=N-1;i=i+1){
        for (j=0;j<=N-1;j=j+1){
            if (i==j){
                D[i][j]=0;
            }
            else if (A[i][j]==1){
                D[i][j]=1;
            }
            else{
                D[i][j]=INT_MAX;
            }
        }
    }
    for (k=0;k<=N-1;k=k+1){
        for (i=0;i<=N-1;i=i+1){
            for (j=0;j<=N-1;j=j+1){
                if (max(D[i][k],D[k][j])==INT_MAX){
                    continue;
                }
                if (D[i][j]>D[i][k]+D[k][j]){
                    D[i][j]=D[i][k]+D[k][j];
                }
            }
        }
    }
    ans=0;
    for (i=0;i<=N-1;i=i+1){
        for (j=0;j<=i-1;j=j+1){
            if (D[i][j]==INT_MAX){
                return INT_MAX;
            }
            ans+=D[i][j];
        }
    }
    ans=ans/(N*(N-1)/2);
    return ans;
}
int main(){
    //freopen("adj.txt","r",stdin);
    int N,i,j;
    float alpha,cost;
    cin>>N>>alpha;
    int A[N][1000];
    for (i=0;i<=N-1;i=i+1){
        for (j=0;j<=N-1;j=j+1){
            cin>>A[i][j];
        }
    }
    cout<<"D(G) = "<<avgdist(A,N);
    return 0;
}