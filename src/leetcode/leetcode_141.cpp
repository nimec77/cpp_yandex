#include <iostream>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

vector<int> inputArray() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x: a) cin >> x;
    return a;
}

ListNode *createList(vector<int> nums, int pos) {
    auto head = new ListNode(nums.front());
    auto p = head;
    ListNode *cycleNode = nullptr;
    if (pos == 0) {
        cycleNode = head;
    }
    for (int i = 1; i < nums.size(); i++) {
        auto node = new ListNode(nums[i]);
        if (i == pos) {
            cycleNode = node;
        }
        p->next = node;
        p = node;
    }
    if (cycleNode != nullptr) {
        p->next = cycleNode;
    }
    return head;
}

bool hasCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    if (head == nullptr) {
        return false;
    }

    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }

    return false;
}

int main() {
    auto nums = inputArray();
    int pos;
    cin >> pos;
    auto head = createList(nums, pos);
    auto result = hasCycle(head);
    cout << result << endl;
    return 0;
}
