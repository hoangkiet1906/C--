#include <iostream>
#include <conio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include<stack>
using namespace std;
 
#define MAX 10
#define EMPTY -1
 
struct ExpNode
{
    int Type;    //so
    char *Symbol;  //a,b,c,d
    float value;    //de chua gia tri cua bien
    ExpNode *left;
    ExpNode *right;
};
 
struct sstack
{
    ExpNode *data[MAX];
    int Top;
};
 
int isempty(sstack *s)
{
    return (s->Top == EMPTY)? 1 : 0;
}
 
void emptystack( sstack *s )
{
    s->Top = EMPTY;
}
 
//dao chuoi
char *daochuoi (const char *str)
{
    int len = strlen(str);
    char *tam=new char(len+1);
    for( int i=0; i <= len/2; i++ )
    {
        tam[i] = str[len-i-1];
        tam[len-i-1] = str[i];
    }
    tam[len] = 0;
    return tam;
}
 
void push(char *S,int &T,char X)
{
    if ( T == 100 )
        cout<<"khong bo sung dc";
    else
        {
            T = T+1;
            S[T] = X;
        }
    return;
}
 
 
void pop( char *S, int &T, char &X )
{
    if ( T == 0 ) return;
    else
        {
            X = S[T];
            T = T-1;
        }
    return;
}
 
 
void push( float *S, int &T, float X)
{
    if ( T == 100 )
        cout<<"khong bo sung dc";
    else
        {
            T = T+1;
            S[T] = X;
        }
    return;
}
 
 
 
void pop( float *S, int &T, float &X )
{
    if ( T == 0 ) cout<<"bieu thuc nhap vao khong dung";
    else
        {
            X = S[T];
            T = T-1;
        }
    return;
}
 
 
 
void push( sstack *s, ExpNode *item )
{
    if( s->Top == (MAX-1) )
    {
        cout<<"\n Stack day";
    }
    else
    {
        ++s->Top;
        s->data[s->Top] = item;
    }
}
 
 
 ExpNode* pop( sstack *s )
 {
     ExpNode *ret = NULL;
     if( !isempty(s) )
     {
         ret = s->data[s->Top];
         --s->Top;
     }
     return ret;
 }
 
 
//chuyen chuoi ki tu so thanh so
float chuyen( char *a )
{
    int l,flat = -1,dem = 0;
    float s = 0;
    l=strlen(a);
    for ( int i = 0; i < l; i++ )
        if ( a[i] == 46 )       // Neu ky tu bang dau '.'
        {
            flat = i;
            break;
        }
    if ( flat == -1 )
        for ( int i = l-1; i >= 0; i--,dem++ )
            s += ( a[i] - 48 )*pow(double(10),dem);
    else
        {
        for ( int i = flat-1; i >= 0; i--,dem++ )
            s += ( a[i] - 48 )*pow(double(10),dem);
        dem = -1;
        for ( int i = flat+1; i<l; i++,dem-- )
            s += ( a[i] - 48 )*pow(double(10),dem);
        }
    return s;
}
 
int douutien ( char c )
{
    if( c == '+' || c == '-')
        return 1;
    else if( c == '*' || c == '/' )
        return 2;
    else if( c == '!' )
        return 3;
    else    return 0;
}
 
 
// --------------chuyen tu xau trung to sang xau tien to-----------
char *chuyentrungto ( char *g )
{
    int n = strlen(g),T = 0,j = -1;
    char *h;
    char *inFix;    inFix = daochuoi(g);
    char *chuoihauto = new char[100],x;
    char stack[100];        //luu cac ky tu +,-,*,/,(,)
    char *a=chuoihauto;     //con tro chua chuoi de xuat
   
   
   
        for( int i = 0; i<n; i++ )  // doc chuoi vao: inFix
        {
            if ( inFix[i] != ' ' )
            {
                if ( ( inFix[i] >= '0' && inFix[i] <= '9' ) || inFix[i] == '.' || inFix[i] >= 'a' && inFix[i] <= 'z' )                  //Neu la toan hang thi cho vao
                {   a[++j]=inFix[i];                                                //chuoi xuat   
                if ( ( inFix[i+1] == '+' ) || ( inFix[i+1] == '-' ) || ( inFix[i+1] == '*' ) || ( inFix[i+1] == '/' ) || ( inFix[i+1] == '\0' ) || ( inFix[i+1] == ' ' ) || ( inFix[i+1] == '(' ) )
                        a[++j]=' ';
                }
                //Neu gap ki tu ')' thi ta push vao stack
                else if ( inFix[i] == ')' )
                    push( stack, T, inFix[i] );
                //Neu gap ki tu '('
                else if ( inFix[i] == '(' )
                {
                    while ( stack[T] != ')' )
                    {   pop( stack, T, x ); a[++j] = x; a[++j] = ' ';}
                    //pop phan tu chua ki tu ')' ra khoi stack
                    pop( stack, T, x);
                }
                else    //Khi gap cac toan tu(+,-,*,/) ta push vao stack
                {
                    if ( ( inFix[0] == '-' ) || ( inFix[i] == '-' && inFix[i+1] == '+' ) || ( inFix[i] == '-' && inFix[i+1] == '-' ) || ( inFix[i] == '-' && inFix[i+1] == '*' ) || ( inFix[i] == '-' && inFix [i+1] == '/' )||( inFix [i] == '-' && inFix [i+1] == ')' ) )
                        inFix[i] = '!';
                    while ( ( T != 0 ) && ( douutien( stack[T] ) >= douutien( inFix[i] ) ) )
                    {
                        pop( stack, T, x ); a[++j] = x; a[++j] = ' ';
                    }
                    push( stack, T, inFix[i] );
                }
            }
           
        }
        //sau khi ra khoi vong for thi Pop het cac phan tu con lai trong stack b vao chuoi xuat
        while( T != 0 )
        {
            pop( stack, T, x ); a[++j] = x; a[++j] = ' ';
        }
        a[j] = '\0';
        h = daochuoi(a);
        //xuat chuoi hau to ra     
        return h;
}
 
 
 
