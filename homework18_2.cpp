#include <iostream>
#include <cstring>

using namespace std;

class String
{
public:
    // конструктори
    String();
    String(const char *const);
    String(const String &);
    ~String();
    // Перевантажені оператори
    char &operator[](int offset);
    char operator[](int offset) const;
    String operator+(const String &);
    void operator+=(const String &);
    String &operator=(const String &);
    // Загальні методи доступу
    int GetLen() const { return itsLen; }
    const char *GetString() const { return itsString; }
    // Статичний цілочисельний лічильник ConstructorCount;
private:
    String(int); // закритий конструктор
    char *itsString;
    unsigned short itsLen;
};

// конструктор класу String за замовчуванням створює рядок завдовжки 0 байт
String::String()
{
    itsString = new char[1];
    itsString[0] = '\0';
    itsLen = 0;
    // cout «"I tDefault string constructorl n";
    // ConstructorCount++;
}

// закритий конструктор, який використовується тільки
// методами класу до створення нового рядка
// Вказаного розміру, заповненого нулями
String::String(int len)
{
    itsString = new char[len + 1];
    for (int i = 0; i <= len; i++)
   	 itsString[i] = '\0';
    itsLen = len;
    // cout << "\tString(int) constructor\n";
    // ConstructorCount++;
}

// Перетворює масив символів у рядок
String::String(const char *const cString)
{
    itsLen = strlen(cString);
    itsString = new char[itsLen + 1];
    for (int i = 0; i < itsLen; i++)
   	 itsString[i] = cString[i];
    itsString[itsLen] = '\0';
    // cout << "\tString(char*) constructor\n";
    // ConstructorCount++;
}

// Конструктор-копіювальник
String::String(const String &rhs)
{
    itsLen = rhs.GetLen();
    itsString = new char[itsLen + 1];
    for (int i = 0; i < itsLen; i++)
   	 itsString[i] = rhs[i];
    itsString[itsLen] = '\0';
    // cout << "\tString(String&) constructor\n";
    // ConstructorCount++;
}

// Деструктор звільняє зайняту пам'ять
String::~String()
{
    delete[] itsString;
    itsLen = 0;
    // cout <<"\tString destructor\n";
}

// Цей оператор звільняє пам'ять, та був
// копіює рядок і розмір
String &String::operator=(const String &rhs)
{
    if (this == &rhs)
   	 return *this;
    delete[] itsString;
    itsLen = rhs.GetLen();
    itsString = new char[itsLen + 1];
    for (int i = 0; i < itsLen; i++)
   	 itsString[i] = rhs[i];
    itsString[itsLen] = '\0';
    return *this;
    // cout <<"\tString operator=\n";
}

// Неконстантний оператор індексування.
// Повертає посилання символ, який можна
// Змінити
char &String::operator[](int offset)
{
    if (offset > itsLen)
   	 return itsString[itsLen - 1];
    else
   	 return itsString[offset];
}

// Константний оператор індексування,
// використовується для константних об'єктів (див. конструктор-копіювальник! )
char String::operator[](int offset) const
{
    if (offset > itsLen)
   	 return itsString[itsLen - 1];
    else
   	 return itsString[offset];
}

// створює новий рядок, додаючи поточний
// Рядок до rhs
String String::operator+(const String &rhs)
{
    int totalLen = itsLen + rhs.GetLen();
    String temp(totalLen);
    int i, j;
    for (i = 0; i < itsLen; i++)
   	 temp[i] = itsString[i];
    for (j = 0; j < rhs.GetLen(); j++, i++)
   	 temp[i] = rhs[j];
    temp[totalLen] = '\0';
    return temp;
}

// змінює поточний рядок, нічого не повертаючи
void String::operator+=(const String &rhs)
{
    unsigned short rhsLen = rhs.GetLen();
    unsigned short totalLen = itsLen + rhsLen;
    String temp(totalLen);
    int i, j;
    for (i = 0; i < itsLen; i++)
   	 temp[i] = itsString[i];
    for (j = 0; j < rhs.GetLen(); j++, i++)
   	 temp[i] = rhs[i - itsLen];
    temp[totalLen] = '\0';
    *this = temp;
}

// int String: ConstructorCount = 0;

