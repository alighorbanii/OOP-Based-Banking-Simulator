/**
 * This code defines a class called Date, which represents a date and time. 
 * It includes functionalities to set and get the month, day, year, and hour, as well as to print the date in a specific format.
 **/

#include "Date.h" 

void Date::set(int month_, int day_, int year_, int hour_) {
    // Method to set the date and time
    month = month_; // Set the month of the date
    day = day_; // Set the day of the date
    year = year_; // Set the year of the date
    hour = hour_; // Set the hour of the date
}

int Date::getMonth() const {
    // Method to get the month of the date
    return month; // Return the month of the date
}

int Date::getDay() const {
    // Method to get the day of the date
    return day; // Return the day of the date
}

int Date::getYear() const {
    // Method to get the year of the date
    return year; // Return the year of the date
}

int Date::getHour() const {
    // Method to get the hour of the time
    return hour; // Return the hour of the time
}

void Date::print() const {
    // Method to print the date and time
    string months[] = { // Array containing names of all months
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    // Print formatted date and time
    // Adjust index to match month names starting from January
    cout << months[month - 1] << " " << day << ", " << year << ", " << hour << ":00";
}