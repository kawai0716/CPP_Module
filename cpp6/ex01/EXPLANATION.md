# ex01 解説

## 仕様の核を抽出
- 根拠: 「Implement a class Serializer... static methods」「Data 数、テスト用main.」

## 1. Data構造体を先に決める
- 根拠: 「You must create a non-empty (meaning it has data members) Data structure」
  「Do not forget to turn in the files of your Data structure」
- 実装: `ex01/Data.hpp` に `int id; double value; char tag;` を用意
- 派生: 後続のテストで実際に値を入れて復元確認できるようにメンバーを複数にした

## 2. Serializer のインターフェース設計
- 根拠: 「Serializer, which will not be initializable by the user in any way」
  「static methods」
- 実装: `ex01/Serializer.hpp` で `static uintptr_t serialize(Data*);` と
  `static Data* deserialize(uintptr_t);` を宣言
- 追加判断: インスタンス化禁止のため private コンストラクタ/コピー/代入/デストラクタを宣言

## 3. キャスト実装
- 根拠: 「It takes a pointer and converts it to the unsigned integer type」
- 実装: `ex01/Serializer.cpp` で
  - `serialize`: `reinterpret_cast<uintptr_t>(ptr)`
  - `deserialize`: `reinterpret_cast<Data*>(raw)`
- 派生: C++98 で使える `<stdint.h>` を `ex01/Serializer.hpp` に追加

## 4. テスト用 main を作成
- 根拠: 「Write a program to test that your class works as expected」
  「ensure the return value of deserialize() compares equal to the original pointer」
- 実装: `ex01/main.cpp`
  - `Data data;` に値を設定
  - serialize → deserialize してアドレス一致を `==` で検証
  - 復元後のメンバー値も表示して確認


## reinterpret_cast を使うべき理由
### 結論
この課題の serialize/deserialize では、`reinterpret_cast` を書くのが正解で、実質必須。

### 理由
- `Data*` と `uintptr_t` は別型なので暗黙変換はできない。
- `static_cast` ではポインタ→整数はできないため、`reinterpret_cast` が適切。
- 問題文の追加ルール「型変換は特定のキャストで行う」は、ここでは `reinterpret_cast` を選ぶのが筋。

### 補足
- C風キャストでもコンパイルは通る場合があるが、この課題の意図（キャストの種類を明示）に反するので避けた方が安全。

## `uintptr_t` とは
`uintptr_t` は「ポインタを安全に格納できるだけの幅を持つ符号なし整数型」。

- 目的: `Data*` のアドレス値を整数として保持したいときに使う。
- 定義: C++98 では `<stdint.h>` にある（C++11以降は `<cstdint>` の `std::uintptr_t`）。
- サイズ: 環境依存（32bitなら32bit、64bitなら64bit）。

この課題で `serialize` が `Data*` を `uintptr_t` に変換し、`deserialize` で元に戻すための型として指定されている。
