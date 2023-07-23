#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

int tonum(string s) {
	int num = 0;
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == '1')num += pow(2, i);
	}
	return num;
}

string gethamming(string data) {
	int n = data.length();
	int r = 0;
	while (pow (2, r) < n + r + 1) {
		r++;
	}
	string hamming;
	hamming.push_back('0');
	int pos = 0;
	for (int i = 1; i <= n + r; ++i)
	{
		if (pow(2, (int)log2(i)) == i)hamming.push_back('0');
		else {
			hamming.push_back(data[pos]);
			pos++;
		}
	}

	for (int i = 1; i < hamming.length(); i *= 2)
	{
		int one = 0;
		for (int j = i; j < hamming.length(); j += 2 * i) {
			for (int k = j; k < j + i; k++) {
				if (k >= hamming.length())break;
				if (hamming[k] == '1')one++;
			}
		}
		if (one % 2)hamming[i] = '1';
		else hamming[i] = '0';
	}
	hamming.erase(0, 1);
	return hamming;
}
int errorfinder(string hamming) {
	hamming = "0" + hamming;
	string error;

	for (int i = 1; i < hamming.length(); i *= 2)
	{
		int one = 0;
		for (int j = i; j < hamming.length(); j += 2 * i) {
			for (int k = j; k < j + i; k++) {
				if (k >= hamming.length())break;
				if (hamming[k] == '1')one++;
			}
		}
		if (one % 2)error.push_back('1');
		else error.push_back('0');
	}

	return tonum(error);

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
	string data;
	cout << "Enter the data bits" << endl;
	cin >> data;

	string hamming = gethamming(data);

	cout << "Hamming code: ";
	cout << hamming << endl << endl;
	sending();

	cout << "enter received data" << endl;
	string recv;
	cin >> recv;

	int error = errorfinder(recv);

	if (error == 0) {
		system("Color 0a");
		cout << "Correct!" << endl;
	}
	else {
		system("Color 0c");
		cout << "Error detected at position " << error << endl;
		if (recv[error - 1] == '1')recv[error - 1] = '0';
		else recv[error - 1] = '1';
		cout << "Corrected code: " << endl;
		cout << recv << endl;
	}

}
