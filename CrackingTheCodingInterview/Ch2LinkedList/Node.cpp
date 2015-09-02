#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <string>

using namespace std;

class Vector{
public:
	int x, y;
	Vector() {};
	Vector(int a, int b) : x(a), y(b) {}
	Vector operator + (const Vector&);
};

//template<int>
class Node{
public:
	int data;
	Node* next;

	Node(int d) {
		data = d;
		next = NULL;
	}

	void appendToTail(Node* n) {
		Node* curr = this;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = n;
	}

	void removeDuplicates(){
		Node* curr = this;
		while (curr != NULL){
			Node* runner = curr;
			while (runner->next != NULL){
				if (curr->data == runner->next->data){
					runner->next = runner->next->next;
				}
				else{
					runner = runner->next;
				}
			}
			curr = curr->next;
		}
	}

	void findKthToLast(Node* &n, int k){
		findKthToLast(this, n, k);
	}

	void printList(){
		Node* curr = this;
		while (curr != NULL){
			printf("%d ", curr->data);
			curr = curr->next;
		}
		printf("\n");
	}

private:
	int findKthToLast(Node* n, Node* &result, int k){
		if (n->next == NULL) return 1;
		int pos = 1 + findKthToLast(n->next, result, k);
		if (pos == k) result = n;
		return pos;
	}

};

int main() {
	Node* head = new Node(0);
	head->appendToTail(new Node(4));
	head->appendToTail(new Node(2));
	head->appendToTail(new Node(1));
	head->appendToTail(new Node(4));
	head->appendToTail(new Node(5));
	head->appendToTail(new Node(6));
	head->appendToTail(new Node(8));
	head->appendToTail(new Node(5));
	head->appendToTail(new Node(4));
	head->printList();
	head->removeDuplicates();
	head->printList();
	Node* nodek;
	head->findKthToLast(nodek, 3);
	printf("Kth node=%d\n", nodek->data);

	Node* num1 = new Node(6);
	num1->appendToTail(new Node(1));
	num1->appendToTail(new Node(7));
	Node* num2 = new Node(5);
	num1->appendToTail(new Node(9));
	num1->appendToTail(new Node(2));
	return 0;
}