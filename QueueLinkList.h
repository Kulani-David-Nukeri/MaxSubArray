//
//  QueueLinkList.hpp
//  MaxSubArray
//
//  Created by Tyson on 2016/08/24.
//  Copyright © 2016 Tyson Cross. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

struct Node{
    int kadane;
    int divCon;
    int brute;
    Node* next;
    Node* prev;
};


class QueueLinkList{
public:
    QueueLinkList();
    bool isEmpty() const;
    const Node& front() const;                  //return front element
    const Node& rear() const;                   // return back element
    int getQueueSize() const;                   // return number of elements
    void add(Node* inputNode,const int& a, const int& b, const int& c);
    void enqueue(const int& a, const int& b, const int& c);
    void remove(Node* input);
    void dequeueFront();
    void dequeue();
    friend std::ostream& operator<<(std::ostream& out, const QueueLinkList& obj);
    ~QueueLinkList();

private:
    Node* head;
    Node* tail;
    int queueSize;
};

#define QueueLinkList_h

#include <stdio.h>

#endif /* QueueLinkList_h */
