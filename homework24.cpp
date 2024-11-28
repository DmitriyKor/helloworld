#include <iostream>
#include <iterator>

using namespace std;

#define MEM_RESERVATION 2
#define MIN_CAPACITY 16

template <class T>
class Container
{
public:
    Container();
    Container(int length);
    Container(const Container<T>& rhs);
    ~Container()
    {
        delete[] mData;
        mCapacity = 0;
        mLength = 0;
        mZeroIndex = 0;
    }
    int GetLength() { return mLength; } // Size()
    void Fill(T value);
    T Front() const;
    T Back() const;
    void PushFront(T value);
    T PopFront();
    T PopBack();
    void PushBack(T value);
    void Insert(T value, int position);
    void DisplayValues();  
    T& operator[](int index){return mData[mZeroIndex+index];}  
    struct Iterator 
    {
        using iterator_category = std::forward_iterator_tag;
        using difference_type   = std::ptrdiff_t;
        using value_type        = T;
        using pointer           = T*;  
        using reference         = T&;  
        Iterator(pointer ptr) : m_ptr(ptr) {}
        reference operator*() const { return *m_ptr; }
        pointer operator->() { return m_ptr; }
        Iterator& operator++() { m_ptr++; return *this; }  
        Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
        friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
        friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };         
    private:
        pointer m_ptr;    
    };   
    Iterator begin() { return Iterator(&mData[mZeroIndex]); }
    Iterator end()   { return Iterator(&mData[mZeroIndex+mLength]); }    
private:
    T *mData;
    int mCapacity;
    int mLength;
    int mZeroIndex;
    void RealocateMemory();
};

template <class T>
Container<T>::Container(int length)
{
    mCapacity = max(MIN_CAPACITY, length * MEM_RESERVATION);
    mData = new T[mCapacity];
    mLength = length;
    // індекс першого елементу
    mZeroIndex = (mCapacity - length) / 2;
    /*перший елемент починається не з початку виділеного масиву.
    так легше додавати дані в початок списку, зменшуючи mZeroIndex. Коли mZeroIndex досягне 0
    або mZeroIndex+mLength досягне mCapacity, тоді виділяємо більший фрагмент пам'яті та переносимо дані */
}

template <class T>
Container<T>::Container()
{
    mCapacity = MIN_CAPACITY;
    mData = new T[mCapacity];
    mLength = 0;
    // індекс першого елементу
    mZeroIndex = mCapacity / 2;
}

template <class T>
Container<T>::Container(const Container<T>& rhs)
{
    mCapacity = rhs.mCapacity;
    mData = new T[mCapacity];
    mLength = rhs.mLength;
    mZeroIndex = rhs.mZeroIndex;
    memcpy(&(mData[mZeroIndex]), &(rhs.mData[rhs.mZeroIndex]), mLength * sizeof(T));
}

template <class T>
void Container<T>::RealocateMemory()
{
    cout << "Realocating memory\n";
    T *oldData = mData;
    int oldZeroIndex = mZeroIndex;
    // рахуємо новий розмір масиву, мінімум 16
    mCapacity = max(MIN_CAPACITY, mLength * MEM_RESERVATION); //Для більших розмірів можна резервувати менше
    // виділяємо нову пам'ять
    mData = new T[mCapacity];
    // вираховуємо новий mZeroIndex так щоб блок даних був посередині
    mZeroIndex = (mCapacity - mLength) / 2;
    // копіюємо дані в нову пам'ять
    memcpy(&(mData[mZeroIndex]), &oldData[oldZeroIndex], mLength * sizeof(T));
    // звільняємо стару пам'ять
    delete[] oldData;
}

template <class T>
void Container<T>::Fill(T value)
{
    for (int i = mZeroIndex; i < mZeroIndex + mLength; i++)
        mData[i] = value;
}

template <class T>
void Container<T>::DisplayValues()
{
    cout << "\nmZeroIndex=" << mZeroIndex << "; mLength=" << mLength << "; mCapacity=" << mCapacity << endl;
    for (int i = mZeroIndex; i < mZeroIndex + mLength; i++)
        cout << mData[i] << " ";
    cout << endl;
}

