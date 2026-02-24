# CPP08 ex02 メモ（MutantStack）

## 1. ex02でやっていること

- `std::stack` を継承して、**iteratorで中身を走査できる stack** を作る課題
- 学習の主目的は「便利なstack」そのものより、以下の理解
  - `std::stack` はコンテナではなく **コンテナアダプタ**
  - 内部コンテナ `c` の存在
  - `iterator` / `const_iterator` / `reverse_iterator`
  - テンプレート継承と `typename`

## 2. stackの基本（LIFO）

- LIFO = **後入れ先出し**
- 後から `push` したものほど先に `pop` される
- 概念的には「上に積む」イメージ

例:

```cpp
push(10);
push(20);
push(30);
```

このとき

- `top()` は `30`
- `pop()` で `30` が消える

## 3. `pop()` / `top()` / `size()`

- `pop()` : **top要素を削除する**（値は返さない）
- `top()` : **次に取り出される要素**（一番上）
- `size()` : **要素数**

### 注意

`pop()` は値を返さないので、値も欲しいときは:

```cpp
int x = mstack.top();
mstack.pop();
```

## 4. `top()` と `begin()` の違い

- `mstack.top()` は **値（正確には参照）** を返す
- `mstack.begin()` は **iterator（位置）** を返す

つまり:

- `top()` = 「次に出る値」
- `begin()` = 「順番に見るための開始位置」

`MutantStack` では `begin()` は内部コンテナの先頭を返すため、通常は **下側（古い要素側）** から始まる。

## 5. `MutantStack` の仕組み（重要）

`MutantStack` は `std::stack<T>` を継承し、内部コンテナ `c` の iterator を外に公開している。

```cpp
typedef typename std::stack<T>::container_type::iterator iterator;
```

```cpp
iterator begin()
{
    return this->c.begin();
}

iterator end()
{
    return this->c.end();
}
```

- `container_type` = `std::stack` が内部で使っているコンテナ型
- `this->c` = `std::stack` の内部コンテナ
- `typename` = `...::iterator` が型だと明示するために必要

## 6. `main` のループ出力が `5 3 5 737 0` になる理由

`main` の流れ:

1. `push(5)`
2. `push(17)`
3. `pop()` → `17` が削除される
4. `push(3), push(5), push(737), push(0)`

最終的な中身（下 -> 上）は:

- `5, 3, 5, 737, 0`

そのあと:

```cpp
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();

++it;
--it;
while (it != ite)
{
    std::cout << *it << std::endl;
    ++it;
}
```

- `begin()` から `end()` まで順にたどる
- `++it; --it;` は元の位置に戻しているだけ（出力順に影響なし）

したがって出力は:

```txt
5
3
5
737
0
```

## 7. `reverse_iterator` は必要？

今回の `main` では未使用なので、**最小実装としては不要**。

ただし入れておく価値はある:

- APIが揃う（`begin/end` があるなら `rbegin/rend` も自然）
- 逆順走査できる
- STLの理解を示しやすい

例:

```cpp
for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
    std::cout << *it << std::endl;
```

これは上側（top側）から見ていく走査になる。

## 8. 一言でまとめると

- ex02は `std::stack` に **iterator機能を足す課題**
- `top()` は上の値、`begin()` は走査開始位置
- `MutantStack` によって stackの中身を壊さずに列挙できる
