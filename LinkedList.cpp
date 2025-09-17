#include "LinkedList.h"

int main(){
    LinkedList list;
    list.InsertAtHead(10);
    list.InsertAtTail(20);
    list.InsertAtHead(30);
    list.InsertAtTail(40);
    list.InsertAtTail(50);
    list.InsertAtTail(60);
    list.PrintList();
    list.DeleteVal(70);
    list.InsertAtTail(70);
    list.PrintList();
    list.DeleteHead();
    list.InsertAtTail(70);
    list.InsertAtTail(80);
    list.PrintList();
    list.DeleteTail();
    list.DeleteVal(70);
    list.PrintList();
}