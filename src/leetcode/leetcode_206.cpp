#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *inputList() {
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
    return head->next;
}

ListNode *reverseList(ListNode *head) {
    stack<ListNode *> s;
    if (head == nullptr) {
        return head;
    }
    while (head != nullptr) {
        s.push(head);
        head = head->next;
    }
    head = s.top();
    auto p = head;
    s.pop();
    while (!s.empty()) {
        p->next = s.top();
        s.pop();
        p = p->next;
    }
    p->next = nullptr;

    return head;
}

ListNode *reverseListRecurs(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode *newHead = reverseListRecurs(head->next);
    head->next->next = head;
    head->next = nullptr;

    return newHead;
}

int main() {
    auto head = inputList();
    head = reverseListRecurs(head);
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}
