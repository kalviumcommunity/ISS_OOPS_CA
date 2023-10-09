#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Candidate {
private:
    string name;
    string email;

public:
    Candidate(){
        cout << "Default Constructor Called" << endl;
    };
    Candidate(string name, string email) {
        this->name = name;
        this->email = email;
        cout << "Parameterised Constructor Called" << endl;
    }
    ~Candidate(){
        cout << "Candidate Destructor Called" << endl;
    };
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
    Candidate candidate;

public:
    Meeting(string date, string time, Candidate candidate) {
        this->date = date;
        this->time = time;
        this->candidate = candidate;
    }
    Meeting(const Meeting &other){
        this->date = other.date;
        this->time = other.time;
        this->candidate = other.candidate;
        cout << "Copy Constructor Called" << endl;
    }
    ~Meeting() {
        cout << "Destructor Called" << endl;
    }

    string getDate() const {
        return this->date;
    }

    string getTime() const {
        return this->time;
    }
 
    Candidate getCandidate() const {
        return this->candidate;
    }
};

class MeetingScheduler {
private:
    vector<Meeting> meetings;

public:
    void scheduleMeeting(Candidate candidate) {
        string date, time;
        cout << "Enter Meeting Date (YYYY-MM-DD): ";
        getline(cin, date);
        cout << "Enter Meeting Time (HH:MM AM/PM): ";
        getline(cin, time);
        
        Meeting meeting(date, time, candidate);
        meetings.push_back(meeting);
        cout << "Meeting scheduled successfully for " << candidate.getName() << endl;
    }

// For later milestones
    // void listMeetings() {
    //     if (meetings.empty()) {
    //         cout << "No meetings scheduled." << endl;
    //         return;
    //     }

    //     cout << "Scheduled Meetings:" << endl;
    //     for (const Meeting& meeting : meetings) {
    //         cout << "Date: " << meeting.getDate() << ", Time: " << meeting.getTime() << ", Candidate: " << meeting.getCandidate().getName() << endl;
    //     }
    // }
};

int main() {
    MeetingScheduler scheduler;
    Candidate c1;
    c1.setCandidate();

    scheduler.scheduleMeeting(c1);

// For later milestones
    // scheduler.listMeetings();

    return 0;
}
