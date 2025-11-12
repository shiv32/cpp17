#include <hip/hip_runtime.h>
#include <iostream>

// Ultra simple kernel - no printf, no atomics, just thread ID reading
__global__ void hello_kernel(int *output) {
    int tid = threadIdx.x;
    int bid = blockIdx.x;
    int idx = bid * blockDim.x + tid;
    
    // Simple computation - write thread ID to output
    output[idx] = tid;
}

int main() {
    std::cout << "=== HIP Hello World Program ===" << std::endl;
    std::cout << "Starting HIP program on GPU..." << std::endl;
    std::cout << std::endl;

    // Allocate GPU memory for output
    int *d_output = nullptr;
    int num_threads = 8;
    hipError_t error = hipMalloc(&d_output, num_threads * sizeof(int));
    if (error != hipSuccess) {
        std::cerr << "Error allocating GPU memory: " << hipGetErrorString(error) << std::endl;
        return 1;
    }
    
    std::cout << "Launching kernel with " << num_threads << " threads..." << std::endl;
    
    // Launch kernel: 1 block, 8 threads
    hipLaunchKernelGGL(hello_kernel, dim3(1), dim3(num_threads), 0, 0, d_output);
    
    // Check for launch errors
    error = hipGetLastError();
    if (error != hipSuccess) {
        std::cerr << "Error launching kernel: " << hipGetErrorString(error) << std::endl;
        (void)hipFree(d_output);
        return 1;
    }
    
    std::cout << "Waiting for GPU to complete..." << std::endl;
    
    // Wait for kernel to complete
    error = hipDeviceSynchronize();
    if (error != hipSuccess) {
        std::cerr << "Error during synchronization: " << hipGetErrorString(error) << std::endl;
        (void)hipFree(d_output);
        return 1;
    }
    
    std::cout << "GPU computation completed!" << std::endl;
    std::cout << std::endl;
    
    // Copy result back
    int h_output[8];
    error = hipMemcpy(h_output, d_output, num_threads * sizeof(int), hipMemcpyDeviceToHost);
    if (error != hipSuccess) {
        std::cerr << "Error copying memory: " << hipGetErrorString(error) << std::endl;
        (void)hipFree(d_output);
        return 1;
    }
    
    // Print results
    std::cout << "Thread IDs from GPU:" << std::endl;
    for (int i = 0; i < num_threads; i++) {
        std::cout << "  Thread " << i << ": " << h_output[i] << std::endl;
    }
    
    // Free GPU memory
    (void)hipFree(d_output);
    
    std::cout << std::endl;
    std::cout << "================================" << std::endl;
    return 0;
}
