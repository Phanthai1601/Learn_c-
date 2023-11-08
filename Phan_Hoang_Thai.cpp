#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int a,b,c;
		cin>>a>>b>>c;
		if(a<0){
			cout<<"CURVE DOWN\n";
		}else if(a>0){
			cout<<"CURVE UP\n";
		}else cout<<"NO CURVE\n";
	}
}
