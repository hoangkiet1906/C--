#include<iostream>
using namespace std;

struct TNode{
	int data;
	TNode *left;
	TNode *right;
};

typedef TNode *Tree;

void Init(Tree &t){
	t = NULL;
}

TNode *creatNode(int x){
	TNode *t=  new TNode;
	if(t == NULL ) exit(1);
	t->data = x;
	t->left = NULL;
	t->right = NULL;
	return t;
}

int insert(Tree &t, Tree p ){
	if( t != NULL ){
		if( t->data == p->data ) return -1;
		else{
			if( p->data < t->data) return insert( t->left, p );
			else return insert( t->right, p );
		}		
	}
	t = new TNode;
	if( t == NULL ) return 0;
	t = p;
	return 1;
}

TNode *searchDQ(Tree t, int x ){ // tim kiem dung de quy
	if( t ){
		if( t->data == x ) return t;
		else{
			if( t->data > x ) return searchDQ( t->left, x );
			else if( t->data < x ) return searchDQ( t->right, x );
		}
	}
	return NULL;
}

void thayThe( Tree p, Tree t ){
	if( t->left != NULL ) thayThe( p, t->left );
	else{
		p->data = t->data;
		p = t;
		t = t->right;
	//	delete t;
	}
}

TNode *getS( TNode *p ){
	TNode *current = p->right;
	TNode *parent = NULL;
	TNode *s = NULL;
	while( current != NULL ){
		parent = s;
		s = current;
		current = current->left;
	}
	if( s!= p->right ){
		parent->left = s->right;
		s->right = p->right;
	}
	return s;
}


void NLR(Tree t){
	if( t != NULL ){
		cout<< t->data  << " ";
		NLR(t->left);
		NLR(t->right);
	}
}

void LNR(Tree t ){
	if(t != NULL ){
		LNR(t->left);
		cout<<t->data << " ";
		LNR(t->right);
	}
}

void LRN(Tree t){
	if(t != NULL ){
		LRN(t->left);
		LNR(t->right);
		cout<< t->data << " ";
	}
}

void NRL( Tree t){
	if( t!= NULL ){
		cout<<t->data<< " ";				
		NRL(t->right);
		NRL(t->left);
	}
}

void RNL( Tree t){
	if( t != NULL ){
		RNL( t->right );
		cout<< t->data << " ";
		RNL(t->left);
	}
}

void RLN( Tree t ){
	if(t!=NULL){		
		RLN(t->right);
		RLN(t->left);
		cout<<t->data<< " ";
	}
}

void countLeafNode(Tree t, int &count ){
	if(t){
		countLeafNode(t->left, count);
		if(t->left == NULL && t->right == NULL ) count++;
		countLeafNode(t->right, count);
	}
}

int dem( Tree root ){	// dem so node trong cay nhi phan.
	if( root == NULL ) return 0;
	else return( dem(root->right) + dem(root->left) ) +1;
}
TNode *getSuccessor(TNode *p){
	while(p->left) p = p->left;
	return p;
}

void deleteNode(Tree &t, int x ){
	if(t == NULL) return;
	if( x < t->data ) deleteNode(t->left, x);
	else if( x > t->data ) deleteNode(t->right, x);
	else{
		TNode *p = t;
		if(!t->left){
			p = t;
			t = t->right;
			delete p;
		}
		else if( !t->right ){
			p = t;
			t = t->left;
			delete p;
		} else{
			TNode *q = getSuccessor(t->right);
			t->data = q->data;
			deleteNode(t->right, q->data);
		}
	}
}

void del(Tree &t){
	int x;
	cout<< "\Nhap node can xoa : ";
	cin >> x;
	deleteNode(t, x);
}

int maxDepth( Tree root ){
	if( !root ) return -1;
	else return max( maxDepth( root->left ) , maxDepth( root->right ) ) + 1;
}

void menu(){
	Tree t;
	Init(t);
	int n, x;
	while(1){
		cout<<"\nNhap gia tri x cho node can them, nhap 0 de thoat: "; cin>> x;
		if( x == 0 ) break;
		Tree p = creatNode(x);
		int k = insert( t, p );
		if( k == 0 ) cout<<"\nkhong du bo nho.";
		else if( k == -1 ) cout<<"\nTrung voi phan tu da co, nhap lai: ";
	}	
	cout<<"\nDuyet cay nhi phan NLR: \n"; NLR(t);
	cout<<"\nDuyet cay nhi phan LNR: \n"; LNR(t);
	cout<<"\nDuyet cay nhi phan LRN: \n"; LRN(t);
	cout<<"\nDuyet cay nhi phan NRL: \n"; NRL(t);
	cout<<"\nDuyet cay nhi phan RNL: \n"; RNL(t);
	cout<<"\nDuyet cay nhi phan RLN: \n"; RLN(t);
	cout<<"\nNhap gtr can tim: "; cin >> x;
	TNode *p = searchDQ(t,x);
	if( p ) cout<< "Success!" << endl;
	else cout<< "\nFailed.";
	
	int count = 0;
	countLeafNode(t,count);
	cout<< "\ncay nhi phan co "<< count << " node la";
	cout<<"\nSo node trong cay nhi phan tim kiem: " << dem(t) << endl;
	
	cout<<"\nDo cao cua K la : "<<maxDepth(t)+1<<endl;
	
	del(t);
	cout<<"\nDuyet cay nhi phan NLR: \n"; NLR(t);
	cout<<"\nDuyet cay nhi phan LNR: \n"; LNR(t);
	cout<<"\nDuyet cay nhi phan LRN: \n"; LRN(t);
	cout<<"\nDuyet cay nhi phan NRL: \n"; NRL(t);
	cout<<"\nDuyet cay nhi phan RNL: \n"; RNL(t);
	cout<<"\nDuyet cay nhi phan RLN: \n"; RLN(t);
}



int main(){
	menu();
	return 0;
}
