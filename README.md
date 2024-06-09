# CPlusPlanner

A Basic CLI task planner for C++ proof and understanding. It is under the name "SkillSync" and allows you to list, add, and remove tasks.
These tasks are stored locally via tasks.txt.

## Installation

1. Clone the repository:
   ```
   git clone https://github.com/Original-Lily/CPlusPlanner.git
   ```

2. Ensure you have a valid C++ compiler installed and use:
   ```
   g++ -o SkillSync.exe SkillSync.cpp
   ```

3. Run the program via:
   ```
   .\SkillSync.exe
   ```
   
# Usage

### Main menu options:
   ```
   Homework Manager
   1. List tasks
   2. Add a task
   3. Remove a task
   4. Quit
   Enter your choice:
   ```

### List tasks:
   ```
   Enter your choice: 1
   No tasks to display.
   ```
If there are tasks, it will list them:
   ```
   Enter your choice: 1
   Tasks:
   1. Finish math homework
   2. Complete science project
   ```

### Add a task:
   ```
   Enter your choice: 2
   Enter the task: Read chapter 5 of history book
   Task added.
   ```
The task will be saved to your local text file

### Remove your task:
   ```
   Enter your choice: 3
   Enter the task number to remove: 1
   Task removed.
   ```
The task will be removed from your local text file
