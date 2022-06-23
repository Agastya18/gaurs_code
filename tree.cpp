//#include<iostream>
//using namespace std;
#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;cout<<
   struct node *left;
   struct node *right;
};

typedef struct node node;
node* creat(int data)
{
    node *n=(node*)malloc(sizeof(node));
n->left=NULL;
n->right=NULL;
n->data=data;
//cout<<n->data<<endl;
return n;
}
void preorder(node *root)
{ 
   if(root==NULL)
   {
      return ;
   }
   
  
   preorder(root->left);
   printf("%d ",root->data );
   preorder(root->right);
    
}

 int main()
{
 

 node *p=creat(4);
  node *p1=creat(1);
   node *p2=creat(6);
   node *p3=creat(5);
   node *p4=creat(2);
   p->left=p1;
   p->right=p2;
   p1->left=p3;
   p1->right=p4;
   preorder(p);


}