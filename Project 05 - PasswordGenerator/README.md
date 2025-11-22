
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
````

## 📖 Usage

Run the executable from your terminal with arguments:

```bash
# Default (10 characters, letters only)
./keyforge

# 16 characters including numbers
./keyforge -l 16 -n

# 24 characters including numbers and symbols (Strongest)
./keyforge -l 24 -n -s
```
