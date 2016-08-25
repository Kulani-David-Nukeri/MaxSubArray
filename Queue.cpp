#include<iostream>
#include<sstream>
#include<fstream>
#include<iomanip>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<cstdlib>
using namespace std;
//Queue structure
struct Node{
	int kadane;
	int divCon;
	int brute;
	Node* next;
};

class QueueLinkList{
 public:
	QueueLinkList();
	bool isEmpty() const;
	const Node* front() const;
	const Node* rear() const;
	int getQueueSize() const;
	void dequeue();
	void queue(const int& a,const int& b, const int& c);
	friend ostream& operator<<(ostream& out, const QueueLinkList& obj);
	
 private:
	Node* head;
	Node* tail;
	int queueSize;
};
QueueLinkList::QueueLinkList(): queueSize(0){}
bool QueueLinkList::isEmpty() const{
	if(queueSize==0){
		return true;	
	}
	else{
		return false;
	}
}
const Node* QueueLinkList::front() const{
	return head;
}
const Node* QueueLinkList::rear() const{
	return tail;
}
int QueueLinkList::getQueueSize() const{
	return queueSize;
}
void QueueLinkList::dequeue(){
	Node* oldhead = head;
	head = head->next;
	delete oldhead;
	queueSize--;
}
void QueueLinkList::queue(const int& a,const int& b,const int& c){
	Node* newNode = new Node;
	newNode->brute = a;
	newNode->divCon = b;
	newNode->kadane = c;
	newNode->next = NULL;
	if(isEmpty()){
		head = newNode;
		tail = head;
		queueSize++;
	}
	else{
		tail->next = newNode;
		tail = newNode;
		queueSize++;
	}
}

//Queue Structure terminal point
//DSS Data Structure and Smooth Algorithm

//DSS Data Structure and Smooth Algorithm terminal point
