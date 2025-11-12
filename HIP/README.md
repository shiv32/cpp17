# GPU Programming with HIP on Manjaro

## HIP (Heterogeneous-compute Interface for Portability)

HIP is AMD's parallel computing platform and API that allows you to write GPU-accelerated C++ code for AMD GPUs. 
Think of it as AMD's answer to NVIDIA's CUDA.

### Quick Facts:
- **Open Source & Free** - Part of AMD's ROCm ecosystem
- **CUDA-like Syntax** - Familiar to CUDA developers
- **AMD GPU Support** - Perfect for your Radeon RX 580
- **Performance** - Excellent for compute tasks

---

## Installation on Manjaro

### Prerequisites
- Manjaro Linux (any edition)
- AMD Radeon RX 580 GPU
- Internet connection

### Step 1: Update System
```bash
sudo pacman -Syu
```

### Step 2: Install ROCm and HIP
```bash
sudo pacman -S rocm-hip-runtime rocm-hip-sdk cmake base-devel
```

This installs:
- `rocm-hip-runtime` - HIP runtime libraries
- `rocm-hip-sdk` - HIP compiler (hipcc) and development tools
- `cmake` - Build system
- `base-devel` - Essential build tools (gcc, make, etc.)

### Step 3: Add ROCm to PATH
```bash
echo 'export PATH="/opt/rocm/bin:$PATH"' >> ~/.zshrc
source ~/.zshrc
```

### Step 4: Grant GPU Access
```bash
sudo usermod -a -G video $USER
sudo usermod -a -G render $USER
```

Log out and back in for group changes to take effect, or run:
```bash
newgrp video
```

### Step 5: Verify Installation
```bash
rocm-smi
hipcc --version
```

Both commands should run without errors.

## Building and Running HIP Programs

### Project Structure

```
Project-1/
├── src/
│   ├── hello_gpu.hip        # Main HIP Hello World program
│   ├── gpu_check.hip        # GPU diagnostic tool
│   └── arch_check.hip       # Architecture compatibility check
├── CMakeLists.txt           # Optimized for AMD Radeon RX 580 (gfx803)
├── QUICKSTART.md            # Quick start guide
└── README.md                # This file
```

### Build with CMake

```bash
# Create build directory
mkdir -p build
cd build

# Configure and build
cmake ..
make

# All three programs will be built
```

### Run the Programs

**Main program (Hello GPU):**
```bash
./hello_gpu
```

**GPU diagnostic check:**
```bash
./gpu_check
```

**Architecture compatibility check:**
```bash
./arch_check
```

## Example HIP Code

```cpp
#include <hip/hip_runtime.h>
#include <iostream>

// GPU kernel - runs on GPU
__global__ void hello_kernel(int *output) {
    int tid = threadIdx.x;
    output[tid] = tid;
}

int main() {
    // Allocate GPU memory
    int *d_output;
    hipMalloc(&d_output, 8 * sizeof(int));
    
    // Launch kernel: 1 block, 8 threads
    hipLaunchKernelGGL(hello_kernel, dim3(1), dim3(8), 0, 0, d_output);
    
    // Wait for GPU to finish
    hipDeviceSynchronize();
    
    // Copy data back to CPU
    int h_output[8];
    hipMemcpy(h_output, d_output, 8 * sizeof(int), hipMemcpyDeviceToHost);
    
    // Print results
    for (int i = 0; i < 8; i++) {
        std::cout << "Thread " << i << ": " << h_output[i] << std::endl;
    }
    
    // Free GPU memory
    hipFree(d_output);
    return 0;
}
```

## Troubleshooting on Manjaro

### GPU Not Detected
```bash
# Check if GPU is recognized by system
lspci | grep -i amd

# Check GPU visibility with ROCm
rocm-smi

# If not visible, install AMD microcode updates
sudo pacman -S amd-ucode

# Update to latest kernel
sudo pacman -S linux-latest

# Reboot
sudo reboot
```

### Command Not Found: hipcc
```bash
# Add ROCm to PATH temporarily
export PATH="/opt/rocm/bin:$PATH"

# Or permanently (already done in setup)
cat ~/.zshrc | grep rocm
```

### GPU Access Denied
```bash
# Check if you're in the video group
groups $USER

# If not, add yourself
sudo usermod -a -G video $USER
sudo usermod -a -G render $USER

# Log out and back in
```

### Performance Issues
- Your RX 580 is optimized for compute with gfx803 architecture
- Max 1024 threads per block
- 8 GB VRAM available
- Typical usage: Scientific computing, ML, image processing

## GPU Specifications

**Device**: AMD Radeon RX 580 2048SP
- **Architecture**: GFX803 (Polaris)
- **VRAM**: 8192 MB
- **Max Threads/Block**: 1024
- **Compute Capability**: 8.0
- **Wave Size**: 64
- **LDS per Block**: 64 KB

## Project Documentation

- **`QUICKSTART.md`** - Quick start guide for building and running
- **`HIP_EXTENSION_NOTE.md`** - Why we use `.hip` extension instead of `.cpp`

## Resources

- [ROCm Official Documentation](https://rocmdocs.amd.com/)
- [HIP Programming Guide](https://github.com/ROCm/HIP)
- [AMD GPU Programming](https://www.amd.com/en/technologies/hpc-gpu-computing)
- [Manjaro Documentation](https://manjaro.org/)
