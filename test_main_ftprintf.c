 #include <stdio.h>

int ft_printf(const char *format, ...);

int main(void) {
    int ret_std;
    int ret_ft;

    printf("========================================\n");
    printf("        ft_printf TEST SUITE           \n");
    printf("========================================\n\n");

    // 1. 文字列のみのテスト
    printf("[1. 文字列のみ]\n");
    ret_std = printf("STD: Hello, World!\n");
    ret_ft  = ft_printf("FT : Hello, World!\n");
    printf("Return Value -> STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // 2. 文字 (%c) のテスト
    printf("[2. 文字 (%%c)]\n");
    ret_std = printf("STD: Character: %c %c %c\n", 'A', 'b', '*');
    ret_ft  = ft_printf("FT : Character: %c %c %c\n", 'A', 'b', '*');
    printf("Return Value -> STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // 3. 文字列 (%s) のテスト
    printf("[3. 文字列 (%%s)]\n");
    ret_std = printf("STD: String: %s\n", "Embedded System / 42Tokyo");
    ret_ft  = ft_printf("FT : String: %s\n", "Embedded System / 42Tokyo");
    printf("Return Value -> STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // 4. 整数 (%d, %i) のテスト
    printf("[4. 整数 (%%d, %%i)]\n");
    ret_std = printf("STD: Int: %d | Zero: %d | Minus: %i\n", 2147483647, 0, -2147483648);
    ret_ft  = ft_printf("FT : Int: %d | Zero: %d | Minus: %i\n", 2147483647, 0, -2147483648);
    printf("Return Value -> STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // 5. 符号なし整数 (%u) のテスト
    printf("[5. 符号なし整数 (%%u)]\n");
    ret_std = printf("STD: Unsigned: %u | Max: %u\n", 12345, 4294967295U);
    ret_ft  = ft_printf("FT : Unsigned: %u | Max: %u\n", 12345, 4294967295U);
    printf("Return Value -> STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // 6. 16進数 (%x, %X) のテスト
    printf("[6. 16進数 (%%x, %%X)]\n");
    ret_std = printf("STD: hex: %x | HEX: %X | Zero: %x\n", 255, 3735928559U, 0);
    ret_ft  = ft_printf("FT : hex: %x | HEX: %X | Zero: %x\n", 255, 3735928559U, 0);
    printf("Return Value -> STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // 7. ポインタ (%p) のテスト
    printf("[7. ポインタ (%%p)]\n");
    int num = 42;
    void *ptr = &num;
    ret_std = printf("STD: Pointer: %p | Null: %p\n", ptr, NULL);
    ret_ft  = ft_printf("FT : Pointer: %p | Null: %p\n", ptr, NULL);
    printf("Return Value -> STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // 8. パーセント記号 (%%) のテスト
    printf("[8. パーセント記号 (%%%%)]\n");
    ret_std = printf("STD: Success Rate: 100%%\n");
    ret_ft  = ft_printf("FT : Success Rate: 100%%\n");
    printf("Return Value -> STD: %d | FT: %d\n\n", ret_std, ret_ft);

    // 9. 連続したフォーマットのテスト
    printf("[9. 複合テスト]\n");
    ret_std = printf("STD: %c%s%d%x%%\n", 'C', "lang", 2026, 42);
    ret_ft  = ft_printf("FT : %c%s%d%x%%\n", 'C', "lang", 2026, 42);
    printf("Return Value -> STD: %d | FT: %d\n\n", ret_std, ret_ft);

    printf("========================================\n");
    printf("             TEST END                  \n");
    printf("========================================\n");

    return (0);
}
