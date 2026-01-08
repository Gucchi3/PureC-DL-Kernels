# PureC-DL-Kernels
![Language](https://img.shields.io/badge/language-C99-blue)
![Platform](https://img.shields.io/badge/platform-Any%20%28x86%2FARM%2FRISC--V%29-green)
![Status](https://img.shields.io/badge/status-Active%20Development-orange)

## 📖 Overview
A lightweight, zero-dependency C implementation of deep learning operators, targeting Convolutional Neural Networks (CNN), Vision Transformers (ViT), and State Space Models (Mamba/VMamba).

The goal is to achieve **maximum portability** across any processor architecture (x86, ARM, RISC-V, DSPs, MCUs) by using standard C99 without external libraries.

## 🚀 Key Features
- **Pure C implementation**: No C++, no heavy frameworks (PyTorch/TensorFlow).
- **Hardware Agnostic**: Compiles on any platform with a standard C compiler.
- **Embedded Optimization**: Efficient pointer arithmetic and memory management designed for resource-constrained devices.

## 📊 Implementation Status

| Category | Operator / Module | Status | Note |
| :--- | :--- | :---: | :--- |
| **Convolution** | Conv2d (HWC) | ✅ Done | Supports Stride, Padding, Bias |
| | Pointwise / Depthwise | ⏳ Todo | |
| **Normalization** | Batch Norm | ⏳ Todo | To be fused into Conv for inference |
| | Layer Norm | ⏳ Todo | |
| **Activation** | **ReLU** | 🚧 **Now** | **Current Focus** |
| | SiLU | ⏳ Todo | Required for Mamba blocks |
| **Linear** | Linear (Dense) | ⏳ Todo | |
| **Attention** | Self-Attention (QKV) | ⏳ Todo | Multi-Head Attention |
| **Mamba**| **Efficient VMamba S6** | ⏳ Todo | The ultimate goal |

## 🛠 Usage Example

🚧 **Under Construction** 🚧

*(Detailed documentation and usage examples will be added soon.)*

## 📄 License

??? License
