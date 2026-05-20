*This project has been created as part of the 42 curriculum by mkaneko.*

# ft_printf

## Description
Description
This project is an implementation of a custom printf function created as part of the 42Tokyo curriculum.
It reproduces the behavior of the standard printf by printing output according to the specified format.


### Overall Processing Flow
	(1)Iterate through the format string one character at a time.

	(2)Print normal characters directly using write(1, ...).

	(3)When encountering '%', treat the next character as a format specifier.

	(4)Delegate processing to handle_format().

	(5)Retrieve the corresponding argument using va_arg.

	(6)Call the appropriate output function depending on the specifier.

	(7)Accumulate and return the total number of printed characters.

Because this implementation writes directly to the output without using buffers,
no dynamic memory allocation is required, making the design simple and safe.

### The data structure being used
	● va_list (Variadic Arguments)
		Used to handle multiple arguments in the same way as the standard printf.

		Passing va_list* allows multiple functions to share the same argument list.

		The typical usage flow is:

			Declare: va_list args

			Initialize: va_start(args, first_argument)

			Retrieve: va_arg(args, type) (advances to the next argument)

			cleanup: va_end(args)

		This mechanism requires no memory allocation and is efficient.

	● Other Data Structures
		No arrays, structs, or linked lists are used.

#### Reasons:

	Characters are printed sequentially using write.

	Numeric conversion is handled recursively.

	Almost no state needs to be maintained, so using a struct would not provide benefits.

#### Algorithm of each format specifier
##### %d, %i (Signed Integers)
	- Retrieve an int and cast it to long for safe negative handling.

	- If negative, print '-' and convert to a positive value.

	- Convert using print_digit(n, 10, 0).

	- print_digit prints digits recursively from the most significant digit.

##### %u (Unsigned Integer)
	- Retrieve an unsigned int.

	- Convert using print_digit(n, 10, 0).

##### %x, %X (Hexadecimal)
	- Retrieve an unsigned int.

	- Convert using print_digit(n, 16, upper).

	- Switch between "0123456789abcdef" and "0123456789ABCDEF" depending on the upper flag.

##### %p (Pointer)
	- Cast void* to unsigned long.

	- Print (nil) if the pointer is NULL.

	- Print "0x" prefix.

	- Convert using print_pointer() (recursive hex conversion).

＜Improvement＞
If the printed length had been stored inside print_ptr,
print_digit() could have been reused instead of implementing print_pointer().
This is noted as a future improvement.


- Recursion allows printing digits from the most significant position without using buffers.

- Centralizing base conversion in print_digit reduces code duplication.

- Using unsigned long for pointers avoids architecture‑dependent issues.

- Passing va_list by pointer allows safe sharing across multiple functions.

- No dynamic memory allocation ensures there is no risk of memory leaks.

##### test
Tested using Tripouille’s printfTester.
```
make m PATH=../ft_printf
```
#### files
All files are placed in the same directory (following the 42 rule of max 5 functions per .c file).

```
Makefile
README.md
ft_printf.h
ft_printf.c
ft_printf_functions.c
ft_print_pointer.c
```

##### Code Overview

- ft_printf.c

	- ft_printf

	- handle_format

	- print_int

	- print_hex

- ft_printf_functions.c

	- print_unsigned

	- print_digit

	- print_str

	- print_char

- ft_print_pointer.c

	- print_ptr

	- print_pointer


##### Specifier	Description
| Specifier | Description |
|----------|-------------|
| `%c` | Print a single character |
| `%s` | Print a string (handles NULL) |
| `%p` | Print a pointer in hexadecimal (handles NULL) |
| `%d` | Signed decimal integer |
| `%i` | Signed integer |
| `%u` | Unsigned decimal integer |
| `%x` | Hexadecimal (lowercase) |
| `%X` | Hexadecimal (uppercase) |
| `%%` | Print a literal % |



## Instruction
#### Makefile
- `make` / `make all` → builds libftprintf.a

- `make clean` → removes object files

- `make fclean` → removes object files + library

- `make re` → rebuild from scratch

### Compilation
```
cc -Wall -Wextra -Werror

Include the header in your source file:
```
```
c
#include "ft_printf.h"
Compile and link with the library:
```
c 
```
make
cc main.c -Wall -Wextra -Werror -L. -lftprintf
```


## Resources
https://programming-place.net/ppp/contents/c/appendix/reference/printf.html

https://en.cppreference.com/w/c/io/fprintf

https://qiita.com/keitean/items/7cd52af571d27a1173d0

man printf

These were used to understand the behavior of the standard printf.

### Use of AI
	AI was used for structuring and refining the README text.
	Advice was also taken when debugging unclear errors.



## 説明 Description

