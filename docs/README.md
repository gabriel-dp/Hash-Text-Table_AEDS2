# Hash Text Table (Docs)

The challenge is to use a hash table to search the occurrences of a word in a text, making a program efficient in its CPU and memory usage. In addition to producing the software, the duo must develop a complete documentation on what was done to reach the final product.

&nbsp;

[![button](./docs-button.png)](./original-instructions.pdf)

&nbsp;

## Understanding the problem

[`> See original work instructions (PDF) <`](./original-instructions.pdf)

---

### Important instructions details

- Hash table must use Open Adressing
- Each word must be assigned to a unique slot
- Ignore single character words
- Ignore UPPER and lower case differences

---

### Input

The program must to read two files

- input.txt
- pesquisa.txt

#### input.txt

Random text with some limitations like described below.

```txt
Pedra, papel, tesoura, lagarto, Spock.
Eh muito simples! Olhe - tesoura corta papel, papel cobre pedra, pedra esmaga lagarto,
lagarto envenena Spock, Spock esmaga tesoura, tesoura decapita lagarto, lagarto come papel,
papel refuta Spock, Spock vaporiza pedra e como sempre, pedra quebra tesoura...
Sheldon Cooper
```

```c
// Text Limitations
#define MAX_WORDS_INPUT 256
#define MAX_CHAR_PER_WORD 20
#define MAX_CHAR_PER_LINE 80
```

#### pesquisa.txt

Random words to be searched in the input file, one per line. The first line contains the words quantity.

```c
6
lagarto
papel
pedra
spock
tesoura
esmaga
```

---

### Output

The result must be printed on console. Each line must have quantity, word and occurrences separated with spaces.

`quantity word lines`

```c
5 lagarto 1 2 3
5 papel 1 2 3 4
5 pedra 1 2 4
5 spock 1 3 4
5 tesoura 1 2 3 4
2 esmaga 2 3
```
