/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 09:58:24 by marvin            #+#    #+#             */
/*   Updated: 2025/08/19 09:58:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP  

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class Phonebook {
public:
    Phonebook();        

    // 妥当な Contact のみ追加。false のときは無視。
    bool add(const Contact& c);

    // 登録一覧（index, first, last, nick）を表示（実装は .cpp）
    void list() const;

    // 表示順 index（0..size()-1）の詳細5項目を出力。範囲外は false
    bool showDetail(int index) const;

    // 現在の件数（0..8)
    int size() const;

    // 表示順 index → 物理配列インデックスへの変換
    int logicalToPhysical(int logicalIndex) const;

private:
    // 幅10に合わせて右寄せ・超過は末尾'.'で9文字＋'.'にする
    static std::string fit10(const std::string& s);

private:
    enum { kCapacity = 8 };
    Contact data_[kCapacity];
    int     size_; // 0..8
    int     next_; // 次に書き込む物理位置 0..7
};

#endif