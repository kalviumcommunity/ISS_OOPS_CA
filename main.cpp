#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Candidate {
private:
    string name;
    string email;

public:
    Candidate(string name, string email) : name(name), email(email) {}

    string getName() const {
        return name;
    }

    string getEmail() const {
        return email;
    }
};

class Meeting {
private:
    string date;
    string time;
    Candidate candidate;

public:
    Meeting(string date, string time, Candidate candidate) : date(date), time(time), candidate(candidate) {}

    string getDate() const {
        return date;
    }

    string getTime() const {
        return time;
    }

    Candidate getCandidate() const {
        return candidate;
    }
};

class MeetingScheduler {
private:
    vector<Meeting> meetings;

public:
    void scheduleMeeting(string date, string time, Candidate candidate) {
        Meeting meeting(date, time, candidate);
        meetings.push_back(meeting);
        cout << "Meeting scheduled successfully for " << candidate.getName() << endl;
    }

    void listMeetings() {
        if (meetings.empty()) {
            cout << "No meetings scheduled." << endl;
            return;
        }

        cout << "Scheduled Meetings:" << endl;
        for (const Meeting& meeting : meetings) {
            cout << "Date: " << meeting.getDate() << ", Time: " << meeting.getTime() << ", Candidate: " << meeting.getCandidate().getName() << endl;
        }
    }
};

int main() {
    MeetingScheduler scheduler;

    Candidate candidate1("Dev Pratap", "dev@freshmenu.com");
    Candidate candidate2("Navaneeth", "nav@phonepe.com");

    scheduler.scheduleMeeting("2023-09-25", "10:00 AM", candidate1);
    scheduler.scheduleMeeting("2023-09-26", "2:00 PM", candidate2);

    scheduler.listMeetings();

    return 0;
}
