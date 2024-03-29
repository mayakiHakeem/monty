# Monty Bytecode Interpreter

This is a simple Monty bytecode interpreter implemented in C. It reads bytecode files line by line, parses the instructions, and executes them accordingly. The Monty language is a simple stack-based language used for learning and experimenting with programming concepts.

## Table of Contents
- [Overview](#Overview)
- [Features](#Features)
- [Usage](#Usage)
- [Contributing](#Contributing)
- [License](#License)

## Overview
Monty is a project that aims to interpret Monty bytecode files containing instructions to manipulate a stack data structure. It reads instructions from a file, parses them, and executes them to perform operations like pushing values onto the stack, popping values, performing arithmetic operations, and more.

## Features
- Interpretation of Monty bytecode instructions
- Stack-based data structure operations
- Support for various operations such as push, pop, add, subtract, multiply, divide, etc.
- Error handling for invalid instructions, stack underflow, and memory allocation failures

## Usage
To use the Monty interpreter, follow these steps:

1. Compile the source code using gcc or any C compiler:

```gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty```

2. Run the interpreter with a Monty bytecode file as input:

```./monty bytecode_file.m```

Replace bytecode_file.m with the path to your Monty bytecode file.

For more examples and detailed usage, refer to the Monty language documentation.

## Contributing
Contributions to this project are welcome! If you find any issues, have suggestions for improvements, or want to add new features, feel free to open an issue or submit a pull request.

Before contributing, please review the [Contribution Guidelines]().

## License
This project is licensed under the MIT License - see the [LICENSE]() file for details.
