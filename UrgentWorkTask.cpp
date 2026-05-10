#include "UrgentWorkTask.h"
#include <iostream>
#include <stdexcept>




UrgentWorkTask::UrgentWorkTask(const std::string& title,
                               const std::string& description,
                               int priority,
                               const std::string& dueDate,
                               const std::string& department,
                               const std::string& assignedTo,
                               int hoursUntilDeadline,
                               const std::string& escalationContact)
    : WorkTask(title, description, priority, dueDate, department, assignedTo),
      hoursUntilDeadline(hoursUntilDeadline),
      escalationContact(escalationContact)
{
    if (hoursUntilDeadline <= 0) {
        throw std::invalid_argument("Hours until deadline must be positive.");
    }
    if (escalationContact.empty()) {
        throw std::invalid_argument("Escalation contact cannot be empty for an UrgentWorkTask.");
    }
}

void UrgentWorkTask::display() const {
    std::cout << "┌─────────────────────────────────────────\n";
    std::cout << "│  [!!! URGENT WORK TASK !!!]\n";
    std::cout << "│  Title       : " << title               << "\n";
    std::cout << "│  Desc        : " << description          << "\n";
    std::cout << "│  Priority    : " << priority             << " / 5\n";
    std::cout << "│  Due Date    : " << dueDate              << "\n";
    std::cout << "│  Department  : " << department           << "\n";
    std::cout << "│  Assigned To : " << assignedTo           << "\n";
    std::cout << "│  Hours Left  : " << hoursUntilDeadline   << " hour(s)\n";
    std::cout << "│  Escalate To : " << escalationContact    << "\n";
    std::cout << "└─────────────────────────────────────────\n";
}

std::string UrgentWorkTask::getType()                const { return "UrgentWorkTask"; }
int         UrgentWorkTask::getHoursUntilDeadline()  const { return hoursUntilDeadline; }
std::string UrgentWorkTask::getEscalationContact()   const { return escalationContact; }
