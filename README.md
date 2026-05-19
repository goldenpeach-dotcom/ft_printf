*This project has been created as part of the 42 curriculum by mkaneko.*

# ft_printf

## Description
This project is a re-implementation of the C standard library function printf().
I've reimplemented IBC's printf().

To handle variable arguments (functions with a different number of arguments each time), you need to use macros from `stdarg.h`.

This macro is used in the following way:
Declare `va_list args(arbitrary)`,
Initialize with `va_start(args, first argument)`,
Retrieve arguments of the specified type size using `va_arg(args, type)`, advance the reading position to the next argument, and
Perform cleanup with `va_end(args)`.

This macro is used in the main `ft_printf(const char *format, ...)` function to illustrate the flow.

It reads each character within the first argument's quotation marks.

If a `%` appears before the end,
it passes it as a pointer to the `handle_format` function, which uses `va_arg` for manipulation.

For characters other than '%', it immediately outputs using the `write` function and counts the number of characters.

In `handle_format`, the function is divided according to the format specifier to match the type.
Each output function uses the `write` function to output to standard output and returns a value.

When returning to `ft_printf`, the number of characters is counted from the return value, and `va_end` cleans up `va_list`, returning the last number of characters output before terminating.

Key points:

Uses va_start to begin processing variable arguments and va_end to finish.

Implements format‑specific behavior inside the handle_format() function.

Ensures that the position of the variable argument list remains consistent across function calls, preventing misalignment.

Handles large values such as INT_MIN and LONG_MAX by carefully selecting the correct types when using va_arg.

Splits functionality into separate output functions for readability and maintainability.

## Supported Conversions
Specifier	Description
- %c	Prints a single character
- %s	Prints a string (safe handling of NULL)
- %p	Prints a pointer in hexadecimal format (handles NULL)
- %d	Prints a signed decimal integer
- %i	Prints a signed decimal integer
- %u	Prints an unsigned decimal integer
- %x	Prints a lowercase hexadecimal number
- %X	Prints an uppercase hexadecimal number
- %%	Prints a literal % character


## Instructions
### Makefile

make / make all  
Creates the archive library (libftprintf.a)

make clean  
Removes object files

make fclean  
Removes object files and the archive library

make re  
Cleans everything and rebuilds from scratch

### Compilation

cc -Wall -Wextra -Werror
How to Use
Include the header file in your source:

c
#include "ft_printf.h"
Link the library during compilation:

bash
make
cc main.c -I ft_printf/includes -L ft_printf -lftprintf -o myprogram

## Resources

https://programming-place.net/ppp/contents/c/appendix/reference/printf.html

https://en.cppreference.com/w/c/io/fprintf

https://qiita.com/keitean/items/7cd52af571d27a1173d0

man printf

These resources were used to understand the behavior and specifications of the standard printf function.

## Use of AI
AI assistance was used to format and refine the structure of this README.

AI provided advice when debugging issues that were difficult to identify.




## 説明

libcのprintf()を再実装しました。
可変引数（引数の数が毎回変わる関数）を扱うためには `stdarg.h`のマクロ を使用する必要があります。
このマクロは、
va_list args(任意)を宣言、
va_start(args,第一引数)で初期化、
va_arg(args, 型)で指定した型のサイズ分,引数を引き出し次の引数へと読み込み位置を進め、
va_end(args)でクリーンナップを行うという流れで使用します。

このマクロを、流れがわかるようにメインのft_printf(const char *format, ...)の中で使いました。
第一引数の""で囲まれた中を１文字ずつ見ていきます。
終端までの間で`%`が出てきたら、
va_arg を使って操作する関数handle_formatへポインタの形で渡します。
'%'以外の文字の場合は、write関数で即出力し、文字数をカウントします。
handle_formatでは、フォーマット指定子によって、型に合うよう関数を分けました。
それぞれの出力関数でも、write関数を利用して標準出力し、戻り値を返します。

ft_printfに戻るときに返り値から文字数をカウントし、
va_endでva_listをクリーンアップして最後に出力した文字数を返して終了です。


主なポイント：

- `va_start` で可変引数処理を開始し、`va_end` で終了する基本構造を採用。
- `handle_format()` にてフォーマット指定子ごとの処理を分岐。
- 可変引数の読み取り位置がずれないよう、関数分割後も 常に同じ参照位置を維持するよう注意。
- `INT_MIN` や `LONG_MAX` などの大きな値にも対応するため、`va_arg` の型指定を正確に実装。
- 出力形式ごとに関数を分割し、読みやすく保守しやすい構造に。数字の出力に関しては16進数まで同じ関数で変換できるように作成。
- 第一引数がNULLのときは,printfがエラーのときの動きに合わせ、return(-1)としました。
---

## 対応した変換

| Specifier | Description |
|----------|-------------|
| `%c` | 1文字を出力 |
| `%s` | 文字列を出力（NULL も安全に処理） |
| `%p` | ポインタを16進数で表示（NULL対応） |
| `%d` | 10進数（符号付き） |
| `%i` | 10進数の整数 |
| `%u` | 10進数（符号なし） |
| `%x` | 16進数（小文字） |
| `%X` | 16進数（大文字） |
| `%%` | `%` をそのまま出力 |

---

## ビルド方法

### Makefile

- `make` / `make all`  
  → アーカイブファイル（libftprintf.a）を作成  
- `make clean`  
  → オブジェクトファイルを削除  
- `make fclean`  
  → アーカイブファイル + オブジェクトファイルを削除  
- `make re`  
  → 全削除後に再ビルド  

### コンパイル

- cc -Wall -Wextra -Werror


### 使い方

1. ソースにヘッダーファイルを追加：

```c
#include "ft_printf.h"
```
2. コンパイル時にライブラリをリンク。

```
make
cc main.c -Wall -Wextra -Werror -L. ft_printf -lftprintf
```
## 参考文献

https://programming-place.net/ppp/contents/c/appendix/reference/printf.html

https://en.cppreference.com/w/c/io/fprintf (en.cppreference.com in Bing)

https://qiita.com/keitean/items/7cd52af571d27a1173d0

man printf

printf の挙動理解のために参考にしました。

## AIの利用

README の構成と文章の整形に AI を使用しました。

エラー原因が分からないときにアドバイスを受けました。
