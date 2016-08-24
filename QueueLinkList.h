//
//  QueueLinkList.hpp
//  MaxSubArray
//
//  Created by Tyson on 2016/08/24.
//  Copyright © 2016 Tyson Cross. All rights reserved.
//

struct Node{
    const int kadane;
    const int divCon;
    const int brute;
    Node* next;
};

#ifndef QueueLinkList_h

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

class QueueLinkList{
public:
    QueueLinkList();
    bool isEmpty() const;
    const Node& front() const;                  //return front element
    const Node& rear() const;                   // return back element
    int size() const;                   // return number of elements
    void enqueue(const int& a, const int& b, const int& c);
    void dequeue();
    friend std::ostream& operator<<(std::ostream& out, const QueueLinkList& obj);
    ~QueueLinkList();

private:
    Node* head;
    Node* tail;
    int element_size;
};


#define QueueLinkList_h

#include <stdio.h>

#endif /* QueueLinkList_h */
