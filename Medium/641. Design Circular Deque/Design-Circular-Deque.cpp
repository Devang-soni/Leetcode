/*
Design your implementation of the circular double-ended queue (deque).

Implement the MyCircularDeque class:

MyCircularDeque(int k) Initializes the deque with a maximum size of k.
boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
boolean isEmpty() Returns true if the deque is empty, or false otherwise.
boolean isFull() Returns true if the deque is full, or false otherwise.
 

Example 1:

Input
["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 2, true, true, true, 4]

Explanation
MyCircularDeque myCircularDeque = new MyCircularDeque(3);
myCircularDeque.insertLast(1);  // return True
myCircularDeque.insertLast(2);  // return True
myCircularDeque.insertFront(3); // return True
myCircularDeque.insertFront(4); // return False, the queue is full.
myCircularDeque.getRear();      // return 2
myCircularDeque.isFull();       // return True
myCircularDeque.deleteLast();   // return True
myCircularDeque.insertFront(4); // return True
myCircularDeque.getFront();     // return 4
 
*/

class MyCircularDeque {
private:
    vector<int> deq;
    int front;
    int last;
    int size;
    int capacity;

public:
    MyCircularDeque(int k) {
        deq = vector<int>(k);   // Replace queue with deq
        size = 0;
        capacity = k;
        front = 0;
        last = k - 1;           // Replace rear with last
    }

    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + capacity) % capacity;
        deq[front] = value;     // Replace queue with deq
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        last = (last + 1) % capacity;  // Replace rear with last
        deq[last] = value;             // Replace queue with deq
        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        last = (last - 1 + capacity) % capacity;  // Replace rear with last
        size--;
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return deq[front];   // Replace queue with deq
    }

    int getRear() {
        if (isEmpty()) return -1;
        return deq[last];    // Replace queue with deq and rear with last
    }

    bool isEmpty() { return size == 0; }

    bool isFull() { return size == capacity; }
};

