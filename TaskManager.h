#pragma once
#include <vector>
#include <memory>
#include <string>
#include <functional>
#include "Task.h"








class TaskManager {
private:
    
    std::vector<std::shared_ptr<Task>> tasks;

public:
    
    void addTask(std::shared_ptr<Task> task);
    void displayAll() const;
    void displayByType(const std::string& type) const;
    void searchByTitle(const std::string& keyword) const;
    void sortByPriority();          
    void sortByTitle();
    bool deleteByTitle(const std::string& title);
    void displaySummary() const;    

    int  getTaskCount() const;

    
    
    
    template <typename T>
    std::vector<std::shared_ptr<T>> filterTasks() const {
        std::vector<std::shared_ptr<T>> result;
        for (const auto& task : tasks) {
            
            auto casted = std::dynamic_pointer_cast<T>(task);
            if (casted) {
                result.push_back(casted);
            }
        }
        return result;
    }
};
