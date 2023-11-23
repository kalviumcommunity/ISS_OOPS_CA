#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    string email;

public:
    Person() {}
    Person(string name, string email) : name(name), email(email) {}

    // Pure virtual function, making Person an abstract class
    virtual void setDetails() = 0;

    string getName() const {
        return name;
    }

    string getEmail() const {
        return email;
    }
};

class Candidate : public Person {
public:
    Candidate() {}
    Candidate(string name, string email) : Person(name, email) {}

    void setDetails() override {
        cout << "Enter Candidate Name: ";
        getline(cin, name);
        cout << "Enter Candidate Email: ";
        getline(cin, email);
    }
};

class Employee : public Person {
private:
    string designation;

public:
    Employee() {}
    Employee(string name, string email, string designation) : Person(name, email), designation(designation) {}

    void setDetails() override {
        cout << "Enter Employee Name: ";
        getline(cin, name);
        cout << "Enter Employee Email: ";
        getline(cin, email);
        cout << "Enter Designation: ";
        getline(cin, designation);
    }

    string getDesignation() const {
        return designation;
    }
};

class Meeting {
private:
    string date;
    string time;
    Person* participant;

public:
    Meeting(string date, string time, Person* participant) : date(date), time(time), participant(participant) {}

    string getDate() const {
        return date;
    }

    string getTime() const {
        return time;
    }

    Person* getParticipant() const {
        return participant;
    }
};

class MeetingScheduler {
private:
    static string companyName;
    vector<Meeting*> meetings;

public:
    static void setCompanyName(string name) {
        companyName = name;
    }

    static string getCompanyName() {
        return companyName;
    }

    void scheduleMeeting(Person* participant) {
        string date, time;
        cout << "Enter Meeting Date (DD-MM-YYYY): ";
        getline(cin, date);
        cout << "Enter Meeting Time (HH:MM AM/PM): ";
        getline(cin, time);

        Meeting* meeting = new Meeting(date, time, participant);
        meetings.push_back(meeting);
        cout << "Meeting scheduled successfully for " << participant->getName() << endl;
    }

    void listMeetings() {
        if (meetings.empty()) {
            cout << "No meetings scheduled." << endl;
            return;
        }

        for (const Meeting* meeting : meetings) {
            cout << "Date: " << meeting->getDate() << ", Time: " << meeting->getTime() << ", Participant: " << meeting->getParticipant()->getName() << endl;
        }
    }

    ~MeetingScheduler() {
        for (Meeting* meeting : meetings) {
            delete meeting;
        }
    }
};

string MeetingScheduler::companyName = "";

int main() {
    MeetingScheduler::setCompanyName("PhonePe");
    MeetingScheduler scheduler;
    Person* participant;

    while (true) {
        cout << "Select participant type (1 for Candidate, 2 for Employee, 0 to exit): ";
        int choice;
        cin >> choice;
        cin.ignore();  // Consume the newline character left by cin

        switch (choice) {
            case 1:
                participant = new Candidate();
                break;
            case 2:
                participant = new Employee();
                break;
            default:
                // Exit the loop if the choice is not 1 or 2
                delete participant;
                participant = nullptr;
                break;
        }

        if (!participant) {
            break;  // Exit the loop if participant is null
        }

        participant->setDetails();
        scheduler.scheduleMeeting(participant);

        cout << "Do you want to schedule another meeting? (yes/no): ";
        string choiceStr;
        getline(cin, choiceStr);

        if (choiceStr != "yes") {
            delete participant;
            break;
        }
    }

    cout << "Welcome to " << MeetingScheduler::getCompanyName() << ", Here are your scheduled meetings: " << endl;
    scheduler.listMeetings();

    return 0;
}
