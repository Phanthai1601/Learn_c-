#include<bits/stdc++.h>
using namespace std;
vector<int>ke[100001];
bool visited[100001];
int cnt,parent[100001];
set<int>se;
void bfs(int u){
	queue<int>q;
	q.push(u);
	visited[u]=true;
	while(!q.empty()){
		int v=q.front();
		cout<<v;
		q.pop();
		
		for(int x:ke[v]){
			if(!visited[x]){
				visited[x]=true;
				q.push(x);
				parent[x]=v;
			}
		}
	}
}
void dfs(int u,vector<int> & path){
	visited[u]=true;
	path.push_back(u);
	for(int x:ke[u]){
		if(!visited[x]){
			dfs(x,path);
		}
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		ke[x].push_back(y);
		
	}
	for(int i=0;i<n;i++){
		sort(ke[i].begin(),ke[i].end());
	}
	vector<int>path;
	dfs(1,path);
	for(int x:path){
		if(x==n){
			cnt++;
		}
	}
	if(cnt==0){
		cout<<"IMPOSSIBLE";
	}else{
	
	cout<<path.size()<<endl;
	for(int x:path){
		cout<<x<<" ";
	}}
	
	
}
