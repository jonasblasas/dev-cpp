#include <bits/stdc++.h> 

using namespace std;

/*

stack:
 - top
 - pop
 - push
 - empty
*/

struct Queue
{
    stack<int> s1, s2;

    void Enqueue(int value)
    {
        s1.push(value);
    }

    int Dequeue()
    {
        if(s1.empty() and s2.empty())
        {
            throw "Queue is empty";
        }

        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int val = s2.top();
        s2.pop();
        return val;
    }

};

int main() {

    Queue q;
    q.Enqueue(10);
    q.Enqueue(11);
    q.Enqueue(12);

    // Should print 10, 11, 12

    try {
        cout << "dequeue 1: " << q.Dequeue() << endl;
        cout << "dequeue 2: " << q.Dequeue() << endl;
        cout << "dequeue 3: " << q.Dequeue() << endl;

        cout << "dequeue 4: " << q.Dequeue() << endl;
    } catch (const char* msg) {
        cerr << "dequeue error: " << msg << endl;
    }

    cout << "program exit" << endl;
    return 0;
}