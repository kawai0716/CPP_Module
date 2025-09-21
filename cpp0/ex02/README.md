# C++ Module 00 - ex02 : The Job Of Your Dreams

## 📖 概要
- グローバル銀行「GlobalBanksters United」の開発チームで消失した `Account.cpp` を再実装する課題。
- `Account.hpp` とテストコード `tests.cpp`、そして実行ログ `19920104_091532.log` をもとに **完全一致する出力** を再現する。
- タイムスタンプ部分は環境依存だが、フォーマット (`[YYYYMMDD_HHMMSS] `) は一致させる必要がある。

---

## 🎯 学習の狙い
- **クラス設計**と**静的メンバ変数**による「全体集計」の管理を理解する。
- **コンストラクタ／デストラクタ**による初期化と終了処理の役割を学ぶ。
- **入金／出金処理**を通じて「個別データ」と「全体集計」の両立を扱う。
- **入出力フォーマットの厳密性**を守ることで、仕様を正確に満たすコーディング習慣を身につける。
- 小さなステップで実装→テスト→振り返りを行い、堅牢なプログラム開発プロセスを体験する。

---

## 📂 ファイル構成と役割

ex02/
├── Account.hpp # クラス宣言（メンバ変数・メソッドのプロトタイプ）
├── Account.cpp # クラス実装（静的変数定義・各メソッドの定義）
├── tests.cpp # 提供されたテストコード（入出金や集計確認を自動で実行）
├── 19920104_091532.log # 提供ログファイル（期待される出力サンプル）
├── Makefile # ビルド設定（makeで ./account を生成）
└── README.md # 本ファイル（概要・学習狙い・構成説明）

---

##  出力の順番
「口座の作成 → 全体集計表示 → 各口座状態表示 → 入金処理 → 集計表示 → 出金処理 → 最終的に閉じる」

---

## 🔑 変数名の意味

### 個別アカウントごとのメンバ
- `_accountIndex` : 口座番号（生成順に採番される）
- `_amount` : この口座の現在残高
- `_nbDeposits` : この口座の入金回数
- `_nbWithdrawals` : この口座の出金回数

### クラス全体で共有する静的メンバ
- `_nbAccounts` : 現在の総口座数
- `_totalAmount` : 全口座の総残高
- `_totalNbDeposits` : 全口座での入金総回数
- `_totalNbWithdrawals` : 全口座での出金総回数

---

## ログ出力キーの意味まとめ（英語 → 意味）

- `index` → 口座番号（Account index, 0から始まる連番）
- `amount` → 口座の残高（Balance）
- `p_amount` → 直前の残高（Previous balance, 取引前の残高）
- `created` → 口座の生成イベント（Account creation）
- `closed` → 口座の終了イベント（Account closure / destruction）
- `accounts` → 全体の口座数（Total number of accounts）
- `total` → 全口座の総残高（Total balance across all accounts）
- `deposit` → 入金額（Deposit amount for a transaction）
- `nb_deposits` → 個別口座の入金回数（Number of deposits for this account）
- `deposits` → 入金回数（Number of deposits, contextに応じて個別または全体）
- `withdrawal` → 出金額（Withdrawal amount for a transaction、または refused）
- `nb_withdrawals` → 個別口座の出金回数（Number of withdrawals for this account）
- `withdrawals` → 出金回数（Number of withdrawals, contextに応じて個別または全体）
- `refused` → 出金失敗（Withdrawal refused due to insufficient funds）

---

## ✅ 出力フォーマット例

- 生成時：Account::Account(int initial_deposit)

[2025XXXX_XXXXXX] index:0;amount:42;created


- 入金時：makeDeposit

[2025XXXX_XXXXXX] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1


- 出金失敗時：

[2025XXXX_XXXXXX] index:0;p_amount:47;withdrawal:refused


- 全体集計：displayAccountsInfos()

[2025XXXX_XXXXXX] accounts:8;total:20049;deposits:0;withdrawals:0


---

## 📝 注意点
- **タイムスタンプ部分以外は1文字も違えないこと**（`;`やキー名など）。
- `withdrawal:refused` の場合は **amount や nb_withdrawals を絶対に出さない**。
- デストラクタでは **集計値を変更しない**


---

## 📓 開発記録（学習サイクル Step A〜F）

- **Step A: `_displayTimestamp()`**
- `strftime` を使って `[YYYYMMDD_HHMMSS]␣` を出力する関数を実装。
- 学び：フォーマット厳守（ゼロ埋め、スペース忘れに注意）。

- **Step B: 静的メンバ定義＋コンストラクタ／デストラクタ**
- 口座生成時に index 採番、総額更新、`created` ログ。
- 破棄時に `closed` ログ（集計は変更しない）。
- 学び：静的メンバは `.cpp` に必ず1回定義が必要。

- **Step C: `displayAccountsInfos()`**
- 全体集計を 1 行で出力。
- 学び：静的メンバの値をまとめて表示、順序・綴りに注意。

- **Step D: `displayStatus()`**
- 個別口座の状態を 1 行で出力。
- 学び：const メソッドであること、個別の残高や回数を正確に出す。

- **Step E: `makeDeposit(int)`**
- 入金処理。旧残高 `p_amount` を出し、残高と回数を更新。
- 学び：更新順序と出力順序（p_amount → deposit → amount → nb_deposits）を間違えない。

- **Step F: `makeWithdrawal(int)`**
- 出金処理。残高不足なら `refused`、成功時は残高と回数更新。
- 学び：失敗時は集計を一切変更しない。出力の差異に注意。

---

## ✅ 採点で落としやすいポイント

- タイムスタンプ直後の**スペース忘れ**
- `withdrawal:refused` のあとに余計な `;amount:` を出してしまう
- 静的メンバを `.cpp` に定義し忘れる（リンクエラー）
- キー名や複数形の**綴りミス**
- `displayStatus()` が `const` でない
- Makefile の出力名が `megaphone` のまま

---

### 1. いまの「初期化リスト」の場合、何が違うと思いますか?
- 初期化リストは「オブジェクトが生成される瞬間に値を渡す」
- 代入は「一度デフォルトで作ってから後で上書きする」
- const や 参照 をメンバにするときは「初期化リストでしか書けない」
- 代入だと「まず空文字列が作られる → そのあと代入」＝2回仕事する
  初期化リストなら「最初からその値で作る」＝1回で済む。
```cpp    
代入
        Account::Account(int initial_deposit) {
                _accountIndex = _nbAccounts;
            _amount = initial_deposit;
            _nbDeposits = 0;
            _nbWithdrawals = 0;
}
```

```cpp
初期化リスト
        Account::Account(int initial_deposit)
        : _accountIndex(_nbAccounts)
        , _amount(initial_deposit)
        , _nbDeposits(0)
        , _nbWithdrawals(0)
        {
            // コンストラクタ本体
        }
```