#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node* next;
    Node* prev;
};

template <typename T>

class Queue
{
private:
    Node<T>* front;
    Node<T>* back;
    int count;

public:
    Queue() : front(nullptr), back(nullptr), count(0) {}

    ~Queue()
    {
        Clear();
    }


    void Enqueue(T data)
    {
        Node<T>* newNode = new Node<T>;
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = back;

        if (IsEmpty())
        {
            front = back = newNode;
        }
        else
        {
            back->next = newNode;
            back = newNode;
        }
        count++;
    }


    void Dequeue()
    {
        if (IsEmpty())
        {
            cout << "Queue is empty, nothing to dequeue." << endl;
            return;
        }

        Node<T>* temp = front;
        front = front->next;

        if (front)
        {
            front->prev = nullptr;
        }
        else
        {
            back = nullptr;
        }

        delete temp;
        count--;
    }


    T Peek() const
    {
        if (IsEmpty())
        {
            throw runtime_error("Queue is empty, nothing to peek.");
        }
        return front->data;
    }

    bool IsEmpty() const
    {
        return front == nullptr;
    }

    void Clear()
    {
        while (!IsEmpty())
        {
            Dequeue();
        }
    }

    int GetCount() const
    {
        return count;
    }
};

int main()
{
    Queue<char> queue;

    queue.Enqueue('H');
    queue.Enqueue('e');
    queue.Enqueue('l');
    queue.Enqueue('l');
    queue.Enqueue('o');

    cout << "Front element of the queue: " << queue.Peek() << endl;
    cout << "Number of elements in the queue: " << queue.GetCount() << endl;

    queue.Dequeue();
    queue.Dequeue();
    cout << "Front element of the queue after dequeuing: " << queue.Peek() << endl;
    cout << "Number of elements in the queue after dequeuing: " << queue.GetCount() << endl;

    queue.Clear();
    cout << "Queue cleared. Is the queue empty? " << (queue.IsEmpty() ? "Yes" : "No") << endl;

    return 0;
}