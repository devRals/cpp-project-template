# devRals's C++ Project Development Environment

A simple C++ project template using CMake and Nix.

The goal is to provide a reusable development environment without having to reinvent
the build setup for every project.
Only requirement for this template to use cmake for building the project.

## Getting Started

1. Clone this template: `git clone https://github.com/devRals/cpp-project-template.git .`
2. Create a debug build: `cmake -S . -B build/debug`

## Structure

```.
├── build/                 # Generated build files
│   ├── debug/
│   └── release/
├── include/               # Header files
├── lib/                   # Optional precompiled libraries
├── src/                   # Implemention Files
├── compile_commands.json  # A symlink to the build/debug/compile_commands.json to make sure
│                          # clangd (language server protocol) works correctly
├── CMakeLists.txt         # CMake build configuration
├── flake.nix              # Nix development environment
├── flake.lock             # Locked Nix dependencies
├── LICENSE
└── README.md
```

build/ and lib/ are ignored by Git.

## Commands for Development

| Command                                                  | Info                                                        |
| -------------------------------------------------------- | ----------------------------------------------------------- |
| `cmake -S . -B build/debug`                              | Configure debug build                                       |
| `cmake --build build/debug`                              | Build the project into the ./build/debug                    |
| `cmake -S . -B build/release -DCMAKE_BUILD_TYPE=Release` | Configure release build                                     |
| `cmake --build build/release`                            | Build the project in release mode in to the ./build/release |

## LICENSE

MIT
