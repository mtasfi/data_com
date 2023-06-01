// Lab 2: Checksum
// Suppose the following block of 16 bits is to be sent using a checksum of 8 (or multiple of 8) bits.
// 10101001 00111001
// Find out the checksum. Add the checksum to the message.
// Enter the data received by the receiver. Determine whether there is any error or not.

//i have only shown how to calculate checksum for 2 blocks of 8bits. with slight modification this code can find checksum for any number of blocks of any size.

#include<bits/stdc++.h>
using namespace std;

string complementAdd(string a, string b) {
	string sum;
	int carry = 0;

	for (int i = 7; i >= 0; i--) {
		if (carry == 0) {
			if (a[i] == '1' and b[i] == '1')sum.push_back('0'), carry = 1;
			else if (a[i] == '1' or b[i] == '1')sum.push_back('1');
			else sum.push_back('0');
		}
		else {
			if (a[i] == '1' and b[i] == '1')sum.push_back('1');
			else if (a[i] == '1' or b[i] == '1')sum.push_back('0');
			else sum.push_back('1'), carry = 0;
		}
	}
	reverse(sum.begin(), sum.end());

	if (carry)return complementAdd(sum, "00000001");
	return sum;
}

string complement(string s) {
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == '1')s[i] = '0';
		else s[i] = '1';
	}
	return s;
}

int main() {

	string a, b;
	cout << "Enter 2 block of 8bit data" << endl;
	cin >> a >> b;

	string checksum = complement(complementAdd(a, b));
	cout << "Sending data with checksum" << endl;
	cout << a << " " << b << " " << checksum << endl;

	cout << "Enter the blocks that receiver received" << endl;
	string x, y, z;
	cin >> x >> y >> z;

	string res = complementAdd(complementAdd(x, y), z);
	int error = 0;
	for (auto c : res)if (c == '0')error = 1;

	if (error)cout << "Received bits are not correct" << endl;
	else cout << "Received bits are correct" << endl;

	return 0;
}
