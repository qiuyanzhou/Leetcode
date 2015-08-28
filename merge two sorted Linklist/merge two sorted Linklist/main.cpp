//
//  main.cpp
//  merge two sorted Linklist
//
//  Created by qiuyanzhou on 8/27/15.
//  Copyright (c) 2015 qiuyanzhou. All rights reserved.
//

#include <iostream>
using namespace std;
struct ListNode {
    ListNode* next;
    int value;
    ListNode(int v) : value(v),next(NULL) {};
};
void printLL(ListNode* head) {
    while (head != NULL) {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

void insertNodeInFront(ListNode*& head, ListNode* node) {
    node->next=head;
    head = node;
}

ListNode* merge(ListNode* one, ListNode* two) {
    // write your solution here
    if (one == NULL && two == NULL){
        return one;
    }
    if (one == NULL) {
        return two;
    }
    if (two == NULL) {
        return one;
    }
    ListNode* head = new ListNode(0);
    ListNode* cur = head;
    while (one != NULL && two != NULL) {
        if(one->value <= two->value) {
            cur->next = one;
            one = one->next;
        } else {
            cur->next = two;
            two = two->next;
        }
        cur = cur->next;
    }
    if (one != NULL) {
        cur->next = one;
    }
    if (two != NULL) {
        cur->next = two;
    }
    return head->next;
}

int main(int argc, const char * argv[]) {
    // insert code here...
     ListNode* n1 = new ListNode(1);
     ListNode* n2 = new ListNode(2);
     ListNode* n3 = new ListNode(3);
     ListNode* n4 = new ListNode(4);
     ListNode* head = n4;
     insertNodeInFront(head, n3);
     insertNodeInFront(head, n2);
     //insertNodeInFront(head, n1);
     printLL(head);
     ListNode* head1 = merge(head, n1);
     printLL(head1);
    
    return 0;
}
