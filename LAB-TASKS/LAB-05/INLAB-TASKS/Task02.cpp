#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string url;
    Node* next;

    Node(string u)
    {
        url = u;
        next = nullptr;
    }
};

class BrowserHistory
{
private:
    Node* top;

public:
    BrowserHistory()
    {
        top = nullptr;
    }

    void visit(string url)
    {
        Node* newNode = new Node(url);
        newNode->next = top;
        top = newNode;

        cout << "Now at: " << url << endl;
    }

    void goBack()
    {
        if (top == nullptr || top->next == nullptr)
        {
            cout << "No previous page in history" << endl;
            return;
        }

        Node* temp = top;
        top = top->next;
        delete temp;

        cout << "Back to: " << top->url << endl;
    }

    string currentPage()
    {
        if (top != nullptr)
        {
            return top->url;
        }

        return "";
    }
};

int main()
{
    BrowserHistory browser;

    browser.visit("google.com");
    browser.visit("github.com");
    browser.visit("docs.com");

    browser.goBack();
    browser.goBack();
    browser.goBack();

    return 0;
}
