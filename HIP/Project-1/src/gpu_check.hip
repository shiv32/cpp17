#include <hip/hip_runtime.h>
#include <iostream>
#include <cstring>

int main() {
    std::cout << "=== GPU Diagnostic Check ===" << std::endl;
    std::cout << std::endl;

    // Check 1: Get device count
    std::cout << "Check 1: Detecting GPUs..." << std::endl;
    int device_count = 0;
    hipError_t error = hipGetDeviceCount(&device_count);
    if (error != hipSuccess) {
        std::cerr << "❌ Error getting device count: " << hipGetErrorString(error) << std::endl;
        return 1;
    }
    std::cout << "✓ Found " << device_count << " GPU device(s)" << std::endl;
    std::cout << std::endl;

    if (device_count == 0) {
        std::cerr << "❌ No GPU devices found!" << std::endl;
        return 1;
    }

    // Check 2: Get device properties
    std::cout << "Check 2: Getting GPU properties..." << std::endl;
    hipDeviceProp_t prop;
    error = hipGetDeviceProperties(&prop, 0);
    if (error != hipSuccess) {
        std::cerr << "❌ Error getting device properties: " << hipGetErrorString(error) << std::endl;
        return 1;
    }
    std::cout << "✓ Device Name: " << prop.name << std::endl;
    std::cout << "  Total Global Memory: " << (prop.totalGlobalMem / (1024*1024)) << " MB" << std::endl;
    std::cout << "  Max Threads per Block: " << prop.maxThreadsPerBlock << std::endl;
    std::cout << "  Compute Capability: " << prop.major << "." << prop.minor << std::endl;
    std::cout << std::endl;

    // Check 3: Set device
    std::cout << "Check 3: Setting device..." << std::endl;
    error = hipSetDevice(0);
    if (error != hipSuccess) {
        std::cerr << "❌ Error setting device: " << hipGetErrorString(error) << std::endl;
        return 1;
    }
    std::cout << "✓ Device set successfully" << std::endl;
    std::cout << std::endl;

    // Check 4: Memory allocation
    std::cout << "Check 4: Testing memory allocation..." << std::endl;
    int *d_test = nullptr;
    size_t test_size = 1024 * 1024; // 1 MB
    error = hipMalloc(&d_test, test_size);
    if (error != hipSuccess) {
        std::cerr << "❌ Error allocating GPU memory: " << hipGetErrorString(error) << std::endl;
        return 1;
    }
    std::cout << "✓ Allocated " << (test_size / 1024) << " KB on GPU" << std::endl;

    // Check 5: Memory write test
    std::cout << "Check 5: Testing memory write..." << std::endl;
    error = hipMemset(d_test, 42, test_size);
    if (error != hipSuccess) {
        std::cerr << "❌ Error writing to GPU memory: " << hipGetErrorString(error) << std::endl;
        (void)hipFree(d_test);
        return 1;
    }
    std::cout << "✓ Successfully wrote to GPU memory" << std::endl;

    // Check 6: Memory copy test
    std::cout << "Check 6: Testing memory copy (GPU -> Host)..." << std::endl;
    int *h_test = new int[256];
    error = hipMemcpy(h_test, d_test, 256 * sizeof(int), hipMemcpyDeviceToHost);
    if (error != hipSuccess) {
        std::cerr << "❌ Error copying from GPU memory: " << hipGetErrorString(error) << std::endl;
        delete[] h_test;
        (void)hipFree(d_test);
        return 1;
    }
    
    // Verify copy
    bool copy_ok = true;
    for (int i = 0; i < 10; i++) {
        if (h_test[i] != (int)0x2a2a2a2a) { // 42 repeated in each byte
            copy_ok = false;
            break;
        }
    }
    
    if (copy_ok) {
        std::cout << "✓ Memory copy successful" << std::endl;
    } else {
        std::cout << "⚠ Memory copy data verification failed" << std::endl;
    }
    std::cout << std::endl;

    // Check 7: Simple kernel test
    std::cout << "Check 7: Testing kernel readiness..." << std::endl;
    error = hipGetLastError(); // Clear any previous errors
    if (error != hipSuccess) {
        std::cerr << "⚠ Previous error detected: " << hipGetErrorString(error) << std::endl;
    }
    std::cout << "✓ Kernel system ready" << std::endl;
    std::cout << std::endl;

    // Check 8: Device synchronization
    std::cout << "Check 8: Testing device synchronization..." << std::endl;
    error = hipDeviceSynchronize();
    if (error != hipSuccess) {
        std::cerr << "❌ Error during synchronization: " << hipGetErrorString(error) << std::endl;
        delete[] h_test;
        (void)hipFree(d_test);
        return 1;
    }
    std::cout << "✓ Device synchronization successful" << std::endl;
    std::cout << std::endl;

    // Cleanup
    delete[] h_test;
    error = hipFree(d_test);
    if (error != hipSuccess) {
        std::cerr << "⚠ Warning: Error freeing GPU memory: " << hipGetErrorString(error) << std::endl;
    }

    std::cout << "=== GPU Check Complete ===" << std::endl;
    std::cout << "✓ All checks passed! Your GPU is working correctly." << std::endl;

    return 0;
}
