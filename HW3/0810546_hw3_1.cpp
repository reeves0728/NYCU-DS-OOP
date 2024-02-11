#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int cmd[1000], x[1000];

bool testStack(int n) {
    stack<int> Stack;
    for(int i = 0; i < n; i++) {
        if(cmd[i] == 1) {
            Stack.push(x[i]);
        } else {
            if(Stack.empty() || Stack.top() != x[i])
                return false;
            Stack.pop();
        }
    }
    return true;
}

bool testQueue(int n) {
    queue<int> Queue;
    for(int i = 0; i < n; i++) {
        if(cmd[i] == 1)
            Queue.push(x[i]);
        else {
            if(Queue.empty() || Queue.front() != x[i])
                return false;
            Queue.pop();
        }
    }
    return true;
}

bool testPriorityQueue(int n) {
    priority_queue<int> Heap;
    for(int i = 0; i < n; i++) {
        if(cmd[i] == 1) {
            Heap.push(x[i]);
        } else {
            if(Heap.empty() || Heap.top() != x[i])
                return false;
            Heap.pop();
        }
    }
    return true;
}

int main() {
    int n, i;
    while(cin >> n) {
        for(i = 0; i < n; i++) 
            cin >> cmd[i] >> x[i];

        int flag = 0, ans;
        if(testStack(n)) {
            ans = 1;
            flag++;
        }
        if(testQueue(n)) {
            ans = 2;
            flag++;
        }
        if(testPriorityQueue(n)) {
            ans = 3;
            flag++;
        }
        if(flag == 0) {
            cout << "impossible\n";
        } else if(flag == 1) {
            if(ans == 1) 
                cout << "stack\n";
            else if(ans == 2) 
                cout << "queue\n";
            else 
                cout << "priority queue\n";
        } else {
            cout << "not sure\n";
        }
    }
    return 0;
}
