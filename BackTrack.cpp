// dic huyen trong me cung 2
#include<bits/stdc++.h>
using namespace std;
int n,a[100][100];
int dx[4]={0,-1,1,0};
int dy[4]={-1,0,0,1};
string s="ULDR";
void inp(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
}
void Try(int i,int j,string p){
	if(i==n&&j==n){
		cout<<p<<endl;
	}
	for(int k=0;k<4;k++){
		int i1=i+dx[k],j1=j+dy[k];
		if(i1<=n&&i1>=1&&j1<=n&&j1>=1&&a[i1][j1]==1){
			a[i1][j1]=0;
			Try(i1,j1,p+s[k]);
			a[i1][j1]=1;
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		inp();
		Try(1,1,"");
	}
}
