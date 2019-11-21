class MyCircularDeque {
public:
    int size;
    int cnt;

    struct node {
        int data;
        struct node *next;
        struct node *prev;
        node (int data, struct node *next = NULL, struct node *prev = NULL) {
            this->data = data;
            this->next = next;
            this->prev = prev;
        }
    };

    struct node *front;
    struct node *last;

    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        size = k;
        cnt = 0;
        front = NULL;
        last = NULL;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }

        auto n = new node(value);

        if (isEmpty()) {
            front = n;
            last = n;
        } else {
            n->next = front;
            front->prev = n;
            front = n;
        }
        cnt += 1;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }

        auto n = new node(value);

        if (isEmpty()) {
            front = n;
            last = n;
        } else {
            last->next = n;
            n->prev = last;
            last = n;
        }
        cnt += 1;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }

        auto t = front;
        if (front == last) {
            front = NULL;
            last = NULL;
        } else {
            auto n = front->next;
            n->prev = NULL;
            front = n;
        }
        cnt -= 1;
        delete t;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }

        auto t = last;
        if (front == last) {
            front = NULL;
            last = NULL;
        } else {
            auto n = last->prev;
            n->next = NULL;
            last = n;
        }
        cnt -= 1;
        delete t;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return front->data;
    }

    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return last->data;
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return cnt == 0;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return cnt == size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
