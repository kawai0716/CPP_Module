/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 09:58:28 by marvin            #+#    #+#             */
/*   Updated: 2025/08/19 09:58:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Phonebook::Phonebook() : size_(0), next_(0) {}

bool Phonebook::add(const Contact& c) {
    if(c.isEmpty()) return false;
    data_[next_] = c; // 物理位置に書き込み
    next_ = (next_ + 1) % kCapacity; // 次の物理位置へ循環
    if(size_ < kCapacity) ++size_; // サイズは最大8まで
    return true;
}

int Phonebook::size() const { return size_; }

int Phonebook::logicalToPhysical(int logicalIndex) const {
    int oldest = (size_ < kCapacity) ? 0 : next_;
    return (oldest + logicalIndex) % kCapacity; // 論理インデックスを物理位置に変換
}

std::string Phonebook::fit10(const std::string& s) {
    if(s.size() <= 10)
        return std::string(10 - s.size(), ' ') + s;
    else if(s.size() >= 11)
        return s.substr(0, 9) + '.';
    return s;
}

void Phonebook::list() const {
    if(size_ >= 1)
        std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
    for(int i = 0; i < size_; ++i)
    {
        int phys = logicalToPhysical(i);
        std::cout << std::setw(10) << i << "|"
                    << fit10(data_[phys].getFirst()) << "|"
                    << fit10(data_[phys].getLast()) << "|"
                    << fit10(data_[phys].getNick()) << std::endl;
    }
}

bool Phonebook::showDetail(int index) const {
    if(index < 0 || index >= size_)
    {
        std::cout << "Invalid index" << std::endl;
        return false;
    }
    int phys = logicalToPhysical(index);
    const Contact& c = data_[phys];
    std::cout << "First Name: " << c.getFirst() << std::endl;
    std::cout << "Last Name: "  << c.getLast()  << std::endl;
    std::cout << "Nickname: "   << c.getNick()  << std::endl;
    std::cout << "Phone: "      << c.getPhone() << std::endl;
    std::cout << "Secret: "     << c.getSecret()<< std::endl;
    return true;
}
