#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode inputList() {
    int n;
    cin >> n;
    auto *head = new ListNode();
    ListNode *p = head;
    while (n--) {
        int val;
        cin >> val;
        p->next = new ListNode(val);
        p = p->next;
    }
    return *head->next;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr) {
        return list2;
    }
    if (list2 == nullptr) {
        return list1;
    }
    auto *head = new ListNode();
    ListNode *p = head;
    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val < list2->val) {
            p->next = list1;
            list1 = list1->next;
        } else {
            p->next = list2;
            list2 = list2->next;
        }
        p = p->next;
    }
    if (list1 != nullptr) {
        p->next = list1;
    }
    if (list2 != nullptr) {
        p->next = list2;
    }
    return head->next;
}

int main() {
    ListNode list1 = inputList();
    ListNode list2 = inputList();
    ListNode *list = mergeTwoLists(&list1, &list2);
    while (list != nullptr) {
        cout << list->val << " ";
        list = list->next;
    }
    return 0;
}
