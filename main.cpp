#include <iostream>
#include <string>
#include <limits>
#include <memory>

#include "TaskManager.h"
#include "WorkTask.h"
#include "UrgentWorkTask.h"
#include "StudyTask.h"









static std::string readLine(const std::string& prompt) {
    std::string value;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, value);
        if (!value.empty()) return value;
        std::cout << "  Input cannot be empty. Try again.\n";
    }
}


static int readInt(const std::string& prompt, int lo, int hi) {
    int value{};
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value >= lo && value <= hi) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "  Please enter a number between " << lo << " and " << hi << ".\n";
    }
}


static void addWorkTask(TaskManager& manager) {
    std::cout << "\n  --- Add Work Task ---\n";
    try {
        std::string title      = readLine("  Title       : ");
        std::string desc       = readLine("  Description : ");
        int         priority   = readInt ("  Priority (1-5): ", 1, 5);
        std::string dueDate    = readLine("  Due Date    : ");
        std::string department = readLine("  Department  : ");
        std::string assignedTo = readLine("  Assigned To : ");

        auto task = std::make_shared<WorkTask>(
            title, desc, priority, dueDate, department, assignedTo);
        manager.addTask(task);
    } catch (const std::exception& e) {
        std::cout << "  Error: " << e.what() << "\n";
    }
}


static void addUrgentWorkTask(TaskManager& manager) {
    std::cout << "\n  --- Add Urgent Work Task ---\n";
    try {
        std::string title       = readLine("  Title             : ");
        std::string desc        = readLine("  Description       : ");
        int         priority    = readInt ("  Priority (1-5)    : ", 1, 5);
        std::string dueDate     = readLine("  Due Date          : ");
        std::string department  = readLine("  Department        : ");
        std::string assignedTo  = readLine("  Assigned To       : ");
        int         hours       = readInt ("  Hours Until Deadline: ", 1, 9999);
        std::string escalation  = readLine("  Escalation Contact: ");

        auto task = std::make_shared<UrgentWorkTask>(
            title, desc, priority, dueDate,
            department, assignedTo, hours, escalation);
        manager.addTask(task);
    } catch (const std::exception& e) {
        std::cout << "  Error: " << e.what() << "\n";
    }
}


static void addStudyTask(TaskManager& manager) {
    std::cout << "\n  --- Add Study Task ---\n";
    try {
        std::string title    = readLine("  Title       : ");
        std::string desc     = readLine("  Description : ");
        int         priority = readInt ("  Priority (1-5): ", 1, 5);
        std::string dueDate  = readLine("  Due Date    : ");
        std::string subject  = readLine("  Subject     : ");
        std::cout << "  Resource URL (press Enter to skip): ";
        std::string url;
        std::getline(std::cin, url);

        auto task = std::make_shared<StudyTask>(
            title, desc, priority, dueDate, subject, url);
        manager.addTask(task);
    } catch (const std::exception& e) {
        std::cout << "  Error: " << e.what() << "\n";
    }
}


static void menuAddTask(TaskManager& manager) {
    std::cout << "\n  Task type:\n"
              << "    1. Work Task\n"
              << "    2. Urgent Work Task\n"
              << "    3. Study Task\n";
    int choice = readInt("  Select: ", 1, 3);
    switch (choice) {
        case 1: addWorkTask(manager);       break;
        case 2: addUrgentWorkTask(manager); break;
        case 3: addStudyTask(manager);      break;
    }
}


static void menuSort(TaskManager& manager) {
    std::cout << "\n  Sort by:\n"
              << "    1. Priority (highest first)\n"
              << "    2. Title (alphabetical)\n";
    int choice = readInt("  Select: ", 1, 2);
    if (choice == 1) manager.sortByPriority();
    else             manager.sortByTitle();
}


