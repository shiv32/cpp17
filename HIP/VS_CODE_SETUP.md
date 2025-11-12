# VS Code HIP Syntax Highlighting Setup

## Issue: Extension Conflicts

If you encounter conflicts between extensions (like PyTorch HIP and Microsoft C/C++), follow these simple steps.

## Solution: Use Built-in C++ Highlighting

Your project is already configured to treat `.hip` files as C++ for syntax highlighting.

### What We Did:

We created `.vscode/settings.json` with these settings:

```json
{
    "files.associations": {
        "*.hip": "cpp"
    },
    "[cpp]": {
        "editor.defaultFormatter": "ms-vscode.cpptools",
        "editor.formatOnSave": true
    },
    "C_Cpp.intelliSenseEngine": "Tag Parser",
    "C_Cpp.intelliSenseEngineFallback": "disabled",
    "editor.semanticHighlighting.enabled": true
}
```

### What This Does:

✓ Treats `.hip` files as C++ → Gets C++ syntax highlighting
✓ Uses Microsoft's built-in C/C++ extension (no conflicts)
✓ Enables semantic highlighting for better code visibility
✓ Provides IntelliSense for standard C++ (works with HIP functions)
✓ Auto-formats code on save

### Result:

Your `.hip` files now have:
- ✓ Syntax highlighting (using C++ colors)
- ✓ Code completion
- ✓ Error checking
- ✓ IntelliSense support

## Manual Setup (If Needed)

If you don't see highlighting, you can manually set it:

1. **Open any `.hip` file**
2. **Bottom right corner** - Click the language mode (should show "C++")
3. If it shows "Plain Text" or something else:
   - Click it
   - Select **"C++"** from the dropdown
   - Choose **"Configure File Association for .hip"**

## HIP-Specific IntelliSense

To get IntelliSense for HIP headers, create a `c_cpp_properties.json`:

```bash
mkdir -p .vscode
cat > .vscode/c_cpp_properties.json << 'EOF'
{
    "configurations": [
        {
            "name": "Linux",
            "includePath": [
                "${workspaceFolder}/**",
                "/opt/rocm/include",
                "/opt/rocm/include/hip"
            ],
            "defines": [
                "__HIP_PLATFORM_AMD__",
                "__HIP_DEVICE_COMPILE__"
            ],
            "compilerPath": "/opt/rocm/bin/hipcc",
            "cStandard": "c17",
            "cppStandard": "c++17",
            "intelliSenseMode": "linux-gcc-x64"
        }
    ],
    "version": 4
}
EOF
```

This tells VS Code's IntelliSense where to find HIP headers!

## Disable Conflicting Extensions

If you still have conflicts:

1. Open **Extensions** (Ctrl+Shift+X)
2. Search for any HIP/CUDA-related extensions you installed
3. Click the ⚙️ gear icon → **Disable** (or **Uninstall**)
4. Keep only **Microsoft C/C++** extension

## Testing

After setup:

1. Open a `.hip` file
2. You should see:
   - Keywords highlighted (like `__global__`, `__device__`)
   - Includes highlighted differently
   - Comments in gray
   - Code completion when typing

If not visible:
- Press **Ctrl+K Ctrl+0** to reload window
- Or restart VS Code

## Summary

✓ No conflicting extensions needed
✓ Uses Microsoft's C/C++ extension (built-in)
✓ `.hip` files treated as C++ 
✓ Proper syntax highlighting
✓ Full IntelliSense support

Your project is now ready for HIP development in VS Code! 🚀
