# 🔐 KeyForge

A lightweight, command-line password generator written in **C++**. It uses the Mersenne Twister engine (`std::mt19937`) for high-quality randomness.

## 🚀 Features

* **Custom Length:** Set any password length with `-l`.
* **Numbers:** Optionally include numbers with `-n`.
* **Symbols:** Optionally include special characters with `-s`.
* **Fast & Secure:** Low memory usage and secure random generation.

## 🛠️ Build

You can compile the source code using `g++`:

```bash
g++ main.cpp -o keyforge
