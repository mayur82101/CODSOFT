#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> tasks;
    int choice;

    while (true) {
        cout << "\n--- TO-DO LIST MANAGER ---\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Delete Task\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // clear input buffer

        switch (choice) {

        case 1: {
            string task;
            cout << "Enter task: ";
            getline(cin, task);
            tasks.push_back(task);
            cout << "Task added successfully.\n";
            break;
        }

        case 2:
            if (tasks.empty()) {
                cout << "No tasks available.\n";
            } else {
                cout << "\nYour Tasks:\n";
                for (size_t i = 0; i < tasks.size(); i++) {
                    cout << i + 1 << ". " << tasks[i] << endl;
                }
            }
            break;

        case 3: {
            if (tasks.empty()) {
                cout << "No tasks to delete.\n";
                break;
            }
            int del;
            cout << "Enter task number to delete: ";
            cin >> del;

            if (del < 1 || del > tasks.size()) {
                cout << "Invalid task number.\n";
            } else {
                tasks.erase(tasks.begin() + del - 1);
                cout << "Task deleted successfully.\n";
            }
            break;
        }

        case 4:
            cout << "Exiting To-Do List Manager. Goodbye!\n";
            return 0;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}

