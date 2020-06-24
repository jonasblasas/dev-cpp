#include <iostream>
using namespace std;

class ListNode
{
    public:
    int data;
    ListNode* next;
};

void push(ListNode **head_ref, int value)
{
    ListNode *new_node = new ListNode();
    new_node->data = value;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void append(ListNode **head_ref, int value)
{
    ListNode *new_node = new ListNode();
    new_node->data = value;
    new_node->next = NULL;

    if(*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    ListNode *last = *head_ref;

    while(last->next != NULL) 
    {
        last = last->next;
    }

    last->next = new_node;
    return;
}

void insertAfter(ListNode *prev_node, int value)
{
    if(prev_node == NULL)
    {
        return;
    }

    ListNode *new_node = new ListNode();
    new_node->data = value;

    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void printList(ListNode *node)
{
    while(node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

ListNode* reverseList(ListNode *head)
{
    if(head == NULL)
    {
        return NULL;
    }

    ListNode *reversedHead = NULL;

    ListNode *cur = head;

    while(cur != NULL)
    {
        push(&reversedHead, cur->data);
        cur = cur->next;
    }

    return reversedHead;
}


int main() {

    ListNode *head = NULL;

    push(&head, 1);
    push(&head, 2);
    push(&head, 3);

    append(&head, 4);
    append(&head, 5);
    append(&head, 6);

    insertAfter(head->next, 7);

    cout << "print linked list" << endl;
    printList(head);

    ListNode *reversed = reverseList(head);
    cout << "print reversed list" << endl;
    printList(reversed);

    cout << "program finished" << endl;
    return 0;
}