QueueLinkList::QueueLinkList(){
    head = new Node();
    tail = new Node();
    head ->next = tail;
    tail ->prev = head;
    queueSize = 0;
}
QueueLinkList::~QueueLinkList(){
    while(!isEmpty()) dequeueFront();
    delete head;
    delete tail;
}
bool QueueLinkList::isEmpty() const{
    return (head ->next == tail);
}

const Node& QueueLinkList::front() const{
    return *head;
}

const Node& QueueLinkList::rear() const{
    return *tail;
}

int QueueLinkList::getQueueSize() const{
    return queueSize;
}

void QueueLinkList::add(Node* inputNode,const int& a, const int& b, const int& c){
    Node* newNode = new Node();
    newNode->brute = a;
    newNode->divCon = b;
    newNode->kadane = c;

    newNode->next = inputNode;
    newNode ->prev = inputNode ->prev;
    inputNode ->prev -> next = inputNode ->prev = newNode;
}
void QueueLinkList::enqueue(const int& a, const int& b, const int& c){

    add(head->next,a, b,c);
     queueSize ++;

}


void QueueLinkList::remove(Node* input){
    Node* prevNode = input -> prev;
    Node* newNode = input ->next;
    prevNode ->next = newNode;
    newNode ->prev = prevNode;
}
void QueueLinkList::dequeue(){

    remove(tail -> prev);
    queueSize --;
}
void QueueLinkList::dequeueFront(){
    remove(head -> next);
    queueSize --;
}
/*
std::ostream& operator<<(std::ostream& out, const QueueLinkList& obj){
    Node* temp = obj.tail;
    int n =1;
    temp = temp->prev;
    while( n < obj.getQueueSize()){
        temp = temp->prev;
        out << temp->brute << ' ' << temp->divCon << ' ' << temp->kadane << std::endl;

        n++;
    }
    return out;
}
*/
