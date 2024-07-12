# Minishell

Minishell is a simple shell program implemented in C, designed as a project for 42 Paris. It aims to replicate the basic functionalities of a Unix shell, providing a command-line interface for users to interact with the operating system.

## Table of Contents

- [Minishell](#minishell)
  - [Table of Contents](#table-of-contents)
  - [Features](#features)
  - [Installation](#installation)
  - [Usage](#usage)
  - [Project Structure](#project-structure)
  - [Contributing](#contributing)
  - [License](#license)

## Features

-   Command execution with arguments
-   Environment variable management
-   Input/output redirection
-   Piping between commands
-   Signal handling
-   Built-in commands like `echo`, `cd`, `pwd`, `export`, `unset`, `env`, and `exit`

## Installation

To build and run Minishell, follow these steps:

1. Clone the repository:

-   `git clone https://github.com/Dang-Hai-Tran/minishell_42.git`
-   `cd minishell_42`

2. Build and run Minishell:

-   `make`
-   `./bin/minishell`

## Usage

Once you have started Minishell, you can use it like any other Unix shell. For example:

-   Execute a command: `ls -l`
-   Use build-in commands: `echo "Hello, World!"`, `cd path_to_directory`, `pwd`, `export name="value"`, `unset name`, `env`, and `exit`
-   Use input/output redirection: `ls -l > output.txt`, `cat < input.txt`
-   Use pipes: `ls -l | grep lib`

## Project Structure

The project is organized as follows:

-   `srcs/`: Contains the source code files.
    -   `exec/`: Execution-related functions.
    -   `env/`: Environment variable management.
    -   `parser/`: Command parsing and syntax analysis.
    -   `redirect/`: Input/output redirection handling.
    -   `signal/`: Signal handling.
    -   `builtins/`: Built-in command implementations.
    -   `error/`: Error handling functions.
    -   `subshell/`: Subshell creation and management.
-   `incs/`: Header files.
-   `libft/`: Custom library functions.
-   `Makefile`: Build configuration.

## Contributing

Contributions are welcome! If you have any suggestions or improvements, feel free to open an issue or submit a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
