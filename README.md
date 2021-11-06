# libloggibud

C++ library for [LoggiBUD](https://github.com/loggi/loggibud) data structures.

This project is extremely linked to
[LoggiBUD](https://github.com/loggi/loggibud) project and it aims to supply
C++ resources and data structures for all components that were written in
Python on LoggiBUD project. I created this project for apply researching studies
in capacitated vehicle routing problems using instances provided by LoggiBUD.

## Installation

__libloggibud__ was written based on Unix systems and uses CMake as build
system, to install directly from source make sure you have installed `cmake` and use following commands for configure the Makefiles and compile all project:

```sh
cmake -S . -B build -Wno-dev
```

then...
```sh
cmake --build build --config Release --target install
```

and you'll have `libloggibud.a`, all headers and Loggibud CMake package globally
on your system.

Alternatively, you can use the flag `-DLOCAL` for generate all _build products_
in a `dist` directory placed on root of repository folder.

```sh
cmake -S . -B build -Wno-dev -DLOCAL=ON
```

## Basic Usage

The project aims to provide the same simplicity provided by LoggiBUD in Python,
for example, for read JSON instance files and generate an object with all data
with only one command.

```cpp
#include <loggibud/cvrp_instance.h>

int main(int argc, const char *argv[]) {
    auto problem = loggibud::CVRPInstance::from_file("cvrp-pa-100.json");

    for (auto d : problem.deliveries) {
        std::cout << "Size of delivery: " << d.size << std::endl;
    }

    return EXIT_SUCCESS;
}
```

## License

[GPLv3](https://www.gnu.org/licenses/gpl-3.0.pt-br.html)
