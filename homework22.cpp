#include <iostream>

using namespace std;

class List
{
public:
	List() : head(0), tail(0), theCount(0) {}
	virtual ~List();
	void insert(int value);
	void append(int value);
	int is_present(int value) const;
	int is_empty() const
	{
    	return head == 0;
	}
	int count() const { return theCount; }
    void display() const;
private:
	class ListCell
	{
	public:
    	ListCell(int value, ListCell *cell = 0) : val(value),
                                              	next(cell) {}
    	int val;
    	ListCell *next;
	};
	int val;
	ListCell *next;
	ListCell *head;
	ListCell *tail;
	int theCount;
};

void List::insert(int value)
{
    head = new ListCell (value, head);
    theCount++;
    if (theCount==1)
        tail = head;
}

void List::append(int value)
{
    if (tail==0)
    {
        tail = new ListCell(value, 0);
        head = tail;
    }   
    else 
    {
        tail->next = new ListCell(value, 0); 
        tail = tail->next; 
    }; 
    theCount++;
}

int List::is_present(int value) const
{
    ListCell *cell = head;    
    while (cell!=0)
    {
        if (cell->val==value) return 1;
        cell = cell->next;
    }  
    return 0;  
}

void List::display() const
{
    cout << "\ncontent of the list:\n";
    ListCell *cell = head;    
    while (cell!=0)
    {
        cout << cell->val <<" -> ";
        cell = cell->next;
    }  
    cout << endl;
}

List::~List()
{
    ListCell *cell;
    next = head;    
    while (next!=0)
    {
        cell = next;
        next = next->next;
        delete cell;
    }
    head = 0;
    tail = 0;
    theCount = 0;
}



int main()
{
    List * MyList = new List;
    MyList->insert(5);
    MyList->insert(3);
    MyList->append(20);
    MyList->insert(2);
    MyList->display();


    delete MyList;
    return 0;
}