#include <iostream>
#include<vector>
#include<queue>
using namespace std;
template <typename t>
class binarytreenode{
    public
    binarytreenode(t data){
        this->data=data;
        left=NULL;:
    t data;
    binarytreenode *left;
    binarytreenode* right;

        right=NULL;
    }
    ~binarytreenode(){
        delete left;
        delete right;
    }
};

void printtree(binarytreenode<int>*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<':';
    if(root->left!=NULL){
        cout<<"l"<<root->left->data;
    }
    if(root->right!=NULL){
        cout<<"r"<<root->right->data;
    }
    cout<<endl;
    printtree(root->left);
    printtree(root->right);
}

binarytreenode<int>* takeinput(){
    int rdata;
    cin>>rdata;
    if(rdata==-1){
        return NULL;
    }
    binarytreenode<int>* root=takeinput(rdata);
    binarytreenode<int>* lchild=takeinput();
    binarytreenode<int>*rchild=takeinput();
    root->left=lchild;
    root->right=rchild;
    return root;
}

binarytreenode<int>* takeinputlevel(){
    int rootd;
    cin>>rootd;
    binarytreenode<int>*root= new binarytreenode<int>(rootd);
    queue<binarytreenode<int>*> pnodes;
    pnodes.push(root);
    while(pnodes.size()!=0){
        binarytreenode<int>*front= pnodes.front();
        pnodes.pop();
        cout<<"enter l c data of"<<front->data<<endl;
        int lcdata;
        cin>>lcdata;
        if(lcdata!=-1){
             binarytreenode<int>*child= new binarytreenode<int>(lcdata);
             front->left= child;
              pnodes.push(child);
        }
        cout<<"enter r c data of"<<front->data<<endl;
        int rcdata;
        cin>>rcdata;
        if(rcdata!=-1){
             binarytreenode<int>*child= new binarytreenode<int>(rcdata);
             front->right= child;
              pnodes.push(child);
        }
    }
    return root;

}
void printLevelWise(binarytreenode<int> *root) {
	if(root==NULL){
		return;
	}
	
	queue<binarytreenode<int>*> pnodes;
	pnodes.push(root);
	while(pnodes.size()!=0){
		binarytreenode<int>* front= pnodes.front();
		pnodes.pop();
		cout<<front->data<<":";

		if(front->left!=NULL){
			cout<<"L"<<":"<<front->left->data;
		     pnodes.push(front->left);
		}
		else{
			cout<<"L"<<":"<<"-1";
		}
		if(front->right!=NULL){
			cout<<","<<"R"<<":"<<front->right->data;
			 pnodes.push(front->right);
		}
		else{
			cout<<","<<"R"<<":"<<"-1";
		}
		cout<<endl;
     
	}

}

int numnodes(binarytreenode<int>*root){
    if(root==NULL){
        return 0;
    }
    return 1+numnodes(root->left)+numnodes(root->right);

}
bool isNodePresent(binarytreenode<int> *root, int x) {
    if(root==NULL){
        return false;
    }
    queue<binarytreenode<int> *> q;
    q.push(root);
    while(q.size()!=NULL){
       binarytreenode<int>* front= q.front();
        q.pop();
        if(front->data==x){
            return true;
        }
        if(front->left!=NULL){
            q.push(front->left);
        }
         if(front->right!=NULL){
            q.push(front->right);
        }
    }
}