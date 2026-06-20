#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

// Time component
struct Time
{
    int hour;
    int minute;
    bool isAm;
    friend ostream &operator<<(ostream &out, const Time &time)
    {
        out.fill('0');
        out << setw(2) << time.hour << ':' << setw(2) << time.minute << ' ' << ((time.isAm) ? "a.m." : "p.m.") << endl;
        return out;
    }
};

int main(void)
{
    // Mapping each course to its room number
    map<string, int> mapCourseToRoomNumber = {
        {"CS101", 3004},
        {"CS102", 4501},
        {"CS103", 6755},
        {"NT110", 1244},
        {"CM241", 1411}};

    // Mapping each course to its instructor
    map<string, string> mapCourseToInstructor = {
        {"CS101", "Haynes"},
        {"CS102", "Alvarado"},
        {"CS103", "Rich"},
        {"NT110", "Burke"},
        {"CM241", "Lee"}};

    // Mapping each course to its meeting time object
    map<string, Time> mapCourseToMeetingTime = {
        {"CS101", {8, 0, 1}},
        {"CS102", {9, 0, 1}},
        {"CS103", {10, 0, 1}},
        {"NT110", {11, 0, 1}},
        {"CM241", {1, 0, 0}}};

    // Recieve course number as an input value
    string courseNumber;
    cout << "Enter course number: " << endl;
    cin >> courseNumber;

    // Print each course attribute to its mapped value
    cout << "Course's room number: " << ' ' << (mapCourseToRoomNumber[courseNumber]) << endl;
    cout << "Course's instructor: " << ' ' << (mapCourseToInstructor[courseNumber]) << endl;
    cout << "Course's instructor: " << ' ' << (mapCourseToMeetingTime[courseNumber]) << endl;
    return 0;
}