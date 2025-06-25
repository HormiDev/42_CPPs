/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 19:18:21 by ide-dieg          #+#    #+#             */
/*   Updated: 2025/06/24 21:54:18 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) 
: _accountIndex(_nbAccounts++), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) 
{
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account() 
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void Account::_displayTimestamp() 
{
	int year, month, day, hour, minute, second;
	time_t now = time(0);
	struct tm *ltm = localtime(&now);

	year = 1900 + ltm->tm_year;
	month = 1 + ltm->tm_mon;
	day = ltm->tm_mday;
	hour = ltm->tm_hour;
	minute = ltm->tm_min;
	second = ltm->tm_sec;

	std::cout << "[" << year << std::setw(2) << std::setfill('0') << month 
			  << std::setw(2) << std::setfill('0') << day 
			  << "_" << std::setw(2) << std::setfill('0') << hour 
			  << std::setw(2) << std::setfill('0') << minute 
			  << std::setw(2) << std::setfill('0') << second 
			  << "] ";
}

int Account::getNbAccounts() 
{
	return _nbAccounts;
}

int Account::getTotalAmount() 
{
	return _totalAmount;
}

int Account::getNbDeposits() 
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals() 
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts 
			  << ";total:" << _totalAmount 
			  << ";deposits:" << _totalNbDeposits 
			  << ";withdrawals:" << _totalNbWithdrawals 
			  << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << "index:" << _accountIndex 
			  << ";p_amount:" << _amount - deposit
			  << ";deposit:" << deposit 
			  << ";amount:" << _amount 
			  << ";nb_deposits:" << _nbDeposits 
			  << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	if (withdrawal > _amount) {
		std::cout << "index:" << _accountIndex 
				  << ";p_amount:" << _amount 
				  << ";withdrawal:refused" 
				  << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout << "index:" << _accountIndex 
			  << ";p_amount:" << _amount + withdrawal 
			  << ";withdrawal:" << withdrawal 
			  << ";amount:" << _amount 
			  << ";nb_withdrawals:" << _nbWithdrawals 
			  << std::endl;
	return true;
}

int Account::checkAmount() const
{
	return _amount;
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex 
			  << ";amount:" << _amount 
			  << ";deposits:" << _nbDeposits 
			  << ";withdrawals:" << _nbWithdrawals 
			  << std::endl;
}