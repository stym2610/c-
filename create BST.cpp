#include<stdio.h>
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
typedef struct BST_node
 {
 	int data;
 	struct BST_node* left;
 	struct BST_node* right;
 }BST_node;
 
class TREE
{
	public:
	BST_node* root;
	    
	BST_node* getBST_node()
 {
 	BST_node* ptr = new BST_node();
 	printf("enter data\n");
 	scanf("%d",&ptr->data);
 	ptr->left = NULL;
 	ptr->right= NULL;
 	return ptr;
 }
 
 void create_tree()
 {
 	BST_node *temp1, *temp2;
  	int i, n;
  	printf("enter no of BST_nodes\n");
  	scanf("%d", &n);
  	root = getBST_node();
	for(i = 1; i<n; i++)
	{
		temp1 = root;
		temp2 = getBST_node();
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
 }
 
 Node* insert(Node* root, int x)
{
    if(root == NULL) return new Node(x);
    if(root->data > x) root->left = insert(root->left,x);
    else root->right = insert(root->right, x);
    return root;
}
Node* constructBst(int arr[], int n)
{
    Node* root = NULL;
    for(int i=0; i<n; i++)root = insert(root ,arr[i]);
    return root;
}
 
 void inorder_display(BST_node* root)
 {
 	if(root == NULL)
 	  return;
    inorder_display(root->left);
    printf("%d\n", root->data);
    inorder_display(root->right); 
 }
 
 void inorder_without_recursion(BST_node* root)
 {
 	stack <BST_node*> s;
 	BST_node* current = root;
 	while(1)
 	{
 		while(current!=NULL)
 		{
 			s.push(current);
 			current = current->left;
		 }	
 		if(current == NULL && !s.empty())	
 		{
 			current = s.top();
 			printf("%d\n", current->data);
 			s.pop();
 			current = current->right;
		 }
		 if(current == NULL && s.empty())
		 	break;
	 }
 }
 
 void preorder_display(BST_node* root)
 {
 	if(root == NULL)
 	  return;
 	printf("%d\n", root->data);  
 	preorder_display(root->left);
	preorder_display(root->right); 
 }
 
 void preorder_without_recursion(BST_node* root)
 {
 	if(root == NULL)return;
 	stack <BST_node*> s;
 	BST_node* current = root;
 	s.push(current);
 	while(!s.empty())
 	{
 		current = s.top();
 		printf("%d\n", current->data);
 		s.pop();
 		if(current->right!=NULL)
 			s.push(current->right);
		if(current->left!=NULL)
			s.push(current->left);
	 }	
 }
 
 void postorder_display(BST_node* root)
 {
 	if(root == NULL)
 	  return;
    postorder_display(root->left);
    postorder_display(root->right);
    printf("%d\n", root->data);
 }
 
 void postorder_without_recursion(BST_node*)
 {
 	if(root == NULL) return;
 	stack <BST_node*> s1;
 	stack <BST_node*> s2;
 	BST_node* current = root;
 	s1.push(current);
 	while(!s1.empty())
 	{
 		current = s1.top();
 		s2.push(current);
 		s1.pop();
 		if(current->left!=NULL)
 			s1.push(current->left);
 		if(current->right!=NULL)
 			s1.push(current->right);
	 }
	 while(!s2.empty())
	 {
	 	printf("%d\n", s2.top()->data);
	 	s2.pop();
	 }	
 }
 
 int count(BST_node *root)
 {
 	if(root == NULL)
 	  return 0;
 	return (1 + count(root->left) + count(root->right));	  
 }
 
 int sum(BST_node* root)
 {
 	if(root == NULL)
 	  return 0;
    return (root->data + sum(root->left) + sum(root->right)); 
 }
 
bool search(Node* root, int x)
{
    if(root == NULL)
     return 0;
    if(root->data == x)
     return 1;
    else if(root->data < x)
        search(root->right, x);
    else
        search(root->left, x);    
}

bool isPairPresent(struct node *root, int target)
{
    stack <node*> s1;
    node* c1 = root;
    int x;
    bool result = false;
    while(true)
    {
        while(c1 != NULL)
        {
            s1.push(c1);
            c1 = c1->left;
        }
        if(c1 == NULL && !s1.empty())
        {
            c1 = s1.top();
            x = target - c1->val;
            if(x != c1->val) result = search(root, x);
            if(result) break;
            s1.pop();
            c1 = c1->right;
        }
        if(c1 == NULL && s1.empty()) break;
    }
    return result;
}

void convert(Node* root1, int a[], int* top)
{
    if(root1 == NULL) return;
    convert(root1->left, a, top);
    a[*top] = root1->data;
    (*top)++;
    convert(root1->right, a,top);
}

void merge(Node *root1, Node *root2)
{
   int a[100], top = 0, temp;
   convert(root1, a, &top);
   convert(root2, a, &top);
   for(int i = 0; i<top; i++)
   {
       for(int j = 0;j<top - i; j++)
       {
           if(a[j] > a[j+1])
           {
              temp = a[j];
              a[j] = a[j+1];
              a[j+1] = temp;
           }
       }
   }
   
  for(int i=0; i<top; i++) cout<<a[i]<<" ";
}

void merge(Node *root1, Node *root2)
{
    if(root1 == NULL &&  root2 == NULL) return;
    if(root1 == NULL)
    {
        inorder(root2);
        return;
    }
    if(root2 == NULL)
    {
        inorder(root1);
        return;
    }
   Node *c1=root1, *c2=root2;
   stack <Node*>  s1, s2;
   while(true)
   {
       while(c1 != NULL)
       {
           s1.push(c1);
           c1 = c1->left;
       }
       while(c2 != NULL)
       {
           s2.push(c2);
           c2 = c2->left;
       }
       if(s1.empty() || s2.empty()) 
          break;
       else
       {
           if(s1.top()->data < s2.top()->data)
           {
               cout<<s1.top()->data<<" ";
               c1 = s1.top()->right;
               s1.pop();
           }
           else
           {
               cout<<s2.top()->data<<" ";
               c2 = s2.top()->right;
               s2.pop();
           }
       }
   }
   if(s1.empty())
   {
       while(true)
       {
           while(c2!=NULL)
            {
                s2.push(c2);
                c2 = c2->left;
             }
             if(s2.empty())
               break;
             else
            {
               cout<<s2.top()->data<<" ";
               c2 = s2.top()->right;
               s2.pop();
            }
       }
       
   }
   if(s2.empty())
   {
       while(true)
       {
           while(c1 != NULL)
            {
                s1.push(c1);
                c1 = c1->left;
            }
            if(s1.empty()) 
             break;
             else
            {
                cout<<s1.top()->data<<" ";
                c1 = s1.top()->right;
                s1.pop();
             }
       }
   }
}
 
Node* LCA(Node *root, int n1, int n2)
{
   
   if(root == NULL) return NULL;
   if((root->data > n1 && root->data < n2) || (root->data < n1 && root->data > n2) || root->data == n1 || root->data == n2)
    return root;
    else if(root->data >n1 && root->data > n2) LCA(root->left, n1, n2);
    else LCA(root->right, n1, n2);
}

int minDiff(Node *root, int k)
{
    int a[201], top = 0, min;
    convert(root, a,&top);
    if(k>a[0]) min = k - a[0];
    else min = a[0] - k;
    for(int i = 1; i<top; i++)
    {
        if(k == a[i]) 
        {
            min = 0;
            break;
        }
        else if(k>a[i])
        {
            if((k - a[i]) < min) min = k - a[i];
        }
        else
        {
            if((a[i] - k) < min) min = a[i] - k;
        }
    }
    return min;
}

bool isIdentical(Node *r1, Node *r2)
{   
    if(r1 == NULL && r2 == NULL) return true;
    if((r1 && !r2) || (!r1 && r2)) return false;
    return (r1->data == r2->data) && isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
}

int countPairs(Node* root1, Node* root2, int x)
{
    int top1 = 0, top2 = 0;
    int n1 = count(root1);
    int n2 = count(root2);
    int* a1 = new int[n1];
    int* a2 = new int[n2];
    convert(root1, a1, &top1);
    convert(root2, a2, &top2);
    int count = 0;
    for(int i = 0; i<n1; i++)
    {
        for(int j = 0; j<n2;  j++)
        {
            if((a1[i] + a2[j]) == x)
            count++;
        }
    }
    return count;
}
 
 int height(BST_node* root)
 {
 	if(root == NULL)
 	  return 0;
 	else
 	{
		if(height(root->left) > height(root->right))
		  return 1 + height(root->left); 	
		else
		  return 1+ height(root->right);  
    }  
 }
 void level_traversal()
 {
 	if(root == NULL)
 	{
 		printf("tree is emptyy\n");
	 	return;	
    }
    BST_node* x;
    queue <BST_node*> q;
    q.push(root);
    while(!q.empty())
    {
	    	x = q.front();
    		printf("%d ", x->data);
    		q.pop();
	    cout<<endl;
    	if(x->left!=NULL)
    	  q.push(x->left);
    	if(x->right!=NULL)
		  q.push(x->right);  
    }	 	
 }
};
 
 main()
 {
 	cout<<"hello";
 	TREE T;
  	T.create_tree();
	printf("inorder display\n");	
	T.inorder_display(T.root);
	printf("inorder display\n");
	T.inorder_without_recursion(T.root);
	printf("preorder display\n");
	T.preorder_display(T.root);
	printf("preorder display\n");
	T.preorder_without_recursion(T.root);
	printf("postorder display\n");
	T.postorder_display(T.root);
	printf("postorder display\n");
	T.postorder_without_recursion(T.root);
	printf("level order display\n");
	T.level_traversal();
	printf("\ntotal BST_nodes : %d\n", T.count(T.root));
	printf("sum of BST_nodes is: %d\n", T.sum(T.root));
	printf("Height of tree is: %d\n", T.height(T.root));
 }
