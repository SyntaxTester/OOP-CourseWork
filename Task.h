#pragma once
#include <string>





class Task {
protected:
    std::string title;
    std::string description;
    int priority;      
    std::string dueDate;

public:
    Task(const std::string& title,
         const std::string& description,
         int priority,
         const std::string& dueDate);

    virtual ~Task() = default;

    
    virtual void display() const = 0;

    
    virtual std::string getType() const;

    
    std::string getTitle()       const;
    std::string getDescription() const;
    int         getPriority()    const;
    std::string getDueDate()     const;

    
    void setPriority(int p);
};
