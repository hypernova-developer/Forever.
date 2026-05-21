# Forever.

A high-velocity, zero-dependency Git automation CLI tool written in pure C++23. Engineered to eliminate multi-step staging, committing, and pushing workflows into a single execution sequence.

## Features

- **Single-Line Sync:** Replaces `git add .`, `git commit -m "..."`, and `git push origin <branch>` with one command.
- **Smart Branch Resolution:** Automatically defaults to `main` if no branch argument is provided.
- **Pre-Flight Sanity Checks:** Verifies the existence of a local `.git` repository before spawning system tasks to prevent command failure pipelines.
- **Local Logging Protocol:** Generates and appends execution logs to `forever_history.log` upon every successful remote synchronization.
- **Zero Interpreter Overhead:** Compiled directly into native machine code using the `CompileX Engine` for maximum speed and zero runtime dependencies.

## Architecture & Commands
 - **forever "<commit_message>" [branch_name]** The main command does the work.

### Options
- `--help`: Displays the tactical command manual.
- `--version`: Displays the internal engine development data and current LTS version.

## Source Manifest

The core logic handles automatic process execution via standard system gateways:

- **Stage:** Executes `git add .` to index structural changes.
- **Commit:** Encrypts and seals the payload inside `git commit -m "<message>"`.
- **Push:** Dispatches the tracked objects to `origin/<branch>`.
- **Log:** Appends a localized ISO-like timestamp and execution data into the historical tracking file.

## Compilation via CompileX

To compile and inject `forever` into your operating system's binary pathways. You can use the `CompileX Engine`:

```powershell
compilex forever.cpp
```
Once compiled, the file name will be renamed to `forever.exe` automatically. You have to place it within your system's `PATH` environment variable directory.

## License

Developed by [hypernova-developer](https://github.com/hypernova-developer). Part of the hypernova core toolchain ecosystem. 
This project is protected by the **GNU GPL v3.0**.