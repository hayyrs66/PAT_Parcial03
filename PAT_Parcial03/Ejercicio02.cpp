#include "Ejercicio02.h"
#include <unordered_map>
#include <vector>

using namespace std;

vector<string>* Ejercicio02::findRepeatedDnaSequences(Node<char>* head)
{
    unordered_map<string, int> map;
    vector<string>* result = new vector<string>();
    string sequence;
    Node<char>* current = head;


    for (int i = 0; i < 10 && current != nullptr; ++i) {
        sequence.push_back(current->value);
        current = current->next;
    }

    if (sequence.size() < 10) {
        return result;
    }

    ++map[sequence];

    while (current != nullptr) {
        sequence.erase(sequence.begin());

        sequence.push_back(current->value);

        ++map[sequence];

        if (map[sequence] == 2) {
            result->push_back(sequence);
        }

        current = current->next;
    }

    return result;
}
