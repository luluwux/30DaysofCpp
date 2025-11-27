/**
 * @file ProgressBar.hpp
 * @brief A lightweight, header-only C++ Progress Bar library for CLI applications.
 * @version 1.1.0
 * @date 2025
 * * Features:
 * - ETA (Estimated Time of Arrival) calculation.
 * - Auto-formatting for data units (B, KB, MB, GB).
 * - Customizable width, characters, and colors.
 * - Spinner animation.
 */

#pragma once 

#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include <vector>
#include <cmath>
#include <sstream>

/**
 * @brief Configuration structure to customize the progress bar.
 */
struct BarConfig {
    int width = 40;                 // Width of the progress bar (in characters)
    std::string fillChar = "█";     // Character used for the filled part
    std::string emptyChar = " ";    // Character used for the empty part
    bool useColors = true;          // Enable/Disable ANSI colors
    bool isByteMode = false;        // If true, numbers are formatted as bytes (KB, MB, etc.)
};

class ProgressBar {
private:
    long long total;
    BarConfig config;
    std::string description;
    std::chrono::time_point<std::chrono::steady_clock> startTime;
    const std::vector<char> spinner = {'|', '/', '-', '\\'};
    int spinnerIdx = 0;

    // Helper: Converts raw bytes into human-readable strings (e.g., 1024 -> "1.0 KB")
    std::string formatUnit(long long value) {
        if (!config.isByteMode) return std::to_string(value);

        const char* units[] = {"B", "KB", "MB", "GB", "TB"};
        int i = 0;
        double dValue = static_cast<double>(value);
        while (dValue > 1024 && i < 4) {
            dValue /= 1024;
            i++;
        }
        
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(1) << dValue << " " << units[i];
        return oss.str();
    }

    // Helper: Formats seconds into MM:SS
    std::string formatTime(long long seconds) {
        long long m = seconds / 60;
        long long s = seconds % 60;
        std::ostringstream oss;
        oss << std::setw(2) << std::setfill('0') << m << ":" 
            << std::setw(2) << std::setfill('0') << s;
        return oss.str();
    }

public:
    /**
     * @brief Construct a new Progress Bar object
     * * @param totalSteps Total amount of work to be done.
     * @param desc Description text shown before the bar.
     * @param conf Configuration struct (optional).
     */
    ProgressBar(long long totalSteps, std::string desc = "Processing", BarConfig conf = BarConfig()) 
        : total(totalSteps), description(desc), config(conf) {
        startTime = std::chrono::steady_clock::now();
    }

    /**
     * @brief Updates the progress bar state. Call this inside your main loop.
     * * @param current The current progress value (must be <= totalSteps).
     */
    void update(long long current) {
        float progress = (total > 0) ? (float)current / total : 0.0f;
        int filledLength = (int)(config.width * progress);

        // Calculate elapsed time and ETA
        auto now = std::chrono::steady_clock::now();
        long long elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - startTime).count();
        long long eta = (progress > 0.0f) ? (long long)(elapsed / progress) - elapsed : 0;

        std::cout << "\r"; // Carriage return to overwrite the line

        // Draw Spinner and Description
        std::cout << spinner[spinnerIdx] << " " << description << " [";
        spinnerIdx = (spinnerIdx + 1) % 4;

        // Draw the Bar (with Colors if enabled)
        if (config.useColors) std::cout << "\033[36m"; // Cyan
        for (int i = 0; i < config.width; ++i) {
            if (i < filledLength) std::cout << config.fillChar;
            else std::cout << config.emptyChar;
        }
        if (config.useColors) std::cout << "\033[0m"; // Reset color

        // Draw Stats: Percentage | Current/Total | ETA
        std::cout << "] " << std::setw(3) << int(progress * 100) << "%";
        std::cout << " | " << formatUnit(current) << "/" << formatUnit(total);
        
        // Show ETA only if valid
        if (eta >= 0 && progress < 1.0f) {
            std::cout << " | ETA: " << formatTime(eta) << "   "; 
        }

        std::cout.flush(); // Force output to screen
    }

    /**
     * @brief Finalizes the progress bar. Moves cursor to the next line.
     */
    void finish() {
        update(total); // Ensure bar is at 100%
        std::cout << "\n";
        if (config.useColors) std::cout << "\033[32m"; // Green
        std::cout << "✔ " << description << " Completed!";
        if (config.useColors) std::cout << "\033[0m";
        std::cout << std::endl;
    }
};