#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left,*right;
};
typedef struct node node;
node *creat(int data)
{
	node *n=(node *)malloc(sizeof(node));
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	return n;
}
void preorder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}
void inorder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}
void postorder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	
	postorder(root->left);
	printf("%d ",root->data);
	postorder(root->right);
}
int isbst(node *root)
{ static node * prev=NULL;
	 
	if(root!=NULL)
	{
       if(!isbst(root->left))
       {
       	return 0;
       }
       if(prev!=NULL && root->data<=prev->data)
       {
       	return 0;
       }
       prev=root;
       return isbst(root->right);
	}
	else
	{
		return 1;
	}
}
node *search(node *root,int key)
{
	if(root==NULL)
	{
		return NULL;
	}
	if(root->data==key)
	{
		return root;
	}
	if(root->data>key)
	{
	    return search(root->left,key);
	}
	if(root->data<key)
	{
		return search(root->right,key);
	}
}
node *searchitr(node *root,int key)
{
	while(root!=NULL)
	{
		if(key==root->data)
		{
			return root;
		}
		else if(key<root->data)
		{
			root=root->left;
		}
		else
		{
			root=root->right;
		}
	}
	return NULL;
}
void insertbst(node *root,int key)
{
   node *prev=NULL;
   while(root!=NULL){
      prev=root;
   if(key==root->data)
   {
      printf("cannot insert.\n");
      return;
   }
   else if(key<root->data)
   {
      root=root->left;
   }
   else
   {
      root=root->right;
   }
}
node *nn=creat(key);
if(key<prev->data)
{
   prev->left=nn;
}
else
{
   prev->right=nn;
}

}

 int main(int argc, char const *argv[])

{
	//node *prev=NULL;
	node *p=creat(5);
	node *p1=creat(3);
	node *p2=creat(6);
	node *p3=creat(1);
	node *p4=creat(4);
	p->left=p1;
	p->right=p2;
	p1->left=p3;
	p1->right=p4;
	printf("pre order is :");
	preorder(p);
	printf("inorder is :");
	inorder(p);
	printf("postorder is :");
	postorder(p);
	printf("\n");
	//printf("%d",isbst(p));
	//node *s=search(p,2);
	node *i= searchitr(p,10);
	if(i!=NULL){
	printf("found %d ",i->data);}
	else
	{
		printf("\n not found");
	}
	return 0;
}