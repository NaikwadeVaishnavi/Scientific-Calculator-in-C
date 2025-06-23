# 🔢 Scientific Calculator 💡

A modern, browser-based scientific calculator built with a **C backend** and a sleek **HTML/CSS/JS frontend** — connected seamlessly using **Python's built-in CGI server**.  
💻 No XAMPP, no external servers — just fast native C performance in your browser.

---
## 🧠 Technologies Used

| Layer       | Tech                            |
|-------------|----------------------------------|
| 👨‍🎨 Frontend | HTML + CSS + JavaScript          |
| 🔧 Backend   | C (compiled to `.exe`)           |
| 🌐 Server    | Python’s `http.server` with CGI  |



---

## 🖼️ Interface Preview

> 🖥️ Calculator with button clicks + keyboard input  
> 📤 Result is displayed **below the calculator**, inline using `<iframe>`

---

## 📁 Project Structure

```text
calculator_project/
├── index.html            # Main calculator UI
├── style.css             # Styling and layout
├── cgi-bin/              # CGI scripts directory
│   ├── calculator.c      # C source code (CGI logic)
│   └── calculator.exe    # Compiled C backend (CGI executable)
````

---

## ⚙️ Setup Instructions (Windows)

### ✅ Step 1: Compile the Backend (C to EXE)

Install [MinGW](https://www.mingw-w64.org/) or [TDM-GCC](https://jmeubank.github.io/tdm-gcc/), then:

```bash
cd calculator_project/cgi-bin
gcc calculator.c -o calculator.exe -lm
```

---

### ✅ Step 2: Start the Python CGI Web Server

From the `calculator_project` root folder:

```bash
python -m http.server 8000 --cgi
```

📌 Make sure Python 3 is installed and added to PATH.

---

### ✅ Step 3: Open in Browser

Visit:

```
http://localhost:8000/index.html
```

Start calculating instantly!

---

## ⌨️ Keyboard Shortcuts

| Key         | Function              |
| ----------- | --------------------- |
| `0-9`       | Input numbers         |
| `+ - * / ^` | Operators             |
| `Enter`     | Submit expression     |
| `Backspace` | Delete last character |
| `c`         | Clear input           |
| `s`         | Insert `sin(`         |
| `q`         | Insert `sqrt(`        |
| `f`         | Insert `factorial(`   |
| `p`         | Insert `pi`           |

🎯 Combines traditional input with full keyboard control!

---

## 🧪 Supported Math Functions

* Basic: `+`, `-`, `*`, `/`, `^`
* Trigonometric: `sin()`, `cos()`, `tan()`
* Inverse trig: `asin()`, `acos()`, `atan()`
* Root functions: `sqrt()`, `cbrt()`
* Special: `factorial()`, `pi`

All handled in **pure C** for high-speed calculation!

---
