/**
 * @file main.cpp
 * @brief Demo application for ProgressBar library.
 */

#include <iostream>
#include <thread> // For sleep simulation
#include "ProgressBar.hpp"

int main() {
    // Enable UTF-8 for Windows Console to see the block characters (█)
    #ifdef _WIN32
        system("chcp 65001 > nul");
    #endif

    // --- CASE 1: Simple Task Counter ---
    std::cout << "--- Demo 1: Simple Task ---\n";
    ProgressBar taskBar(100, "Calculating");
    
    for (int i = 0; i <= 100; ++i) {
        taskBar.update(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(20)); // Simulate work
    }

    std::cout << "\n\n";

    // --- CASE 2: File Download Simulation (Byte Mode) ---
    std::cout << "--- Demo 2: File Download (Smart Units) ---\n";
    
    // Configure for a file download look
    BarConfig downloadConfig;
    downloadConfig.isByteMode = true;   // Auto-convert to KB/MB
    downloadConfig.width = 30;          // Compact width
    downloadConfig.fillChar = "#";      // Classic style

    long long fileSize = 120 * 1024 * 1024; // 120 MB File
    ProgressBar downloadBar(fileSize, "Downloading", downloadConfig);

    long long downloaded = 0;
    while (downloaded < fileSize) {
        // Simulate chunk download
        downloaded += 2 * 1024 * 1024; // +2 MB per step
        if (downloaded > fileSize) downloaded = fileSize;
        
        downloadBar.update(downloaded);
        std::this_thread::sleep_for(std::chrono::milliseconds(80)); // Simulate network lag
    }
    downloadBar.finish();

    return 0;
}