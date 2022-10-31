# Hash Text Table (Docs)

Some intro here..........

---

- [The Problem](#the-problem)
  - [Description](#description)
  - [Input](#input)
  - [Output](#output)

---

&nbsp;

&nbsp;

## The problem

[`> See original work instructions (PDF) <`](./original-instructions.pdf)

---

### Description

```c
/*
** Important details
**
** Hash table must use Open Adressing
** Each word must be assigned to a unique slot
** Ignore single character words
** Ignore UPPER and lower case differences
*/
```

---

### Input

```c
// File names
const char* outputFile = "prog";
const char* inputFile = "input.txt";
const char* searchFile = "pesquisa.txt";
```

#### input.txt

Random text with some limitations like described below.

```c
// Text Limitations
const int MAX_WORDS_INPUT = 256;
const int MAX_CHAR_PER_WORD = 20;
const int MAX_CHAR_PER_LINE = 80;
```

```txt
Pedra, papel, tesoura, lagarto, Spock.
Eh muito simples! Olhe - tesoura corta papel, papel cobre pedra, pedra esmaga lagarto,
lagarto envenena Spock, Spock esmaga tesoura, tesoura decapita lagarto, lagarto come papel,
papel refuta Spock, Spock vaporiza pedra e como sempre, pedra quebra tesoura...
Sheldon Cooper
```

#### ./pesquisa.txt

Random words to be searched in the input file. The first line contains the words quantity.

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

#### ./prog

```txt
quantity word lines
```

```c
5 lagarto 1 2 3
5 papel 1 2 3 4
5 pedra 1 2 4
5 spock 1 3 4
5 tesoura 1 2 3 4
2 esmaga 2 3
```
