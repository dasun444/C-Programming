# Smart Medical Inventory & Dispensing System 🏥💊

A comprehensive console-based medical inventory, prescription management, automated dispensing simulation, and billing system written in **C**. Developed as a structured project using modular programming concepts and structures.

## 🚀 Features & Modules

The system is divided into 5 major modules to manage end-to-end medical logistics:

1. **Inventory Management** (`Module 1`)
   * Add, search, and update medicine stock quantities.
   * Real-time low stock alerts (< 10 units) and removal of expired stock items.

2. **Prescription Management** (`Module 2`)
   * Create and validate prescriptions against existing inventory.
   * Track patient prescription history and modify dosages seamlessly.

3. **Automated Dispensing Simulator** (`Module 3`)
   * Process prescription dispense requests with inventory stock deduction.
   * Simulate weight verification (with a 5% variance check) to flag dispensing errors or weight mismatches.

4. **Billing & Revenue** (`Module 4`)
   * Automatically generate patient bills based on active prescriptions.
   * Apply insurance discounts, process payments, view unpaid balances, and calculate total daily revenue (in LKR).

5. **Supplier Logistics** (`Module 5`)
   * Register new medical suppliers and link them to specific inventory items.
   * Auto-generate purchase orders (POs) for low-stock items and calculate average lead times.

---

## 🛠️ Technologies Used
* **Language:** C (Standard C99 / C11)
* **Concepts:** Structures (`struct`), Global Arrays, Modular Functions, Control Flow & String Manipulation.

---

## 💻 How to Run

1. Clone or download this repository.
2. Open a terminal or command prompt in the project directory.
3. Compile the C file using a C compiler (like GCC):
   ```bash
   gcc main.c -o medical_system
   # On Windows
medical_system.exe

# On Linux / macOS
./medical_system
