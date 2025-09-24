#include <iostream>

struct X {
    void hello() {
        std::cout << "hello\n";
    }
    void twice(int n) {
        std::cout << n * 2 << "\n";
    }
};

int main() {
    X x;

    // 型エイリアス（メンバー関数ポインタ）
    typedef void (X::*F0)();       // 引数なし・戻り値void
    typedef void (X::*F1)(int);    // 引数1つint・戻り値void

    // 関数ポインタの代入
    F0 f0 = &X::hello;
    F1 f1 = &X::twice;

    // 実体オブジェクトで呼び出し
    (x.*f0)();        // → "hello"

    // ポインタオブジェクトで呼び出し
    X* px = &x;
    (px->*f0)();      // → "hello"

    // 引数つき関数を呼び出し
    (x.*f1)(21);      // → "42"
}

g++ -Wall -Wextra -std=c++98 test.cpp -o test
./test
