#include <Account.hpp>
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbWithdrawals = 0;
int Account::_totalNbDeposits = 0;

Account::Account(int initial_deposit) {
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_totalAmount += this->_amount;
	_nbAccounts++;
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account(void) {
	_displayTimestamp();
	_totalAmount -= this->_amount;
	_nbAccounts--;
	std::cout << " index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
}

int Account::checkAmount() const { return this->_amount; }

void	Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << checkAmount() << ";";

	this->_amount += deposit;
	this->_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << checkAmount() << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << checkAmount() << ";";
	if (withdrawal > checkAmount())	{
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	} else {
		std::cout << "withdrawal:" << withdrawal << ";";
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		std::cout << "amount:" << checkAmount() << ";";
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return true;
	}
}

void Account::_displayTimestamp() {
	std::time_t t = std::time(NULL);
	std::tm *now = std::localtime(&t);
	char buf[20];

	std::strftime(buf, 20, "[%Y%m%d_%H%M%S]", now);
	std::cout << buf;
}

void Account::displayStatus() const {
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex << ";";
	std::cout << "amount:" << checkAmount() << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}


int Account::getNbAccounts() { return _nbAccounts; }

int Account::getTotalAmount() { return _totalAmount; }

int Account::getNbDeposits() { return _totalNbDeposits; }

int Account::getNbWithdrawals() { return _totalNbWithdrawals; }

void Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}