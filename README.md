# STM32F4_RTOS_IG

**Building an RTOS from Scratch for STM32F4 (ARM Cortex-M4)**

![ARM](https://img.shields.io/badge/Arch-ARM_Cortex--M4-red)
![C](https://img.shields.io/badge/Language-C-blue)
![RTOS](https://img.shields.io/badge/RTOS-From_Scratch-green)
![STM32](https://img.shields.io/badge/MCU-STM32F4-cyan)
![License](https://img.shields.io/badge/License-MIT-yellow)

---

## 📖 Overview

This repository documents the process of building a **Real-Time Operating System (RTOS) from scratch** for the STM32F4 series (ARM Cortex-M4). Starting from bare-metal, through kernel internals, to a working multi-tasking system — all implemented step by step.

> **Not using FreeRTOS or any third-party RTOS — this is a custom kernel implementation.**

---

## 📦 Repository Structure

```
STM32F4_RTOS_IG/
├── 00_CompilerSettings/     # Compiler & linker configuration
├── 01_CubeMXUsage/          # STM32CubeMX initialization
├── 02_CMX_ButtonUsage/      # GPIO button input with HAL
├── 03_CMX_ButtonIRQ/        # GPIO interrupt handling
├── 04_KernelInternal/       # RTOS Kernel — Part 1
├── 04_KernelInternal_2/     # RTOS Kernel — Part 2
├── 04_KernelInternal_3/     # RTOS Kernel — Part 3
├── 04_KernelInternal_4/     # RTOS Kernel — Part 4
├── 04_KernelInternal_5/     # RTOS Kernel — Part 5
├── 05_LED_Assem/            # LED control in Assembly
├── 06_Counting/             # Task counting & timing
├── 07_CMSIS/                # ARM CMSIS integration
├── 07_SVC_Exception/        # Supervisor Call exception
├── _extra/                  # Supplementary materials
├── LICENSE
└── README.md
```

---

## 🧠 Kernel Internals (5-Part Series)

The core of this project is the **5-part Kernel Internal series**, covering:

| Part | Topics |
|:----:|:-------|
| **1** | Task control block, context switching basics |
| **2** | Scheduler implementation, task states |
| **3** | Stack management, PendSV handler |
| **4** | Mutex, semaphore, synchronization primitives |
| **5** | Inter-task communication, queues |

---

## 🚀 Topics Covered

| Category | Topics |
|:---------|:-------|
| **Toolchain** | ARM GCC compiler settings, linker scripts |
| **MCU Init** | STM32CubeMX configuration, clock setup |
| **GPIO** | Button input, external interrupts (EXTI) |
| **Kernel** | Task control block, context switch, scheduler |
| **Synchronization** | Mutex, semaphore, critical sections |
| **Exceptions** | SVC handler, PendSV, SysTick |
| **CMSIS** | ARM CMSIS-Core for RTOS integration |
| **Assembly** | Low-level LED control, register manipulation |

---

## 🛠 Hardware & Tools

| Component | Detail |
|:----------|:-------|
| **MCU** | STM32F4 (ARM Cortex-M4F) |
| **IDE** | STM32CubeIDE / Keil MDK-ARM |
| **Toolchain** | ARM GCC / ARMCC |
| **Debugger** | ST-Link / JTAG |

---

## 📄 License

MIT License — see [LICENSE](LICENSE).

---

## 📬 Contact

**Mustafa YILMAZ** — Embedded Software Engineer

[![LinkedIn](https://img.shields.io/badge/LinkedIn-Connect-blue)](https://linkedin.com/in/mustafaylmz1995)
[![GitHub](https://img.shields.io/badge/GitHub-Follow-black)](https://github.com/mustafaylmz1995)
