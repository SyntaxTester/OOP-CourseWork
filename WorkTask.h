#pragma once
#include "Task.h"





class WorkTask : public Task {
protected:
    std::string department;   
    std::string assignedTo;   

public:
    WorkTask(const std::string& title,
             const std::string& description,
             int priority,
             const std::string& dueDate,
             const std::string& department,
             const std::string& assignedTo);

    
    void        display() const override;
    std::string getType() const override;

    
    std::string getDepartment()  const;
    std::string getAssignedTo()  const;
};
