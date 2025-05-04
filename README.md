
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

## 🚀 How to Run
1. **Clone the repo**  
   Use the following command to clone the repository:
   ```bash
   git clone https://github.com/dawoodmdbr/Fantasy-Arena
2. Open in **VS Code** or any C++ IDE  
3. Compile the project  
4. Run the executable (main.cpp)

## Game Instructions

- **Choose Your Character**: Pick from Warrior, Mage, or Archer for both players.
- **Choose Your Arena**: Select an arena that influences the battle with environmental effects.
- **Combat**: Players alternate turns to attack, use special abilities, or perform combo moves.
- **Winning**: The first player to reduce the opponent's health to zero wins.

---

---

## ✨ Special Features

- 🔁 **Random Combo Attacks** – Offered to one player randomly every few rounds
- ⏳ **4-Round Cooldown** – Special abilities reset after every 4 rounds
- 🌪️ **Weather Effects** – Arena applies different effects every round
- ⚖️ **Operator Overloading** – Used for combo logic and power comparisons
- 🧠 **Turn-Based Strategy** – Each move matters

---

## 📂 File Structure

```
📁 FantasyArena/
├── main.cpp             # Entry point of the game
├── Character.h/.cpp     # Base and derived character classes
├── Arena.h/.cpp         # Arena effects and logic
├── GameManager.h/.cpp   # Game control logic
└── README.md            # Project documentation
```


## 🧑‍💻 Developed By

**Mian Dawood bin Rafay**

---

## 📜 License

This project is for educational use only and is not licensed for commercial distribution.
