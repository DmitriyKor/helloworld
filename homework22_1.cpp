#include <iostream>

using namespace std;


template <typename T>
class List;

template <typename T>
class ListCell
{
public:
   	friend class List<T>;
    ListCell(T value, ListCell *cell = 0) : val(value),	next(cell) {}
   	T val;
   	ListCell *next;
};


template <typename T>
class List
{
public:
	List() : head(0), tail(0), theCount(0) {}
	virtual ~List();
	void insert(T value);
	void append(T value);
	int is_present(T value) const;
	int is_empty() const
	{
    	return head == 0;
	}
	int count() const { return theCount; }
    void display() const;
    template <typename U> friend bool operator==(const List<U> & rList1, const List<U> & rList2);
private:
	T val;
	ListCell<T> *next;
	ListCell<T> *head;
	ListCell<T> *tail;
	int theCount;
};

class Cat
{
public:
    Cat() : mWeight(0){};
    Cat(float weight) : mWeight(weight) {};
    ~Cat(){};
    friend ostream& operator<<(ostream &os, const Cat & rCat);
private:
    float mWeight;
};

ostream& operator<<(ostream &os, const Cat & rCat)
{
    os << "weight " << rCat.mWeight;
    return os;
}

template <typename U>
bool operator==(const List<U> &rList1, const List<U> &rList2)
{
    cout << "\n== operator\n";
    if (rList1.theCount!=rList2.theCount) 
    {
        cout << "Length different";
        return false;
    };  
    cout << "Length the same";

    if (rList1.theCount==0)
        return true;
    ListCell<U> *cell1 = rList1.head;    
    ListCell<U> *cell2 = rList2.head;    
    cout << "/ncheck1/n";
    while (cell1!=0)
    {
        if (cell1->val!=cell2->val) 
        {
            return false;
        }
        cell1 = cell1->next;
        cell2 = cell2->next;
    }  
    return true;
}


template <typename T>
void List<T>::insert(T value)
{
    head = new ListCell (value, head);
    theCount++;
    if (theCount==1)
        tail = head;
}

template <typename T>
void List<T>::append(T value)
{
    if (tail==0)
    {
        tail = new ListCell<T>(value, 0);
        head = tail;
    }   
    else 
    {
        tail->next = new ListCell<T>(value, 0); 
        tail = tail->next; 
    }; 
    theCount++;
}

template <typename T>
int List<T>::is_present(T value) const
{
    ListCell<T> *cell = head;    
    //cout << "\nValue is "<<value << endl;
    while (cell!=0)
    {
        if (cell->val==value) 
        {
            //cout << "\nCell value is "<<cell->val <<endl;
            return 1;
        }
        cell = cell->next;
    }  
    return 0;  
}

template <typename T>
void List<T>::display() const
{
    //cout << "type of the list: " << typeid(T).name() << endl;
    cout << "\ncontent of the list:\n";
    ListCell<T> *cell = head;    
    while (cell!=0)
    {
        cout << cell->val <<" -> ";
        cell = cell->next;
    }  
    cout << endl;
}
template <typename T>
List<T>::~List()
{
    ListCell<T> *cell;
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
    List<string> * MyStringList = new List<string>;
    MyStringList->insert("Hello");
    MyStringList->append("Very");
    MyStringList->insert("Low");
    MyStringList->display();  
    cout << "'High' is " << (MyStringList->is_present("High") ? "" : "not ") << "present\n";
    cout << "'Low' is " << (MyStringList->is_present("Low") ? "" : "not ") << "present\n";



    List<int> * MyIntList = new List<int>;
    MyIntList->insert(10);
    MyIntList->insert(8);
    MyIntList->append(20);
    MyIntList->insert(3);
    MyIntList->display();   
    
    Cat *MyCat;
    List<Cat> * MyCatList = new List<Cat>;
    MyCat = new Cat(3.3);
    MyCatList->insert(*MyCat);
    MyCat = new Cat(5.3);
    MyCatList->insert(*MyCat);
    MyCatList->display();


    List<int> * MyIntList2 = new List<int>;
    MyIntList2->insert(10);
    MyIntList2->insert(8);
    MyIntList2->append(20);
    MyIntList2->insert(3);
    bool equals = (MyIntList == MyIntList2);


    delete MyStringList;
    delete MyIntList;
    delete MyCatList;
    return 0;
}