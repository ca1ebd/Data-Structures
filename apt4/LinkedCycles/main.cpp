#include "../node.h"
#include <vector>

using namespace std;

int cycle_length(lil_node* head) {
    lil_node* current = head;
    vector<lil_node*> prev_nodes;
    while(current != nullptr){
        for(int i=0; i<prev_nodes.size(); i++){
            if(prev_nodes[i] == current){ //loop detected
                int count = 0;
                for(lil_node* iterator = current->next; iterator != current; iterator=iterator->next){
                    count++;
                }
                return count;
            }
        }
        prev_nodes.push_back(current);
    }
    return -1;
}