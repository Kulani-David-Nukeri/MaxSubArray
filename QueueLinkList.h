//
//  QueueLinkedList.hpp
//  MaxSubArray
//
//  Created by Tyson on 2016/08/24.
//  Copyright © 2016 Tyson Cross. All rights reserved.
//


#ifndef QueueLinkedList

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

class Node{
public:
    Node();
    int getElem();
    //~Node();
private:
    const int elem;
    Node* next;
};

class QueueLinkedList{
public:
    QueueLinkedList();
    ~QueueLinkedList();
    bool isEmpty() const;
    const int front();                  //return front element
    const int rear();                   // return back element
    //const int size();                // return number of elements
    void enqueue(const int e);
    void dequeue();
    friend std::ostream& operator<<(std::ostream& out, const QueueLinkedList& obj);

private:
    Node* head;
    Node* tail;
    //int size;
};


#define QueueLinkedList

#include <stdio.h>

#endif /* QueueLinkedList_hpp */
