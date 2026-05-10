#pragma once
#include "Task.h"





class StudyTask : public Task {
private:
    std::string subject;       
    std::string resourceUrl;   

public:
    StudyTask(const std::string& title,
              const std::string& description,
              int priority,
              const std::string& dueDate,
              const std::string& subject,
              const std::string& resourceUrl = "");

    void        display() const override;
    std::string getType() const override;

    std::string getSubject()     const;
    std::string getResourceUrl() const;
};
