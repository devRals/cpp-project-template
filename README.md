# devRals's C++ Project Development Environment

A simple C++ project template using CMake and Nix.

The goal is to provide a reusable development environment without having to reinvent
the build setup for every project.
Only requirement for this template to use cmake for building the project.

## Getting Started

1. Clone this template: `git clone https://github.com/devRals/cpp-project-template.git .`
2. Create a debug build: `cmake -S . -B build && cmake --build build`

## Structure

```.
├── build/                 # Generated build files
├── include/               # Global header files
├── external/
│   ├── include/           # Header files of precompiled libraries
│   └── lib/
│       ├── shared/        # Shared libraries (.so, .dll files)
        └── static/        # Static libraries (.a, .lib files)
├── src/...                # Internal library source files
├── app/...                # Executable source files
├── compile_commands.json  # A symlink to the build/compile_commands.json to make sure
│                          # clangd (language server protocol) works correctly
├── CMakeLists.txt         # CMake build configuration
├── flake.nix              # Nix development environment
├── flake.lock             # Locked Nix dependencies
├── LICENSE                # MIT License
└── README.md
```

## Commands for Development

| Command                                          | Info                                                |
| ------------------------------------------------ | --------------------------------------------------- |
| `cmake -S . -B build`                            | Configure debug build                               |
| `cmake --build build`                            | Build the project into the ./build                  |
| `cmake -S . -B build -DCMAKE_BUILD_TYPE=Release` | Configure release build                             |
| `cmake --build build`                            | Build the project in release mode in to the ./build |

## LICENSE

MIT
