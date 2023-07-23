#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

string getxor(string a, string b) {
	int n = a.length();
	string result;

	for (int i = 0; i < n; ++i)
	{
		if (a[i] == b[i])result.push_back('0');
		else result.push_back('1');
	}
	return result;
}
string getcrc(string data, string generator) {
	int n = data.length();
	int l = generator.length();

	for (int i = 1; i < l; ++i)
	{
		data.push_back('0');
	}
	string a, zero;
	for (int i = 0; i < l; ++i)
	{
		a.push_back(data[i]);
		zero.push_back('0');
	}
	string crc = getxor(a, generator);

	for (int i = l; i < data.length(); ++i)
	{
		crc.erase(0, 1);
		crc.push_back(data[i]);
		if (crc[0] == '1')crc = getxor(crc, generator);
		else crc = getxor(crc, zero);

	}
	crc.erase(0, 1);
	return crc;
}

void sending() {
	cout << endl << endl << "Sending ";
	for (int i = 0; i < 30; ++i)
	{
		cout << (char)219;
		Sleep(80);
	}
	cout << endl;
}

int main() {
	cout << "Enter the Data bits" << endl;
	string data;
	cin >> data;
	string generator;
	cout << "Enter the generator" << endl;
	cin >> generator;

	string crc = getcrc(data, generator);

	cout << endl << "crc = " << crc << endl;

	sending();
	cout << data << crc << endl << endl;

	cout << "Enter the received bits" << endl;
	string received;
	cin >> received;

	string result = getcrc(received, generator);
	int error = 0;
	for (auto it : result)if (it == '1')error = 1;

	if (error) {
		system("Color 0c");
		cout << "Error Detected!" << endl;
	}
	else {
		system("Color 0a");
		cout << "No Error!" << endl;
	}

}