template <class T>
T Container<T>::Front() const
{
    if (mLength > 0)
        return mData[mZeroIndex];
    else
        return 0;
}

template <class T>
T Container<T>::Back() const
{
    if (mLength > 0)
        return mData[mZeroIndex + mLength];
    else
        return 0;
}

template <class T>
void Container<T>::PushFront(T value)
{
    //зменшуємо mZeroIndex
    mZeroIndex--;
    //зберігаємо дані
    mData[mZeroIndex] = value;
    mLength++;
    //якщо mZeroIndex досяг 0, перевиділяємо пам'ять
    if (mZeroIndex == 0)
        RealocateMemory();
}

template <class T>
T Container<T>::PopFront()
{
    if (mLength > 0)
    {
        //зберігаємо значення
        T tmpValue = mData[mZeroIndex];
        //збільшуємо mZeroIndex
        mZeroIndex++;
        //кількість даних зменшується
        mLength--;
        // якщо даних мало, звільняємо пам'ять. В зворотну сторону звільняємо не так активно
        if (mCapacity / mLength > MEM_RESERVATION * 2)
            RealocateMemory();
        return tmpValue;
    }
    else
        return 0;
}

template <class T>
void Container<T>::Insert(T value, int position)
{
    if (position >= 0 && position <= mLength)
    {
        //якщо є дані, то сдвигаємо їх (в даному варіанті тільки вправо)
        if (mLength>0 && position<mLength)
        {
            //for (int i = mZeroIndex+position; i < mZeroIndex + mLength; i++)
            //    mData[i+1] = mData[i];
            memmove(&mData[mZeroIndex+position+1], &mData[mZeroIndex+position], sizeof(T)*(mLength-position));
        };
        mData[mZeroIndex+position]=value;
        mLength++;
        //перевірка чи дійшли до кінця, чи не пора збільшувати масив
        if (mZeroIndex+mLength==mCapacity)
            RealocateMemory();
    }
}

template <class T>
void Container<T>::PushBack(T value)
{
    //дописуємо дані в кінець, там є запас
    mData[mZeroIndex + mLength] = value;
    mLength++;
    //якщо запасу немає
    if (mZeroIndex + mLength == mCapacity)
        RealocateMemory();
}

template <class T>
T Container<T>::PopBack()
{
    if (mLength > 0)
    {
        T tmpValue = mData[mZeroIndex + mLength];
        mLength--;
        // якщо даних мало, звільняємо пам'ять
        if (mCapacity / mLength > MEM_RESERVATION * 2)
            RealocateMemory();
        return tmpValue;
    }
    else
        return 0;
}

int main()
{
    Container<int> MyIntCont;
    Container<double> MyDoubleCont;

    //Перевірка PushFront
    for (int i = 0; i < 15; i++)
    {
        MyIntCont.PushFront(99 - i);
        MyDoubleCont.PushFront(99 - double(i)/10);
    }
    //Перевірка PushBack
    for (int i = 0; i < 15; i++)
    {
        MyIntCont.PushBack(i + 101);
        MyDoubleCont.PushBack(double(i)/10 + 101);
    }
    MyIntCont.DisplayValues();
    MyDoubleCont.DisplayValues();
    
    //Перевірка PopFront, PopBack
    for (int i = 0; i < 12; i++)
    {
        MyIntCont.PopFront();
        MyIntCont.PopBack();
        MyDoubleCont.PopFront();
        MyDoubleCont.PopBack();        
    }
    MyIntCont.DisplayValues();
    MyDoubleCont.DisplayValues();
    
    //Перевірка Insert
    MyIntCont.Insert(111,5);
    MyDoubleCont.Insert(122.77,4);
    MyIntCont.DisplayValues();
    MyDoubleCont.DisplayValues();
    
    //Перевірка доступу по індексу []
    MyIntCont[4]=300;
    cout << MyIntCont[4] << endl;

    //Перевірка ітератора
    for (auto j : MyDoubleCont)
        cout << j <<" ";    

    return 0;
}