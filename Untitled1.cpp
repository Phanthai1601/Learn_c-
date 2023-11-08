#include<bits/stdc++.h>
using namespace std;
struct student{
	string name ,id;
	double gpa;
};
struct SV{
	student s;
	SV *next;
};
typedef struct SV* sv;
sv makeNode(){
	student s;
	cout<<"Nhap thong tin sinh vien : \n";
	cout<<"Nhap Id : ";cin>>s.id;
	cout<<"Nhap ten : ";cin.ignore();
	getline(cin,s.name);
	cout<<"Nhap GPA : ";cin>>s.gpa;
	sv temp =new SV();
	temp->s=s;
	temp->next=NULL;
	return temp;
}
bool empty(sv a){
	return a==NULL;
}
int Size(sv a){
	int cnt=0;
	while(a!=NULL){
		a=a->next;
	} return cnt;
}
void insertFirst(sv &a){
	sv temp=makeNode();
	if(a==NULL){
		a=temp;
	}else{
		temp->next=a;
		a=temp;
	}
}
void insertLast(sv &a){
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
	int n=Size(a);
	if(pos<=0||pos>n+1){
		cout<<"Vi tri chen khong hop le!\n";
	}
	if(n==1){
		insertFirst(a);
		return;
	}else if(n==pos+1){
		insertLast(a);
		return;
	}
	sv p=a;
	for(int i=1;i<pos-1;i++){
		p=p->next;
	}
	sv temp =makeNode();
	temp->next=p->next;
	p->next=temp;
}
void deleteFirst(sv &a){
	if(a==NULL) return;
	a=a->next;
}
void deleteLast(sv &a){
	if(a==NULL) return;
	sv truoc=NULL,sau=a;
	while(sau->next!=NULL){
		truoc=sau;
		sau=sau->next;
	}
	if(truoc==NULL){
		a=NULL;
	}else {
		truoc->next=NULL;
	}
}
void deleteMiddle(sv &a,int pos){
	int n=Size(a);
	if(pos<1||pos>n){
		cout<<"vi tri xoa khong hop le";
	}
	sv p=a,q=NULL;
	for(int i=1;i<pos;i++){
		q=p;
		p=p->next;
	}
	if(q!=NULL){
		q->next=p->next;
	}else a=a->next;
}
void in(student s){
	cout<<"ID : "<<s.id<<endl;
	cout<<"Ho ten : "<<s.name<<endl;
	cout<<"GPA : "<<s.gpa<<endl;
}
void inds(sv a){
	cout<<"----Danh sach sinh vien---------\n";
	while(a!=NULL){
		in(a->s);
		a=a->next;
	}
	cout<<endl;
	cout<<"----------------------------\n";
}
void Sx(sv &a){
	for(sv p= a;p->next!=NULL;p=p->next){
		sv min=p;
		for(sv q=p->next;q!=NULL;q=q->next){
			if(q->s.gpa<min->s.gpa){
				min=q;
			}
		}
		student tmp=min->s;
		min->s=p->s;
		p->s=tmp;
	}
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
		    insertFirst(head);
		}else if(n==2){
			insertLast(head);
		}else if(n==3){
			int pos;
			cout<<"Nhap vi tri can chen :";
			cin>>pos;
			insertMiddle(head,pos);
		}else if(n==4){
			deleteFirst(head);
		}
		else if(n==5){
			deleteLast(head);
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
