#include<iostream>
#include<vector>
#include<algorithm>
#include "../eigen-3.4.0/Eigen/Dense"
#include "../eigen-3.4.0/Eigen/Eigenvalues"
using Eigen::MatrixXd;
using Eigen::VectorXcd;
using namespace std;
int main(){
  //freopen("../adj.txt","r",stdin);
  int N,i,j,k;
  vector<float>V;
  float alpha;
  cin>>N>>alpha;
  MatrixXd L(N,N);
  VectorXcd EV;
  int A[1000][1000];
  for (i=0;i<=N-1;i=i+1){
      for (j=0;j<=N-1;j=j+1){
          cin>>A[i][j];
      }
  }
  for (i=0;i<=N-1;i=i+1){
    for (j=0;j<=N-1;j=j+1){
      if (i!=j){
        L(i,j)=-A[i][j];
      }
      if (i==j){
        L(i,j)=0;
        for (k=0;k<=N-1;k=k+1){
          L(i,j)+=A[i][k];
        }
      }
    }
  }
  EV=L.eigenvalues();
  V.clear();
  for (i=0;i<=N-1;i=i+1){
    V.push_back(EV(i).real());
  }
  sort(V.begin(),V.end());
  cout<<"λ₂(G) = "<<V[1]<<endl;
  return 0;
}