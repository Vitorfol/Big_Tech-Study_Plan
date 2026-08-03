class MyQueue {

private:
    stack<int> store;

public:
    MyQueue() {}
    
    void push(int x) {
        this->store.push(x);
    }
    
    int pop() {
        if (this->empty()) return -1;
        stack<int> aux;
        while(this->store.size() > 1) {
            int curr = this->store.top();
            this->store.pop();
            aux.push(curr);
        }

        int front = this->store.top();
        this->store.pop();
        while(!aux.empty()) {
            int curr = aux.top();
            aux.pop();
            store.push(curr);
        }

        return front;
    }
    
    int peek() {
        if (this->empty()) return -1;
        stack<int> aux;
        while(store.size() > 1) {
            int curr = store.top();
            this->store.pop();
            aux.push(curr);
        }

        int front = this->store.top();
        while(!aux.empty()) {
            int curr = aux.top();
            aux.pop();
            store.push(curr);
        }

        return front;
    }
    
    bool empty() {
        return this->store.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
