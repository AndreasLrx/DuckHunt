# Duck Hunt

[![Build](https://github.com/AndreasLrx/DuckHunt/actions/workflows/build-tests.yml/badge.svg)](https://github.com/AndreasLrx/DuckHunt/actions/workflows/build-tests.yml)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

This project is a remake of the Nintendo Duck Hunt game using. It is mostly made as a demo project for the [ECSTASY](https://github.com/AndreasLrx/ecstasy) library usage

## Authors

- Andréas Leroux (andreas.leroux@epitech.eu)

## Download

You can get the current development version from the [Git repository](https://github.com/AndreasLrx/DuckHunt)

# Building

Required tools:

- CMake 3.16 (minimum)

## Command Line

For Linux:

```sh
# Configure the project
cmake -B build/release_unix .. -G 'Unix Makefiles' -DCMAKE_BUILD_TYPE=Release

# Build the executable and libraries
cmake --build release_unix
```

## IDEs

The library may also be built with any IDE that has `CMakePresets.json` support, such as Visual Sudio, VSCode + CMake Tools, or CLion.

## Contributing

This is an open source project. If you want to get involved and suggest some additional features, file a bug report or submit a patch, create an issue or submit a pull request.
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License

This Duck Hunt remake is distributed under the [MIT licence](https://opensource.org/licenses/MIT).
In short, it is free for any use (commercial or personal, proprietary or open-source). You can use it in your project without any restriction. You can even omit to mention that you use it -- although it would be appreciated.
