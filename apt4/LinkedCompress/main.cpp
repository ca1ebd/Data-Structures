#include <iostream>
#include "../node.h"
#include <vector>

using namespace std;

node* compress(node* head) {
    node* previous_node = new node{"null"};
    node* current = head;
    while(current != nullptr){
        if(current->data == previous_node->data){
            //remove current node
            previous_node->next = current->next;
            delete current;
            current = previous_node;


        }
        previous_node = current;
        current = current->next;
    }

//    for(node* current = head; current != nullptr; current = current->next){
//        if(current->data == previous_node->data){
//            node* to_delete = current;
//            previous_node->next = current->next;
//            delete to_delete;
//        }
//        previous_node = current;
//    }

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

    vector<string> my_list = {"apple", "apple", "banana", "banana"};
    print_linked(compress(vector_to_list(my_list)));

    return 0;
}