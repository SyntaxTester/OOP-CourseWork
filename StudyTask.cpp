#include "StudyTask.h"
#include <iostream>
#include <stdexcept>





StudyTask::StudyTask(const std::string& title,
                     const std::string& description,
                     int priority,
                     const std::string& dueDate,
                     const std::string& subject,
                     const std::string& resourceUrl)
    : Task(title, description, priority, dueDate),
      subject(subject),
      resourceUrl(resourceUrl)
{
    if (subject.empty()) {
        throw std::invalid_argument("Subject cannot be empty for a StudyTask.");
    }
}

void StudyTask::display() const {
    std::cout << "┌─────────────────────────────────────────\n";
    std::cout << "│  [STUDY TASK]\n";
    std::cout << "│  Title    : " << title       << "\n";
    std::cout << "│  Desc     : " << description  << "\n";
    std::cout << "│  Priority : " << priority     << " / 5\n";
    std::cout << "│  Due Date : " << dueDate      << "\n";
    std::cout << "│  Subject  : " << subject      << "\n";
    if (!resourceUrl.empty()) {
        std::cout << "│  Resource : " << resourceUrl << "\n";
    }
    std::cout << "└─────────────────────────────────────────\n";
}

std::string StudyTask::getType()       const { return "StudyTask"; }
std::string StudyTask::getSubject()    const { return subject; }
std::string StudyTask::getResourceUrl() const { return resourceUrl; }
