#include <iostream>
#include <string>
using namespace std;

class PlayerNode
{
public:
    string name;
    PlayerNode* next;

    PlayerNode(string playerName)
    {
        name = playerName;
        next = nullptr;
    }
};

class RoundRobin
{
private:
    PlayerNode* head;
    PlayerNode* current;

public:
    RoundRobin()
    {
        head = nullptr;
        current = nullptr;
    }

    void addPlayer(string name)
    {
        PlayerNode* newNode = new PlayerNode(name);

        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
            current = head;
            return;
        }

        PlayerNode* last = head;

        while (last->next != head)
            last = last->next;

        last->next = newNode;
        newNode->next = head;
    }

    void displayPlayers()
    {
        if (head == nullptr)
        {
            cout << "No players" << endl;
            return;
        }

        PlayerNode* temp = head;

        do
        {
            cout << temp->name;

            temp = temp->next;

            if (temp != head)
                cout << " -> ";
        }
        while (temp != head);

        cout << endl;
    }

    void nextTurn()
    {
        if (current == nullptr)
        {
            cout << "No players" << endl;
            return;
        }

        current = current->next;
        cout << current->name << endl;
    }

    void removePlayer(string name)
    {
        if (head == nullptr)
            return;

        PlayerNode* currentNode = head;
        PlayerNode* previous = nullptr;

        do
        {
            if (currentNode->name == name)
                break;

            previous = currentNode;
            currentNode = currentNode->next;
        }
        while (currentNode != head);

        if (currentNode->name != name)
            return;

        if (currentNode == head)
        {
            if (head->next == head)
            {
                delete head;
                head = nullptr;
                current = nullptr;
                return;
            }

            PlayerNode* last = head;

            while (last->next != head)
                last = last->next;

            head = head->next;
            last->next = head;

            if (current == currentNode)
                current = head;

            delete currentNode;
            return;
        }

        previous->next = currentNode->next;

        if (current == currentNode)
            current = currentNode->next;

        delete currentNode;
    }
};

int main()
{
    RoundRobin game;

    game.addPlayer("Ali");
    game.addPlayer("Beena");
    game.addPlayer("Cara");

    cout << "Players: ";
    game.displayPlayers();

    game.nextTurn();
    game.nextTurn();
    game.nextTurn();
    game.nextTurn();

    game.removePlayer("Beena");

    cout << "After removing Beena: ";
    game.displayPlayers();

    game.nextTurn();
    game.nextTurn();
    game.nextTurn();

    return 0;
}
