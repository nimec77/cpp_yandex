#include <iostream>
#include <set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *helper(ListNode *prev, ListNode *head, int val) {
    auto cur = head;
    while (cur != nullptr) {
        if (cur->val == val) {
            if (prev != nullptr) {
                prev->next = cur->next;
                auto temp = cur;
                cur = cur->next;
                delete temp;
            } else {
                auto temp = head;
                head = cur->next;
                cur = head;
                delete temp;
            }
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}

ListNode *removeElements(ListNode *head, int val) {
    return helper(nullptr, head, val);
}

int main() {
    return 0;
}
