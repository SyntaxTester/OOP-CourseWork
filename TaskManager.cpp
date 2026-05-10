#include "TaskManager.h"
#include <iostream>
#include <algorithm>   
#include <stdexcept>











void TaskManager::addTask(std::shared_ptr<Task> task) {
    if (!task) {
        throw std::invalid_argument("Cannot add a null task.");
    }
    
    auto it = std::find_if(tasks.begin(), tasks.end(),
        [&task](const std::shared_ptr<Task>& t) {
            return t->getTitle() == task->getTitle();
        });
    if (it != tasks.end()) {
        throw std::runtime_error("A task with the title \"" + task->getTitle() + "\" already exists.");
    }
    tasks.push_back(task);
    std::cout << "  Task \"" << task->getTitle() << "\" added successfully.\n";
}


void TaskManager::displayAll() const {
    if (tasks.empty()) {
        std::cout << "  No tasks found.\n";
        return;
    }
    std::cout << "  Total tasks: " << tasks.size() << "\n\n";
    for (const auto& task : tasks) {
        task->display();   
    }
}


void TaskManager::displayByType(const std::string& type) const {
    bool found = false;
    for (const auto& task : tasks) {
        if (task->getType() == type) {
            task->display();
            found = true;
        }
    }
    if (!found) {
        std::cout << "  No tasks of type \"" << type << "\" found.\n";
    }
}


void TaskManager::searchByTitle(const std::string& keyword) const {
    bool found = false;
    
    auto it = std::find_if(tasks.begin(), tasks.end(),
        [&keyword](const std::shared_ptr<Task>& t) {
            return t->getTitle().find(keyword) != std::string::npos;
        });

    
    while (it != tasks.end()) {
        (*it)->display();
        found = true;
        it = std::find_if(std::next(it), tasks.end(),
            [&keyword](const std::shared_ptr<Task>& t) {
                return t->getTitle().find(keyword) != std::string::npos;
            });
    }

    if (!found) {
        std::cout << "  No tasks matching \"" << keyword << "\".\n";
    }
}


void TaskManager::sortByPriority() {
    
    std::sort(tasks.begin(), tasks.end(),
        [](const std::shared_ptr<Task>& a, const std::shared_ptr<Task>& b) {
            return a->getPriority() > b->getPriority();
        });
    std::cout << "  Tasks sorted by priority (highest first).\n";
}


void TaskManager::sortByTitle() {
    std::sort(tasks.begin(), tasks.end(),
        [](const std::shared_ptr<Task>& a, const std::shared_ptr<Task>& b) {
            return a->getTitle() < b->getTitle();
        });
    std::cout << "  Tasks sorted alphabetically by title.\n";
}


bool TaskManager::deleteByTitle(const std::string& title) {
    auto it = std::find_if(tasks.begin(), tasks.end(),
        [&title](const std::shared_ptr<Task>& t) {
            return t->getTitle() == title;
        });
    if (it == tasks.end()) {
        return false;
    }
    tasks.erase(it);
    return true;
}


void TaskManager::displaySummary() const {
    
    auto countType = [&](const std::string& type) {
        return std::count_if(tasks.begin(), tasks.end(),
            [&type](const std::shared_ptr<Task>& t) {
                return t->getType() == type;
            });
    };

    std::cout << "  ┌─── Task Summary ───────────────┐\n";
    std::cout << "  │  Total           : " << tasks.size()            << "\n";
    std::cout << "  │  Work Tasks      : " << countType("WorkTask")       << "\n";
    std::cout << "  │  Urgent Work     : " << countType("UrgentWorkTask") << "\n";
    std::cout << "  │  Study Tasks     : " << countType("StudyTask")      << "\n";
    std::cout << "  └────────────────────────────────┘\n";
}


int TaskManager::getTaskCount() const {
    return static_cast<int>(tasks.size());
}
