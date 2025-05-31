
🔌 Project: Command-Line Tool with Plugin Commands

📌 Concept
    Build a command-line utility (cli_tool) that supports built-in commands (like help, version) and allows extending functionality using plugins (e.g. convert, analyze, export, etc.).

Each plugin provides a new command the user can invoke.

💡 Example Usage
    ./cli_tool info
    ./cli_tool convert file.txt
    ./cli_tool export data.json

help is built-in
convert and export are plugins

🔧 Features
    Plugin Interface: defines run(int argc, char** argv) and get_name().
    Dynamic Loading: plugins are shared libraries (e.g. libconvert.so, libexport.so)
    No App Changes Needed to add new commands — just drop a .so in plugins/

🗂️ Project Structure

    PluginCLI/
    ├── include/
    │   └── PluginInterface.hpp
    ├── main/
    │   ├── main.cpp
    │   └── CMakeLists.txt
    ├── plugins/
    │   ├── ConvertPlugin.cpp
    │   ├── ExportPlugin.cpp
    │   └── CMakeLists.txt
    ├── CMakeLists.txt
    └── README.md


🧱 How to Extend
    Add a new plugin like AnalyzePlugin.cpp, register it in the plugin CMake, and rebuild. 
    The CLI will load and support analyze as a new command — no changes to the app.

✅ Why It’s Real-World
    Mimics how tools like git, ffmpeg, or clang can be extended.
    Encourages separation of core and extensions.
    Easy to test, maintain, and scale.

------------------------------------------------------------------------------
Build and Run
Note: need gcc-11

$mkdir build
$cd build

$cmake -DCMAKE_C_COMPILER=/home/linuxbrew/.linuxbrew/bin/gcc-11 -DCMAKE_CXX_COMPILER=/home/linuxbrew/.linuxbrew/bin/g++-11 ..
$make

$cd main
$./cli_tool
------------------------------------------------------------------------------