42Tokyo の課題として作成した、自作の printf 関数の実装です。
標準の printf と同様、指定されたフォーマットに従って出力を行います。

### アルゴリズムとデータ構造の詳細
#### 全体の処理の流れ
	1.format を 1 文字ずつ走査

	2.通常文字はそのまま write(1, …)

	3.'%' を検出したら次の文字をフォーマット指定子として解釈

	4.handle_format() に処理を委ねる。

	5.指定子に応じて va_arg で値を取得

	6.専用の出力関数で書き込み

	7.出力した文字数を合計して返す

バッファを使わずに直接 write するため、メモリ確保が不要で安全な実装になっています。

#### 使用しているデータ構造
##### ● va_list（可変長引数）
	標準 printf と同じ仕組みで複数の引数を扱える。

	・va_list* を渡すことで、複数の関数で同じ引数列を共有できる。
 		このマクロは、
		va_list args(任意)を宣言、
		va_start(args,第一引数)で初期化、
		va_arg(args, 型)で指定した型のサイズ分,引数を引き出し次の引数へと読み込み位置を進め、
		va_end(args)でクリーンナップを行うという流れで使用します。

	・メモリ確保が不要で高速。

##### ● その他のデータ構造
	配列・構造体・リストなどは使用していません。

###### 理由：

	・文字出力は逐次 write で十分・

	・数値変換は再帰で桁を分解できる・

	・状態管理がほぼ不要で、構造体を使うメリットがない。

#### 各フォーマット指定子のアルゴリズム

##### %d, %i（符号付き整数）
	・int を取得し、long にキャストして負数を安全に扱う

	・負数なら '-' を出力し、正の値に変換

	・print_digit(n, 10, 0) で 10 進数に変換

	・print_digit は再帰で上位桁から出力

##### %u（符号なし整数）
	・unsigned int を取得

	・print_digit(n, 10, 0) をそのまま使用

##### %x, %X（16進数）
	・unsigned int を取得

	・print_digit(n, 16, upper) を使用

	・"0123456789abcdef" / "0123456789ABCDEF" を切り替え

##### %p（ポインタ）
	・void* を unsigned long にキャスト

	・NULL の場合は (nil) を出力

	・"0x" を出力

	・print_pointer() で 16 進数変換（再帰）

＜改善点＞

	print_ptr 内で長さを保持しておけば、
	print_pointer() ではなく print_digit() を再利用できた。
	次回の改善ポイントとして記録。
---

###  設計の正当化
	・再帰を使うことで、バッファなしで桁を上位から出力できる。

	・基数変換を print_digit に集約し、コードの重複を避けた。

	・ポインタは unsigned long で扱い、アーキテクチャ依存の問題を避けた。

	・va_list をポインタで渡すことで、複数の関数で同じ引数列を安全に共有できる。

	・メモリ確保を行わないため、リークの心配がない安全な実装。

### テスト
	Tripouille の printfTester を使用して動作確認済み。
	```
	make m PATH=../ft_printf
	```
---

### ファイル構成

📂 ファイル構成
すべて同じディレクトリに配置しています（42 の「1 ファイル 5 関数」制限に対応）。

コード

	Makefile
	README.md
	ft_printf.h
	ft_printf.c
	ft_printf_functions.c
	ft_print_pointer.c
	ft_printf.c


- ft_printf.c 
	- ft_printf
	- handle_format
	- print_int
	- print_hex
	
- ft_printf_functions
	- print_unsigned
	- print_digit
	- print_str
	- print_char


- ft_print_pointer.c
	- print_ptr
	- print_pointer

---

### 対応した変換

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

## ビルド方法 Instruction

### Makefile

- `make` / `make all`  
  → アーカイブファイル（libftprintf.a）を作成  
- `make clean`  
  → オブジェクトファイルを削除  
- `make fclean`  
  → アーカイブファイル + オブジェクトファイルを削除  
- `make re`  
  → 全削除後に再ビルド  

#### コンパイル
```
- cc -Wall -Wextra -Werror
```

### 使い方

1. ソースにヘッダーファイルを追加：

```c
#include "ft_printf.h"
```
2. コンパイル時にライブラリをリンク。

```
make
cc main.c -Wall -Wextra -Werror -L. -lftprintf
```
---

## 参考文献 Resources

https://programming-place.net/ppp/contents/c/appendix/reference/printf.html

https://en.cppreference.com/w/c/io/fprintf (en.cppreference.com in Bing)

https://qiita.com/keitean/items/7cd52af571d27a1173d0

man printf

printf の挙動理解のために参考にしました。

## AIの利用

README の構成と文章の整形に AI を使用しました。

エラー原因が分からないときにアドバイスを受けました。
