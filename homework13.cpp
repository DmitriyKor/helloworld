#include <iostream>

using namespace std;

const int FIELD_SIZE = 3;
enum FIELDVALUE
{
    NOTHING,
    CROSS,
    ZERO
};

class GameField
{
private:
    FIELDVALUE mField[FIELD_SIZE][FIELD_SIZE];

public:
    void ResetField();
    void DisplayField();
    void MakeMove(int row, int col, FIELDVALUE value) { mField[row][col] = value; };
    FIELDVALUE CheckVictory();
};

string GetSymbol(FIELDVALUE value)
{
    switch (value)
    {
    case FIELDVALUE::ZERO:
        return "0";
    case FIELDVALUE::CROSS:
        return "X";
    default:
        return "_";
    }
}

int main()
{
    GameField *Fld = new GameField;
    FIELDVALUE res;

    Fld->ResetField();
    cout << "Field view:\n";
    Fld->DisplayField();

    Fld->MakeMove(1, 1, FIELDVALUE::CROSS);
    Fld->MakeMove(0, 0, FIELDVALUE::CROSS);
    Fld->MakeMove(2, 2, FIELDVALUE::CROSS);
    Fld->DisplayField();

    res = Fld->CheckVictory();
    if (res != FIELDVALUE::NOTHING)
        cout << "Winner is " << GetSymbol(res);

    return 0;
}

void GameField::ResetField()
{
    for (int row = 0; row < FIELD_SIZE; row++)
    {
        for (int col = 0; col < FIELD_SIZE; col++)
        {
            mField[row][col] = FIELDVALUE::NOTHING;
        }
    }
}

void GameField::DisplayField()
{
    char symbol;
    for (int row = 0; row < FIELD_SIZE; row++)
    {
        for (int col = 0; col < FIELD_SIZE; col++)
        {
            cout << GetSymbol(mField[row][col]) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

FIELDVALUE GameField::CheckVictory()
{
    for (int row = 0; row < FIELD_SIZE; row++)
    {
        if (mField[row][0] == mField[row][1] && mField[row][0] == mField[row][2] && mField[row][0] != FIELDVALUE::NOTHING)
        {
            return mField[row][0];
        }
    }

    for (int col = 0; col < FIELD_SIZE; col++)
    {
        if (mField[0][col] == mField[1][col] && mField[0][col] == mField[2][col] && mField[0][col] != FIELDVALUE::NOTHING)
        {
            return mField[0][col];
        }
    }

    if (mField[0][0]!=FIELDVALUE::NOTHING
    && mField[0][0]==mField[1][1]
    && mField[0][0]==mField[2][2])
    {
        return mField[0][0];
    }

    if (mField[0][2]!=FIELDVALUE::NOTHING
    && mField[0][2]==mField[1][1]
    && mField[0][2]==mField[2][0])
    {
        return mField[0][2];
    }

    return FIELDVALUE::NOTHING;
}