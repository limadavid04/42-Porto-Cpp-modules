#include "Account.hpp"
#include <iostream>
#include <iomanip>


int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	_amount = initial_deposit;
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
}
Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
	// [19920104_091532] index:0;amount:47;closed
}
int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}
int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}
int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}
int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_nbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << _amount + deposit << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
	_amount+=deposit;
	_totalNbDeposits++;
	_totalAmount+=deposit;
	// index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1;
}
bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	if (_amount - withdrawal < 0)
	{
		std::cout << "withdrawal:" << "refused" << std::endl;
		return (false);
	}
	_nbWithdrawals++;
	std::cout << "withdrawal:" << withdrawal << ";";
	std::cout << "amount:" << _amount - withdrawal << ";";
	std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	_amount-=withdrawal;
	_totalNbWithdrawals++;
	_totalAmount-=withdrawal;
	return (true);
// 	[19920104_091532] index:0;p_amount:47;withdrawal:refused
// [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
}
int		Account::checkAmount( void ) const
{
	return (_amount);
}
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" <<_amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals  << std::endl;
}

void Account::_displayTimestamp(void)
{
	time_t	now = time(0);
	tm		time_data = *localtime(&now);

	std::cout << "[" << time_data.tm_year + 1900 << std::setw(2) << std::setfill('0') << time_data.tm_mon + 1
	<< std::setw(2) << std::setfill('0') << time_data.tm_mday << "_" << std::setw(2) << std::setfill('0')
	<< time_data.tm_hour << std::setw(2) << std::setfill('0') << time_data.tm_min << std::setw(2) << std::setfill('0')
	<< time_data.tm_sec << "] ";
}


