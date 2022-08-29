#pragma once
#include "CMyData.h"
class CMyDataEx :
    public CMyData
{
public:
    CMyDataEx() {
        cout << "CMyDataEx()" << endl;
    }

    void TestFunc() {
        PrintData();
        SetData(5);
        cout << CMyData::GetData() << endl;
    }
};



