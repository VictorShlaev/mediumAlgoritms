/*
*  Given a linked list, swap every two adjacent nodes and return its head.
*  You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
* Input: head = [1,2,3,4]
* Output: [2,1,4,3]
*/

#include <iostream>
#include <vector>



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* swapPairsVal(ListNode* head) {
    ListNode* tmp = head;
    int i =0;
    while(tmp){
        if(i%2 ==0){
            int cur = tmp->val;
            int n = tmp->next->val;
            tmp->val = n;
            tmp->next->val = cur;
        }
        tmp = tmp->next;
        i++;

    }
    return head;

}



ListNode* swapPairs(ListNode* head) {
    ListNode* tmp = head;
    std::vector<ListNode*> nodes;
    while(tmp){
        nodes.push_back(tmp);
        tmp = tmp->next;
    }
    if(nodes.empty()) return nullptr;
    for(size_t i =0; i < nodes.size()-1; i+=2){
        std::swap(nodes[i], nodes[i+1]);
    }
    ListNode* r = nodes[0];
    tmp = r;
    for(size_t i =1; i< nodes.size(); ++i){
        r->next = nodes[i];
        r = r->next;
    }
    r->next = nullptr;
    return tmp;
}

void printList(ListNode* node){
    while(node){
        std::cout<<node->val<<" ";
        node = node->next;
    }
}
int main(){
    ListNode* n1 = new ListNode(6);
    ListNode* n2 = new ListNode(5,n1);
    ListNode* n3 = new ListNode(4,n2);
    ListNode* n4 = new ListNode(3,n3);
    ListNode* n5 = new ListNode(2,n4);
    ListNode* n = new ListNode(1,n5);
    ListNode* r = swapPairs(n);
    printList(r);
//    ListNode* v = swapPairsVal(n);
//    printList(v);
    return  0;

}
