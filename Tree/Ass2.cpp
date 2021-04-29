#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef struct Node
{
    int data;
    Node* left;
    Node* right;
} node_t;
 
void Free( node_t* root )
{
    if ( root == NULL )
        return;
 
    Free( root->left );
    Free( root->right );
    free( root );
}
 
int LeftOf( const int value, const node_t* root )
{
    return value < root->data;
}
 
int RightOf( const int value, const node_t* root )
{
    return value > root->data;
}
 
node_t* Insert( node_t* root, const int value )
{
    if ( root == NULL )
    {
        node_t* node = (node_t*)malloc( sizeof( node_t ) );
        node->left = NULL;
        node->right = NULL;
        node->data = value;
        return node;
    }
    if ( LeftOf( value, root ) )
        root->left = Insert( root->left, value );
    else if ( RightOf( value, root ) )
        root->right = Insert( root->right, value );
    return root;
}

void PreOrder(node_t* root){
    if(root != NULL)
    {
        printf("%d ", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
 
void InOrder(node_t* root){
    if(root != NULL)
    {
        InOrder(root->left);
        printf("%d ", root->data);
        InOrder(root->right);
    }
}
 
void PostOrder(node_t* root){
    if(root != NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ", root->data);
    }
}

int DEMLA(node_t* T)
{   if(T==NULL) return 0;
    else
       if(T->left==NULL && T->right==NULL) return 1;
       else return DEMLA(T->left)+DEMLA(T->right);
}
int Max(int a,int b)
{
    if(a>=b)
        return (a);
    else
        return (b);
}
//-----------------------------------------------------
//Ham tinh chieu cao cua cay
int chieuCao(node_t* pTree)
{
    if((pTree==NULL)||(pTree->left==NULL&&pTree->right==NULL))//Neu Cay Rong Hoac Chi Co 1 Goc Thi Khong Co Nut La
        return 1;
    else
        return (1+Max(chieuCao(pTree->left),chieuCao(pTree->right)));
}


}
