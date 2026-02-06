# ex00 ScalarConverter 解説（日本語）

## 概要
このドキュメントは `ScalarConverter::convert()` の入力判定の流れと、
`printFromDouble()` が `double` を各型へどう出力するかを整理したものです。

## convert(): 入力 -> double -> 出力
上から順に判定し、最初に一致したものだけが処理されます。

1. char リテラル
   - `isCharLiteral()` は `'x'` のように長さ3・単一引用符で囲まれた1文字のみ許可
   - 変換: `char c = literal[1]` -> `printFromDouble((double)c, false)`
2. 疑似値（nan/inf）
   - `-inff`, `+inff`, `nanf`, `-inf`, `+inf`, `nan`
   - 変換: `printPseudo()` で固定文字列を出力（数値変換なし）
3. int リテラル
   - `isIntLiteral()` は符号 + 数字列のみ
   - 変換: `std::strtol` -> `printFromDouble((double)val, false)`
4. float リテラル
   - `isFloatLiteral()` は小数点必須 + 末尾 `f`
   - 変換: `std::strtod` -> `printFromDouble(val, true)`
5. double リテラル
   - `isDoubleLiteral()` は小数点必須
   - 変換: `std::strtod` -> `printFromDouble(val, false)`
6. どれにも一致しない
   - 4種類すべて `impossible` を出力

## printFromDouble(): double -> char / int / float / double
1つの `double` 値から4種類の表現を出力します。

- char
  - NaN / ±inf / [0,127] 以外は `char: impossible`
  - 範囲内でも `std::isprint` が偽なら `char: Non displayable`
  - それ以外は `'c'` 形式で表示
- int
  - NaN または `int` 範囲外は `int: impossible`
  - それ以外は `static_cast<int>(value)` を表示
- float / double
  - `std::fixed` + `setprecision(1)` で小数1桁固定
  - float: `static_cast<float>(value)` + `f`
  - double: `value` をそのまま表示
  - `wasFloatLiteral == false` の場合は `unsetf(floatfield)` で `fixed` を解除
  - 注意: `unsetf(floatfield)` は `fixed/scientific` のみ解除するため、
    `setprecision(1)` は残ります（同じ `std::cout` を使うなら影響あり）

## isCharLiteral() の判定
`isCharLiteral()` は「表示可能な1文字 + 単一引用符」のみ許可します。

- OK: `'a'`
- NG: `''`, `'ab'`, `'\n'`
