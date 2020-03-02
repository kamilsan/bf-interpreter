## Brainfuck interpreter

Simple interpreter of an esoteric programming language called Brainfuck. It assumes that the memory tape consists of 30000 cells, where each of them can store an integer. When interpreted program will try to access a cell outside the range, an error will occur. Characters that are not a part of the language will be ignored during interpretation.

### Build

```bash
cmake .
make
```

### Usage

```bash
./bf source_code.bf
```

