#include <iostream>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    auto l = headA;
    auto r = headB;

    while (l != r) {
        if (l == nullptr) {
            l = headB;
        } else {
            l = l->next;
        }

        if (r == nullptr) {
            r = headA;
        } else {
            r = r->next;
        }
    }

    return l;
}

int main() {
    return 0;
}
