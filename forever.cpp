#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <cstdlib>

namespace fs = std::filesystem;

void show_help()
{
    std::cout << "[Forever. CLI] -- High-Velocity Git Automation Tool\n\n";
    std::cout << "Usage:\n";
    std::cout << "  forever \"<commit_message>\" [branch_name]\n\n";
    std::cout << "Options:\n";
    std::cout << "  --help     Show tactical command manual\n";
    std::cout << "  --version  Display engine development data\n";
}

void show_version()
{
    std::cout << "---------------------------------------------------\n";
    std::cout << "[Forever. Automation Engine]\n";
    std::cout << "Version: 1.0.0-LTS\n";
    std::cout << "Developer: hypernova-developer\n";
    std::cout << "Environment: Windows (CMD Optimized)\n";
    std::cout << "---------------------------------------------------\n";
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        show_help();
        return 1;
    }

    std::string arg1 = argv[1];

    if (arg1 == "--help")
    {
        show_help();
        return 0;
    }

    if (arg1 == "--version")
    {
        show_version();
        return 0;
    }

    if (!fs::exists(".git"))
    {
        std::cerr << "[Error] Tactical Error: No .git repository found in this directory.\n";
        return 1;
    }

    std::string commit_message = arg1;
    std::string branch_name = "main";

    if (argc > 2)
    {
        branch_name = argv[2];
    }

    std::cout << "[Forever.] Initiating auto-sync sequence to branch: [" << branch_name << "]\n";

    std::cout << "[Stage] Staging structural changes...\n";
    if (std::system("git add .") != 0)
    {
        std::cerr << "[Error] Operation Aborted: 'git add' failed.\n";
        return 1;
    }

    std::cout << "[Commit] Sealing commit payload...\n";
    std::string commit_cmd = "git commit -m \"" + commit_message + "\"";
    if (std::system(commit_cmd.c_str()) != 0)
    {
        std::cerr << "[Error] Operation Aborted: 'git commit' failed.\n";
        return 1;
    }

    std::cout << "[Push] Launching payload to origin/" << branch_name << "...\n";
    std::string push_cmd = "git push origin " + branch_name;
    if (std::system(push_cmd.c_str()) != 0)
    {
        std::cerr << "[Error] Operation Aborted: Network push rejected.\n";
        return 1;
    }

    std::cout << "[Success] Mission Accomplished -> Repository synchronized successfully via Forever.\n";
    return 0;
}
