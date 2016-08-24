#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

typedef int Algorithm;
class IntNode{
	public:
	    Algorithm kadane;
	    Algorithm divCon;
	    Algorithm brute;


		IntNode* next;

		friend class IntLinkedList;
};

class IntLinkedList{
	public:
		IntLinkedList();
		~IntLinkedList();
		bool isEmpty()const;
		const int num();		//prints front element
		void addFront(const int& a, const int& b, const int& c);
		void removeFront();
		friend ostream& operator<<(ostream& out, const IntLinkedList& obj);

	private:
		IntNode* head;
};

IntLinkedList::IntLinkedList() :head(NULL){}
IntLinkedList::~IntLinkedList(){
	while(!isEmpty()) removeFront();
}
bool IntLinkedList::isEmpty()const{
	 return head == NULL;
}
/*
const int& IntLinkedList::front()const{

}
*/
void IntLinkedList::addFront(const int& a, const int& b, const int& c){
	IntNode* v = new IntNode;
	v ->brute=a;
	v ->divCon=b;
	v ->kadane=c;
	v ->next=head;
	head =v;
}
void IntLinkedList::removeFront(){
	IntNode* old =head;
	head = old->next;
	delete old;
}

ostream& operator<<(ostream& out, const IntLinkedList& obj){
	IntNode* temp = obj.head;
	while(temp !=NULL){
		out << temp->brute<<' '<<temp->divCon<<' '<<temp->kadane<<endl;
		temp = temp->next;
	}
	return out;
}

int main (void){
	IntLinkedList* data= new IntLinkedList();
    ifstream input;

    input.open("output.txt");
    if(!input){
        cerr<<"File Not Found"<<endl;
        return -1;
    }

    int inputSize,alg1,alg2,alg3;
    string firstLine;

    getline(input,firstLine); //skips first line
    input>>inputSize>>alg1>>alg2>>alg3;

    while(input){
        data ->addFront(alg1,alg2,alg3);
        //cout<<alg1<<' '<<alg2<<' '<<alg3<<endl;
        input>>inputSize>>alg1>>alg2>>alg3;
    }
  cout<< *data <<endl;



return 0;
}
