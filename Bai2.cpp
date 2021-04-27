// Danh sach lien ket don vong.

#include<iostream>
using namespace std;
int n;
struct Node{
	int data;
	Node *next;// chua dia chi node ke tiep ma no tro toi
};

struct List{
	Node *head;
	Node *tail;
};

void Init(List &l){ // k tao List rong
	l.head = l.tail = NULL;
}

Node *creatNode(int x ){ //tao thong tin cho node
	Node *p = new Node;
	if(p == NULL) exit(1);
	p->next = NULL;
	p->data = x;
	return p;
}

bool isEmpty(List l ){ // k tr a xem lieu List co rong hay k.
	if(l.head == NULL ) return true;
	return false;
}

// chen vao dau List:
void addHead(List &l, int x ){ 
	Node *p = creatNode(x);
	if(isEmpty(l)) l.head = l.tail = p;
	else{
		p->next = l.head; // con tro next cua p tro toi dia chi cua node head(ban dau)
		l.head = p; // cap nhat node head( luc sau )
	}
	l.tail->next = l.head; // khep vong don.
}
// ham chen vao cuoi List
void addTail(List &l, int x ){
	Node *p = creatNode(x);
	if(isEmpty(l)) addHead(l,x);
	else{
		l.tail->next = p;
		l.tail = p;
	}
	l.tail->next = l.head; // khep vong don
}
// tim kiem
Node *search(List l, int k ){
	Node *p = l.head;
	do {
		if( p->data == k ) return p;
		else p = p->next;
	} while( p != l.head );
	return NULL;
}

void addMid(List &l, int x, int k ){ // chen node co data = x vao sau node co data  = k;
	Node *p = search(l,k);
	if(p!=NULL){
		Node *q= creatNode(x);
		Node *r = p->next;
		p->next = q;
		q->next = r;
	}
	else cout<<"\nKhong tim thay node co data = k.";
}
/*
void addAtK(List &l, int x, int k ){ // chen vi tri bat ki;
	if(isEmpty(l) || k<= 1 ) addHead(l,x);
	else if(k>= n) addTail(l,x);
	else{
		Node *p = creatNode(x);
		Node *q = new Node, *w = new Node;
		Node *r = l.head;
		int dem = 0;
		while(r!=NULL){
			dem++;
			q = r;
			if(dem == k ) break;
			else r = r->next;
		}
		w = l.head;
		while(w->next!= q) w = w->next;
		w->next = p;
		p->next = r;
	}
} */
// nhap vao mot list bat ki
void nhap(List &l){
	cout<<"\nnhap so ptu ban dau cua List: "; cin>> n;
	for(int i = 1; i<= n; i++ ) addTail(l,i);
}
// xuat thong tin ra man hinh
void xuat(List l ){	
	if(l.head){
		cout<< "\nDanh sach cac phan tu: \n";
		Node *p = l.head;
		do{
			cout<<" " << p->data;
			p = p->next;
		}while( p != l.head );
	}
	else cout<< "\nDanh Sach Rong";
	cout<< endl;
}

void delHead(List &l ){ // xoa node o dau List
	if(!isEmpty(l)){
		if(l.head != l.tail ){
			Node *p = l.head;
			l.head = l.head->next; // cap nhat l.head
			delete p; // xoa bo node head ban dau
			l.tail->next = l.head;
		}
		else l.head = NULL;
	}
	else return;
}

void delTail(List &l ){
	if(!isEmpty(l)){
		if(l.head != l.tail ){
			Node *p = l.head;
			Node *q = new Node;
			while(p->next != l.tail ) p = p->next; // tim node ngay truoc tail
			q = p; // gan node nay cho node q
			p = p->next; // p chinh la node tail can xoa
			l.tail = q; // cap nhat l.tail
			l.tail->next = l.head;
			delete p;
		} else l.head = NULL;
	}
	else return;
}

void delAtK(List &l, int k ){
	if( k <= 1) delHead(l);
	else if( k >= n ) delTail(l);
	else{
		int dem = 0;
		if(!isEmpty(l)){
			Node *p = l.head;
			Node *q = new Node;
			while(p != NULL){ // tim node thu k.
				dem++;
				q = p;
				if(dem == k ) break; // tim thay thi break
				else p= p->next; // k thi tim tiep
			}
			Node *r = l.head;
			while(r->next != q ) r = r->next; // tim node k-1
			r->next = q->next; // cho node next cua node k-1 tro toi node k+1;
			delete q;
		}
	}
}

void menu(){
	List l;
	Init(l);
	nhap(l);
	xuat(l);
	int k, x, lc;
	do{
		cout<<"\n______MENU______\n1_Chen dau.\n2_chen cuoi."
			<<"\n3_Chen sau vi tri node data = k.\n4_Chen vao vi tri bat ki."
			<<"\n5_Xuat Thong tin List.\n6_Xoa phan tu dau List."
			<<"\n7_Xoa phan tu o cuoi List.\n8_Xoa node o vi tri k."

			<<"\n0_Thoat.\n_Ban chon ? ";
			cin>> lc;
		switch(lc){
			case 0: break;
			case 1: cout<<"\nNhap x: "; cin>> x; addHead(l,x); n++; break;
			case 2: cout<<"\nNhap x: "; cin>> x; addTail(l,x); n++; break;
			case 3: cout<<"\nNhap x, k: "; cin>> x >> k; addMid(l,x, k);n++; break;
			case 5: xuat(l); break;
			case 6: delHead(l); n--; break;
			case 7: delTail(l); n--; break;
			case 8: cout<<"\nNhap vi tri k: "; cin>> k; delAtK(l,k); n--; break;
		}
	}while(lc != 0 );
}

int main(){
	menu();	
	return 0;
}
