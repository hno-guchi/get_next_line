# get_next_line

get_next_lineは、ファイルディスクリプターから1行ずつ読み取る関数です。
`\n`をデリミタとします。

## インストール

```sh
make
```

これで`get_next_line.a` という静的ライブラリが生成されます。

## 使い方

1. `get_next_line.a` をコンパイル時にリンクします。
2. `get_next_line.h` をインクルードして使用します。

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void) {
    int fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        return (1);
    }
    char *line = NULL;
    while ((line = get_next_line(fd))) {
        if (!line) {
            break;
        }
        printf("%s", line);
        free(line);
        line = NULL;
    }
    close(fd);
    return (0);
}
```

コンパイル:

```sh
gcc -Wall -Wextra -Werror main.c -L. -lgnl -o [my_program]
```

## 関数の動作
- `get_next_line` は、与えられたファイルディスクリプターから1行ずつ読み取り、`\n` を含む文字列として返します。
- ファイルの終端に達すると `NULL` を返します。
- 内部バッファを使用し、効率的に読み取りを行います。
