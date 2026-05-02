# ML Library from Scratch (C + MNIST)

A lightweight machine learning library implemented in **C**, built completely from scratch.  
This project demonstrates matrix operations, model building, and training on the MNIST dataset.

---

## 🚀 Features
- Custom memory allocator (`arena.c`)
- Random number generator (`prng.c`)
- Matrix operations (`matrix.c`)
- Model creation and training (`model.c`)
- MNIST dataset preprocessing (`mnist.py`)
- Simple build script (`build.bat`) for Windows

---

## 📂 Project Structure

ml-library-from-scratch/
└── machine-learning/
    ├── src/               C source files
    ├── include/           C header files
    ├── mnist.py           Python script for dataset prep
    └── build.bat          Windows build script

---

## ⚡ Getting Started

### 1. Prepare Dataset
Run the Python script to download MNIST and save it in `.mat` format:

```bash
python mnist.py
```
This will generate:

train_images.mat

train_labels.mat

test_images.mat

test_labels.mat


### 2. Build & Run (Windows)
From inside the machine-learning folder:

```bash
.\build.bat
```
This compiles all .c files and runs the program.

### 3. Output

- Training progress (cost per epoch)
- Accuracy on test set
- Sample digit visualization

---

## 🛠 Requirements
- C Compiler (GCC/MinGW on Windows)
- Python 3.11+ (for dataset prep)
- numpy and tensorflow-datasets

---

## 📌 Notes
- The project is educational — designed to show how ML can be implemented from scratch in C.
- No external ML frameworks are used.
- Extendable: you can add new layers, activation functions, or optimizers.

---

## ✨ Future Work
- Add convolutional layers
- Implement SGD with momentum
- Cross-platform build (Linux/macOS)

---

## 📜 License
MIT License — feel free to use, modify, and share.



