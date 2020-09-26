#include<iostream>
#include <fstream>
#include<vector>
#include<algorithm>

using namespace std;

unsigned int num_of_bits, num_of_minterms;
unsigned int max_num;
unsigned int minterm_10;

struct number
{
	vector<unsigned int>bits;
	unsigned int num_of_ones;
};

void Display_1D_Vector(const number& v)
{
	for (int i = 0; i < v.bits.size(); i++)
		cout << v.bits[i];
	cout << endl;

}
number Convert_10_T0_2(unsigned int num)
{
	number remainders;
	remainders.num_of_ones = 0;
	if (num == 0)
	{
		remainders.bits.push_back(0);

	}
	else
	{
		unsigned int remainder;
		while (num != 0)
		{
			remainder = num % 2;
			remainders.bits.push_back(remainder);
			remainders.num_of_ones += remainder;
			num /= 2;
		}
	}
	while (remainders.bits.size() < num_of_bits)

		remainders.bits.push_back(0);

	reverse(remainders.bits.begin(), remainders.bits.end());

	return remainders;
}
int main()
{
	cout << "How many minterms will you enter?";
	cin >> num_of_minterms;
	cout << endl;
	cout << "How many bits will each minterm have?";
	cin >> num_of_bits;
	cout << endl;
	max_num = pow(2, num_of_bits) - 1;
	vector<number>minterms_1d;
	vector<vector<number>>minterms_2d(num_of_bits + 1);

	for (unsigned int min_counter = 0; min_counter < num_of_minterms; min_counter++)
	{
		cout << "Enter a minterm in base 10 from 0 to" << max_num << endl;
		cin >> minterm_10;
		if ((minterm_10 < 0) || (minterm_10 > max_num))
		{
			cout << "Minterm is out of range" << endl;
			min_counter--;
		}
		else
		{
			minterms_1d.push_back(Convert_10_T0_2(minterm_10));
		}
	}
	unsigned int m, col, num_of_cols;
	for (m = 0; m < minterms_1d.size(); m++)
		minterms_2d[minterms_1d[m].num_of_ones].push_back(minterms_1d[m]);

	for (m = 0; m < minterms_2d.size(); m++)
	{
		num_of_cols = minterms_2d[m].size();
		if (num_of_cols > 0)
		{
			cout << "Group:" << m << endl;
			for (col = 0; col < num_of_cols; col++)
				Display_1D_Vector(minterms_2d[m][col]);
		}
	}
	return 0;

}