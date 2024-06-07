#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void loadTasks(std::vector<std::string>& tasks, const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file." << std::endl;
        return;
    }

    std::string task;
    while (std::getline(file, task)) {
        tasks.push_back(task);
    }

    file.close();
}

void saveTasks(const std::vector<std::string>& tasks, const std::string& filename) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file." << std::endl;
        return;
    }

    for (const std::string& task : tasks) {
        file << task << std::endl;
    }

    file.close();
}

int main() {
    std::vector<std::string> tasks;
    const std::string filename = "tasks.txt";
    std::string newTask;

    loadTasks(tasks, filename);
    while (true) {
        std::cout << "Homework Manager" << std::endl;
        std::cout << "1. List tasks" << std::endl;
        std::cout << "2. Add a task" << std::endl;
        std::cout << "3. Remove a task" << std::endl;
        std::cout << "4. Quit" << std::endl;
        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: 
                if (tasks.empty()) {
                    std::cout << "No tasks to display." << std::endl;
                } else {
                    std::cout << "Tasks:" << std::endl;
                    for (size_t i = 0; i < tasks.size(); ++i) {
                        std::cout << i + 1 << ". " << tasks[i] << std::endl;
                    }
                }
                break;

            case 2:
                std::cin.ignore();
                std::cout << "Enter the task: ";
                std::getline(std::cin, newTask); 
                tasks.push_back(newTask);
                saveTasks(tasks, filename);
                std::cout << "Task added." << std::endl;
                break;

            case 3:
                if (tasks.empty()) {
                    std::cout << "No tasks to remove." << std::endl;
                } else {
                    std::cout << "Enter the task number to remove: ";
                    int taskNumber;
                    std::cin >> taskNumber;
                    if (taskNumber > 0 && taskNumber <= static_cast<int>(tasks.size())) {
                        tasks.erase(tasks.begin() + taskNumber - 1);
                        saveTasks(tasks, filename);
                        std::cout << "Task removed." << std::endl;
                    } else {
                        std::cout << "Invalid task number." << std::endl;
                    }
                }
                break;

            case 4:
                std::cout << "Goodbye!" << std::endl;
                return 0;

            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
    return 0;
}
