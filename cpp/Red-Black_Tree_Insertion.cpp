
#include <stdio.h>
#include <iostream>
using namespace std;
 
class Node{
    public:
    int n;
    bool isRed;
    Node* parent;
    Node* nodeL;
    Node* nodeR;
    Node(){
        isRed=true;
        n=-100;
        parent=NULL;
        nodeL=NULL;
        nodeR=NULL;
        
    }
  
    
    void insertNode(int x){
        if(this->n==-100){
            n=x;
            parent=NULL;
            isRed=false;
            // cout<<x<<endl;
            return;
        }
        Node* ptr=this;
        while(true){
            if(x>ptr->n){
                if(ptr->nodeR==NULL){
                    ptr->nodeR=new Node();
                    ptr->nodeR->n=x;
                    ptr->nodeR->parent=ptr;
                    ptr->nodeR->isRRViolated();
                    // if(this->isRed){
                    //     this.isRRViolated();
                    // }
                    return;
                }
                ptr=ptr->nodeR;
            }else if(x<ptr->n){
                
                if(ptr->nodeL==NULL){
                    ptr->nodeL=new Node();
                    ptr->nodeL->n=x;
                    ptr->nodeL->parent=ptr;
                    
                    ptr->nodeL->isRRViolated();
                    
                    // if(this->isRed){
                    //     this.isRRViolated();
                    // }
                    return;
                }
                
                ptr=ptr->nodeL;
            }
        }
    }
    


    
    void isRRViolated();
 

    
    void printNode(){
        if(this==NULL)
            return;
        cout<<(this->n)<<(this->isRed?" Red parent :":" Black parent :")<<((this->parent!=NULL)?(this->parent->n):-100)<<endl;
        this->nodeL->printNode();
        this->nodeR->printNode();
    }
    
};


  Node* root=new Node();
    
int main()
{
    int i,t;
    while(i){
        cout<<"1.Insert 2.Print Tree 0.exit"<<endl;
        cout<<"Enter a choice :";
        cin>>i;
        switch(i){
            case 1:
            cout<<"Enter a number :";
            cin>>t;
            root->insertNode(t);
            break;
            case 2:
            root->printNode();
            break;
        }
     
        
    }
    
    return 0;
}

void Node::isRRViolated(){
        if(this->parent==NULL && this->isRed){
            this->isRed=false;
            return;
        }
        if(this->parent==NULL){
            return;
        }
        if(!this->parent->isRed){
            return;
        }
        if(this->parent->parent==NULL){
            this->parent->isRed=false;
            this->isRed=true;
            return;
        }
        
        // cout<<"Checking node :"<<this->n<<endl;
        Node* gp=this->parent->parent;
        Node* pa=this->parent;
        Node* unc=NULL;
        
        if(gp->nodeL==pa){
            unc=gp->nodeR;
            if(unc==NULL || !unc->isRed){
                if(pa->nodeL==this){
                    Node* t=gp->parent;
                    gp->nodeL=pa->nodeR;
                    if(parent->nodeR!=NULL){
                    parent->nodeR->parent=gp;
                    }
                    gp->parent=pa;
                    pa->nodeR=gp;
                    pa->parent=t;
                    if(t==NULL){
                        root=pa;
                    }else{
                        if(t->nodeL==gp){
                            t->nodeL=pa;
                        }else{
                            t->nodeR=pa;
                        }
                    }
                    pa->isRed=false;
                    gp->isRed=true;
                    


                }else{

                    Node* t=gp->parent;
                    this->parent=t;
                    if(t==NULL){
                        root=this;
                    }else{
                        if(t->nodeL==gp){
                            t->nodeL=this;
                        }else{
                            t->nodeR=this;
                        }
                    }
                    if(this->nodeL!=NULL){
                        this->nodeL->parent=pa;
                    }
                    
                    if(this->nodeR!=NULL){
                        this->nodeR->parent=gp;
                    }
                    
                    
                    pa->nodeR=this->nodeL;
                    gp->nodeL=this->nodeR;
                    this->nodeR=gp;
                    this->nodeL=pa;
                    pa->parent=this;
                    gp->parent=this;
                    this->isRed=false;
                    gp->isRed=true;
                    pa->isRed=true;


                }


            }else{
                gp->isRed=true;
                pa->isRed=false;
                unc->isRed=false;
                gp->isRRViolated();

            }
        
        }else{
            unc=gp->nodeL;
            if(unc==NULL || !unc->isRed){
                 if(pa->nodeR==this){
                    Node* t=gp->parent;
                    
                    gp->nodeR=pa->nodeL;
                    
                    if(parent->nodeL!=NULL){
                    
                    parent->nodeL->parent=gp;
                    }

                    gp->parent=pa;

                    pa->nodeL=gp;
                    pa->parent=t;
                    if(t==NULL){
                        root=pa;
                    }else{
                         if(t->nodeL==gp){
                            t->nodeL=pa;
                        }else{
                            t->nodeR=pa;
                        }
                    }
                    pa->isRed=false;
                    gp->isRed=true;
                    


                }else{
                      Node* t=gp->parent;
                    this->parent=t;
                    if(t==NULL){
                        root=this;
                    }else{
                         if(t->nodeL==gp){
                            t->nodeL=this;
                        }else{
                            t->nodeR=this;
                        }
                    }
                    if(this->nodeL!=NULL){
                        this->nodeL->parent=gp;
                    }
                    
                    if(this->nodeR!=NULL){
                        this->nodeR->parent=pa;
                    }
                    
                    pa->nodeL=this->nodeR;
                    gp->nodeR=this->nodeL;
                    
                    
                    this->nodeL=gp;
                    this->nodeR=pa;
                    pa->parent=this;
                    gp->parent=this;
                    this->isRed=false;
                    gp->isRed=true;
                    pa->isRed=true;

                }
            
            }else{
                gp->isRed=true;
                pa->isRed=false;
                unc->isRed=false;
                gp->isRRViolated();

            }
        }
        
    }
    
    

            
    
