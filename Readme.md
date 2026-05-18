# 🤖 Q-Learning Grid World AI (C++)

A self-learning AI agent built from scratch in C++ using Reinforcement Learning (Q-Learning). The agent learns how to navigate a 5x5 grid world from a start position to a goal while avoiding obstacles — purely through trial and error.

---

## 👨‍💻 Developer

**Enes Birer**  
Amasya University  
Computer Engineering (3rd Year Student)

---

# 🎯 Project Goal

- Understand Reinforcement Learning fundamentals  
- Implement Q-Learning algorithm from scratch (no ML libraries)  
- Build a self-learning AI agent in C++  
- Simulate a grid-based pathfinding environment  
- Visualize learning in terminal  

---

# 🧠 How the AI Learns

The agent uses Q-Learning:

1. Observes current state (position in grid)
2. Chooses an action (epsilon-greedy)
3. Receives reward
4. Updates Q-table
5. Improves over time

---

## 📌 Q-Learning Formula

Q(s,a) = Q(s,a) + α [ r + γ max Q(s',a') - Q(s,a) ]

Where:
- α = learning rate  
- γ = discount factor  
- r = reward  
- s = state  
- a = action  

---

# 🗺️ Environment (Grid World)

5x5 grid world:

Symbols:
- A → Agent  
- G → Goal  
- # → Wall  
- . → Empty  

Example:

A . . . .
. # # # .
. . . # .
. # . . .
. . . # G

---

# 🎮 Actions

0 → Up  
1 → Down  
2 → Left  
3 → Right  

---

# 🏆 Reward System

- Goal reached → +100  
- Wall hit → -100  
- Each step → -1  

---

# 🧪 Training Behavior

## 🔴 Early Training (Random)

A . . . .
. # # # .
. . . # .
. # . . .
. . . # G

→ Random movement, no strategy

---

## 🟡 Mid Training

A → . . .
. # # # .
. . . # .
. # . . .
. . . # G

→ Partial learning begins

---

## 🟢 Final Policy

A → → → →
. # # # ↓
. . . # ↓
. # → → ↓
. . . # G

→ Optimal path learned

---

# ⚙️ Build & Run

g++ main.cpp Agent.cpp GridWorld.cpp QTable.cpp -o Q_BOT.exe

./Q_BOT.exe

---

# 📁 Project Structure

Q_BOT/
│── main.cpp  
│── Agent.h / Agent.cpp  
│── GridWorld.h / GridWorld.cpp  
│── QTable.h / QTable.cpp  
│── README.md  

---

# 🧠 Features

- Q-Learning from scratch  
- Epsilon-greedy policy  
- Reward system  
- Terminal visualization  
- Self-learning AI agent  
- No external ML libraries  

---

# 🚀 Future Improvements

- Deep Q-Learning (Neural Networks)  
- GUI visualization (SFML / SDL2)  
- Dynamic obstacles  
- Multi-agent RL  
- Learning curve graphs  
- Model save/load system  

---

# 📌 What I Learned

- Reinforcement Learning basics  
- Q-learning implementation  
- State-action-reward systems  
- AI training logic  
- C++ project architecture  

---

# 👨‍💻 Author

Enes Birer  
Amasya University  
Computer Engineering (3rd Year)