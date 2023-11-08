#include<bits/stdc++.h>
using namespace std;
struct student{
	string name,id;
	double gpa;
};
struct Sv{
	student s;
	Sv *next;
};
typedef Sv* sv;
sv makeNode(){
	student s;
	cout<<"Nhap thong tin sinh vien\n";
	cout<<"Nhap id sinh vien";
	cin>>s.id;
	cout<<"Nhap ho ten hoc sinh : ";
	cin>>s.name;
	cout<<"Nhap gpa cua sinh vien : ";
	cin>>s.gpa;
	sv temp= new Sv();
	temp->s=s;
	temp->next=NULL;
	return temp;
}
bool empty(sv a){
	return a==NULL;
}
int size(sv a){
	int cnt=0;
	while(a!=NULL){
		cnt++;
		a=a->next;
	} return cnt;
}
void insertfirst(sv &a){
	sv temp=makeNode();
	if(a==NULL){
		a=temp;
	}else {
		temp->next=a;
		a=temp;
	}
}
void insertlast(sv &a){
	sv temp=makeNode();
	if(a==NULL){
		a=temp;
	}else {
		sv p=a;
		while(p->next!=NULL){
			p=p->next;
		}
		p->next=temp;
	}
}
void insertMiddle(sv &a,int pos){
	int n=size(a);
	if(pos<=0||pos>n+1){
		cout<<"Vi tri chen khong le";
	}
	if(n==1){
		insertfirst(a);
		return;
	}else if(n==pos+1){
		insertlast(a);
		return;
	}else {
		sv p=a;
		for(int i=1;i<pos-1;i++){
			p=p->next;
		}
		sv temp=makeNode();
		temp->next=p->next;
		p->next=temp;
	}
}
void deletefirst( sv &a){
	if(a==NULL){
		return;
	}
	a=a->next;
}
void deletelast(sv &a){
	if(a==NULL) return;
	sv truoc=NULL,sau=a;
	while(sau->next!=NULL){
		truoc=sau;
		sau=sau->next;
	}
	if(truoc==NULL){
		a=NULL;
	}else{
		truoc->next=NULL;
	}
}
void deletemiddle(sv &a,int pos){
	int n=size(a);
	if(pos<=0||pos>n){
		cout<<"vi tri chen khong hop le";
		return;
	}
	sv truoc=NULL,sau=a;
	for(int i=1;i<pos;i++){
		truoc=sau;
		sau=sau->next;
	}
	if(truoc==NULL){
		a=a->next;
	}else truoc->next=sau->next;
}
int main(){
	sv head =NULL;
	while(1){
		cout<<"----------------MENU-----------------\n";
		cout<<"1.Them mot sinh vien vao dau danh sach lien ket\n";
		cout<<"2.Them mot sinh vien vao cuoi danh sach lien ket\n";
		cout<<"3.chen mot sinh vien vao giua danh sach lien ket\n";
		cout<<"4.Xoa sinh vien dau cua danh sach lien ket don\n";
		cout<<"5.Xoa sinh vien cuoi cua danh sach lien ket don\n";
		cout<<"6.Xoa sinh vien o giua danh sach lien ket don \n";
		cout<<"7.Hien thi danh sach  lien ket \n";
		cout<<"8.Sap xep danh sach sinh vien theo gpa\n";
		cout<<"0.Ket thuc chuong trinh \n";
		cout<<"-------------------------------------\n";
		cout<<"Nhap lua chon :";
		int n;cin>>n;
		if(n==1){
		    insertfirst(head);
		}else if(n==2){
			insertlast(head);
		}else if(n==3){
			int pos;
			cout<<"Nhap vi tri can chen :";
			cin>>pos;
			insertMiddle(head,pos);
		}else if(n==4){
			deletefirst(head);
		}
		else if(n==5){
			deletelast(head);
		}else if(n==6){
			int pos;
			cout<<"Nhap vi tri can xoa :";cin>>pos;
			deleteMiddle(head,pos);
		}else if(n==7){
		    inds(head);
		}else if(n==8){
			Sx(head);
		}else if(n==0){
			break;
		}
		} return 0;
}
