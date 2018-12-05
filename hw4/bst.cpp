#include <iostream>
#include <cstdlib>
using namespace std;
struct node
	{
	public:
		node* left;
		node* right;
		node* parent;
		int key;
		string data;
	};
class BinarySearchTree
{
//private:
	

public:
	node* root;
	BinarySearchTree()
	{
		root = NULL;
	}
	bool isEmpty() const { return root == NULL; }
	void INORDER_TREE_WALK(node*);
	void TREE_INSERT(int );
	void PREORDER_TREE_WALK(node*);
	void POSTORDER_TREE_WALK(node*);
	int TREE_MAXIMUM(node*);
	int TREE_MINIMUM(node*);
	int TREE_SUCCESSOR(node*);
	void DELETE(int);
	void find(int, node**, node**);
	void REMOVE_MAX();
};

void BinarySearchTree::TREE_INSERT(int d)
{
	// This implements the algorithm in page 261 of the textbook
	node* z = new node();
	
	z->key = d;
	z->left = NULL;
	z->right = NULL;

	node* y = NULL;
	node* x = root;
	node* parent = NULL;

	while (x != NULL)
	{
		y = x;
		if (z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}

	parent = y;
	if (y == NULL)
		root = z;
	else if (z->key < y->key)
		y->left = z;
	else
		y->right = z;
	}

	

void BinarySearchTree::PREORDER_TREE_WALK(node* x)
{
  if (x!=NULL)
  {
  	cout<< " " << x->key << " ";
  	if (x->left) PREORDER_TREE_WALK(x->left);
  	if (x->right)PREORDER_TREE_WALK(x->right);
  }

}

void BinarySearchTree::POSTORDER_TREE_WALK(node* x)
{
	if (x!=NULL)
	{	if (x->left) POSTORDER_TREE_WALK(x->left);
		if (x->right) POSTORDER_TREE_WALK(x->right);
        cout << " " << x->key << " ";
    }
}

void BinarySearchTree::INORDER_TREE_WALK(node* x)
{
	if (x != NULL)
	{
		if (x->left) INORDER_TREE_WALK(x->left);
		cout << " " << x->key << " ";
		if (x->right) INORDER_TREE_WALK(x->right);
	}
	

}

int BinarySearchTree::TREE_MAXIMUM(node* x)
{   if (x==NULL)
	{
		cout<<"Tree is empty"<<endl;
	}
	
	while (x->right!=NULL) 
		{ x=x->right;
		}

		return x->key;
}


int BinarySearchTree::TREE_MINIMUM(node* x)
{	
	 if (x==NULL)
	{
		cout<<"Tree is empty"<<endl;
	}
	
	while (x->left!=NULL) 
		{ x=x->left;
		}

		return x->key;
}
int BinarySearchTree::TREE_SUCCESSOR(node* x)
{	
	node* parent=x;
	node* y;
	if (x->right!=NULL)
	{
		return TREE_MINIMUM(x->right);
	}
	
	
	else
	{y=x->parent;
	while (y!=NULL and x==y->right)
		{
			x=y;
			y=y->parent;
		}
	
	return y->key;
    }
}
void BinarySearchTree::find(int d, node **parent, node **y)
{
    node *ptr, *ptrs;
  if (root == NULL)
    {
        *y = NULL;
        *parent = NULL;
        return;
    }
    if (d == root->key)
    {
        *y = root;
        *parent = NULL;
        return;
    }
    if (d < root->key)
        ptr = root->left;
    else
        ptr = root->right;
    ptrs = root;
    while (ptr != NULL)
    {
        if (d == ptr->key)
        {
            *y = ptr;
            *parent = ptrs;
            return;
        }
        ptrs = ptr;
        if (d < ptr->key)
            ptr = ptr->left;
	else
	    ptr = ptr->right;
    }
    *y = NULL;
    *parent = ptrs;

}
void BinarySearchTree::DELETE(int val)
{
node* p;
node* x;
if (root == NULL)
{
cout<<"Empty Tree"<<endl;
return;
}
find(val, &p, &x);
if (x == NULL)
{
cout<<"Node not found"<<endl;
return;
}
//case 1
if (x->left == NULL && x->right == NULL)
{
	node* parent=p;
	node* y=x;
	if (parent==NULL)
	{
		root=NULL;
	}
	else
	{
		if (y==parent->left)
			parent->left=NULL;
		else
			parent->right=NULL;
	}
}
//case 2
if (x->left == NULL && x->right != NULL)
{
	node* parent=p;
	node* y=x;
	node* c;
	if (y->left!=NULL)
		c=y->left;
	else
		c=y->right;
	if(parent==NULL)
	{
		root=c;
	}
	else
	{
		if(y==parent->left)
			parent->left=c;
		else
			parent->right=c;
	}
}
//case 3
if (x->left != NULL && x->right != NULL)
{
	node* parent=p;
	node* y=x;
	node* ptr;
	node* ptrs;
	node* s;
	node* pars;
	ptrs=y;
	ptr=y->right;
	while(ptr->left!=NULL)
	{
		ptrs=ptr;
		ptr=ptr->left;
	}
	s=ptr;
	pars=ptrs;

	//call case 1
if (s->left == NULL && s->right == NULL)
{
	node* parent=pars;
	node* y=s;
	if (parent==NULL)
	{
		root=NULL;
	}
	else
	{
		if (y==parent->left)
			parent->left=NULL;
		else
			parent->right=NULL;
	}
}
else
//call case 2
{
	node* parent=pars;
	node* y=s;
	node* c;
	if (y->left!=NULL)
		c=y->left;
	else
		c=y->right;
	if(parent==NULL)
	{
		root=c;
	}
	else
	{
		if(y==parent->left)
			parent->left=c;
		else
			parent->right=c;
	}

}
if (parent == NULL)
    {
        root = s;
    }
    else
    {
        if (y == parent->left)
            parent->left = s;
        else
            parent->right = s;
    }
    s->left = y->left;
    s->right = y->right;
}
free(x);
}

void BinarySearchTree::REMOVE_MAX()
{
	int max=TREE_MAXIMUM(root);
	DELETE(max);
}

int main()
{
	BinarySearchTree bst;
	int choice, key;
	int *val;
	while (true)
	{
		cout << endl << endl;
		cout << " Binary Search Tree Example " << endl;
		cout << " ----------------------------- " << endl;
		cout << " 1. Insert a Node " << endl;
		cout << " 2. Pre-Order Traversal " << endl;
		cout << " 3. Post-Order Traversal "<<endl;
		cout << " 4. In-Order Traversal "<<endl;
		cout << " 5. Find Max "<<endl;
		cout << " 6. Remove Max "<<endl;
		cout << " 7. Successor "<<endl;
		cout << " 8. Delete a Node "<<endl;
		cout << " 9. Exit " << endl;
		cout << " Enter your choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1: cout << " Enter key (int value) to be inserted : ";
			cin >> key;
			bst.TREE_INSERT(key);
			break;
		case 2: cout << endl;
		    cout << " Pre-Order Traversal "<< endl;
		    cout << "-------------------" << endl;
		    bst.PREORDER_TREE_WALK(bst.root);
		    break;
		case 3: cout << endl;
		    cout << " Post-Order Traversal "<< endl;
		    cout << "-------------------" << endl;
		    bst.POSTORDER_TREE_WALK(bst.root);
		    break;
		case 4: cout << endl;
			cout << " In-Order Traversal " << endl;
			cout << " -------------------" << endl;
			bst.INORDER_TREE_WALK(bst.root);
			break;
		case 5: cout << endl;
		    cout << " Find Max "<< endl;
		    cout << "-------------------" << endl;
		    cout << bst.TREE_MAXIMUM(bst.root);
		    break;
		case 6: cout << endl;
		    cout << " Max number deleted "<< endl;
		    bst.REMOVE_MAX();
		    break;
		case 7: cout << endl;
			if (bst.root==NULL)
			{
				cout<<"Tree is empty"<<endl;
				break;
			}
			else{
				int value;
				node* p;
				node* x;
			cout << "Successor of Root"<< endl;
		    cout << "-------------------" << endl;
		 	cout<< bst.TREE_SUCCESSOR(bst.root);
		    break;
		case 8: cout << endl;
			if(bst.root==NULL)
			{
				cout<<"Tree is empty"<<endl;
				break;
			}
			else
			{	int num;
				cout<<"Enter the node to be deleted"<<endl;
				cin>>num;
				cout << " Node Deleted "<< endl;
				bst.DELETE(num);
			}
			break; 
		case 9: system("pause");
			return 0;
			break;
		default:
			cout << "Invalid choice";
		}
	}
}}