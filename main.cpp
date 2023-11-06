#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Candidate {
private:
    string name;
    string email;

public:
    Candidate(){};
    Candidate(string name, string email) {
        this->name = name;
        this->email = email;
    }
    void setCandidate() {
        string name;
        string email;
        cout << "Enter Candidate Name: ";
        getline(cin, name);
        this->name = name;
        cout << "Enter Candidate Email: ";
        getline(cin, email);
        this->email = email;
    }
    string getName() const {
        return this->name;
    }

    string getEmail() const {
        return this->email;
    }
};

class Meeting {
private:
    string date;
    string time;
    Candidate* candidate;

public:
    Meeting(string date, string time, Candidate* candidate) {
        this->date = date;
        this->time = time;
        this->candidate = candidate;
    }
    Meeting(const Meeting &other){
        this->date = other.date;
        this->time = other.time;
        this->candidate = new Candidate(*(other.candidate));
    }

    ~Meeting() {
        delete candidate;
    }

    string getDate() const {
        return this->date;
    }

    string getTime() const {
        return this->time;
    }

    Candidate* getCandidate() const {
        return this->candidate;
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
    void scheduleMeeting(Candidate* candidate) {
        string date, time;
        cout << "Enter Meeting Date (DD-MM-YYYY): ";
        getline(cin, date);
        cout << "Enter Meeting Time (HH:MM AM/PM): ";
        getline(cin, time);

        Meeting* meeting = new Meeting(date, time, candidate);
        meetings.push_back(meeting);
        cout << "Meeting scheduled successfully for " << candidate->getName() << endl;
    }

    void listMeetings() {
        if (meetings.empty()) {
            cout << "No meetings scheduled." << endl;
            return;
        }

        for (const Meeting* meeting : meetings) {
            cout << "Date: " << meeting->getDate() << ", Time: " << meeting->getTime() << ", Candidate: " << meeting->getCandidate()->getName() << endl;
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
    Candidate* c1;

    while (true) {
        c1 = new Candidate();
        c1->setCandidate();
        scheduler.scheduleMeeting(c1);

        cout << "Do you want to schedule another meeting? (yes/no): ";
        string choice;
        getline(cin, choice);

        if (choice != "yes") {
            delete c1;
            break;
        }
    }

    cout<< "Welcome to "<< MeetingScheduler::getCompanyName() << ", Here are your scheduled meetings: " << endl;
    scheduler.listMeetings();

    return 0;
}
