// kiem tra so nguyen to
bool nto(int n){
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0) return false ;
	}return n>1;
}
/  / day so fibonacii
void in(long long n){
	long long fibo[100];
	fibo[0]=0;
	fibo[1]=1;
	for(int i=2;i<=92;i++){
		fibo[i]=fibo[i-1]+fibo[i-2];
	}for(int i=0;i<=n;i++){
		cout<<fibo[i]<<'\n';}}
// phi ham ocle
	int phi(int n){
	int res=n;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			res=res-res/i;
			while(n%i==0)
			n/=i;
		}
	}
if(n>1){
	res=res-res/n;
}return res;
}	
// to hop chap k cua n
//cach1
long long gt(int n){
	long long res =1;
	for(int i=1;i<=n;i++) res*=i;
	return res;
}	
long long tohop(int n ,int k){
	long long ngt=gt(n);
	long long kgt=gt(k);
	long long nkgt=gt(n-k);
	return ngt/(kgt*nkgt);
}
//cach2
long long tohop(int n,int k){
	int res=1;
	for(int i=1;i<=k;i++){
		res*=(n-i+1);
		res/=i;
		
	}return res;
}
// uoc chung lon nhat va boi chung nho nhat 
int gcd(int a,int b){
	while(b!=0){
	
	int du =a%b;
	a=b;
	b=du;
}	return a;}
int lcm(int a,int b){
return a/gcd(a,b)*b
}
//sang so nguyen to
 const int n=1000000;
	bool nto[n+1];
void sang(){
	for(int i=0;i<=n;i++){
		nto[i]=true;
	}
	nto[0]=nto[1]=false;
	for(int i=2;i<=sqrt(n);i++){
		if(nto[i]==true){
			for(int j=i*i;j<=n;j+=i){
				nto[j]=false;
			}
		}
	}
}
//so thuan ngich
bool thuannghich(int n){
	int lat=0;int temp=n;
	while(n){
		int du=n%10;
		lat=lat*10+du;
		n/=10;
	}if(lat=temp)
	return true;
	else return false;
	}
// set(sap xep theo thu tu tu be den lon)
+) count;
+) find;
+) erase
// mutlti map(cac phan tu co the trung)
//unordered_map(cac phan tu khong co thu tu)
//map 
// tim kiem nhi phan
bool bs(int a[],int n,int x){
	int l=0,r=n-1;
	while(l<=r){
		int m=(l+r)/2;
		if(a[m]==x) return true;
		else if(a[m]<x){
			l=m+1;
		}
		else r=m-1;
	} return false;
}
bool binarysearch(int a[],int l,int r,int x){
	if(l>r) return false;
	int m=(l+r)/2;
	if(a[m]==x) return true;
	else if(a[m]<x)
	return binarysearch(a,m+1,r,x);
	else return binarysearch(a,l,m-1,x);
}
void seclectionsort(int a[],int n){
	for(int i=0;i<n-1;i++){
		int min_pos=i;
		for(int j=i+1;j<n;j++){
			if(a[j]<a[min_pos]){
				min_pos=j;
			}
		}
		swap(a[i],a[min_pos]);
	}
}
void bublesort(int a[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
}
//sinh hoan vi ke tiep
#include<bits/stdc++.h>
using namespace std;
int n,a[100],ok;
void ktao(){
	for(int i=1;i<=n;i++){
		a[i]=i;
	}
}
void sinh(){
	int i=n-1;
	while(i>=1&&a[i]>a[i+1]){
		--i;
	}
	if(i==0){
		ok=0;
	}
	else {
		int j=n;
		while(a[i]>a[j])
			--j;
			swap(a[i],a[j]);
		
		int l=i+1,r=n;
		while(l<r){
			swap(a[l],a[r]);
			++l;--r;
		}
	}
}
int main(){
	cin>>n;
	ok=1;
	ktao();
	
	while(ok){
		for(int i=1;i<=n;i++){
			cout<<a[i];
			
		}
	
		
		cout<<endl;
		sinh();
	}
	
}
//sang so nguyen to tren doan
#include<bits/stdc++.h>
using namespace std;
void sang(int l,int r){
	bool nto[r-l+1];
	for(int i=0;i<=r-l+1;i++){
		nto[i]=true;
	}
	for(int i=2;i<=sqrt(r);i++){
		for(int j=max(i*i,(l+i-1)/i*i);j<=r;j+=i){
			nto[j-l]=false ;
		}
	}
	for(int i=max(2,l);i<=r;i++){
		if(nto[i-l]){
			cout<<i<<" ";
		}
	}
}
int main(){
	int l,r;
	cin>>l>>r;
	sang(l,r);
}

