ex02 実装メモ（手順と根拠）
--------------------------------

1) 既存コードの確認  
   - ex02 ディレクトリ内に旧 Form 実装と空の派生フォームがあることを確認。  
   - 根拠: Ch. VI 冒頭「base class Form must be an abstract class and should therefore be renamed AForm」。

2) 基底クラスの抽象化 (Form → AForm)  
   - private 属性を維持しつつ純粋仮想 `executeAction()` を追加。  
   - `execute(Bureaucrat const&)` で署名済チェックと実行グレードチェックを共通化し、未署名用 `FormNotSignedException` を追加。  
   - 根拠: Ch. VI 「check that the form is signed and that the grade of the bureaucrat attempting to execute the form is high enough」。

3) Bureaucrat の対応  
   - 参照型を AForm に変更し、`executeForm` を追加して実行成功/失敗をメッセージ化。  
   - 根拠: Ch. V/VI 「signForm must call Form::beSigned」「add the executeForm(AForm const & form) const」。

4) 派生フォーム 3 種の実装  
   - ShrubberyCreationForm (sign 145, exec 137): `<target>_shrubbery` に ASCII ツリーを書く。  
   - RobotomyRequestForm (sign 72, exec 45): ドリル音＋50% 成否出力。  
   - PresidentialPardonForm (sign 25, exec 5): Zaphod に赦免された旨を出力。  
   - 根拠: Ch. VI 「Add the following concrete classes…」「You must check that the form is signed and that the grade…」。

5) テスト用 main の刷新  
   - 署名/実行の成功と権限不足失敗を一通り通すデモケースに差し替え。  
   - 根拠: 各章末「Implement and submit some tests to ensure everything works as expected」。

6) ビルド設定更新  
   - Makefile を ex02 用に刷新し、新規ソースを全てビルド対象へ。  
   - 根拠: Ch. VI 「Files to Submit: …AForm…Shrubbery…Robotomy…Presidential…」。

ポイント  
- 属性は base で private のまま保持（課題で明示）。  
- 例外は GradeTooHigh/Low に加えて未署名例外を追加し、`executeAction()` は派生専用に限定。  
- 大量 if/else を避ける指摘は ex03 だが、ここでも共通チェックを AForm::execute に寄せて分岐を最小化。
