// Lab 1: Vertical Redundancy Check
// Suppose the sender wans to send the word world. In ASCII the five characters (number of characters should be variable) are coded (with even parity) as,
// 1110111 1101111 1110010 1101100 1100100
// Find out the bits sent.
// Enter the character that the receiver has received.
// Show the result. Determine whether the receiver has detected the errors or not.

//didn't understand the question at all....



#include<bits/stdc++.h>
using namespace std;

void toAscii(string code[], int n, string word) {
	for (int i = 0; i < n; ++i)
	{
		int c = word[i];

		string bin;
		while (c) {
			bin.push_back(c % 2 + '0');
			c /= 2;
		}
		reverse(bin.begin(), bin.end());

		//adding parity bit
		int one = 0;
		for (auto c : bin)if (c == 1)one++;
		bin.push_back(one % 2 + '0');
		//

		code[i] = bin;
	}
}

int main() {
	cout << "Enter the number of characters :";
	int n;
	cin >> n;

	string code[n];
	string word;

	cout << "Enter the word :";
	cin >> word;

	toAscii(code, n, word);

	cout << "Sending 8bit data with even parity" << endl;
	for (auto s : code)cout << s << " ";
	cout << endl;

	// receiver side
	int m;
	cout << "Enter the number of characters receiver has received :";
	cin >> m;

	string recv[m];
	cout << "Enter bits that receiver received" << endl;

	for (int i = 0; i < m; ++i)
	{
		cin >> recv[i];
	}

	int error = 0;

	for (int i = 0; i < m; ++i)
	{
		int one = 0;
		for (auto c : recv[i])if (c == 1)one++; //checking is it in even  parity
		if (one % 2)error = 1;
	}

	if (error)cout << "Received bits are not correct" << endl;
	else cout << "Received bits are correct" << endl;




}
