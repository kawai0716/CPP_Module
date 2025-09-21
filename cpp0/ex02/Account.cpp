/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:05:22 by marvin            #+#    #+#             */
/*   Updated: 2025/08/20 11:05:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
:_accountIndex(_nbAccounts)
, _amount(initial_deposit)
, _nbDeposits(0)
, _nbWithdrawals(0)
{
    ++_nbAccounts;
    _totalAmount += _amount;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
                << ";amount:" << _amount
                << ";created" << std::endl;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
                << ";amount:" << _amount
                << ";closed" << std::endl;
}

void Account::_displayTimestamp()
{
    std::time_t t = std::time(NULL);
    std::tm* lt = std::localtime(&t);
    char buf[32];

    if(lt && std::strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S] ", lt))
        std::cout << buf;
    else
        std::cout << "[00000000_000000] ";
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

void Account::displayStatus() const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
                << ";amount:" << _amount
                << ";deposits:" << _nbDeposits
                << ";withdrawals:" << _nbWithdrawals
                << std::endl;
}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
                << ";p_amount:" << _amount
                << ";deposit:" << deposit;

    _amount += deposit;
    ++_nbDeposits;
    _totalAmount += deposit;
    ++_totalNbDeposits;
    std::cout << ";amount:" << _amount
                << ";nb_deposits:" << _nbDeposits
                << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
                << ";p_amount:" << _amount
                << ";withdrawal:";

    if(withdrawal > _amount)
    {
        std::cout << "refused" << std::endl;
        return false;
    }

    std::cout << withdrawal;
    _amount -= withdrawal;
    ++_nbWithdrawals;
    _totalAmount -= withdrawal;
    ++_totalNbWithdrawals;
    std::cout << ";amount:" << _amount
                << ";nb_withdrawals:" << _nbWithdrawals
                << std::endl;
    return true;
}
