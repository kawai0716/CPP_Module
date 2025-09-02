/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 09:58:36 by marvin            #+#    #+#             */
/*   Updated: 2025/08/19 09:58:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

static std::string trim(const std::string& s)
{
    std::string::size_type b = 0, e = s.size();
    while (b < e && (s[b] == ' ' || s[b] == '\t'))
         ++b; // 前の空白を削除
    while (b < e && (s[e - 1] == ' ' || s[e - 1] == '\t'))
         --e; // 後ろの空白を削除
    return s.substr(b, e - b); // 前後の空白を除いた部分文字列を返す
}

static bool isDigits(const std::string& s)
{
    if(s.empty()) return false; // 空文字列は数字ではない
    for(std::string::size_type i = 0; i < s.size(); ++i)
    {
        char c = s[i];
        if(c < '0' || c > '9') 
            return false; // 数字以外の文字があれば false
    }
    return true; // 全て数字なら true
}

/* 1) デフォルトコンストラクタ：valid_ を false に初期化 */
Contact::Contact()
: first_(), last_(), nickname_(), phone_(), secret_(), valid_(false)
{}

/* 2) 5項目すべて非空ならセットして valid_=true */
bool Contact::setField(const std::string& first,
                       const std::string& last,
                       const std::string& nickname,
                       const std::string& phone,
                       const std::string& secret)
{
    std::string f    = trim(first);
    std::string l     = trim(last);
    std::string n = trim(nickname);
    std::string p    = trim(phone);
    std::string s   = trim(secret);

    if (f.empty() || l.empty() ||
        n.empty() || p.empty() || s.empty() ||
        !isDigits(p)) // 電話番号は数字のみで構成されるべき{
        return false; // どれか空なら失敗（何も代入しない）
        
    first_    = f;
    last_     = l;
    nickname_ = n;
    phone_    = p;
    secret_   = s;
    valid_    = true;
    return true;
}

/* 3) ゲッタ群（宣言と完全一致のシグネチャで定義） */
std::string Contact::getFirst() const  { return first_;    }
std::string Contact::getLast()  const  { return last_;     }
std::string Contact::getNick()  const  { return nickname_; }
std::string Contact::getPhone() const  { return phone_;    }
std::string Contact::getSecret() const { return secret_;   }

/* 4) 空かどうかの判定 */
bool Contact::isEmpty() const { return !valid_; }
