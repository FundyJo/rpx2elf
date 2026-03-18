# rpx2elf
Convert Wii U RPL/RPX files to standard ELF format. This tool is still unfinished and for now all it can do is decompress the RPL/RPX zlib compressed sections, as well as display important information regarding the ELF headers and data.

# Credits
comex (documentation and research of the RPL/RPX format)

deroad (additional research of the RPL/RPX format)

Mark Adler (zlib header files)

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
# rpx2elf
