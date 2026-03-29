# rpx2elf

Convert Wii U RPL/RPX files to standard ELF format. This tool decompresses zlib-compressed sections and converts RPL/RPX files to standard ELF executables.

## Features

- Converts Wii U RPL/RPX format to standard ELF
- Decompresses zlib-compressed sections
- Displays detailed ELF header and section information
- Optimized single-source file architecture for easy compilation
- Cross-platform support (Linux, macOS, Windows)

## Building

### Linux/macOS
```bash
make
```

### Windows (cross-compile from Linux)
```bash
make win
```

### Debug build
```bash
make DEBUG=1
```

## Usage

```bash
rpx2elf [INPUT.RPL/RPX] [OUTPUT.ELF]
```

## Code Structure

The project has been optimized with a clean, modular structure:
- `rpx2elf.h` - All type definitions, structures, and function declarations
- `rpx2elf.c` - Complete implementation in a single source file
- `Makefile` - Optimized build configuration with LTO support

This architecture makes it easy to compile into a single, optimized executable for any platform.

## Credits

- Hykem (original development)
- comex (documentation and research of the RPL/RPX format)
- deroad (additional research of the RPL/RPX format)
- Mark Adler (zlib header files)

## Cross-platform binaries via GitHub Actions

This repository includes a workflow that builds executable binaries for:

- Linux (`rpx2elf`)
- macOS (`rpx2elf`)
- Windows (`rpx2elf.exe`)

### How to use

- On every push/PR, GitHub Actions builds all platforms and uploads artifacts.
- To create a GitHub Release with binaries, push a version tag such as `v1.0.0`.

Example:

```bash
git tag v1.0.0
git push origin v1.0.0
```

The workflow will publish release assets and a `SHA256SUMS` file.

## License

Licensed under the terms of the GNU GPL, version 3
http://www.gnu.org/licenses/gpl-3.0.txt
