#include<bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	Node *left;
	Node *right;
	int height;
};
Node* newnode (int key)
{
	Node* node;
	node = (Node*)malloc(sizeof(Node));
	node->left = NULL;
	node->right = NULL;
	node->val = key;
	node->height = 1;
	return node;
}
int height (Node *root)
{
	if ( root == NULL)
	{
		return 0;
	}
	else return root->height;
}
Node* rotateright(Node *node)
{
	Node *temp = node->left;
	Node *temp1 = temp->right;
	temp->right = node;
	node->left = temp1;
	node->height = 1 + max(height(node->left),height(node->right));
	temp->height = 1 + max(height(temp->left),height(temp->right));
	return temp;
}
Node* rotateleft(Node *node)
{
	Node *temp = node->right;
	Node *temp1 = temp->left;
	temp->left = node;
	node->right = temp1;
	node->height = 1 + max(height(node->left),height(node->right));
	temp->height = 1 + max(height(temp->left),height(temp->right));
	return temp;
}
Node* insert (int key,Node* root)
{
	if ( root == NULL)
	{
		return newnode(key);
	}
	if ( root->val > key)
	{
		root->left = insert(key,root->left);
	}
	else if ( root->val < key)
	{
		root->right = insert(key,root->right);
	}
	else return root;
	  
	root->height = 1 + max(height(root->left),height(root->right));
	int heightdifference = height(root->left) - height(root->right);
	
	if ( heightdifference > 1 && key < root->left->val)
	{
		return rotateright(root);
	}
	if ( heightdifference > 1 && key > root->left->val)
	{
		root->left = rotateleft(root->left);
		return rotateright(root);
	}
	if ( heightdifference < -1 && key > root->right->val)
	{
		return rotateleft(root);
	}	
	if ( heightdifference < -1 && key < root->right->val)
	{
		root->right = rotateright(root->right);
		return rotateleft(root);
	}
	return root;
}
int balance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
struct Node* minnode (Node *root)
{
	Node *cur = root;
	while ( cur->left != NULL)
	{
		cur = cur->left;
	}
	return cur;
} 
Node* deleteNode(Node *root,int key)
{
	if ( root == NULL)
	{
		return NULL;
	}
	if ( root->val > key)
	{
		root->left = deleteNode(root->left,key);
	}
	else if ( root->val < key)
	{
		root->right = deleteNode(root->right,key);
	}
	else
	{
		if ( root->left == NULL && root->right == NULL)
		{
			Node *temp = root;
			root = NULL;
			free(temp);
		}
		else if ( root->left == NULL && root->right != NULL )
		{
			*root = *root->right;
		}
		else if ( root->left != NULL && root->right == NULL)
		{
			*root = *root->left;
		}
		else
		{
			Node *min_node = minnode(root->right);
			root->val = min_node->val;
			root->right = deleteNode(root->right,root->val);
		}
	}
	if ( root == NULL)
	{
		return root;
	}
	root->height = 1 + max(height(root->left),height(root->right));
	int heightdifference = balance (root);
	int hdl = balance(root->left);
	int hdr = balance(root->right);
	if ( heightdifference > 1 &&  hdl >= 0	)
	{
		return rotateright(root);
	}
	if ( heightdifference > 1 && hdl < 0)
	{
		root->left = rotateleft(root->left);
		return rotateright(root);
	}
	if ( heightdifference < -1 && hdr >= 0)
	{
		return rotateleft(root);
	}	
	if ( heightdifference < -1 && hdr < 0)
	{
		root->right = rotateright(root->right);
		return rotateleft(root);
	}
	return root;
}
void inorder(Node *root)
{
	if ( root == NULL)
	{
		return ;
	}
	cout<<root->val<<" ";
	inorder(root->left);
	inorder(root->right);
}
int main()
{
	int n;
	cin>>n;
	struct Node *root = NULL;;
	for ( int i = 0 ; i < n ; i++)
	{
		int j;
		cin>>j;
		root = insert(j,root);
	}
	inorder(root);
	root = deleteNode(root,20);
	inorder(root);
	return 0;
}

