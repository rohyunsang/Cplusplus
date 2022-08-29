#include "CMyDataEx.h"

int main() {

	CMyDataEx data;

	data.SetData(10);
	cout << data.GetData() << endl;

	data.TestFunc();

	return 0;
}
