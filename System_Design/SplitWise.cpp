#include<bits/stdc++.h>

using namespace std;

enum Split{ EQUAL , EXACT, PERCENT};


class User
{
    private:
    int id;
    string name;
    vector<pair<User,double>>userExpenseSheet;
    double totalExpenseSoFar;

    public:
    User(string &);
    int getUniqueId();
    int getId();
    const string& getName() const; 
    void addToUserExpenseSheet(User &, double);
    double getTotalExpenseSoFar() const;    
    const vector<pair<User,double>>& getUserExpenseSheet() const;
    void printTotalBalance();
};


User::User(string &name)
{
    this->name = name;
    this->id = getUniqueId();
    this->totalExpenseSoFar = 0.0;
    this->userExpenseSheet.clear();
}


int User::getUniqueId()
{
    static int uniqueId = 1;
    return uniqueId++;
}

int User::getId()
{
    return this->id;
}


const string& User::getName() const
{
    return this->name;
}

double User::getTotalExpenseSoFar() const
{
    return this->totalExpenseSoFar;
}

const vector<pair<User,double>>& User::getUserExpenseSheet() const
{
    return this->userExpenseSheet;
}


void User::addToUserExpenseSheet(User &user, double value)
{
    if(this->id == user.id)
    return;

    this->totalExpenseSoFar += value;

    for(pair<User,double>&newExpense : userExpenseSheet)
    {
        if(newExpense.first.id == user.id)
        {
            newExpense.second += value;
            return;
        }
    }

    userExpenseSheet.push_back({user,value});
    return;
}

void User::printTotalBalance()
{
    if(this->totalExpenseSoFar > 0)
    cout<<this->getName()<<" owes a total of "<<this->totalExpenseSoFar<<"\n";
    else
    cout<<this->getName()<<" gets back a total of "<<this->totalExpenseSoFar * (-1)<<"\n";
}


class Expense
{
    private:
    int id;
    string description;
    Split split;
    vector<double>percentageDistribution; 
    vector<double>exactDistribution;

    public:
    int getId()const;
    const string getDescription() const;

};


class Splitwise
{
    private:
    vector<User>users;
    unordered_set<int>userIds;

    public:
    bool calulateExpenses();
    bool verifyUsers();
    void registerUser();
    void addExpense();
    void printBalanceForAllUsers();

};


int main()
{

}