# 🏦 Digital Bank System / Sistema Bancario Digital

This project is a console-based Banking System designed to practice and master the core pillars of **Object-Oriented Programming (OOP)** in C++.
Este proyecto es un Sistema Bancario por consola diseñado para practicar y dominar los pilares fundamentales de la **Programación Orientada a Objetos (POO)** en C++.

---

## 🚀 Key Features / Características Clave

### 🇬🇧 English
- **Encapsulation:** Protects sensitive data like `balance` and `pin` using `protected` and `private` access modifiers.
- **Inheritance:** Implements a `SavingAccount` class that inherits all logic from a base `BankAccount` class.
- **Input Validation:** Ensures the system only accepts positive deposits and authorized withdrawals.
- **Dynamic Menu:** Interactive interface to manage accounts in real-time.

### 🇪🇸 Español
- **Encapsulamiento:** Protege datos sensibles como el saldo (`balance`) y el `pin` usando modificadores de acceso `protected` y `private`.
- **Herencia:** Implementa una clase `SavingAccount` que hereda toda la lógica de una clase base `BankAccount`.
- **Validación de Datos:** Asegura que el sistema solo acepte depósitos positivos y retiros autorizados mediante PIN.
- **Menú Dinámico:** Interfaz interactiva para gestionar las cuentas en tiempo real.

---

## 🛠️ Concepts Applied / Conceptos Aplicados

- **Classes & Objects / Clases y Objetos:** Blueprints for different types of bank customers.
- **Constructors / Constructores:** Initialization and rule enforcement at object creation.
- **Inheritance (Is-A) / Herencia:** Relationship between a generic account and a specialized savings account.
- **Memory Management / Gestión de Memoria:** Use of `std::vector` to store and manage object instances.

---

## 📖 How it works / Cómo funciona

1. **Initialization:** Run the program and choose between a **Standard** or **Savings** account.
2. **Operations:**
   - **Deposit:** Add funds to the account (must be > 0).
   - **Withdraw:** Remove funds only if the PIN is correct and there's enough balance.
   - **Show Info:** View current balance and owner details.
   - **Apply Interest:** Exclusive feature for Savings Accounts to grow the balance.

1. **Inicio:** Ejecuta el programa y elige entre una cuenta **Estándar** o de **Ahorros**.
2. **Operaciones:**
   - **Depósito:** Añade fondos (debe ser mayor a 0).
   - **Retiro:** Retira fondos solo si el PIN es correcto y hay saldo suficiente.
   - **Ver Info:** Consulta el saldo actual y los detalles del titular.
   - **Aplicar Interés:** Función exclusiva de la Cuenta de Ahorros para aumentar el saldo.

---

## 💻 Tech Stack / Tecnologías

- **Language:** C++17
- **Compiler:** g++
- **Libraries:** `<iostream>`, `<string>`, `<vector>`, `<iomanip>`

---
