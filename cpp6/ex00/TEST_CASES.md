# ex00 ScalarConverter テストケース（日本語）

出力の改行は省略しています。代表例のみ記載。

## 1. char リテラル
入力: `A`
出力:
- char: 'A'
- int: 65
- float: 65.0f
- double: 65.0

入力: ` `
出力:
- char: ' '
- int: 32
- float: 32.0f
- double: 32.0

## 2. int リテラル
入力: `42`
出力:
- char: '*'
- int: 42
- float: 42.0f
- double: 42.0

入力: `0`
出力:
- char: Non displayable
- int: 0
- float: 0.0f
- double: 0.0

入力: `-1`
出力:
- char: impossible
- int: -1
- float: -1.0f
- double: -1.0

入力: `2147483648`
出力:
- char: impossible
- int: impossible
- float: 2147483648.0f
- double: 2147483648.0

## 3. float リテラル
入力: `3.14f`
出力:
- char: Non displayable
- int: 3
- float: 3.1f
- double: 3.1

入力: `.5f`
出力:
- char: Non displayable
- int: 0
- float: 0.5f
- double: 0.5

入力: `nanf`
出力:
- char: impossible
- int: impossible
- float: nanf
- double: nan

入力: `-inff`
出力:
- char: impossible
- int: impossible
- float: -inff
- double: -inf

## 4. double リテラル
入力: `-12.0`
出力:
- char: Non displayable
- int: -12
- float: -12.0f
- double: -12.0

入力: `1.`
出力:
- char: Non displayable
- int: 1
- float: 1.0f
- double: 1.0

入力: `+inf`
出力:
- char: impossible
- int: impossible
- float: +inff
- double: +inf

## 5. 無効な入力
入力: `42f`
出力:
- char: impossible
- int: impossible
- float: impossible
- double: impossible

入力: `'ab'`
出力:
- char: impossible
- int: impossible
- float: impossible
- double: impossible

入力: `'A'`
出力:
- char: impossible
- int: impossible
- float: impossible
- double: impossible
