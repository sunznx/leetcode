// CreateTime: 2019-12-03 00:05:04
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node *copyRandomList(Node *head) {
        unordered_map<Node*, Node*> hmap;


        Node *newHead = NULL;
        Node *last = NULL;

        Node *p = NULL;
        Node *q = NULL;

        p = head;
        while (p != NULL) {
            Node *t = (Node *) malloc (sizeof(Node));
            t->val = p->val;
            t->next = NULL;
            hmap.insert({p, t});

            if (newHead == NULL) {
                newHead = t;
            } else {
                last->next = t;
            }

            last = t;
            p = p->next;
        }

        p = head;
        q = newHead;
        while (p != NULL) {
            q->random = hmap[p->random];
            p = p->next;
            q = q->next;
        }

        return newHead;
    }
};
