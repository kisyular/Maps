/*
2016-03-31
proj09-bank.cpp
*/
#include <iostream>
using std::cout; using std::endl; using std::ostream; using std::stol;
#include <vector>
using std::vector;
#include <algorithm>
using std::transform;
#include <iterator>
using std::ostream_iterator;
#include <sstream>
using std::ostringstream;
#include <string>
using std::string;
#include<random>
using std::default_random_engine;
using std::uniform_int_distribution;
#include "proj09-bank.h"
#include <map>
using std ::map; using std::make_pair; using std:: pair;
#include <limits>
using std::numeric_limits;

//initialize the constructor with bank_name and random seed
Bank::Bank( string bank_name, int randomSeed ){
	name_ = bank_name;
	rand_eng_.seed(randomSeed) ;
	bank_id_=(dist(rand_eng_));
}
long Bank::bank_id(){
	return bank_id_;
}
string Bank::bank_name(){
	return name_;
}
		
long Bank::create_account( string account_name, string password, double funds){
	
	//create a Bankaccount variable which takes account_name, password and funds
	BankAccount bankaccounts(  account_name,  password,  funds);
	long random_n=(dist(rand_eng_));
		for ( auto chr : password){
			if(isalnum(chr)){ //if the password is isalnum, create bankaccount
				auto it = accounts_.find(random_n);
				if (it == accounts_.end()){
					//if bank_id exists in the accounts_ map, assing the bankaccounts to it
					accounts_[random_n ]= bankaccounts;	
				}else{
					}
			}
		}
		return random_n;
}
	
double Bank::balance(long account_id, string password){
	
	//initialize variable to check for password, name and funds
	auto accountID = accounts_.find(account_id);
	auto accPassword = accounts_[account_id];
	auto accFund_ = accounts_[account_id];
	
	//if both bank_id_ and password_ are correct, display the balance, else return an error
	if(accountID != accounts_.end() && password ==accPassword.password_){
		return accFund_.funds_;}
	else{
		return numeric_limits<double>::min();
		}
}


bool Bank::transfer(long from_id, string from_password, 
long to_id, string to_password, double amount){
	
	//initialize variable to help you track funds and bank_id of the both banks Accounts
	bool result = false;
	auto from_accFunds = accounts_[from_id];
	auto to_accFunds = accounts_[to_id];
	auto to_accID = accounts_.find(to_id);
	auto from_accID = accounts_.find(from_id);
	
	//check to see if both Banks IDs exist in the map
	if (from_accID != accounts_.end()){
		auto to_accPassword = accounts_[to_id];
		if (to_accID != accounts_.end()){
			auto from_accPassword = accounts_[from_id];
			
			//make sure the account to take money from has enough money
			//and that money to transfer is not negative money
			if (from_accFunds.funds_> amount){
				if (amount >0){
					
					//check to see if both password are correct
					if( from_password ==from_accPassword.password_){
						if(to_password ==to_accPassword.password_){
							cout<<endl;
							//take money "from_account" and put it "to_account"
							accounts_[from_id].funds_ -=amount;
							accounts_[to_id].funds_ +=amount;
							result = true;
						}else{
							result = false;
						}
					}
				}
			}
		}else{ cout <<"Account to transfer to not found "<<endl;}
	}else{ cout <<"Account to transfer from not found "<<endl;}
	return result;
}
	
void Bank::print_account(long id, string password, ostream& out){
	auto accountID = accounts_.find(id);
	auto accPassword = accounts_[id];
	auto accName = accounts_[id];
	auto accFundds = accounts_[id];
	
	//check if the account exist and the password is correct
	if (accountID != accounts_.end()){
	if (password==accPassword.password_){

			ostream& operator<<(ostream & out, BankAccount & bankaccount);
			accName.name_[0] = accName.name_[0] + ('A' - 'a');
			out <<"ID: "<<id <<", "<<accName.name_<<", "<<accFundds.funds_<<endl;
		}else{cout <<"Bad PASSWORD"<<endl;}
	}else{cout <<"No Such Account"<<endl;}
}


