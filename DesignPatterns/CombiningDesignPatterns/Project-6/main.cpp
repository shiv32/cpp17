// File System Simulation in C++
// Patterns: Composite, Iterator, Visitor, Command

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <algorithm>

// ------------------- Component (Composite) -------------------
class FileSystemVisitor;

class FileSystemItem
{
public:
    virtual ~FileSystemItem() = default;
    virtual void accept(FileSystemVisitor &visitor) = 0;
    virtual const std::string &getName() const = 0;
};

using FileSystemItemPtr = std::shared_ptr<FileSystemItem>;

// ------------------- File -------------------
class File : public FileSystemItem
{
    std::string name;
    int size;

public:
    File(std::string name, int size) : name(std::move(name)), size(size) {}
    void accept(FileSystemVisitor &visitor) override;
    const std::string &getName() const override { return name; }
    int getSize() const { return size; }
};

// ------------------- Folder -------------------
class Folder : public FileSystemItem
{
    std::string name;
    std::vector<FileSystemItemPtr> children;

public:
    Folder(std::string name) : name(std::move(name)) {}
    void add(FileSystemItemPtr item) { children.push_back(item); }
    void remove(const std::string &name)
    {
        children.erase(std::remove_if(children.begin(), children.end(), [&](const auto &item)
                                      { return item->getName() == name; }),
                       children.end());
    }
    const std::vector<FileSystemItemPtr> &getChildren() const { return children; }
    void accept(FileSystemVisitor &visitor) override;
    const std::string &getName() const override { return name; }
};

// ------------------- Visitor -------------------
class FileSystemVisitor
{
public:
    virtual void visit(File &file) = 0;
    virtual void visit(Folder &folder) = 0;
    virtual ~FileSystemVisitor() = default;
};

void File::accept(FileSystemVisitor &visitor) { visitor.visit(*this); }
void Folder::accept(FileSystemVisitor &visitor) { visitor.visit(*this); }

// Visitor to print structure
class PrintVisitor : public FileSystemVisitor
{
    int indent = 0;

public:
    void visit(File &file) override
    {
        std::cout << std::string(indent, ' ') << "- " << file.getName() << " (File, " << file.getSize() << " KB)\n";
    }
    void visit(Folder &folder) override
    {
        std::cout << std::string(indent, ' ') << "+ " << folder.getName() << " (Folder)\n";
        indent += 2;
        for (auto &child : folder.getChildren())
        {
            child->accept(*this);
        }
        indent -= 2;
    }
};

// Visitor to calculate total size
class SizeVisitor : public FileSystemVisitor
{
    int totalSize = 0;

public:
    void visit(File &file) override { totalSize += file.getSize(); }
    void visit(Folder &folder) override
    {
        for (auto &child : folder.getChildren())
        {
            child->accept(*this);
        }
    }
    int getTotalSize() const { return totalSize; }
};

// ------------------- Commands -------------------
class Command
{
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};

class DeleteCommand : public Command
{
    Folder &folder;
    std::string targetName;

public:
    DeleteCommand(Folder &folder, std::string name)
        : folder(folder), targetName(std::move(name)) {}

    void execute() override
    {
        folder.remove(targetName);
        std::cout << "Deleted: " << targetName << "\n";
    }
};

class MoveCommand : public Command
{
    Folder &from;
    Folder &to;
    std::string itemName;

public:
    MoveCommand(Folder &from, Folder &to, std::string itemName)
        : from(from), to(to), itemName(std::move(itemName)) {}

    void execute() override
    {
        auto &children = from.getChildren();
        auto it = std::find_if(children.begin(), children.end(), [&](const auto &item)
                               { return item->getName() == itemName; });
        if (it != children.end())
        {
            to.add(*it);
            from.remove(itemName);
            std::cout << "Moved " << itemName << " to " << to.getName() << "\n";
        }
    }
};

// ------------------- Main -------------------
int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    auto root = std::make_shared<Folder>("root");
    auto docs = std::make_shared<Folder>("Documents");
    auto pics = std::make_shared<Folder>("Pictures");

    docs->add(std::make_shared<File>("resume.pdf", 120));
    docs->add(std::make_shared<File>("book.txt", 80));
    pics->add(std::make_shared<File>("image.jpg", 300));

    root->add(docs);
    root->add(pics);
    root->add(std::make_shared<File>("readme.md", 10));

    std::cout << "Initial File System:\n";
    PrintVisitor printer;
    root->accept(printer);

    std::cout << "\nTotal Size:\n";
    SizeVisitor sizeCalc;
    root->accept(sizeCalc);
    std::cout << sizeCalc.getTotalSize() << " KB\n";

    std::cout << "\nExecuting DeleteCommand (book.txt):\n";
    DeleteCommand delCmd(*docs, "book.txt");
    delCmd.execute();
    root->accept(printer);

    std::cout << "\nExecuting MoveCommand (resume.pdf to Pictures):\n";
    MoveCommand moveCmd(*docs, *pics, "resume.pdf");
    moveCmd.execute();
    root->accept(printer);

    return 0;
}
