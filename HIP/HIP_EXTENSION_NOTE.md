# HIP File Extension (.hip) - Project Note

## Why `.hip` and not `.cpp`?

### Overview
Files in this project use the `.hip` extension instead of `.cpp` because they contain HIP (Heterogeneous-compute Interface for Portability) code with GPU kernels.

### Key Reasons

#### 1. **Compiler Recognition**
- `.hip` explicitly identifies GPU code to the build system
- The HIP compiler (`hipcc`) automatically detects and compiles `.hip` files with GPU support
- `.cpp` files would not compile GPU kernels (`__global__` functions) correctly

#### 2. **Build System (CMake)**
```cmake
# With .hip extension (CORRECT)
add_executable(app src/main.hip)
# CMake uses HIP compiler settings automatically

# With .cpp extension (WRONG for GPU code)
add_executable(app src/main.cpp)
# CMake treats it as regular C++, GPU kernels fail
```

#### 3. **Compiler Behavior**
```bash
# .hip files compile GPU kernels correctly
hipcc file.hip -o output

# .cpp files with GPU kernels need special handling
hipcc --hip-version file.cpp -o output  # Requires extra flags
```

#### 4. **IDE and Editor Support**
- `.hip` files receive proper syntax highlighting for HIP-specific keywords
- Code completion works for HIP functions: `__global__`, `hipMalloc()`, `hipMemcpy()`, etc.
- Linters understand HIP-specific attributes and functions

#### 5. **Best Practice (AMD Official)**
AMD recommends:
- **`.hip`** - For files containing GPU kernels
- **`.cpp`** - For host-only code without GPU kernels

### Project File Structure

```
Project-1/src/
├── hello_gpu.hip      ✓ Contains __global__ kernel
├── gpu_check.hip      ✓ Uses HIP runtime API
└── arch_check.hip     ✓ Uses HIP runtime API
```

### Mixed Projects Example

You can mix `.hip` and `.cpp` files in larger projects:

```
src/
├── kernels.hip        # GPU kernels (HIP code)
├── utils.cpp          # Host utilities (regular C++)
├── memory.hip         # HIP memory management
└── main.hip           # Main program (HIP code)
```

CMakeLists.txt:
```cmake
add_executable(myapp 
    src/kernels.hip    # All files compiled with hipcc
    src/utils.cpp      # HIP compiler handles both .hip and .cpp
    src/memory.hip
    src/main.hip
)
```

### Technical Details

#### What Makes a File `.hip`?

✓ Contains HIP kernels (`__global__` functions)
✓ Uses HIP runtime API (`hipMalloc`, `hipMemcpy`, etc.)
✓ Uses HIP parallel primitives
✓ Needs to be compiled for GPU execution

#### What Could Be `.cpp`?

✓ Host-only utility functions
✓ Data structures (no GPU interaction)
✓ File I/O operations
✓ Regular C++ standard library code

### Compilation Process

**For `.hip` files:**
```
Source (.hip) 
    ↓
HIP Compiler (hipcc)
    ↓
GPU Code (gfx803) + Host Code (x86_64)
    ↓
Linked Executable
```

**For `.cpp` files (host-only):**
```
Source (.cpp)
    ↓
Regular C++ Compiler
    ↓
Host Code (x86_64)
    ↓
Linked with GPU Code
```

### Summary

| Aspect | `.hip` | `.cpp` |
|--------|--------|--------|
| GPU Kernels | ✓ Supported | ✗ Not Supported |
| HIP API | ✓ Supported | ✓ Limited |
| Build System | ✓ Auto-detected | ✗ Manual config needed |
| Compiler | hipcc (HIP) | g++/clang (C++) |
| GPU Code | ✓ Compiles to GPU | ✗ CPU only |

---

**Best Practice**: Always use `.hip` for files containing GPU code to ensure proper compilation and IDE support!
