#include <iostream>
#include <list>
//#include <cmath>

using namespace std;




void PrintPolynom(const list<int>& pol) {

	for (auto a = pol.begin(); a != pol.end(); a++) {
		cout << *a << " ";
	}
}

	void Swap (list<int> pol) {
		auto it = pol.begin();
		int Start = (*it);
		it = pol.end();
		int End = (*it);
		
		pol.pop_front();
		pol.push_front (Start);
		pol.pop_back();
		pol.push_back(End);
		
		for (auto a = pol.begin(); a != pol.end(); a++) {
			cout << *a << " ";
		}
	
	}


int main() {

	list<int> polynom = { 5, 4, 3, 2, 1 };
	PrintPolynom(polynom);
	Swap(polynom);
	
	return 0;
}