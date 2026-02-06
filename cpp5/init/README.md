# C++ Module 05 まとめ

## モジュール全体の狙い
- 例外と正規化されたクラス設計の練習。グレード範囲チェックで例外を投げ、try/catchで扱う。
- 直交正準形（デフォルト/コピーコンストラクタ、コピー代入、デストラクタ）を意識してクラスを作る。
- 標準出力のログ、`operator<<` のオーバーロード、自作例外クラスの基本を押さえる。

## ex00: Bureaucrat
- 目的: 例外安全なクラス設計と範囲チェック。
- 要件: `name` は不変、`grade` は 1〜150。範囲外なら `GradeTooHighException` / `GradeTooLowException` を投げる。`increment` / `decrement` でも同様。
- 出力: `<<` で `<name>, bureaucrat grade <grade>.`
- 流れ: クラス定義 → 例外クラス → コンストラクタで範囲チェック → インクリ/デクリ実装 → `<<` 実装 → `main` で try/catch テスト。

## ex01: Form
- 目的: 2 クラス間の連携と例外再利用。
- 要件: `name`(不変), `isSigned`(初期 false), `signGrade`, `execGrade`(不変)。範囲外なら `Form::GradeTooHighException` / `Form::GradeTooLowException`。
- 機能: `beSigned(Bureaucrat)` で署名。権限不足なら Low 例外。`<<` で全情報出力。
- Bureaucrat 拡張: `signForm` で `beSigned` 呼び出し、成功/失敗メッセージを出力。
- 流れ: Form 実装 → 範囲チェック → `beSigned` → Bureaucrat::signForm に try/catch → テスト（成功/失敗）。

## ex02: AForm と 3 派生フォーム
- 目的: 抽象基底クラス＋テンプレートメソッド的設計、実行権限チェック。
- 基底: Form を抽象化して `AForm` に。属性は private のまま。`execute(Bureaucrat const&) const` を追加し、署名済み確認と実行権限チェック。足りなければ例外。
- 派生:
  - `ShrubberyCreationForm` (sign 145, exec 137): `<target>_shrubbery` に ASCII ツリーを書く。
  - `RobotomyRequestForm` (sign 72, exec 45): ドリル音を出して 50% 成功/失敗を出力。
  - `PresidentialPardonForm` (sign 25, exec 5): Zaphod に赦免されたと出力。
- Bureaucrat 拡張: `executeForm` で `form.execute` を呼び、成功/失敗を出力。
- 流れ: AForm 設計（共通チェック + 純粋仮想 doAction など）→ 派生で実処理実装 → ファイル出力/乱数/標準出力 → Bureaucrat::executeForm → テスト（未署名/署名済/権限不足/成功）。

## ex03: Intern
- 目的: 文字列からフォームを生成するファクトリメソッド。
- 要件: `Intern::makeForm(name, target)` が `AForm*` を返す。対応名: `"shrubbery creation"`, `"robotomy request"`, `"presidential pardon"`。作成成功で「Intern creates <form>」を出力。未知名なら明示的エラー。
- 実装のコツ: 配列や関数ポインタのテーブルでマッピングし、長い if/else 連鎖を避ける。`new` で各フォームを生成。
- 流れ: マッピング実装 → 既知/未知でテスト → リーク確認。

## 着手の順序提案
1) ex00 で例外と `<<` の型を固める。
2) ex01 でクラス間呼び出しとログパターンを整える。
3) ex02 で抽象基底＋派生、実行チェックの共通化を設計。
4) ex03 でファクトリを実装し、既存フォームを生成できるようにする。

## Module 05 本質サマリ（目的と短い解説）
1) 例外（Exceptions）を完全に理解する  
   - `throw`/`try`/`catch` と `std::exception::what()` を押さえ、コンストラクタでも例外を投げられることを体験する。C++流の「安全なエラーハンドリング」が軸。
2) クラス設計の本質（責務と境界）を理解する  
   - 不変メンバ、範囲チェック、正しい getter、成功/失敗条件の設計を通して「壊れにくいクラス」を設計する感覚を養う。
3) Orthodox Canonical Form（コピー管理）を習得する  
   - デフォルト/コピーコンストラクタ、コピー代入、デストラクタの 4 点セットで、C++ のオブジェクト寿命とコピー動作を明確にする。
4) 継承と抽象クラス（OOP の核）  
   - AForm を抽象化し、派生クラスで振る舞いを分離。virtual/override でポリモーフィズムを体験し、共通化と拡張の分け方を学ぶ。
5) Factory パターンの導入（ex03）  
   - Intern::makeForm で名前→オブジェクト生成をマッピング。大量 if/else を避けるテーブル設計で、拡張しやすい生成処理の型を身につける。

## 身につくスキルと応用イメージ
- 安全なエラーハンドリング: 例外で失敗を表現し、呼び出し側で回復できる設計。
- 堅牢なクラス設計: コンストラクタで不正値を遮断し、const と OCF で寿命を管理。
- OOP 基礎 3 点: カプセル化（private）、継承＋ポリモーフィズム（virtual/override）、抽象化で共通部分と個別処理を整理。
- Factory 初歩: 名前や種類からインスタンスを作る仕組みを設計し、分岐のスパゲッティを防ぐ。
- 現場応用: ファイル/API エラー処理、ゲームのアクション設計、Web リクエスト分岐、ドキュメント生成などでそのまま転用可能。
