#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task
{
    string description;
    bool completed;

    Task(string desc)
    {
        description = desc;
        completed = false;
    }
};

void showMenu()
{
    cout << "\n---- TO-DO LIST MENU ----" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Delete Task" << endl;
    cout << "4. Mark Task as Completed" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

void addTask(vector<Task> &tasks)
{
    string taskDesc;
    cin.ignore();
    cout << "Enter the task: ";
    getline(cin, taskDesc);
    tasks.push_back(Task(taskDesc));
    cout << "Task Added!" << endl;
}

void viewTasks(const vector<Task> &tasks)
{
    if (tasks.empty())
    {
        cout << "No tasks available." << endl;
        return;
    }

    cout << "\n---- TO-DO TASKS ----" << endl;
    for (size_t i = 0; i < tasks.size(); ++i)
    {
        cout << i + 1 << ". [" << (tasks[i].completed ? "✔" : "✘") << "] "
             << tasks[i].description << endl;
    }
}

void deleteTask(vector<Task> &tasks)
{
    if (tasks.empty())
    {
        cout << "No tasks to delete." << endl;
        return;
    }

    int i;
    cout << "Enter the task number to delete: ";
    cin >> i;

    if (i < 1 || i > tasks.size())
    {
        cout << "Invalid task number." << endl;
    }
    else
    {
        tasks.erase(tasks.begin() + i - 1);
        cout << "Task deleted successfully." << endl;
    }
}

void markTaskCompleted(vector<Task> &tasks)
{
    if (tasks.empty())
    {
        cout << "No tasks to update." << endl;
        return;
    }

    int i;
    cout << "Enter the task number to mark as completed: ";
    cin >> i;

    if (i < 1 || i > tasks.size())
    {
        cout << "Invalid task number." << endl;
    }
    else
    {
        tasks[i - 1].completed = true;
        cout << "Task marked as completed!" << endl;
    }
}

int main()
{
    vector<Task> tasks;
    int choice;
    do
    {
        showMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            addTask(tasks);
            break;
        case 2:
            viewTasks(tasks);
            break;
        case 3:
            deleteTask(tasks);
            break;
        case 4:
            markTaskCompleted(tasks);
            break;
        case 5:
            cout << "Exiting... Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Try again!" << endl;
        }

    } while (choice != 5);

    return 0;
}
