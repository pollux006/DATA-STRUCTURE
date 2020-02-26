#include "Node.h"

/** Create a new node and add it to the list, while keeping the list sorted.
*/
Node *insertSorted(Node *first, int data) {
    // your code here
		Node *insert = new Node();
		insert->data_ = data;



		if (first == NULL) {
			insert->next_ = NULL;
			return insert;
		}
		else if(first->data_>data){
			insert->next_ = first;
			return insert;
		}



		Node *pre;
		Node *current;
		pre = first;
		current = first;
		while(current!=NULL){
			if ((current->data_)<data){
				pre = current;
				current = current->next_;
			}
			else if(current->data_==data){
				delete insert;
				return first;
			}
			else {
				insert->next_ = current;
				pre->next_ = insert;
				return first;
			}
		}
		pre ->next_ = insert;
		insert->next_ = NULL;
    return first;
}

/** Creates a new list (containing new nodes, allocated on the heap)
	that contains the set union of the values in both lists.
*/
Node *listUnion(Node *first, Node *second) {
    Node *out = NULL;

    while (first != NULL) {
        // your code here
        // hint: call insertSorted and update l1
				out = insertSorted(out,first->data_);
				first = first ->next_;
    }

    while (second != NULL) {
        // your code here
				out = insertSorted(out,second->data_);
				second = second ->next_;
    }

    return out;
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
