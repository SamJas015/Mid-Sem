#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    queue<string> ticket;
    int maxSize = 5;

    ticket.push("Sam");
    ticket.push("yovan");
    ticket.push("gaint");
    ticket.push("jennet");
    ticket.push("anto");

    // Check if queue is full
    if (ticket.size() == maxSize)
    {
        cout << "Queue is full!" << endl;
    }

    // Add another person only if queue is not full
    if (ticket.size() < maxSize)
    {
        ticket.push("John");
        cout << "John added to the queue." << endl;
    }
    else
    {
        cout << "Cannot add John. Queue is full!" << endl;
    }

    cout << "Ticket given to: " << ticket.front() << endl;
    ticket.pop();

    cout << "Waiting people:" << endl;

    while (!ticket.empty())
    {
        cout << ticket.front() << endl;
        ticket.pop();
    }

    return 0;
}





