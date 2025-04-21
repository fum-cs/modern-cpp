
#include <iostream>
#include <string>

enum Day { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

std::string get_day_name(Day day) {
    switch (day) {
        case Sunday: return "Sunday";
        case Monday: return "Monday";
        case Tuesday: return "Tuesday";
        case Wednesday: return "Wednesday";
        case Thursday: return "Thursday";
        case Friday: return "Friday";
        case Saturday: return "Saturday";
        default: return "Invalid day";
    }
}

int main() {
    Day today = Monday;
    std::cout << "Today is " << get_day_name(today) << ".\n";

    Day tomorrow = static_cast<Day>(today + 1);
    std::cout << "Tomorrow will be " << get_day_name(tomorrow) << ".\n";

    return 0;
}