static void menuFilterDemo(TaskManager& manager) {
    std::cout << "\n  --- Generic Filter Demo (template bonus) ---\n";
    std::cout << "  Filter by:\n"
              << "    1. Work Tasks (includes Urgent)\n"
              << "    2. Study Tasks\n"
              << "    3. Urgent Work Tasks only\n";
    int choice = readInt("  Select: ", 1, 3);

    if (choice == 1) {
        auto workTasks = manager.filterTasks<WorkTask>();
        std::cout << "  Found " << workTasks.size() << " work task(s):\n";
        for (auto& t : workTasks) t->display();
    } else if (choice == 2) {
        auto studyTasks = manager.filterTasks<StudyTask>();
        std::cout << "  Found " << studyTasks.size() << " study task(s):\n";
        for (auto& t : studyTasks) t->display();
    } else {
        auto urgentTasks = manager.filterTasks<UrgentWorkTask>();
        std::cout << "  Found " << urgentTasks.size() << " urgent work task(s):\n";
        for (auto& t : urgentTasks) t->display();
    }
}


static void loadDemoData(TaskManager& manager) {
    try {
        manager.addTask(std::make_shared<StudyTask>(
            "Read C++ Primer",
            "Finish chapters 10-12 on STL containers",
            3, "2025-05-15", "Computer Science",
            "https://leanpub.com/cppprimerplus"));

        manager.addTask(std::make_shared<WorkTask>(
            "Prepare Q2 Report",
            "Compile sales figures and write executive summary",
            4, "2025-05-12", "Marketing", "Alice Smith"));

        manager.addTask(std::make_shared<UrgentWorkTask>(
            "Fix Production Bug",
            "Null-pointer crash on checkout page",
            5, "2025-05-09", "Engineering", "Bob Jones",
            4, "CTO: carol@example.com"));

        manager.addTask(std::make_shared<StudyTask>(
            "Revise Calculus",
            "Review integration techniques for the exam",
            2, "2025-05-20", "Mathematics"));

        manager.addTask(std::make_shared<WorkTask>(
            "Interview Candidates",
            "Technical screen for two junior dev positions",
            3, "2025-05-14", "HR", "Dave Lee"));
    } catch (const std::exception& e) {
        std::cerr << "Demo data error: " << e.what() << "\n";
    }
}




int main() {
    std::cout << "=========================================\n";
    std::cout << "   C++ Task Manager — Coursework Project  \n";
    std::cout << "=========================================\n";

    TaskManager manager;
    loadDemoData(manager);
    std::cout << "\n  (Demo data loaded — 5 tasks)\n";

    bool running = true;
    while (running) {
        std::cout << "\n╔══════════════════════════╗\n";
        std::cout << "║         MAIN MENU         ║\n";
        std::cout << "╠══════════════════════════╣\n";
        std::cout << "║  1. Add Task              ║\n";
        std::cout << "║  2. Display All Tasks     ║\n";
        std::cout << "║  3. Search by Title       ║\n";
        std::cout << "║  4. Sort Tasks            ║\n";
        std::cout << "║  5. Delete Task           ║\n";
        std::cout << "║  6. Summary               ║\n";
        std::cout << "║  7. Generic Filter (bonus)║\n";
        std::cout << "║  0. Exit                  ║\n";
        std::cout << "╚══════════════════════════╝\n";

        int choice = readInt("  Your choice: ", 0, 7);

        switch (choice) {
            case 1:
                menuAddTask(manager);
                break;

            case 2:
                std::cout << "\n  --- All Tasks ---\n";
                manager.displayAll();
                break;

            case 3: {
                std::string kw = readLine("  Search keyword: ");
                std::cout << "\n  --- Search Results ---\n";
                
                try {
                    manager.searchByTitle(kw);
                } catch (const std::exception& e) {
                    std::cout << "  Error during search: " << e.what() << "\n";
                }
                break;
            }

            case 4:
                menuSort(manager);
                break;

            case 5: {
                std::string title = readLine("  Title to delete: ");
                try {
                    if (manager.deleteByTitle(title)) {
                        std::cout << "  Task \"" << title << "\" deleted.\n";
                    } else {
                        std::cout << "  Task \"" << title << "\" not found.\n";
                    }
                } catch (const std::exception& e) {
                    std::cout << "  Error: " << e.what() << "\n";
                }
                break;
            }

            case 6:
                std::cout << "\n";
                manager.displaySummary();
                break;

            case 7:
                menuFilterDemo(manager);
                break;

            case 0:
                running = false;
                std::cout << "\n  Goodbye!\n";
                break;
        }
    }

    return 0;
}
