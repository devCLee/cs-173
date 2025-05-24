#include <iostream>
#include <stack>
#include <queue>
using namespace std;

const int SIZE = 5;

int main(){

    stack<int> s; // use the default constructor for STL's stack
    queue<int> q; // use the default constructor for STL's queue
    priority_queue<int> pq; // use the default constructor for STL's priority queue

    int values[SIZE] = {27,43,21,-5,18};

    // Add to stack and queue
    for (int i = 0; i < 5; i++){
        s.push(values[i]); // push onto stack
        q.push(values[i]); // enqueue onto queue
        pq.push(values[i]); // add to priority queue
    }

    // Remove things from the stack
    cout << "Items on the stack:" << endl;
    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }

    // Remove things from the queue (dequeue)
    cout << "Items in the queue:" << endl;
    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }

    // Remove things from the priority queue
    cout << "Items in the priority queue:" << endl;
    while(!pq.empty()){
        cout << pq.top() << endl;
        pq.pop();
    }

    return 0;
}