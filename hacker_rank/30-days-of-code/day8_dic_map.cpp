#include <iostream>
#include <map>

using namespace std;

int main() {

	string fname;
	int phnum, count;
	map<string, int> dir;
	map<string, int>::const_iterator it;

	cin >> count; // number of records being input

	for (int i = 0; i < count; i++) {
		cin >> fname;
		cin >> phnum;

		dir.insert(pair<string,int>(fname, phnum));
	}

	for (it = dir.begin(); it != dir.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}

	cout << "Which name do you want to find: ";

	cin >> fname;

	if ((it = dir.find(fname)) != dir.end()) {
		cout << fname << " " << it->second << endl;
	} else {
		cout << fname << " does not exist" << endl;
	}
}
