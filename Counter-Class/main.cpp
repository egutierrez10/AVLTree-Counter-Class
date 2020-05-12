#include <iostream>
#include "counter.h"
using namespace std;

int main(){
	Counter<string> C;
	C.insert("apple");
	C.insert("banana");
	C.insert("apple");

	cout << C.size() << endl; // outputs 2
	cout << C["apple"] << endl; // outputs 2
	cout << C["banana"] << endl; // outputs 1
	cout << C["pizza"] << endl; // outputs 0

	vector<string> vec = C.elements();
	for(auto i: vec)
		cout << i << " ";
	cout << endl;
	return 0;
}