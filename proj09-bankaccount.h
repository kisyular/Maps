#ifndef BANKACCOUNT_CLASS
#define BANKACCOUNT_CLASS

#include <iostream>
using std::cout; using std::endl; using std::ostream;
#include <vector>
using std::vector;
#include <algorithm>
using std::transform;
#include <iterator>
using std::ostream_iterator;
#include <sstream>
using std::ostringstream;
#include <map>
using std:: map;
#include <string>
using std::string;
#include<random>
using std::default_random_engine;
//using std::mt19937_64;
using std::uniform_int_distribution;

//make class BankAccount with data members  both private and public
class BankAccount{
	private:
	string name_;
	string password_;
	double funds_;
	
	public:
	BankAccount()=default;
	BankAccount( string name, string password, double funds);
	friend ostream& operator<<(ostream & out, BankAccount &);
	friend class Bank;
};
ostream& operator<<(ostream & out, BankAccount &);
#endif
