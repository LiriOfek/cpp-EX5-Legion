/********************************************************\
File Name: apolon.h
Author: Liri (20/4/2020)
Purpose: This header file contain apolon struct and address struct
\********************************************************/

#pragma once

#include <iostream>
#include <memory>
#include <string>

/*Address struct that contain apartment number, street name and postal code*/
typedef struct address {
	int apartment_number;
	const char* street_name;
	int postal_code;
}Address;

/*Apolon struct that contain first name, last name, personal number, age,
gender, if the apolon is vegetrian, cycle number, address and next Apolon*/
typedef struct apolon {
	std::string first_name;
	std::string last_name;
	int personal_number;
	int age;
	const char* gender;
	const char* is_vegetrian;
	int cycle_number; //cycle number of the course
	Address address;
	std::shared_ptr<apolon> _next;
}Apolon;


