# Simple-MD-Parser

`Simple-MD-Parser` is a lightweight, fast Markdown-to-HTML converter written in C++. It parses basic Markdown syntax and generates valid HTML output.

This project was developed as an exercise in C++ file I/O and string manipulation.

## ✨ Features

This converter supports the following basic Markdown syntax:

  * **Headings:** `<h1>` through `<h6>` (using `#`)
  * **Paragraphs:** Wraps regular text in `<p>` tags.
  * **Blockquotes:** Converts lines starting with ` >  ` into `<blockquote>`.
  * **Horizontal Rules:** Converts lines containing only `---` or `***` into `<hr>`.
  * **Bold Text:** Converts `**bold**` text to `<strong>bold</strong>`.
  * **Italic Text:** Converts `*italic*` text to `<em>italic</em>`.
  * **Links:** Converts `[Text](url)` syntax to `<a href="url">Text</a>`.
  * **HTML Passthrough:** Recognizes existing HTML tags (like `<div>` or `<section>`) and does not wrap them in `<p>` tags.

## 🚀 How to Use

### 1\. Compile

You need a C++ compiler (like `g++`) to build the project.

```bash
# In the project directory
g++ main.cpp -o converter
```

(Change `main.cpp` if your source file has a different name.)

### 2\. Run

You can run the program in two ways:

**Method 1: Command-Line Arguments (Recommended)**

Pass the `input` and `output` files as arguments.

```bash
./converter input.md output.html
```

**Method 2: Interactive Mode**

Run the program without arguments, and it will prompt you for the file names.

```bash
./converter
```

```bash
Enter Input Markdown File Name: input.md
Enter Output HTML File Name: output.html
```

Both methods will read `input.md`, convert its contents, and write the result to `output.html`.

## 📝 Example Usage

**Sample `test.md` Input:**

```md
# Hello World

This is a test for **MarkHead**.
This line should be *italic*.

[This is my GitHub profile](https://github.com/luluwux).

> This is a blockquote.

---

<div align="center">
  This HTML should be untouched.
</div>
```

**Generated `output.html`:**

```html
<h1>Hello World</h1>
<p>This is a test for <strong>MarkHead</strong>.</p>
<p>This line should be <em>italic</em>.</p>
<p><a href="https://github.com/luluwux">This is my GitHub profile</a>.</p>
<blockquote><p>This is a blockquote.</p></blockquote>
<hr>
<div align="center">
  This HTML should be untouched.
</div>
```

## 📜 License

This project is licensed under the MIT License. See the `LICENSE` file for details.
