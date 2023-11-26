#include "Ejercicio01.h"
#include <queue>

using namespace std;

struct compare {
    bool operator()(const Node<int>* a, const Node<int>* b) {
        return a->value < b->value;
    }
};


Node<int>* Ejercicio01::mergeLists(Node<Node<int>*>* lists)
{
   priority_queue<Node<int>*,vector<Node<int>*>, compare> pq;

    Node<int>* dummy = new Node<int>(0);
    Node<int>* tail = dummy;

    for (Node<Node<int>*>* list = lists; list != nullptr; list = list->next) {
        if (list->value != nullptr) {
            pq.push(list->value);
        }
    }

    while (!pq.empty()) {
        tail->next = pq.top();
        pq.pop();
        tail = tail->next;

        if (tail->next != nullptr) {
            pq.push(tail->next);
        }
    }

    Node<int>* head = dummy->next;
    delete dummy;
    return head;
}
