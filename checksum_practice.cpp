#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

string getsum(string a , string b) {
	int n = a.length();
	string result;
	int carry = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		if (carry) {
			if (a[i] == '0' and b[i] == '0')result.push_back('1'), carry = 0;
			if (a[i] == '0' and b[i] == '1')result.push_back('0'), carry = 1;
			if (a[i] == '1' and b[i] == '0')result.push_back('0'), carry = 1;
			if (a[i] == '1' and b[i] == '1')result.push_back('1'), carry = 1;
		}
		else {
			if (a[i] == '0' and b[i] == '0')result.push_back('0'), carry = 0;
			if (a[i] == '0' and b[i] == '1')result.push_back('1'), carry = 0;
			if (a[i] == '1' and b[i] == '0')result.push_back('1'), carry = 0;
			if (a[i] == '1' and b[i] == '1')result.push_back('0'), carry = 1;
		}
	}
	reverse(result.begin(), result.end());
	if (carry)result = getsum(result, "00000001");

	return result;
}

string complement(string s) {
	string comp = s;
	for (int i = 0; i < s.length(); ++i)
	{
		if (comp[i] == '1')comp[i] = '0';
		else comp[i] = '1';
	}
	return comp;
}

void sending() {
	cout << "\n\nSending Data ";
	for (int i = 0; i < 30; ++i)
	{
		// system("Color 0C");
		cout << (char)219;
		Sleep(80);
	}
	cout << endl;
}

int main() {
	string block1, block2;
	cout << "Enter Data Bits" << endl;
	cin >> block1 >> block2;

	string checksum = complement(getsum(block1, block2));

	sending();
	cout << block1 << " " << block2 << " " << checksum << endl << endl;

	cout << "Enter Received Data" << endl;
	string rcv[3];
	cin >> rcv[0] >> rcv[1] >> rcv[2];

	string result = getsum(rcv[2], getsum(rcv[1], rcv[0]));
	int error = 0;
	for (auto it : result)if (it == '0')error = 1;
	cout << endl;

	if (error) {
		system("Color 0c");
		cout << "Error Detected!" << endl;
	}
	else {
		system("Color 0a");
		cout << "No Error!" << endl;
	}

}
