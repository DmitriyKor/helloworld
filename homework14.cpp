#include <iostream>

using namespace std;

class Node
{
private:
    Node *mNext; 
    int mData;
public:
    Node(Node *NextNode, int Data) {mNext=NextNode; mData=Data;};
    ~Node(){mNext=nullptr;};
    Node *GetNext() const {return mNext;};
    void SetNext(Node *NextNode) {mNext=NextNode;};
    int GetData() const {return mData;};
};



int main()
{
    Node *pFirst = new Node(nullptr, 66);
    pFirst->SetNext(new Node(nullptr, 77));
    pFirst->GetNext()->SetNext(new Node(nullptr, 88));
    
    cout << pFirst->GetData() << endl;
    cout << pFirst->GetNext()->GetData() << endl;
    cout << pFirst->GetNext()->GetNext()->GetData() << endl;

    Node *pInsertedNode = new Node(pFirst->GetNext(), 71);
    pFirst->SetNext(pInsertedNode);

    cout << pFirst->GetData() << endl;
    cout << pFirst->GetNext()->GetData() << endl;
    cout << pFirst->GetNext()->GetNext()->GetData() << endl;
    cout << pFirst->GetNext()->GetNext()->GetNext()->GetData() << endl;    

    return 0;
}