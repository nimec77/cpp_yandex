#include <iostream>
#include <map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* inputList() {
    int n;
    cin >> n;
    ListNode *head = nullptr, *tail = nullptr;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (head == nullptr) {
            head = tail = new ListNode(x);
        } else {
            tail->next = new ListNode(x);
            tail = tail->next;
        }
    }
    return head;
}

ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr) {
        return nullptr;
    }
    ListNode *p = head, *q = head->next;
    while (q != nullptr) {
        if (p->val == q->val) {
            p->next = q->next;
            delete q;
            q = p->next;
        } else {
            p = q;
            q = q->next;
        }
    }
    return head;
}

int main() {
    ListNode *head = inputList();
    head = deleteDuplicates(head);
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}
