*This project has been created as part of the 42 curriculum by mkaneko.*

# ft_printf

## Description
This project is a re-implementation of the C standard library function printf().
It uses stdarg.h to handle variable arguments and outputs formatted data to the standard output based on format specifiers beginning with %.

Key points:

Uses va_start to begin processing variable arguments and va_end to finish.

Implements format‑specific behavior inside the handle_format() function.

Ensures that the position of the variable argument list remains consistent across function calls, preventing misalignment.

Handles large values such as INT_MIN and LONG_MAX by carefully selecting the correct types when using va_arg.

Splits functionality into separate output functions for readability and maintainability.

## Supported Conversions
Specifier	Description
%c	Prints a single character
%s	Prints a string (safe handling of NULL)
%p	Prints a pointer in hexadecimal format (handles NULL)
%d	Prints a signed decimal integer
%i	Prints a signed decimal integer
%u	Prints an unsigned decimal integer
%x	Prints a lowercase hexadecimal number
%X	Prints an uppercase hexadecimal number
%%	Prints a literal % character


## Build Instructions
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

libcの**printf()**を再実装しました.  
可変引数を扱うために `stdarg.h` を使用し、`%` で始まるフォーマット指定子に応じて標準出力へ出力する機能を実装しました。

主なポイント：

- `va_start` で可変引数処理を開始し、`va_end` で終了する基本構造を採用。
- `handle_format()` にてフォーマット指定子ごとの処理を分岐。
- 可変引数の読み取り位置がずれないよう、関数分割後も **常に同じ参照位置を維持**するよう注意。
- `INT_MIN` や `LONG_MAX` などの大きな値にも対応するため、`va_arg` の型指定を正確に実装。
- 出力形式ごとに関数を分割し、読みやすく保守しやすい構造に。

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
cc main.c -I ft_printf/includes -L ft_printf -lftprintf -o myprogram
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
