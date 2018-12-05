#include <iostream>
#include <cstdlib>
using namespace std;
class Bst
{
private:
	class flight
	{
	public:
		flight* left;
		flight* right;
		flight* parent;
		int landingTime;
		string planeInfo;
	};

public:
	flight* root;
	Bst()
	{
		root = NULL;
	}
	bool isEmpty() const { return root == NULL; }
	void INSERT(int,int);
	void compare(int,int);
	void find(int , flight**, flight**);
	void DELETE(int );
	int TREE_SUCCESSOR(flight*);
	int TREE_MINIMUM(flight* );


};

int Bst::TREE_MINIMUM(flight* x)
{	
	 if (x==NULL)
	{
		cout<<"Tree is empty"<<endl;
	}
	
	while (x->left!=NULL) 
		{ x=x->left;
		}

		return x->landingTime;
}
int Bst::TREE_SUCCESSOR(flight* x)
{	
	flight* parent=x;
	flight* y;
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
	
	return y->landingTime;
    }
}


void Bst::find(int d, flight **parent, flight **y)
{
    flight *ptr, *ptrs;
  if (root == NULL)
    {
        *y = NULL;
        *parent = NULL;
        return;
    }
    if (d == root->landingTime)
    {
        *y = root;
        *parent = NULL;
        return;
    }

    if (d < root->landingTime)
        ptr = root->left;
    else
        ptr = root->right;
    ptrs = root;
    while (ptr != NULL)
    {
        if (d == ptr->landingTime)
        {
            *y = ptr;
            *parent = ptrs;
            return;
        }
        ptrs = ptr;
        if (d < ptr->landingTime)
            ptr = ptr->left;
	else
	    ptr = ptr->right;
    }
    *y = NULL;
    *parent = ptrs;
}

void Bst::DELETE(int val)
{
flight* p;
flight* x;
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
	flight* parent=p;
	flight* y=x;
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
	flight* parent=p;
	flight* y=x;
	flight* c;
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
	flight* parent=p;
	flight* y=x;
	flight* ptr;
	flight* ptrs;
	flight* s;
	flight* pars;
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
	flight* parent=pars;
	flight* y=s;
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
	flight* parent=pars;
	flight* y=s;
	flight* c;
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

void Bst::compare(int d, int k)
{	

	flight* z = new flight();
	z->landingTime = d;

		z->left = NULL;
	    z->right = NULL;

	flight* y = NULL;
	flight* x = root;
	flight* parent = NULL;
	while (x != NULL)
	{
		y = x;
		if (z->landingTime < x->landingTime)
			x = x->left;
		else
			x = x->right;
	}

	parent = y;
	if (y == NULL)
		root = z;
	else if (z->landingTime < y->landingTime)
		y->left = z;
	else
		y->right = z;

	if(y->right==NULL)
	{
		if(y->landingTime - z->landingTime>k)
			{cout<<"Landing Request Granted"<<endl;}
		else
			{cout<<"Landing Request NOT Granted..enter another landing time"<<endl;
			DELETE(z->landingTime);
			}
	}

	else if(y->left==NULL)
	{
		if(z->landingTime - y->landingTime>k)
            {cout<<"Landing Request Granted"<<endl;
       		cout<<"Subtracted "<<z->landingTime<<" and "<<y->landingTime<<endl;}
        else
           	{cout<<"Landing Request NOT Granted..enter another landing time"<<endl;
           	DELETE(z->landingTime);
            }

	}
	else if(y->left!=NULL && y->right!=NULL)
	{
		if(z->landingTime-y->landingTime>k && z->landingTime - TREE_SUCCESSOR(root)>k)
		{
			cout<<"Landing Request Granted"<<endl;
		}
		else
		{
			cout<<"Landing Request NOT Granted..enter another landing time"<<endl;
           	DELETE(z->landingTime);

		}

	}
}



void Bst::INSERT(int d,int k)
{	
	flight* z = new flight();
	z->landingTime = d;
	if(z->landingTime>k)
	{
		z->left = NULL;
	    z->right = NULL;

	flight* y = NULL;
	flight* x = root;
	flight* parent = NULL;
	while (x != NULL)
	{
		y = x;
		if (z->landingTime < x->landingTime)
			x = x->left;
		else
			x = x->right;
	}

	parent = y;
	if (y == NULL)
		root = z;
	else if (z->landingTime < y->landingTime)
		y->left = z;
	else
		y->right = z;
		cout<<"Landing Request Granted"<<endl;
	}
	else
	{
		cout<<"Landing Request NOT Granted..enter another landing time"<<endl;
	}	

}


	int main ()
	{	Bst bst;
		int time;
		int constraint;
		
		cout<<"Enter the K value: "<<endl;
		cin>> constraint;
		const int K=constraint;
		char choice;
	while (true)
	{
		cout << endl << endl;
		cout <<"Enter Option "<<endl;
		cout <<"(r) Request landing "<<endl;
		cout <<"(w) Withdraw landing request "<<endl;
		cout <<"(l) List landing time "<<endl;
		cout <<"(q) Quit " <<endl;
		cout <<"Enter Your Choice: ";
		cin >> choice;
		cout <<endl << endl;

		switch (choice)
		{	
			case 'r':
			if(bst.root==NULL)
			{
			cout<<"Enter Landing Time: ";
			cin>>time;
			cout<<endl<<endl;
			bst.INSERT(time,K);
			}	
			else
			{	
				cout<<"Enter Landing Time again: ";
				cin>>time;
				cout<<endl<<endl;
				bst.compare(time,K);

			}
			break;
			case 'w': 
			int t;
			cout<<"Enter flight time to withdraw: ";
			cin>>t;
			cout<<endl;
			bst.DELETE(t);
			break;
			case 'l': 
			if (bst.root==NULL)
				{cout<<"No Flights Available"<<endl;}
			else{
			{
				cout<<"Flight time: ";
			}
		}
			break;
			case 'q': system("pause");
			return 0;
			break;
			default: cout<<"Invalid choice "<<endl;
		}
	}
}