#include<iostream>
#include <vector>
#include <queue>
using namespace std;
template <typename t> 
class TreeNode{
  public:
  t data;
  vector <TreeNode<t>*> child;
  TreeNode(t data){
     this->data=data;
  }
};
TreeNode<int>*takeinputlevelwise(){
    int rootd;
    cout<<"enter d"<<endl;
    cin>>rootd;
    TreeNode<int>*root=new TreeNode<int>(rootd);
    queue<TreeNode<int>*> pnodes;
    pnodes.push(root);
    while(pnodes.size()!=0){
        TreeNode<int>*front= pnodes.front();
        pnodes.pop();
        cout<<"enter no. of child"<<rootd<<endl;
        int numchild;
        cin>>numchild;
        for(int i=0;i<numchild;i++){
            int chdata;
            cout<<"enter"<<i<<"child of"<<front->data<<endl;
            cin>>chdata;
            TreeNode<int>*ch=new TreeNode<int>(chdata);
            front->child.push_back(ch);
            pnodes.push(ch);
        }

    }
    return root;
}
TreeNode<int>*takeinput(){
    
     cout<<"enterd"<<endl;
      int rootd;
     cin>>rootd;
     TreeNode<int>*root=new TreeNode<int>(rootd);
     int n;  //no. of children 
     cout<<"enter nu of child of"<<rootd<<endl;
     cin>>n;
     for(int i=0;i<n;i++){
        TreeNode<int>*c=takeinput();
        root->child.push_back(c);
     }
     return root;
}
void print(TreeNode<int>*root){
    if(root==NULL){
        return;    //edge case
    }
    cout<<root->data<<":";
    for(int i=0;i<root->child.size();i++){
        cout<<root->child[i]->data<<',';
    }
    cout<<endl;
    for(int i=0; i<root->child.size();i++){
       print(root->child[i]);
    }
}

int main(){
   // TreeNode<int>*root=new TreeNode<int>(1);
    //TreeNode<int>*node1=new TreeNode<int>(2);
    //TreeNode<int>*node2=new TreeNode<int>(3);
    //root->child.push_back(node1);
    //root->child.push_back(node2);  //conections are made like this 
    TreeNode<int>*root=takeinputlevelwise();
     print(root);
}