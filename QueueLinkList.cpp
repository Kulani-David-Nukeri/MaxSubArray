//
//  QueueLinkList.cpp
//  MaxSubArray
//
//  Created by Tyson on 2016/08/24.
//  Copyright © 2016 Tyson Cross. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include "QueueLinkList.h"

QueueLinkList::QueueLinkList(){
    head = NULL;
    tail = NULL;
    element_size = 0;
}

bool QueueLinkList::isEmpty() const{
    return (head == NULL);
}

const Node& QueueLinkList::front() const{
    return *head;
}

const Node& QueueLinkList::rear() const{
    return *tail;
}

int QueueLinkList::size() const{
    return element_size;
}

void QueueLinkList::enqueue(const int& a, const int& b, const int& c){
    Node* newNode = new Node();
    newNode->brute = a;
    newNode->divCon = b;
    newNode->kadane = c;
    newNode->next = head;
    head = newNode;
}


void QueueLinkList::dequeue(){
}

std::ostream& operator<<(std::ostream& out, const QueueLinkList& obj){
    Node* temp = obj.head;
    while(temp !=NULL){
        out << temp->brute << ' ' << temp->divCon << ' ' << temp->kadane << std::endl;
        temp = temp->next;
    }
    return out;
}

QueueLinkList::~QueueLinkList(){
    while(!isEmpty()) dequeue();
}

