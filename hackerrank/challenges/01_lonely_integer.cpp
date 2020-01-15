/*
You will be given an array of integers. All of the integers except one occur twice. That one is unique in the array.
We will need to read 'n' integers
1 <=- n < 100
0 <= a[i] <= 100 where 0 <= i < n
Debug:
export OUTPUT_PATH=/dev/stdout
Compile: g++ -std=c++11 <filename>
*/
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#define APPROACH1 0
#define APPROACH2 1

using namespace std;

vector<string> split_string(string);

#if APPROACH1
// Complete the lonelyinteger function below.
int lonelyinteger(vector<int> a) {
    list<int> ll;
    for(auto it = a.begin(); it != a.end(); ++it) {
        //*it
        auto rslt1 = find(begin(ll), end(ll), *it);
        if (rslt1 != end(ll)) {
            ll.erase(rslt1);
        } else {
            ll.push_back(*it);
        }

    }
    return ll.front();
}
#endif

#if APPROACH2
// Complete the lonelyinteger function below.
int lonelyinteger(vector<int> a) {
	int result = 0;
	for (auto it = a.begin(); it != a.end(); it++) {
		result = result^(*it);
	}

	return result;
}
#endif

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int result = lonelyinteger(a);
	fout << "OUTPUT: ";
	cout << "Do you see it " << endl;
	cout << getenv("OUTPUT_PATH") << endl;

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

