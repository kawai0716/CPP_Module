# ex00 補足メモ

## const 参照（`const T&`）を使う理由
- 安全性: 比較だけの関数なので、引数を変更しないことを保証できる。
- 効率: 大きい型でもコピーせず参照で受け取れる。
- 一時オブジェクト対応: `const` 参照なら一時値にも束縛できる。

### 例
```cpp
template <typename T>
const T& min(const T& a, const T& b) {
    return (a < b) ? a : b;
}
```

`swap` は値を入れ替えるので `T&`（非const）を使う。
