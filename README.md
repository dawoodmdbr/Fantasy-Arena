
# 🛡️ Fantasy Arena Battle Game

A **console-based C++ fantasy battle simulator** where two players select mythical characters and engage in turn-based combat within magical environments filled with surprises, combos, and elemental effects.

---

## 🎮 Gameplay Overview

- 👥 Two players select a **Warrior**, **Mage**, or **Archer**
- 🏞️ Choose from three dynamic arenas: **FIRE**, **ICE**, or **JUNGLE**
- ⚔️ Fight turn-by-turn using:
  - Basic attacks
  - **Special abilities** (with 4-round cooldown)
  - 🔥 Rare **Combo attacks** when randomly offered
- 🌦️ Weather and environmental effects influence stats and strategy
- 📊 Compare character power every few rounds

---

## 🧙‍♂️ Characters

| Character | Description                        | Special Ability      |
|-----------|------------------------------------|----------------------|
| 🗡️ Warrior | Balanced stats and strong defense  | *Run It Back* – Extra attack and revive on defeat |
| 🔮 Mage    | High attack, low defense           | *Skill Issue* – Steals HP from enemy |
| 🏹 Archer  | Agile, relies on dodging attacks   | *Tailwind* – Dodges next attack |

---

## 🌍 Arenas

| Arena   | Environment Effect                     |
|---------|----------------------------------------|
| 🔥 FIRE | Boosts attack                          |
| ❄️ ICE  | Reduces opponent’s defense             |
| 🌲 JUNGLE | Gradual healing over time             |

---

## ⚙️ How to Compile & Run

### 🛠️ Requirements

- C++11 or higher compatible compiler (e.g. `g++`, `clang++`)

### 🔧 Compilation

```bash
g++ -o arena_game main.cpp GameManager.cpp Character.cpp Arena.cpp -std=c++11
```

### ▶️ Run

```bash
./arena_game       # Linux/macOS
arena_game.exe     # Windows
```

---

## 📂 File Structure

```
📁 ArenaBattleGame/
├── main.cpp             # Entry point of the game
├── Character.h/.cpp     # Base and derived character classes
├── Arena.h/.cpp         # Arena effects and logic
├── GameManager.h/.cpp   # Game control logic
└── README.md            # Project documentation
```

---

## ✨ Special Features

- 🔁 **Random Combo Attacks** – Offered to one player randomly every few rounds
- ⏳ **4-Round Cooldown** – Special abilities reset after every 4 rounds
- 🌪️ **Weather Effects** – Arena applies different effects every round
- ⚖️ **Operator Overloading** – Used for combo logic and power comparisons
- 🧠 **Turn-Based Strategy** – Each move matters

---

## 📌 Notes

- Game is played through a terminal/console interface
- Perfect for practicing:
  - Object-Oriented Programming
  - Inheritance and Polymorphism
  - Operator Overloading in C++
  - Game design logic

---

## 🧑‍💻 Developed By

**Mian Dawood bin Rafay**  
📍 FAST University (CFD Campus)

---

## 📜 License

This project is for educational use only and is not licensed for commercial distribution.
