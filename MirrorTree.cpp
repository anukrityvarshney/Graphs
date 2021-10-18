#include <iostream>
#include <vector>
#include<queue>
#define MAXVALUEOFNODE 1000
using namespace std;

struct Node{
	int data;
	Node *right;
	Node *left;
};

class BT{
	public:
		Node *root;
		vector<Node *> dangling;
		vector<bool> visited;
		bool firstNode;
	
		BT(){
			root = NULL;
			for(int i=0;i<MAXVALUEOFNODE + 1;i++){
				dangling.push_back(NULL);
				}
			for(int i=0;i<MAXVALUEOFNODE + 1;i++){
				visited.push_back(false);
				}
			firstNode = true;
			}

		void addNode(int parent, int child, char direction){
			Node *childNode;			
			Node *parentNode;			
			if(dangling[child] == NULL){
				childNode = new Node;
				childNode->data = child;
				childNode->left = NULL;
				childNode->right = NULL;
				dangling[child] = childNode;
				}
			else{
				childNode = dangling[child];
				}
			if(dangling[parent] == NULL){
				parentNode = new Node;
				parentNode->data = parent;
				parentNode->left = NULL;
				parentNode->right = NULL;
				dangling[parent] = parentNode;
				}
			else{
				parentNode = dangling[parent];
				}
			
			if(root == NULL){
				root = parentNode;
				}

			if(direction == 'L'){
				parentNode->left = childNode;
				}
			else{
				parentNode->right = childNode;
				}
			}
	
		void mirrorTree(){

			
			}

		void inOrderTraversal(Node *node){
			if(node == NULL)return;
			if(node->left != NULL){
				inOrderTraversal(node->left);
				}
			if(firstNode){
				cout<<node->data;
				firstNode = false;
				}
			else{
				cout<<" "<<node->data;
				}
			if(node->right != NULL){
				inOrderTraversal(node->right);
				}
			}
};

int main(void) {
	int edges, parent, child;
	char direction;

	cin>>edges;
	BT bt;
	for(int i=0;i<edges;i++){
		cin>>parent>>child>>direction;
		bt.addNode(parent, child, direction);
	}
	
	bt.mirrorTree();
	bt.firstNode = true;
	cout<<"\n";
	bt.inOrderTraversal(bt.root);
	return 0;
}
