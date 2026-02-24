# CPP08 ex01 メモ（Span / shortestSpan / longestSpan）

## 1. `Span` クラスの役割

- `int` を最大 `N` 個まで保存するクラス
- 保存した数値どうしの差（span）を計算する

## 2. `addNumber` の2種類（オーバーロード）

### `void addNumber(int value);`

- 数値を **1個だけ追加**する
- 空きがなければ例外（`FullException`）

### `template <typename It> void addNumber(It first, It last);`

- イテレータ範囲 `[first, last)` の数値を **まとめて追加**する
- 追加数が空き容量を超えるなら例外（`FullException`）

## 3. `reserve`（`main` の `data.reserve(10000)`）

- `std::vector` の **容量（capacity）** を先に確保する
- 要素数（size）は増えない
- 大量の `push_back` で再確保が何度も起きるのを減らして効率化する

### 注意

- `reserve(10000)` : 容量だけ確保（sizeは変わらない）
- `resize(10000)` : 要素数を10000にする

## 4. `std::sort(copy.begin(), copy.end())`

- `copy` の中の数値を **昇順（小さい順）にソート**する
- `shortestSpan()` で最小差を見つけやすくするため
- 元データ `_numbers` を壊さないようにコピーをソートしている

例:

- ソート前: `[6, 3, 17, 9, 11]`
- ソート後: `[3, 6, 9, 11, 17]`

## 5. `shortestSpan()`

- **最も近い2つの数の差**を返す

手順:

1. 要素数が2未満なら例外（`NotEnoughException`）
2. `_numbers` をコピー
3. コピーをソート
4. 隣り合う要素同士の差を比較して最小を返す

### なぜ隣同士だけでいい？

ソート済みなら、最小差は必ずどこかの「隣り合う要素」の間にあるため。

## 6. `longestSpan()`

- **最も離れた2つの数の差**を返す

手順:

1. 要素数が2未満なら例外（`NotEnoughException`）
2. 最小値を取得（`std::min_element`）
3. 最大値を取得（`std::max_element`）
4. `最大値 - 最小値` を返す

## 7. 例外になる条件

- `shortestSpan()` / `longestSpan()`
  - 数が2個未満 → span を計算できない
- `addNumber(...)`
  - 最大数を超えて追加しようとした

## 8. 一言でまとめると

- `Span` は「数をためる箱」
- `addNumber` は1個追加版と範囲追加版がある
- `shortestSpan` は最小差
- `longestSpan` は最大差
