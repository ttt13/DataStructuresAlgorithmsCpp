#include <iostream>
#include "StringSet.hpp"
#include <string>

using namespace std;

int main ( void )
{
	StringSet st;
	cout << "Conducting insertion test..." << endl;
	string test = "Peter";
	st.insert("Peter");
	st.insert("Tran");
	st.insert("Simon");
	cout << "Size = " << st.size() << endl;

	cout << "Tran appears at: " << st.find("Tran") << endl;

	if (st.remove("Peter") == true){
		cout << "Removed Peter." << endl << endl;
	}
	/*
	cout << "Should be negative: " << st.find(test) << endl;
	cout << "Find Peter: " << st.find("Peter") << endl;
	cout << "Find Tran: " << st.find("Tran") << endl;
	cout << "Find Simon: " << st.find("Simon") << endl;
	cout << "Size = " << st.size() << endl;*/
	StringSet test1(st);
	st.insert("Fraser");
	st.insert("University");


	test1.insert("Peter");
	//StringSet result = test1.unions(st);
	//result.print();
	cout << "St contains: " << endl;
	st.print();

	cout << endl << "test1 contains: " << endl;
	test1.print();

	//StringSet inter = test1.intersection(st);

	/*cout << endl << "Intersection check: " << endl;
	inter.print();*/

	StringSet diff = st.difference(test1);
	cout << endl << "Difference check (st - test1): " << endl;
	diff.print();

	return 0;
}