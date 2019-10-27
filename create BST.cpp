#include<stdio.h>
 typedef struct BST
 {
 	int data;
 	struct BST* left;
 	struct BST* right;
 }node;
  
 node* getnode()
 {
 	node* ptr = new node();
 	printf("enter data\n");
 	scanf("%d",&ptr->data);
 	ptr->left = NULL;
 	ptr->right= NULL;
 	return ptr;
 }
 
 void inorder_display(node* root)
 {
 	if(root == NULL)
 	  return;
    inorder_display(root->left);
    printf("%d\n", root->data);
    inorder_display(root->right); 
 }
 
 void preorder_display(node* root)
 {
 	if(root == NULL)
 	  return;
 	printf("%d\n", root->data);  
 	preorder_display(root->left);
	preorder_display(root->right); 
 }
 
 void postorder_display(node* root)
 {
 	if(root == NULL)
 	  return;
    postorder_display(root->left);
    postorder_display(root->right);
    printf("%d\n", root->data);
 }
 
 main()
 {
  	node *temp1, *temp2, *root;
  	int i, n;
  	printf("enter no of nodes\n");
  	scanf("%d", &n);
  	root = getnode();
	for(i = 1; i<n; i++)
	{
		temp1 = root;
		temp2 = getnode();
		while(1)
		{
			if(temp2->data <= temp1->data)
			{
				if(temp1->left== NULL)
				{
					temp1->left = temp2;
					break; 
				}
				else
				  temp1 = temp1->left;
			}
			else
			{
				if(temp1->right== NULL)
				{
					temp1->right = temp2;
					break; 
				}
				else
				  temp1 = temp1->right;
			}
		}
	}
	printf("inorder display\n");	
	inorder_display(root);
	printf("preorder display\n");
	preorder_display(root);
	printf("postorder display\n");
	postorder_display(root);
 }
