#include<stdio.h>
#include<stdlib.h>

struct bstnode{
  
  int data;
  struct bstnode *left , *right;

};

struct bstnode *newnode(int key){

 struct bstnode *temp = (struct bstnode*)malloc(sizeof(struct bstnode));
 temp->data = key;
 temp->left = temp->right = NULL;
 
 return temp;
}

struct bstnode *insert(struct bstnode *obj , int val){

 if(obj == NULL)
   obj = newnode(val);
 else
   if(obj->data > val)
     obj->left = insert(obj->left , val);
   else
     obj->right = insert(obj->right , val);
 return obj;
}

void traverse(struct bstnode *root){
  if(root != NULL)
   {
   traverse(root->left);
   printf("%d " , root->data);
   traverse(root->right);
   }
}
           
int main()
{
  struct bstnode *root = NULL;
  
 int c;
 int data;
 while(1)
 {
  printf("Enter 1 to insert new node\n");
  printf("Enter 2 to print the tree\n");
  scanf("%d" , &c);
  switch (c)
  {
   
   case 1: 
    printf("Enter data: ");
    scanf("%d" , &data);
    root = insert(root , data);
    break;
    
   case 2:
    printf("Tree created: ");
    traverse(root);
    break;
    
   default:
    printf("Wrong input");
    break;
   };
 }
 
 return 0;
} 
  

 
 
 
 
