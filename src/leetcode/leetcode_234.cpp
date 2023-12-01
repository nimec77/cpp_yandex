#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindrome(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return true;
    }

    auto slow = head;
    auto fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *prev = nullptr;
    while (slow != nullptr) {
        auto next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }

    auto left = head;
    auto right = prev;
    while (right != nullptr) {
        if (left->val != right->val) {
            return false;
        }
        left = left->next;
        right = right->next;
    }

    return true;
}

int main() {
    return 0;
}
