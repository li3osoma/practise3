#include <iostream>
#include "Test.h"
using namespace std;

int main() {
	string textfile, binfile;
	cout << "Cinfirming text file to binary file" << endl;
	cout << "Text file name (without .txt): ";
	cin >> textfile;
	cout << "Binary file name (without .txt): ";
	cin >> binfile;
	int res = fromTextToBin(textfile + ".txt", binfile + ".txt");
	if (res == 1) cout << "can't find the file or files" << endl;
	else {
		cout << "Confirming is finished" << endl << endl;
		testAll();
	}
	return 0;
}