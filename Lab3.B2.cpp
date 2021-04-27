#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20
 
struct stack{
  char character[MAX];
  int top;
};
 
typedef struct stack stack;
 
void Init(stack *a){
  a->top=0;
}
 
void Push(stack *a,int value){
  if(a->top>=MAX){
    printf("ko the them \n");
    exit(1);
  }
  else{
    a->top++;
    a->character[a->top]=value;
  }
}
 
int Pop(stack *a){
  if(a->top<=0){
    printf("ko dc\n");
    exit(1);
  }
  else{
    int temp=a->character[a->top];
    a->top--;
    return temp;
  }
}
 
int check(stack *a,char *str){
  int i;
  int count=0;
  for(i=0;i<strlen(str);i++){  
    if((str[i]=='(')||(str[i]=='{')||(str[i]=='['))
      Push(a,str[i]);
    else if(str[i]==')'){
      if(a->top!=0){        
    if(Pop(a)!='(')  
      return 0;
      }
      else
    Push(a,str[i]);
    }
    else if(str[i]=='}'){
      if(a->top!=0){
    if(Pop(a)!='{')
      return 0;
      }
      else
    Push(a,str[i]);
    }
  else if(str[i]==']'){
    if(a->top!=0){
      if(Pop(a)!='[')
    return 0;
    }
    else
      Push(a,str[i]);
  }
  else if(str[i]=='"'){
    count++;   
    if(count%2!=0){    
      Push(a,str[i]);  
    }
    else{
      if(Pop(a)!='"')
    return 0;
    }
  }
  }
  if(a->top==0)
    return 1;
  else
    return 0;
}
 
int main(){
  stack a;
  Init(&a);
  char str1[20];
  printf("Nhap:");
  fgets(str1,20,stdin);
  if(check(&a,str1))
    printf("Dung\n");
  else
    printf("Sai\n");
}
