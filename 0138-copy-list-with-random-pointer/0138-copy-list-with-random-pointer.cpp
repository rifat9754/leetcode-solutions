/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;
        unordered_map<Node*, Node*> m;
        Node* new_head = new Node(head->val);
        m[head] = new_head;
        Node* old_temp = head->next;
        Node* new_temp = new_head;

        while (old_temp != NULL) {
            Node* copy_node = new Node(old_temp->val);
            m[old_temp] = copy_node;
            new_temp->next = copy_node;
            old_temp = old_temp->next;
            new_temp = new_temp->next;
        }

        old_temp = head;
        new_temp = new_head;

        while (old_temp != NULL) {
            new_temp->random = m[old_temp->random];

            old_temp = old_temp->next;
            new_temp = new_temp->next;
        }

        return new_head;
    }
};