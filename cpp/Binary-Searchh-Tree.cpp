#include<iostream>
#include<iomanip>
using namespace std;

struct node
{
    int data;
    struct node*left;
    struct node*right;
};


struct node* insert(struct node*root,int data)
{
    if(root==NULL)
    {
        struct node*ptr = (struct node*)malloc(sizeof(struct node));
        ptr->data=data;
        ptr->left=NULL;
        ptr->right=NULL;
        return ptr;
    }
    else
    {
        struct node*p = root;
        if(p->data<data)
        {
            p->right = insert(p->right,data);
        }
        else
        {
            p->left = insert(p->left,data);
        }
    }
    return root;
}

struct node* search(struct node*root,int data)
{
    if(root==NULL)
    {
        return NULL;
    }
    else
    {
        if(data>root->data)
        {
            search(root->right,data);
        }
        else if(data<root->data)
        {
            search(root->left,data);
        }
        else
        {
            return root;
        }
    }
}

int arr[100];int i=0;
void Inorder(struct node*root)
{
    if(root!=NULL)
    {
        Inorder(root->left);
        arr[i] = root->data;i++;
        Inorder(root->right);
    }
}

struct node*p=NULL;
struct node *deleteBST(struct node *root, int data)
{
    if (data > root->data)
    {
        p=root;
        deleteBST(root->right, data);
    }
    else if (data < root->data)
    {
        p=root;
        deleteBST(root->left, data);
    }
    else if (data == root->data)
    {
        if(root->left==NULL && root->right==NULL)
        {
            if(root->data<=p->data)
            {
                p->left=NULL;
            }
            else p->right=NULL;
            free(root);
        }
        else if((root->left==NULL&&root->right!=NULL)||(root->right==NULL&&root->left!=NULL))
        {
            if(root->data<p->data)
            {
                if(root->right==NULL)
                {
                    p->left = root->left;
                }
                else if(root->left==NULL)
                {
                    p->left = root->right;
                }
            }
            else
            {
                if(root->right==NULL)
                {
                    p->right = root->left;
                }
                else if(root->left==NULL)
                {
                    p->right = root->right;
                }
            }
            free(root);
        }
        else if(root->left&&root->right)
        {
            struct node*p1,*p2,*p3,*p4;
            Inorder(root->left);
            int pp = arr[i-1];
            int j=i;
            p2 = search(root,pp);
            root->data=p2->data;
            p=root;
            deleteBST(root->left,p2->data);
        }
    }
    return root;
}

void inorder(struct node*root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main()
{
    struct node*root = NULL;
    root = insert(root,5);
    root = insert(root,4);
    root = insert(root,6);
    inorder(root);
    cout<<endl;

    struct node*p1 = search(root,4);
    if(p1!=NULL) cout<<"Node Found"<<endl;
    else cout<<"Node not found"<<endl;
    
    root = deleteBST(root,6);
    inorder(root);
    return 0;
}
