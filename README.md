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
├── 04_KernelInternal/       # RTOS Kernel — Part 1 (5-part series!)
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

## 🧠 RTOS Kernel Internals — 5-Part Series

The core of this project is a **custom RTOS kernel** built from zero. Here's what each part covers:

| Part | Topics | Key Functions |
|:----:|:-------|:--------------|
| **1** | **Task Control Block** — task creation, stack initialization, TCB structure | `TCB_Type`, `xTaskCreateStatic()`, `prvInitialiseNewTask()` |
| **2** | **Context Switching** — PendSV handler, stack frame manipulation, PSP usage | `xPortPendSVHandler()`, `vPortSVCHandler()`, `portSAVE_CONTEXT()` |
| **3** | **Scheduler** — Round-robin, priority-based scheduling, idle task | `vTaskSwitchContext()`, `prvIdleTask()`, `taskYIELD()` |
| **4** | **Synchronization** — Mutex, binary semaphore, counting semaphore, priority inheritance | `xSemaphoreCreateMutex()`, `xSemaphoreGive/Take()`, `prvInheritPriority()` |
| **5** | **Inter-Task Communication** — Message queues, critical sections, suspend/resume | `xQueueCreate()`, `xQueueSend/Receive()`, `taskENTER_CRITICAL()` |

---

## 📚 Detailed Lesson Contents

### Phase 1: Toolchain & Board Setup (Lessons 00–01)
| Lesson | Topic | Concepts |
|:-------|:------|:---------|
| **00** | CompilerSettings | ARM GCC toolchain, linker script, startup file configuration |
| **01** | CubeMXUsage | STM32CubeMX project generation, clock config, peripheral setup |

### Phase 2: GPIO & Interrupts (Lessons 02–03)
| Lesson | Topic | Concepts |
|:-------|:------|:---------|
| **02** | CMX_ButtonUsage | GPIO input with HAL, button reading, debounce |
| **03** | CMX_ButtonIRQ | External interrupt (EXTI), NVIC configuration, ISR |

### Phase 3: RTOS Kernel (Lessons 04–04_5)
| Lesson | Topic | Concepts |
|:-------|:------|:---------|
| **04_1** | KernelInternal — Part 1 | Task creation, TCB, stack initialization |
| **04_2** | KernelInternal — Part 2 | Context switch, PendSV, SVC exceptions |
| **04_3** | KernelInternal — Part 3 | Scheduler implementation, task states |
| **04_4** | KernelInternal — Part 4 | Mutex, semaphore, synchronization primitives |
| **04_5** | KernelInternal — Part 5 | Message queues, inter-task communication |

### Phase 4: Low-Level & CMSIS (Lessons 05–07)
| Lesson | Topic | Concepts |
|:-------|:------|:---------|
| **05** | LED_Assem | Assembly LED control, direct register manipulation |
| **06** | Counting | Task counting example, timing with SysTick |
| **07** | CMSIS + SVC | ARM CMSIS-Core for RTOS, Supervisor Call exception handling |

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

MIT License.

---

## 📬 Contact

**Mustafa YILMAZ** — Embedded Software Engineer

[![LinkedIn](https://img.shields.io/badge/LinkedIn-Connect-blue)](https://linkedin.com/in/mustafaylmz1995)
[![GitHub](https://img.shields.io/badge/GitHub-Follow-black)](https://github.com/mustafaylmz1995)
