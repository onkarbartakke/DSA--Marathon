#include<bits/stdc++.h>

using namespace std;

class Task;


enum TaskType {STORY , FEATURE, BUG};
enum TaskStatus {OPEN , IN_PROGRESS, RESOLVED, DELAYED, COMPLETED};



class Sprint
{
    private:
    int begin,end;
    string name;
    vector<Task>tasks;

    public:
    Sprint(int begin, int end, string name);
    void addTask(Task &task);
    void printDetails();
    const vector<Task>& getTasks() const;
    bool operator==(Sprint spr);
    void eraseTask(int taskNumber);
};

class User
{
    private:
    vector<Task>taskList;
    vector<Sprint>sprintList;
    public:
    Task createTask(TaskType);
    Task createTask(string);
    Sprint createSprint(int,int,string);
    bool addToSprint(Sprint& , Task&);
    bool removeFromSprint(Sprint& , Task&); 
    void printAllTasks();
    bool changeStatus(Task& , TaskStatus);

};

class Task
{
    private:
    int id;
    string substract;
    User user;
    TaskType taskType;
    TaskStatus taskStatus; 
    
    public:
    Task();
    int getId() const;
    int getUniqueId();
    void setSubstract(const string &s);
    void setUser(User user);
    void setTaskType(TaskType taskType);
    void setTaskStatus(TaskStatus taskSatus);
    bool operator==(Task task);
};



Task User::createTask(TaskType taskType)
{
    if(taskType == TaskType::STORY)
    {
        cout<<"Warning! Task of type STORY is being created with no subtract\n";

    }
    Task task;
    task.setTaskType(taskType);
    task.setUser(*this);
    taskList.push_back(task);

    return task;

}

Task User::createTask(string substract)
{
    Task task;
    task.setTaskType(TaskType::STORY);
    task.setSubstract(substract);
    task.setUser(*this);
    taskList.push_back(task);

    return task;
}

Sprint User::createSprint(int start, int end, string name)
{
    Sprint sprint(start,end,name);
    sprintList.push_back(sprint);

    return sprint;
}

bool User::addToSprint(Sprint &sprint, Task &task)
{
    for(Sprint spr : sprintList)
    {
        if(spr == sprint)
        {
            sprint.addTask(task);
            return true;
        }
    }

    return false;
}

bool User::removeFromSprint(Sprint &sprint, Task &task)
{
    vector<Task>taskList;


    for(Sprint spr : sprintList)
    {
        if(spr == sprint)
        {
          taskList = spr.getTasks();
          break;    
        }
    }

    int i = 0;
    for(Task t : taskList)
    {
        if(t == task)
        {
            sprint.eraseTask(i);
            return true;
        }

        i++;
    }

    return false;
}

void User::printAllTasks()
{
    for(Task task : taskList)
    {
        cout<<task.getId()<<" ";
    }

    cout<<"\n";
}

bool User::changeStatus(Task &task, TaskStatus taskStatus)
{
    for(Task &t : taskList)
    {
        if(t.getId() == task.getId())
        {
            t.setTaskStatus(taskStatus);
            return true;
        }
    }

    return false;
}





Task::Task()
{
    this->id = getUniqueId();
    this->taskStatus = TaskStatus::OPEN;

}

int Task::getUniqueId()
{
    static int taskId = 1;
    return taskId++;
}


int Task::getId() const{
    return this->id;
}

void Task::setSubstract(const string &substract)
{
    this->substract = substract;
}

void Task::setTaskStatus(TaskStatus taskSatus)
{
    this->taskStatus = taskSatus;
}

void Task::setTaskType(TaskType taskType)
{
    this->taskType = taskType;
}

void Task::setUser(User user)
{
    this->user = user;
}

const vector<Task>& Sprint::getTasks() const{
    return this->tasks;
}

bool Task::operator==(Task task)
{
    if(this->id == task.id)
    return true;
    else
    return false;
}



Sprint::Sprint(int begin, int end, string name)
{
    this->begin = begin;
    this->end = end;
    this->name = name;
}

void  Sprint::addTask(Task &task)
{
    tasks.push_back(task);
}

void Sprint::printDetails()
{
    cout<<"Sprint Name : "<<this->name<<"\n";
    cout<<"Sprint Begins : "<<this->begin<<"\n";
    cout<<"Sprint Ends : "<<this->end<<"\n\n";  
}

bool Sprint::operator==(Sprint spr)
{
    if(this->begin == spr.begin  && this->end == spr.end && this->name == spr.name)
    return true;
    else
    return false;
}
 
void Sprint::eraseTask(int taskNumber)
{
    tasks.erase(tasks.begin() + taskNumber);
}


int main()
{
    cout<<"Hello World!";    
}