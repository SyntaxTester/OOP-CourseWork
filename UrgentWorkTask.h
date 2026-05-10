#pragma once
#include "WorkTask.h"






class UrgentWorkTask : public WorkTask {
private:
    int hoursUntilDeadline;   
    std::string escalationContact; 

public:
    UrgentWorkTask(const std::string& title,
                   const std::string& description,
                   int priority,
                   const std::string& dueDate,
                   const std::string& department,
                   const std::string& assignedTo,
                   int hoursUntilDeadline,
                   const std::string& escalationContact);

    void        display() const override;
    std::string getType() const override;

    int         getHoursUntilDeadline()  const;
    std::string getEscalationContact()   const;
};
