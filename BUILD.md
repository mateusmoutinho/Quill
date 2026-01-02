# Build Guide

This document describes all available build targets for the Quill project.

## Prerequisites

Ensure you have the `run_blueprint` tool available in your system.

## Usage

```bash
run_blueprint --target <target_name>
```

## Available Targets

### local_unix_bin

Build static object files and link them into a local Linux binary.

```bash
run_blueprint --target local_unix_bin
```

**Outputs:**
- `Quill`

### local_objects_libs

Build static object files (.o) for local Linux development.

```bash
run_blueprint --target local_objects_libs
```

**Outputs:**
- `libs/CArgvParse.o`
- `libs/CTextEngine.o`
- `libs/UniversalGarbage.o`
- `libs/cJSON.o`
- `libs/UniversalSocket.o`
- `libs/LuaCEmbed.o`
- `libs/CWebStudio.o`
- `libs/doTheWorld.o`

### amalgamation

Make a single file amalgamation of the project.

```bash
run_blueprint --target amalgamation
```

**Outputs:**
- `release/Quill.c`

### static_linux

Make a static compiled linux binary of the project.

```bash
run_blueprint --target static_linux
```

**Outputs:**
- `release/Quill_linux_bin.out`

### debian

Create a debian package from the static linux binary.

```bash
run_blueprint --target debian
```

**Outputs:**
- `release/Quill.deb`

### rpm

Create an RPM package from the static linux binary.

```bash
run_blueprint --target rpm
```

**Outputs:**
- `release/Quill.rpm`

### silver_chain_organize

Organize source files using SilverChain.

```bash
run_blueprint --target silver_chain_organize
```

**Outputs:**
- `src/fdeclare.all.h`

## Quick Start

For local development on Linux/macOS:

```bash
run_blueprint --target local_unix_bin
./Quill
```

For creating a release:

```bash
run_blueprint --target static_linux
```