#include <iostream>
#include "../node.h"
#include <vector>

using namespace std;

node* expand(node* head) {
    node* current = head;
    node* old_next;

    while(current->next != nullptr){
        if(current->data != current->next->data){ //test to see if current node data and next node data match
            //add another duplicated node
            node* new_node = new node;
            new_node->data = current->data;
            new_node->next = current->next;
            current->next = new_node;
            current = current->next->next; //skip next node b/c we just added it
//            old_next = current->next;
//            temp->data = current->data;
//            temp->next = old_next; //link temporary node to the "back" of the split
//            current->next = temp;
//            current = current->next->next;
        }
        else{
            current = current->next;
        }
        cout << "Current Data: " << current->data << ""
    }
    return head;
}

void print_linked(node* head){
    node* current = head;
    while(current != nullptr){
        cout << "Data: " << current->data << " Next: " << current->next << endl;
        current = current->next;
    }
}

node* vector_to_list(vector<string> my_list){
    node* head = new node;
    head->data = my_list[0];
    node* tail = head;
    for(int i=1; i<my_list.size(); i++){
        node* new_node = new node;
        new_node->data = my_list[i];
        new_node->next = nullptr;
        tail->next = new_node;
        tail = new_node;
    }
    return head;
}

int main(){
//    node first_node;
//    first_node.data = "apple";
//    first_node.next = nullptr;
//
//    node second_node = {"orange", nullptr};
//    first_node.next = &second_node;
//    print_linked(&first_node);

    vector<string> my_list = {"apple", "orange", "banana", "peach"};
    print_linked(expand(vector_to_list(my_list)));

    return 0;
}

