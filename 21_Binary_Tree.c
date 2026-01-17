#include<stdio.h>
#include<stdlib.h>

typedef struct Tree
{
	int data;
	struct Tree *left,*right;
}tree;

tree* create_node(int v);
tree* insert(tree* root, int v);
tree* search(tree* root, int v);
void inorder(tree* root);
void preorder(tree* root);
void postorder(tree* root);
tree* getsuccessor(tree *cur);
tree* del(tree* root,int x);

void main()
{
	tree *root = NULL,*temp;
	int ch,v;
	do
	{
		printf("\n*--MENU--*\n");
		printf("1.Insert\n");
		printf("2.Search\n");
		printf("3.Inorder display\n");
		printf("4.Preorder display\n");
		printf("5.Postorder display\n");
		printf("6.Delete\n");
		printf("7.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the value:");
				scanf("%d",&v);
				root = insert(root,v);
				break;
			case 2:
				printf("Enter the value:");
				scanf("%d", &v);
				temp = search(root,v);
				if(temp)
					printf("Value Found");
				else
					printf("Value not Found");
				break;
			case 3:
				inorder(root);
				break;
			case 4:
				preorder(root);
				break;
			case 5:
				postorder(root);
				break;
			case 6:
				printf("Enter the value to delete:");
				scanf("%d",&v);
				root = del(root,v);
				break;
			case 7:
				exit(0);
			default:
				printf("\nInvalid choice\n");
		}
	}while(1);	
}

tree* create_node(int v)
{
	tree* nn;
	nn = (tree*)malloc(sizeof(tree));
	nn->data = v;
	nn->left = nn->right = NULL;
	return nn;
}

tree* insert(tree *root, int v)
{
	if(root == NULL)
		return create_node(v);
	if(v < root->data)
		root->left = insert(root->left,v);
	else if(v > root->data)
		root->right = insert(root->right,v);
	else
		printf("Duplicate value");
	return root;
}

tree* search(tree* root, int v)
{
	while(root)
	{
		if(v == root->data)
			return root;
		else if(v < root->data)
			root = root->left;
		else if(v > root->data)
			root = root->right;
	}
	return NULL;
}
void inorder(tree *root)
{
	if(root == NULL)
		return;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}

void preorder(tree *root)
{
	if(root == NULL)
		return;
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}

void postorder(tree *root)
{
	if(root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
}

tree* getsuccessor(tree *cur)
{
	cur = cur->right;
	while(cur && cur->left)
		cur = cur->left;
	return cur;
}

tree* del(tree* root,int x)
{
	tree* temp, *succ;
	if(root == NULL)
	{
		printf("value does not exist");
		return root;
	}
	if(x < root->data)
		root->left = del(root->left,x);
	else if(x > root->data)
		root->right = del(root->right,x);

	else
	{
		if(root->left == NULL)
		{
			temp = root->right;
			free(root);
			return temp;
		}
		if(root->right == NULL)
		{
			temp = root->left;
			free(root);
			return temp;
		}
		succ = getsuccessor(root);
		root->data = succ->data;
		root->right = del(root->right,succ->data);
	}
	return root;
}