用語ミニ辞典（C++ 基本＋例付き）
==================================

クラスまわり
------------
- クラス (class)  
  型の設計図。例: `class Dog { void bark(); };`

- オブジェクト / インスタンス  
  設計図から作った実体。例: `Dog pochi;`

- コンストラクタ / デストラクタ  
  生成時初期化 / 破棄時後始末。例: `Dog()` / `~Dog()`.

- コピーコンストラクタ / コピー代入演算子  
  同型の複製。例: `Dog b(a);` / `b = a;`

- constメンバ / constメンバ関数  
  変更不可なメンバ / オブジェクトを変えないと約束する関数。例: `const std::string name;`、`std::string getName() const;`

- オーバーロード / オーバーライド  
  同名・引数違い（オーバーロード）、継承で同シグネチャ上書き（オーバーライド）。例: `void foo(int); void foo(double);` / `void Dog::speak()` が基底の `speak` を上書き。

継承・ポリモーフィズム
----------------------
- 継承 (inheritance)  
  基底の性質を受け継いで拡張。例: `class Animal { virtual void speak(); }; class Dog : public Animal { void speak(); };`

- 仮想関数 / 純粋仮想関数 (virtual / pure virtual)  
  ポリモーフィズム用。純粋仮想は「実装なし＝継承先で必須」。例: `virtual void speak();` / `virtual void speak() = 0;`

- 抽象クラス  
  純粋仮想関数を持ち直接インスタンス化できないクラス。例: `class Animal { virtual void speak() const = 0; };`

- ポリモーフィズム  
  基底型ポインタ/参照経由で派生の振る舞いを呼ぶ。例: `Animal *p = new Dog; p->speak(); // Dog版`

例外とエラーハンドリング
------------------------
- 例外 (exception)  
  異常時に `throw` で投げ、`try/catch` で受ける仕組み。例:  
  ```cpp
  try { throw std::runtime_error("err"); }
  catch (std::exception &e) { std::cout << e.what(); }
  ```

メモリとポインタ
----------------
- 参照 / ポインタ  
  参照はエイリアス（NULL不可）、ポインタはアドレス保持。例: `int x=1; int &r=x; int *p=&x;`

- ヒープ確保 / 解放  
  `new` で動的確保、`delete` で解放。配列は `new[]` / `delete[]`。例:  
  ```cpp
  int *p = new int(42); delete p;
  int *arr = new int[10]; delete[] arr;
  ```
  リーク防止にはRAII（スマートポインタ`std::auto_ptr`はC++98では非推奨、以降`unique_ptr`/`shared_ptr`）を活用。

- シャローコピー / ディープコピー  
  ポインタ先を共有する浅いコピー vs 中身を複製する深いコピー。動的メモリを持つクラスではコピーコンストラクタ/代入演算子で新規確保＋内容コピーが必要。

- RAII (Resource Acquisition Is Initialization)  
  コンストラクタで資源取得、デストラクタで解放。例:  
  ```cpp
  std::ofstream ofs("file.txt"); // ブロックを抜けると自動でclose
  ```

動的生成とポインタの型変換（本プロジェクトの具体例）
-----------------------------------------------
- `new 派生型` は「派生型のポインタ」を返す。例: `new ShrubberyCreationForm(...)` は `ShrubberyCreationForm*`。

- 派生ポインタは自動で基底ポインタにアップキャストできる。例: `ShrubberyCreationForm*` → `AForm*`。これで戻り値を `AForm*` にして多態的に扱う。

- アップキャスト: 派生 → 基底への暗黙変換で安全。逆のダウンキャストは危険なので `dynamic_cast` などを明示的に使う。

- 抽象クラス（AForm）は実体化できないため、値で返せない。ポインタ/参照で扱う。

- スライス防止: 派生オブジェクトを基底値にコピーすると派生部分が切り落とされるので、ポインタ/参照で保持する。

- `Intern::createShrubbery` のような生成関数は `AForm*` を返し、呼び出し側が `delete` する契約にする（C++98ではスマートポインタが弱いため）。

スコープと名前
--------------
- 作用域解決演算子 `::`  
  所属を明示。例: `std::cout`, `MyClass::member`.

- 名前空間 (namespace)  
  衝突回避の囲い。例:  
  ```cpp
  namespace util { void log(); }
  util::log();
  ```

- `::` を付ける理由（関数名の衝突回避）  
  同名の関数があるときに「どの関数を呼ぶか」を明示する。例:  
  ```cpp
  ::swap(a, b);   // グローバル関数
  std::swap(a, b); // 標準ライブラリ
  ```
  衝突がなければ `iter(...)` のように省略しても問題ない。

演算子関連
----------
- オペレータオーバーロード  
  自作型の演算子挙動を定義。例:  
  ```cpp
  std::ostream& operator<<(std::ostream& os, const Dog& d) {
      return os << d.getName();
  }
  ```

テンプレートとSTL
-----------------
- テンプレート  
  型非依存のコード生成。は「Tという型を呼び出し側で決める」という宣言
  例:  
  ```cpp
  template <typename T> T max(T a, T b) { return a>b ? a : b; }
  ```

- STL (Standard Template Library)  
  標準コンテナ/アルゴリズム群。例: `std::vector<int> v; /* モジュール08まで禁止 */`

- イテレータ  
  コンテナ要素を指す汎用ポインタ風オブジェクト。例:  
  ```cpp
  for (std::vector<int>::iterator it=v.begin(); it!=v.end(); ++it) { ... }
  ```

値カテゴリー
-------------
- 左辺値 / 右辺値 (lvalue / rvalue)  
  代入先になれるもの / 一時オブジェクト。例: `int x; x=3;`（xはlvalue、3はrvalue）。

小さな例セット
---------------
- 例外の基本:  
  ```cpp
  void f(int g) {
      if (g < 1) throw std::runtime_error("too high");
      if (g > 150) throw std::runtime_error("too low");
  }
  ```

- 仮想関数とポリモーフィズム:  
  ```cpp
  class Animal { public: virtual void speak() const = 0; };
  class Dog : public Animal { public: void speak() const { std::cout << "woof\n"; } };
  Animal *a = new Dog(); a->speak(); delete a;
  ```

- ヒープとコピーの注意:  
  ```cpp
  class Buffer {
      char *data;
  public:
      Buffer(size_t n) : data(new char[n]) {}
      Buffer(const Buffer& other) : data(new char[strlen(other.data)+1]) {
          std::strcpy(data, other.data); // ディープコピー
      }
      Buffer& operator=(const Buffer& other) {
          if (this != &other) {
              delete[] data;
              data = new char[strlen(other.data)+1];
              std::strcpy(data, other.data);
          }
          return *this;
      }
      ~Buffer() { delete[] data; }
  };
  ```
