#pragma once
#include <iostream>

using namespace std;

class CMyData
{
public:
	CMyData() {
		cout << "CMyData" << endl;
	}
	int GetData() {
		return m_nData;
	}
	void SetData(int nParam) {
		m_nData = nParam;
	}

protected:
	void PrintData() {
		cout << "CMyData::PrintData()" << endl;
	}

private:
	int m_nData = 0;

};

