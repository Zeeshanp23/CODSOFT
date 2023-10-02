#include <iostream>
#include <vector>

struct Task {
    std::string name;
    bool completed;
};

std::vector<Task> tasks;

void add_task() {
    std::string task_name;
    std::cout << "Enter task: ";
    std::getline(std::cin >> std::ws, task_name);
    tasks.push_back({task_name, false});
    std::cout << "Task added successfully!\n";
}

void view_tasks() {
    std::cout << "Tasks:\n";
    for (int i = 0; i < tasks.size(); i++) {
        std::string status = tasks[i].completed ? "completed" : "pending";
        std::cout << i + 1 << ". " << tasks[i].name << " - " << status << "\n";
    }
}

void mark_task_completed() {
    int task_num;
    std::cout << "Enter task number to mark as completed: ";
    std::cin >> task_num;
    if (task_num <= 0 || task_num > tasks.size()) {
        std::cout << "Invalid task number!\n";
        return;
    }
    tasks[task_num - 1].completed = true;
    std::cout << "Task marked as completed!\n";
}

void remove_task() {
    int task_num;
    std::cout << "Enter task number to remove: ";
    std::cin >> task_num;
    if (task_num <= 0 || task_num > tasks.size()) {
        std::cout << "Invalid task number!\n";
        return;
    }
    tasks.erase(tasks.begin() + task_num - 1);
    std::cout << "Task removed successfully!\n";
}

int main() {
    int choice;
    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                add_task();
                break;
            case 2:
                view_tasks();
                break;
            case 3:
                mark_task_completed();
                break;
            case 4:
                remove_task();
                break;
            case 0:
                std::cout << "Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice.\n";
                break;
        }
    }
}