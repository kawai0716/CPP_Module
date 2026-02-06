## 動作の流れ（例: `Array<int> a(3);`）
1. `Array<int>` がテンプレートから実体化される（`.tpp` が見えているので定義が使える）
2. コンストラクタ `Array(unsigned int n)` が呼ばれ、`_data=0`、`_size=3` に初期化
3. 本体で `new int[3]()` が実行され、要素3つ分のメモリを確保（0で初期化）
4. `a[0]` のようにアクセスすると `operator[]` が呼ばれ、範囲チェック→参照を返す
5. 範囲外（例: `a[10]`）なら `OutOfBounds` を `throw`
6. スコープを抜けるとデストラクタが呼ばれ、`delete[] _data` で解放

## コピーと代入の流れ（深いコピー）
1. `Array<int> b(a);` はコピーコンストラクタが呼ばれる
2. `b` 用に新しい配列を確保し、要素を1つずつコピー
3. `b = a;` は代入演算子が呼ばれる（自分自身代入チェック→新規確保→コピー→古いデータ解放）
4. その結果、`a` と `b` は別の配列を持つ（片方を変えてももう片方は変わらない）

## 問題文の指示と実装対応
- 「引数なしで空配列を作る」
  - 実装: `Array<T>::Array()`
  - ファイル: `cpp7/ex02/Array.tpp`
- 「unsigned int n で n 要素の配列を作る」
  - 実装: `Array<T>::Array(unsigned int n)`
  - ファイル: `cpp7/ex02/Array.tpp`
- 「コピーコンストラクタと代入演算子（深いコピー）」
  - 実装: `Array<T>::Array(const Array&)`, `Array<T>::operator=`
  - ファイル: `cpp7/ex02/Array.tpp`
- 「new[] を必ず使う」
  - 実装: `new T[_size]()` / `new T[other._size]()`
  - ファイル: `cpp7/ex02/Array.tpp`
- 「operator[] でアクセス、範囲外は例外」
  - 実装: `Array<T>::operator[]`（const/非const）で `OutOfBounds` を `throw`
  - ファイル: `cpp7/ex02/Array.tpp`
- 「size() を持つ（const）」
  - 実装: `unsigned int size() const`
  - ファイル: `cpp7/ex02/Array.tpp`
- 「std::exception を使った例外」
  - 実装: `class OutOfBounds : public std::exception` + `what()`
  - ファイル: `cpp7/ex02/Array.hpp`, `cpp7/ex02/Array.tpp`
- 「main.cpp にテストを書く」
  - 実装: 配列生成、コピー独立性、範囲外例外の確認
  - ファイル: `cpp7/ex02/main.cpp`
