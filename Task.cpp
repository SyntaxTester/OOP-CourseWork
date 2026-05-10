#include "Task.h"
#include <stdexcept>





Task::Task(const std::string& title,
           const std::string& description,
           int priority,
           const std::string& dueDate)
    : title(title), description(description), dueDate(dueDate)
{
    
    if (title.empty()) {
        throw std::invalid_argument("Task title cannot be empty.");
    }
    
    setPriority(priority);
}

void Task::setPriority(int p) {
    if (p < 1 || p > 5) {
        throw std::out_of_range("Priority must be between 1 and 5.");
    }
    priority = p;
}

std::string Task::getType()        const { return "Task"; }
std::string Task::getTitle()       const { return title; }
std::string Task::getDescription() const { return description; }
int         Task::getPriority()    const { return priority; }
std::string Task::getDueDate()     const { return dueDate; }
