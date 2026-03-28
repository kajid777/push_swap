# push_swap

## 目的

2 つのスタック（A と B）のみを使って、整数の列を昇順に並べ替えるプログラムです。  
並べ替えに必要な操作（`sa`、`pb`、`ra` など）を標準出力に 1 行ずつ出力します。  
42 School の課題「push_swap」の C 言語実装です。

---

## 使い方

```bash
make
./push_swap 3 1 4 1 5 9 2 6
```

または、スペース区切りの 1 文字列として渡すことも可能です。

```bash
./push_swap "3 1 4 1 5 9 2 6"
```

出力される操作の数が少ないほど優秀なアルゴリズムです。

---

## アルゴリズムの概要

### 1. 座標圧縮（Coordinate Compression）

入力された整数を順位（0 〜 n−1）に変換します。これにより、値の大小関係を保ちながら符号なし整数として扱えるようになり、その後の Radix ソートに対応できます。

### 2. 小規模ソート（要素数 ≤ 5）

2 〜 5 要素はパターンをハードコードした専用手順で処理します。

| 要素数 | 手法 |
|--------|------|
| 2      | `sa` のみ |
| 3      | 3 要素の大小パターン（5 通り）を判定して固定操作列を適用 |
| 4 / 5  | 最小値の位置を特定してスタック B に退避し、残り 3 要素を上記の 3 要素ソートで処理後、`pa` で戻す |

### 3. 大規模ソート（要素数 > 5）：二進 Radix Sort（LSD）

座標圧縮で得た非負整数に対して、LSB（最下位ビット）から順にビットごとに分類します。

- ビットが `0` → `pb`（スタック B へ push）
- ビットが `1` → `ra`（スタック A を rotate）

1 パスが終わったらスタック B の全要素を `pa` で戻します。これを必要なビット数だけ繰り返すことで、O(n × bit_len) 回の操作で整列します。

---

## ディレクトリ構成

```
push_swap/
├── main.c                    # エントリポイント。引数解析とリスト構築
├── push_swap.h               # Node 構造体と全関数のプロトタイプ宣言
├── Makefile                  # ビルド定義
│
├── node_initialization.c     # ノード生成・リスト構築・整数配列化
├── coordinate_compression.c  # 選択ソートによる座標圧縮
├── bit_operations.c          # 最大値・必要ビット長の取得
│
├── sort.c                    # メインのソート処理（radix + 小規模の振り分け）
├── simple_sort.c             # 2〜5 要素の分岐ロジック
├── sort_3_mods.c             # 3 要素各パターンの操作列
├── sort_4_mods.c             # 4 要素各パターンの操作列
├── sort_5_mods.c             # 5 要素各パターンの操作列
│
├── node_operations_1.c       # sa / sb / ss / pa / pb
├── node_operations_2.c       # ra / rb / rr（rotate）
├── node_operations_3.c       # rra / rrb / rrr（reverse rotate）
│
├── utils.c                   # スタックサイズ・パターン判定・昇順チェック
├── handle_errors.c           # 重複チェック・全ノード解放
├── errors.c                  # 無効文字検査・エラー終了
│
└── ft_printf/                # 自作 ft_printf ライブラリ
    ├── ft_printf.c           # ft_printf 本体
    ├── ft_printf_utils.c     # 共通ヘルパ
    ├── ft_print_hex.c        # %x / %X
    ├── ft_print_unsigned.c   # %u
    ├── ft_print_ptr.c        # %p
    ├── ft_printf.h
    ├── Makefile              # libftprintf.a のビルド
    └── libft_srcs/           # 自作 libft ライブラリ
        ├── ft_atoi.c
        ├── ft_split.c
        ├── ft_itoa.c
        └── ...（その他 libft の標準関数群）
```

---

## データ構造

スタック A / B はいずれも **双方向循環リンクリスト** で実装されています。

```c
typedef struct s_node
{
    int             data_num;
    struct s_node   *next;
    struct s_node   *prev;
} t_node;
```

先頭ポインタが「トップ」として機能し、各操作（`ra`、`rra` など）はポインタの付け替えで O(1) で実現されています。

---

## ビルド

```bash
make        # push_swap をビルド
make clean  # オブジェクトファイルを削除
make fclean # 実行ファイルも含めて削除
make re     # fclean + all
```
