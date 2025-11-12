# Quick Start Guide - HIP Hello World

This is a simple HIP (Heterogeneous-compute Interface for Portability) "Hello World" project optimized for AMD Radeon RX 580.

## Project Structure

```
Project-1/
├── src/
│   ├── hello_gpu.hip        # Main HIP Hello World program
│   ├── gpu_check.hip        # GPU diagnostic/check program
│   └── arch_check.hip       # GPU architecture compatibility check
├── CMakeLists.txt           # CMake build configuration (optimized for gfx803)
├── QUICKSTART.md            # This file
└── README.md                # Detailed documentation
```

## Building the Project

### Build using CMake (Recommended)

```bash
mkdir -p build
cd build
cmake ..
make
```

This will build:
- `hello_gpu` - Main HIP program
- `gpu_check` - GPU diagnostic program
- `arch_check` - Architecture compatibility check

## Running the Programs

### 1. Main Program (Hello GPU)

```bash
./build/hello_gpu
```

**Expected Output:**
```
=== HIP Hello World Program ===
Starting HIP program on GPU...

Launching kernel with 8 threads...
Waiting for GPU to complete...
GPU computation completed!

Thread IDs from GPU:
  Thread 0: 0
  Thread 1: 1
  ...
  Thread 7: 7

================================
```

### 2. GPU Check (Diagnostics)

```bash
./build/gpu_check
```

Performs comprehensive GPU diagnostics including:
- GPU detection
- Memory allocation test
- Memory write test
- Memory copy test
- Device synchronization test

### 3. Architecture Check (Compatibility)

```bash
./build/arch_check
```

Shows GPU details and HIP compatibility information.

## What This Program Does

The `hello_gpu` program:
1. **Allocates GPU memory** for storing results
2. **Launches a HIP kernel** with 1 block and 8 threads
3. **Each GPU thread** writes its thread ID to GPU memory
4. **Waits for GPU completion** with error checking
5. **Copies results** from GPU back to CPU
6. **Displays the results**

## Build Optimization

This project is optimized to compile **only for gfx803** (your AMD Radeon RX 580), which:
- ✓ Speeds up compilation
- ✓ Reduces binary size
- ✓ Eliminates driver conflicts
- ✓ Ensures smooth execution
