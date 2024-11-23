git init\
git add .\
git commit -m "my commit"\
git remote add origin \<remote repository URL>\
git push origin master

----------------------------------------------------------------------------------

Install VS Code in Ubuntu

Download VS Code deb file from [VS Code](https://code.visualstudio.com/download)

after download deb file run below command to install

$sudo chmod +x packagename.deb

$sudo dpkg -i packagename.deb

To remove a Debian (Ubuntu) package (.deb)

$sudo dpkg -r packagename

To Reconfigure/Repair an installed Debian (Ubuntu) package (.deb)

$sudo dpkg-reconfigure packagename

---------------------------------------------------------------------------------

VS Code CMake setup on Linux
[cmake-linux](https://code.visualstudio.com/docs/cpp/cmake-linux)

VS Code C++ Create Definitions and Declarations
[Definitions and Declarations](https://devblogs.microsoft.com/cppblog/vs-code-c-extension-january-update-create-definitions-and-declarations/)

VS Code extension for cmake format
[cmake format](https://marketplace.visualstudio.com/items?itemName=xaver.clang-format)

Note:Restart VS Code after extensions install.

VS Code C++ Disassembly View
[Disassembly View](https://devblogs.microsoft.com/cppblog/visual-studio-code-c-july-2021-update-disassembly-view-macro-expansion-and-windows-arm64-debugging/)

VS Code C++ Disassembly View extension
[Disassembly View extension](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide)

VS Code C++ show memory window
[Hex Editor extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.hexeditor)\
In the variables view there is a binary icon. Select that and it will open the hex viewer at that address.

Configure Git to ignore files
[ignore files](https://docs.github.com/en/get-started/getting-started-with-git/ignoring-files)
or [ignore files](https://www.bmc.com/blogs/gitignore/)

Adding a license to a repository
[license](https://docs.github.com/en/communities/setting-up-your-project-for-healthy-contributions/adding-a-license-to-a-repository)

------------------------------------------------------------------------------------------------------------------------

VS Code setting for integrated terminal to stop give input bin path to C++ std::cin, when launch the selected target --> 

go to "Settings" -> type "terminal" in search box -> CMake Tools ->Cmake:Launch Behavior ->select "breakAndResueTerminal"

-------------------------------------------------------------------------------------------------------------------------

See a bin file in a hex editor in Visual Studio Code [Hex Editor](https://marketplace.visualstudio.com/items?itemName=ms-vscode.hexeditor) or [hexdump for VSCode](https://marketplace.visualstudio.com/items?itemName=slevesque.vscode-hexdump) 

Using Git source control in VS Code
[Git in VS Code](https://code.visualstudio.com/docs/sourcecontrol/overview) and
[Git in VS Code](https://code.visualstudio.com/docs/sourcecontrol/intro-to-git)

5 of the Most Useful Graphical Git Clients for Linux
[Graphical Git Clients for Linux](https://www.maketecheasier.com/6-useful-graphical-git-client-for-linux/)

VS Code Linter to detect & fix coding issues locally in C++
[SonarLint](https://marketplace.visualstudio.com/items?itemName=SonarSource.sonarlint-vscode)
Note: SonarLint take some time to detect issue so wait few second after open the code.
      In VS Code bottom you will see sonarLint tag. 

[![Youtube](https://img.shields.io/badge/YouTube-red?style=for-the-badge&logo=youtube&logoColor=white)](https://www.youtube.com/@ShivMLinux)
