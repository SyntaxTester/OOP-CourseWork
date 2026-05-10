#include "WorkTask.h"
#include <iostream>
#include <stdexcept>





WorkTask::WorkTask(const std::string& title,
                   const std::string& description,
                   int priority,
                   const std::string& dueDate,
                   const std::string& department,
                   const std::string& assignedTo)
    : Task(title, description, priority, dueDate),
      department(department),
      assignedTo(assignedTo)
{
    if (department.empty()) {
        throw std::invalid_argument("Department cannot be empty for a WorkTask.");
    }
}

void WorkTask::display() const {
    std::cout << "┌─────────────────────────────────────────\n";
    std::cout << "│  [WORK TASK]\n";
    std::cout << "│  Title      : " << title       << "\n";
    std::cout << "│  Desc       : " << description  << "\n";
    std::cout << "│  Priority   : " << priority     << " / 5\n";
    std::cout << "│  Due Date   : " << dueDate      << "\n";
    std::cout << "│  Department : " << department   << "\n";
    std::cout << "│  Assigned To: " << assignedTo   << "\n";
    std::cout << "└─────────────────────────────────────────\n";
}

std::string WorkTask::getType()       const { return "WorkTask"; }
std::string WorkTask::getDepartment() const { return department; }
std::string WorkTask::getAssignedTo() const { return assignedTo; }