//-------------Tao cay----------
void Taocay( ExpNode **T, char *inFix )
{
    sstack X;
    ExpNode *newnode, *op1, *op2;
    char temp[25];  //luu chuoi ki tu so
    char *p , *d;
    float Y;
    int i = 0, j = (strlen(inFix) - 1);
 
    emptystack(&X);
    p = &inFix[strlen(inFix)-1];
   
    while( *p )
    {
        while( *p == ' ' || *p == '\t' || *p == '\0')
        {
            p--; j--;
        }
        if ( isdigit(*p) )
        {
            while( isdigit(*p) )
            {
                temp[i] = *p;
                p--; j--;
                i++;
            }
 
            temp[i]='\0';
            i = 0;
            d = daochuoi(temp);
           
            newnode = new ExpNode;
            Y=chuyen(d);
            newnode->Symbol=new char[strlen(d)];
            strcpy(newnode->Symbol,d);
            newnode->value=Y;
            newnode->Type=0;
            newnode->left = NULL;
            newnode->right = NULL;
            push(&X,newnode);
           
        }
        else if( *p >= 'a' && *p <= 'z')
        {
            newnode = new ExpNode;
            newnode->Symbol=new char[2];
            newnode->Symbol[0] = *p;    newnode->Symbol[1]='\0';
            newnode->Type=0;
            newnode->left = NULL;
            newnode->right = NULL;
            push( &X, newnode );
        }
        else if( *p == '!' )
        {
            op1 = pop(&X);
            newnode = new ExpNode;
            newnode->Type = 6;
            newnode->right = op1;
            newnode->left = NULL;
            push( &X, newnode );
        }
        else
        {
            op1 = pop(&X);
            op2 = pop(&X);
            newnode = new ExpNode;
            if( *p == '+' )
                newnode->Type = 1;
            else if( *p == '-' )
                newnode->Type = 2;
            else if( *p == '*' )
                newnode->Type = 3;
            else if( *p == '/' )
                newnode->Type = 4;
            else if( *p == '^' )
                newnode->Type = 5;
           
            newnode->left = op1;
            newnode->right = op2;
            push( &X, newnode );
        }
        if ( j == 0 )
            break;
        p--; j--;
    }
    *T = pop(&X);
}
 
 
void Nhapgiatri( ExpNode *(&T) )
{
    if ( ( T->left == NULL ) && ( T->right == NULL ) )
    {   if ( ( T->Symbol[0] >= 'a' ) && ( T->Symbol[0] <= 'z' ) )
        {
            cout<<"\nNhap gia tri cho bien "<<T->Symbol[0]<<" :";
            cin>>T->value;
        }
    }
    else
    {
        Nhapgiatri(T->left);
        Nhapgiatri(T->right);
    }
}
 
 
float Tinh(ExpNode *T)
{
    switch(T->Type)
    {
    case 0: {
                return T->value;
            }
    case 1: return Tinh(T->left)+Tinh(T->right); break;
    case 2: return Tinh(T->left)-Tinh(T->right); break;
    case 3: return Tinh(T->left)*Tinh(T->right); break;
    case 4: return Tinh(T->left)/Tinh(T->right); break;
    case 5: return pow(Tinh(T->left),Tinh(T->right)); break;
    case 6: return -Tinh(T->right); break;
 
    }
    return 0;
}
 
int uT( char c ){ 
	if( c == '(') return 0;
	if( c == '+' || c == '-' ) return 1;
	if( c == '*' || c == '/' || c == '%' ) return 2;
	if( c == '^' ) return 3;
}
void hauTo(string b){ 
	stack<char> s;
	string str, str1 = "";
	int i = 0;
	str = b;
	while( i < str.length() ){
		char c = str.at(i);
		if( c != ' ' ){
			if( c - '0' >= 0 && c - '0' <= 9 || isalpha(c) ) str1 += c;
			else{
				cout<< str1 << " ";
				str1 = "";
				if( c == '(') s.push(c);
				else{
					if( c == ')') {
						while( s.top()!= '('){
							cout<< s.top();
							s.pop();
						}
						if(s.top() == '(' ) s.pop();
					}
					else{
						while( !s.empty() && uT(c) <= uT(s.top())){
							cout<< s.top();
							s.pop();
						}
						s.push(c);
					}
				}
			}
		}
		i++;
	}
	if( str1 != "" ) cout<< str1 << " ";
	while(!s.empty()){
		if(s.top()!= '(') cout<< s.top();
		s.pop();
	}
}

