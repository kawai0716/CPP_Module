# CPP08 ex00 メモ（vector / push_back / iterator / easyfind）

## 1. `std::vector` と `push_back`

- `std::vector<T>` は **同じ型だけを入れる可変長配列**
- `push_back(x)` は **末尾に要素を追加する関数**（代入ではない）

### よくある誤解

```cpp
std::vector<int> v(5, 10);
```

これは「2種類の値をセットで保存」ではなく、

- 要素数 `5`
- 各要素の初期値 `10`

で `vector` を作る、という意味。

## 2. イテレータ（iterator）とは

- コンテナの中の位置を指す **カーソル**
- 配列でいうポインタに近いイメージ

よく使う操作:

- `*it` : 今指している要素の値
- `++it` : 次の要素へ進む
- `it == other` : 同じ位置か比較

## 3. `T::iterator` と `typename`

- `T::iterator` は、コンテナ `T` が持つ **イテレータ型**
- `T` が `std::vector<int>` なら `T::iterator` は `std::vector<int>::iterator`
- `T` が `std::list<int>` なら `T::iterator` は `std::list<int>::iterator`

テンプレート内では `T::iterator` が型かどうかコンパイラが判断できないので、

```cpp
typename T::iterator
```

のように `typename` を付けて「これは型」と明示する。

## 4. `std::find` の引数と返り値

```cpp
std::find(container.begin(), container.end(), value);
```

- `container.begin()` : 探索開始位置（先頭）
- `container.end()` : 探索終了位置（最後の次。要素そのものではない）
- `value` : 探したい値

`std::find` は **見つかった値そのもの** ではなく、**見つかった位置（iterator）** を返す。

## 5. `it == container.end()` が意味すること

`std::find` の仕様:

- 見つかったら: その要素を指す iterator を返す
- 見つからなかったら: 第2引数（`last`）を返す

このコードでは第2引数が `container.end()` なので、

```cpp
it == container.end()
```

が成立したら「値が見つからなかった」という意味になる。

## 6. `easyfind` の考え方（ex00の本体）

- `std::find` で `container` 内を検索する
- 見つかったらその位置（iterator）を返す
- 見つからなければ例外を投げる

```cpp
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("easyfind: value not found");
    return it;
}
```

## 7. 一言でまとめると

- `vector` は可変長配列
- `push_back` は末尾追加
- `iterator` は位置を指すカーソル
- `easyfind` は「見つかれば iterator を返し、なければ例外」
