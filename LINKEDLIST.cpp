#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	struct Node *next;
};
typedef Node* node;
// tao mot node moi tu thong tin da co
node makenode(int x){
	node temp=new Node();
	temp->data=x;
	temp->next=NULL;
	return temp;
}
// tra ve kich thuoc cua danh sach lien ket don
int size(node head){
	int cnt=0;
	while(head!=NULL){
		cnt++;
		head=head->next;
	}
	return cnt;
}
// Hien thi danh sach lien ket don
void display(node head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}
// Them vao dau danh sach lien ket don
void themdau(node &head,int x){
	node moi =makenode(x);
	if(head==NULL){
		head=moi;
	}else {
		moi->next=head;
		head=moi;
	}	
}
// Them vao cuoi danh sach lien ket don
void themcuoi(node &head,int x){
	node moi =makenode(x);
	if(head==NULL){
		head=moi;
	}else {
		node temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=moi;
	}
}
//Them vao giua danh sach lien ket don
void themgiua(node &head,int x,int vitri){
	int n=size(head);
	if(vitri<1||vitri>n+1){
		cout<<"Vi tri chen khong hop le \n";
		return ;
	}
	if(n==1){
		themdau(head,x);
	}
	else if(vitri==n+1){
		themcuoi(head,x);
	}else{
		node temp=head;
		for(int i=1;i<=vitri-2;i++){
			temp=temp->next;
		}
		node moi =makenode(x);
		moi->next=temp->next;
		temp->next=moi;
	}
	
}
// xoa node dau cua danh sach lien ket don
void xoadau(node &head){
	node temp=head;
	head=head->next;
}
// xoa node cuoi cua danh sach lien ket don
void xoacuoi( node &head){
	if(head==NULL){
		cout<<"Danh sach lien ket rong";
		return;
	}
	node p=head,q=NULL;
	while(p->next!=NULL){
		q=p;
		p=p->next;
	}
	delete p;
	if(q==NULL){
		head=NULL;
	}else q->next=NULL;
	
}
void xoagiua(node &head,int pos){
	int n=size(head);
	if(pos<1||pos>n){
		cout<<"Vi tri xoa khong hop le ";
		return ;
	}
	node p=head,q=NULL;
	for(int i=1;i<pos;i++){
		p=q;
		p=p->next;
	}
	if(q!=NULL){
		q->next=p->next;
	}else {
		head=head->next;
		
	}

}
// Tim kiem mot phan tu trong danh sach lien ket don
bool timkiem(node head,int val){
	while(head!=NULL){
		if(head->data==val){
			return true;
		}else head=head->next;
	}
	return false;
}
//sap xep
/*void sapxep(node &head){
	for(node i=head;i!=NULL;i=i->next){
	   node min=i;
		for(node j=i->next;j!=NULL;j=j->next){
			if(j->)
		}
	}
}*/
int main(){
	node head =NULL;
	while(1){
		cout<<"----------------MENU-----------------\n";
		cout<<"1.Them mot node vao dau danh sach lien ket\n";
		cout<<"2.Them mot node vao cuoi danh sach lien ket\n";
		cout<<"3.chen mot node vao gua danh sach lien ket\n";
		cout<<"4.Xoa node dau cua danh sach lien ket don\n";
		cout<<"5.Xoa node cuoi cua danh sach lien ket don\n";
		cout<<"6.Hien thi danh sach  lien ket \n";
		cout<<"7.Tim kiem mot phan tu co trong danh sach lien ket khong\n";
		cout<<"0.Ket thuc chuong trinh \n";
		cout<<"-------------------------------------\n";
		cout<<"Nhap lua chon :";
		int n;cin>>n;
		if(n==1){
			int x;
			cout<<"Nhap gia tri can them :";
			cin>>x;
			themdau(head,x);
		}else if(n==2){
			int x;
			cout<<"Nhap gia tri can them :";
			cin>>x;
			themcuoi(head,x);
		}else if(n==3){
			int x;
			cout<<"Nhap gia tri can chen :";
			cin>>x;
			int pos;
			cout<<"Nhap vi tri can chen :";
			cin>>pos;
			themgiua(head,x,pos);
		}else if(n==4){
			xoadau(head);
		}
		else if(n==5){
			xoacuoi(head);
		}else if(n==6){
			display(head);
		}else if(n==7){
			int val;
			cout<<"Nhap gia tri can tim";
			cin>>val;
			if(timkiem(head,val)){
				cout<<"YES";
			}else cout<<"NO";
		}else if(n==0){
			break;
		}
		}
}
