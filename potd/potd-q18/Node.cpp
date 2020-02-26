#include "Node.h"

void mergeList(Node *first, Node *second) {
  // your code here!

	if (first==NULL){
		first =  second;
	}
	Node *temp1;
	Node *temp2;
	Node *a=first;
	Node *b=second;
	Node *pre = a;
	while(b!=NULL){
	if(a!=NULL){
		temp1 = a->next_;
		temp2 = b;
		b = b->next_;
		a->next_ = temp2;
		temp2->next_ = temp1;
		pre = temp2;
		a = temp1;

	}
	else {
		pre->next_ = b;

		break;
	}
}


}

Node::Node() {
    numNodes++;
}

Node::Node(const Node &other) {
    this->data_ = other.data_;
    this->next_ = other.next_;
    numNodes++;
}

Node::~Node() {
    numNodes--;
}

int Node::numNodes = 0;
