/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 09:58:32 by marvin            #+#    #+#             */
/*   Updated: 2025/08/19 09:58:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

/**
 * @class Contact
 * @brief 個人情報を管理する連絡先クラス
 *
 * このクラスは連絡先の詳細（名前、苗字、ニックネーム、電話番号、秘密情報）を保持し、
 * それぞれの値の設定・取得や、連絡先が有効かどうかの判定を行います。
 */
class Contact {
public:
    /**
     * @brief デフォルトコンストラクタ。空の連絡先を初期化します。
     */
    Contact();

    /**
     * @brief 連絡先の全項目を設定します。
     * @param first 名前
     * @param last 苗字
     * @param nickname ニックネーム
     * @param phone 電話番号
     * @param secret 秘密情報
     * @return 全ての項目が正しく設定された場合はtrue、そうでなければfalse
     */
    bool setField(const std::string& first,
                  const std::string& last,
                  const std::string& nickname,
                  const std::string& phone,
                  const std::string& secret);

    /**
     * @brief 名前を取得します。
     * @return 名前（文字列）
     */
    std::string getFirst() const;

    /**
     * @brief 苗字を取得します。
     * @return 苗字（文字列）
     */
    std::string getLast() const;

    /**
     * @brief ニックネームを取得します。
     * @return ニックネーム（文字列）
     */
    std::string getNick() const;

    /**
     * @brief 電話番号を取得します。
     * @return 電話番号（文字列）
     */
    std::string getPhone() const;

    /**
     * @brief 秘密情報を取得します。
     * @return 秘密情報（文字列）
     */
    std::string getSecret() const;

    /**
     * @brief 連絡先が空（未設定）かどうかを判定します。
     * @return 未設定の場合true、設定済みの場合false
     */
    bool isEmpty() const;

private:
    std::string first_;    ///< 名前を保持します
    std::string last_;     ///< 苗字を保持します
    std::string nickname_; ///< ニックネームを保持します
    std::string phone_;    ///< 電話番号を保持します
    std::string secret_;   ///< 秘密情報を保持します
    bool valid_;           ///< 連絡先が有効かどうかを示します
};

#endif
