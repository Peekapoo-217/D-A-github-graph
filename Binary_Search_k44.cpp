
/*
cay tim kiem nhi phan
*/

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

struct SubScription{
	string name;
	string phoneNumber;	
};

struct Node{
	SubScription data;
	Node * left, * right;	
};

//them vao cay
Node * createNode(SubScription p, Node *left, Node *right){
	return new Node{p, left, right};
}

//chen cay tim kiem nhi phan
Node * add(Node * root, SubScription p){
	if(!root){
		return createNode(p, nullptr, nullptr);
	}
	
	if(p.phoneNumber < root->data.phoneNumber){
		root->left = add(root->left, p);
	}
	else if(p.phoneNumber > root->data.phoneNumber){
		root->right = add(root->right, p);
	}	
	return root;
}

//tham
void visit(Node * root){
	cout<<"Ten: "<<root->data.name<<" So dien thoai: "<<root->data.phoneNumber<<endl;
}

//DFS
void DFS(Node * root){
	if(root != nullptr){
		DFS(root->left);
		visit(root);
		DFS(root->right);
	}	
}

//liet ke so dien thoai
void lietke(Node * root, string x){
	if(root != nullptr){
		
		if(root->data.phoneNumber.compare(0, x.length(), x) == 0){
			cout<<root->data.phoneNumber<<endl;
		}
		
		lietke(root->left, x);
		lietke(root->right, x);
	}
}

//void lietke(Node* root, string x) {
//    if (!root)
//        return;
//    string tmp = root->data.phoneNumber.substr(0, x.length()+1);
//        if (tmp == x) {
//            cout << root->data.phoneNumber << endl;
//        }
//    lietke(root->left, x);  
//    lietke(root->right, x);
//}


int main(){
	Node * root = nullptr;
		
	//them
	root = add(root, {"s1mple", " 0912567343"});
	root = add(root, {"Skir", " 0952567675"});
	root = add(root, {"Ropz", " 0912567930"});
	root = add(root, {"Keoz", " 0912567100"});
	root = add(root, {"Monesy", " 0903567293"});
	
//	DFS(root);

	string x = "0912";
	cout<<"\nCac so dien thoai bat dau bang "<<x<<":" <<endl;
	lietke(root, x);
	
	
	return 0;
}

