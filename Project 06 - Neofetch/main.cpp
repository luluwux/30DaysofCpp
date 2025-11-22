#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
    #include <limits.h>
    #include <sys/sysinfo.h>
    #include <sys/statvfs.h>
#endif

// Color Codes (ANSI)
#define COLOR_RESET  "\033[0m"
#define COLOR_RED    "\033[1;31m" 
#define COLOR_PURPLE "\033[1;35m"

// Bar Generator
std::string createProgressBar(double percentage) {
    std::string bar = "[";
    int filledLength = (int)(percentage / 5);
    
    for(int i=0; i<20; i++) {
        if (i < filledLength) bar += "|";
        else bar += ".";
    }
    bar += "]";
    return bar;
}

int main() {
    char computerName[256];
    char userName[256];
    std::string osName;
    long uptimeSeconds = 0;
    double diskTotal = 0, diskFree = 0;

    #ifdef _WIN32
        osName = "Windows";
    
        DWORD size = sizeof(computerName);
        GetComputerNameA(computerName, &size);
        
        size = sizeof(userName);
        GetUserNameA(userName, &size);
    
        uptimeSeconds = GetTickCount64() / 1000;


        ULARGE_INTEGER uFree, uTotal, uTotalFree;
        if(GetDiskFreeSpaceExA("C:\\", &uFree, &uTotal, &uTotalFree)) {
            diskTotal = (double)uTotal.QuadPart / (1024*1024*1024); // GB
            diskFree = (double)uTotalFree.QuadPart / (1024*1024*1024); // GB
        }

    #else
        osName = "Linux / Unix";
        
        gethostname(computerName, sizeof(computerName));
        
        char* user = getlogin();
        if(user) sprintf(userName, "%s", user);
        else sprintf(userName, "Ghost");

        struct sysinfo info;
        sysinfo(&info);
        uptimeSeconds = info.uptime;

        // Disk Info (Root directory)
        struct statvfs stat;
        if (statvfs("/", &stat) == 0) {
            diskTotal = (double)(stat.f_blocks * stat.f_frsize) / (1024*1024*1024);
            diskFree = (double)(stat.f_bfree * stat.f_frsize) / (1024*1024*1024);
        }
    #endif

    // Uptime
    int hours = uptimeSeconds / 3600;
    int minutes = (uptimeSeconds % 3600) / 60;

    // CPU Cores
    unsigned int cpuCores = std::thread::hardware_concurrency();

    // Disk Percentage Calculation
    double diskUsed = diskTotal - diskFree;
    double diskPercent = (diskTotal > 0) ? (diskUsed / diskTotal) * 100 : 0;

    std::cout << "\n";
    std::cout << COLOR_PURPLE << "   /\\_/\\    " << COLOR_PURPLE << userName << COLOR_RESET << "@" << COLOR_PURPLE << computerName << "\n";
    std::cout << COLOR_PURPLE << "  ( o.o )   " << COLOR_RESET << "---------------------------" << "\n";
    std::cout << COLOR_PURPLE << "   > ^ <    " << COLOR_PURPLE << "OS      : " << COLOR_RESET << osName << "\n";
    std::cout << COLOR_PURPLE << "  /     \\   " << COLOR_PURPLE << "CPU     : " << COLOR_RESET << cpuCores << " Cores\n";
    std::cout << COLOR_PURPLE << "  |     |   " << COLOR_PURPLE << "Uptime  : " << COLOR_RESET << hours << " h " << minutes << " m\n";
    std::cout << COLOR_PURPLE << "  (_____)   " << COLOR_PURPLE << "Disk    : " << COLOR_RED << createProgressBar(diskPercent) << " %" << (int)diskPercent << "\n";
    std::cout << "            " << COLOR_RESET << "(" << (int)diskUsed << "GB / " << (int)diskTotal << "GB)\n";
    std::cout << "\n";

    return 0;
}