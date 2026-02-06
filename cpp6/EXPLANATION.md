# cpp6 学習ポイント（課題別）

## ex00（Conversion of scalar types）
- 入力リテラルの判定: 文字列から char/int/float/double/疑似リテラルを見分ける。
- 文字列→数値変換: `strtol`/`strtod`/`stringstream` などで数値化する流れを理解する。
- 型変換とキャスト: 1つの型にした後、`static_cast` で他の型へ明示変換する考え方。
- 範囲チェックと例外扱い: `std::numeric_limits` を使って overflow/不可能を判定する。
- 出力ルール: 表示不能文字は `Non displayable`、変換不可は `impossible` を出す。

## ex01（Serialization）
- `reinterpret_cast` の用途: ポインタと整数型の相互変換に使う。
- `uintptr_t` の意味: ポインタを安全に保持できる符号なし整数型。
- 非インスタンス化クラス: `Serializer` を private コンストラクタで生成禁止にする。
- 非空構造体の用意: `Data` にメンバを持たせることで「空でない」条件を満たす。
- 同一性のテスト: serialize→deserialize して元のポインタと一致するか確認する。

## ex02（Identify real type）
- 多態性の前提: `Base` に仮想デストラクタを持たせる。
- `dynamic_cast` の違い: ポインタ版は `NULL`、参照版は例外で失敗を検出する。
- `typeinfo` 禁止の対応: キャスト成否で型を判定する。
- ランダム生成: `rand()` を使って A/B/C を生成する流れを作る。
- メモリ管理: `new` したものを `delete` する基本を守る。

## 参考サイト
[様々なキャスト](https://zenn.dev/okyugog/articles/06708132761b35)
