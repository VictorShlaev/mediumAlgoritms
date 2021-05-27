/*
 * You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
 * Merge all the linked-lists into one sorted linked-list and return it.
 * Input: lists = [[1,4,5],[1,3,4],[2,6]]
 * Output: [1,1,2,3,4,4,5,6]
*/

#include <iostream>
#include <vector>
#include <algorithm>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

};

void printList(ListNode* nodes){
    while (nodes) {
        std::cout<<nodes->val<<" ";
        nodes = nodes->next;
    }
    std::cout<<std::endl;
}

ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    std::vector<int> vals;
    for( auto& list: lists){
        while (list) {
            vals.push_back(list->val);
            list = list->next;
        }
    }

    if(vals.empty()) return nullptr;
    std::sort(vals.begin(), vals.end(), std::greater<int>());
    ListNode* res = new ListNode(vals[0]);
    for(size_t i =1; i < vals.size(); ++i){
        res = new ListNode(vals[i], res);
    }
    printList(res);
    return  res;
}

void tests(){
    ListNode* t11 = new ListNode(5);
    ListNode* t12 = new ListNode(4, t11);
    ListNode* t1 = new ListNode(1, t12);

    ListNode* t21 = new ListNode(4);
    ListNode* t22 = new ListNode(3, t21);
    ListNode* t2 = new ListNode(1, t22);

    ListNode* t31 = new ListNode(6);
    ListNode* t3 = new ListNode(2, t31);


    ListNode* t4 = new ListNode(1);
    std::vector<ListNode*> test{t1, t2,t3};
    std::vector<ListNode*> test1 {};
    std::vector<ListNode*> test2 {{}};
    std::vector<ListNode*> test3 {t4};
    mergeKLists(test);
    mergeKLists(test1);
    mergeKLists(test2);
    mergeKLists(test3);
}
int main()
{
    tests();
    return 0;
}
