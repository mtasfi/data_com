#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

string tobin(int n) {
	string bin;
	while (n) {
		bin.push_back(n % 2 + '0');
		n = n / 2;
	}
	reverse(bin.begin(), bin.end());
	return bin;
}

string addparity(string s) {
	int one = 0;
	for (auto it : s)if (it == '1')one++;
	s.push_back(one % 2 + '0');
	return s;
}

int haserror(string s) {
	int one = 0;
	for (auto it : s)if (it == '1')one++;
	return one % 2;
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
	string word;
	cin >> word;
	int n = word.length();

	string data[n];
	for (int i = 0; i < n; ++i)
	{
		data[i] = tobin(word[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		data[i] = addparity(data[i]);
	}
	sending();
	for (auto it : data)cout << it << " ";

	cout << endl << endl;
	cout << "Enter received bits" << endl;

	string recv[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> recv[i];
	}
	int error = 0;
	for (auto it : recv)error += haserror(it);

	if (error) {
		system("Color 0C");
		cout << "Error Detected!" << endl;
	}
	else {
		system("Color 0A");
		cout << "No Error!" << endl;
	}

	return 0;
}
