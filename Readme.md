# Q-Learning Based Grid World Agent (C++ Implementation)

## Overview

This project implements a **model-free reinforcement learning agent** using the **Q-Learning algorithm** in C++. The agent learns to navigate a discrete 5x5 grid world with obstacles and reach a goal state through trial-and-error interaction with the environment.

The implementation is fully written from scratch without any machine learning libraries, focusing on understanding the core mathematical and algorithmic principles of reinforcement learning.

---

## Problem Definition

The environment is formulated as a Markov Decision Process (MDP):

- **State space (S):** All grid positions in a 5x5 environment (25 discrete states)
- **Action space (A):** {Up, Down, Left, Right}
- **Transition function (T):** Deterministic movement with boundary and obstacle constraints
- **Reward function (R):**
  - +100 for reaching the goal state
  - -100 for hitting a wall/invalid move
  - -1 for each time step (to encourage shortest path behavior)

---

## Q-Learning Algorithm

The agent learns an optimal action-value function using the Q-Learning update rule:

\[
Q(s,a) = Q(s,a) + \alpha \left[ r + \gamma \max_{a'} Q(s',a') - Q(s,a) \right]
\]

Where:

- \( s \): current state  
- \( a \): selected action  
- \( r \): reward received after action  
- \( s' \): next state  
- \( a' \): possible next actions  
- \( \alpha \): learning rate  
- \( \gamma \): discount factor  

This update rule iteratively improves the estimation of long-term expected rewards for each state-action pair.

---

## Policy (Action Selection)

An **epsilon-greedy policy** is used:

- With probability \( \epsilon \): choose a random action (exploration)
- With probability \( 1 - \epsilon \): choose action with maximum Q-value (exploitation)

This ensures a balance between exploration of new states and exploitation of learned knowledge.

---

## State Representation

The 2D grid is mapped into a 1D state space:

\[
state = y \cdot width + x
\]

This allows efficient storage and lookup in a tabular Q-function.

---

## Q-Table Representation

The Q-function is stored as a tabular matrix:

- Dimensions: \( 25 \times 4 \)
- Rows represent states
- Columns represent actions

Each entry stores the expected cumulative reward of taking a specific action in a given state.

---

## System Architecture

### 1. GridWorld (Environment)
Defines the environment dynamics:
- Grid structure (walls, goal, empty cells)
- State transitions
- Reward computation
- Valid move checking

### 2. Agent
Implements the learning agent:
- Action selection (epsilon-greedy)
- Interaction with environment
- Q-table updates using Q-learning rule

### 3. QTable
Stores learned knowledge:
- Q-values for state-action pairs
- Best action computation
- Optional save/load functionality

---

## Training Procedure

The learning process is episodic:

1. Initialize agent at start state
2. For each episode:
   - Observe current state
   - Select action using epsilon-greedy policy
   - Execute action in environment
   - Receive reward and next state
   - Update Q-table using Q-learning update rule
   - Continue until goal is reached or episode ends

---

## Convergence Behavior

During training:

- Initial episodes: random exploration dominates
- Mid training: partial policy formation appears
- Final stages: Q-values converge toward optimal policy

The resulting policy approximates the shortest path from start to goal.

---

## Computational Complexity

- Time complexity per update: \( O(1) \)
- Memory complexity: \( O(|S| \cdot |A|) = O(100) \)
- Training complexity: \( O(E \cdot T) \)
  - E = number of episodes
  - T = steps per episode

---

## Limitations

- Tabular representation does not scale to large environments
- No function approximation (e.g., neural networks)
- Deterministic environment only
- No generalization beyond visited states

---

## Possible Extensions

- Deep Q-Network (DQN) with neural function approximation
- Stochastic environments
- Dynamic obstacle generation
- Multi-agent reinforcement learning
- GUI-based visualization (SFML/SDL)
- Learning curve visualization (reward plots)

---

## Build & Run

Compile:

```bash
g++ main.cpp Agent.cpp GridWorld.cpp QTable.cpp -o Q_BOT
