/********************************************************\
File Name: apolons_list.h
Author: Liri (20/4/2020)
Purpose: This header file contain the declaration of the functions of
		 apolons list, and defines of constants
\********************************************************/

#pragma once

#include "apolon.h"

const int NUMBER_OF_APOLONS = 5;
/*Gender:*/
const char* const MALE = "MALE";
const char* const FEMALE = "FEMALE";
/*Is vegeterian:*/
const char* const YES = "YES";
const char* const NO = "NO";

const char* const NAME = "name: ";
const char* const SPACE = " ";
const char* const PERSONAL_NUMBER = ", personal number: ";
const char* const AGE = ", age: ";
const char* const GENDER = ", gender: ";
const char* const IS_VEGETRIAN = ", is vegetrian: ";
const char* const CYCLE_NUMBER = ", cycle number: ";
const char* const APARTMENT_NUMBER = ", apartment number: ";
const char* const STREET = ", street: ";
const char* const POSTAL_CODE = ", postal code: ";

std::shared_ptr<Apolon> add_apolon_to_middle_or_end_of_list(std::shared_ptr<Apolon> &apolons_list,
	std::shared_ptr<Apolon> &new_apolon);

std::shared_ptr<Apolon> add_apolon_to_sort_list(std::shared_ptr<Apolon> &apolons_list,
	std::shared_ptr<Apolon> &new_apolon);

int length_of_list(std::shared_ptr<Apolon> apolons_list);

std::shared_ptr<Apolon> create_and_add_apolon_to_list(std::shared_ptr<Apolon> &apolons_list,
	std::string first_name,
	std::string last_name,
	int personal_number,
	int age,
	const char* gender,
	const char* is_vegetrian,
	int cycle_number,
	Address address);

void print_current_apolon(std::shared_ptr<Apolon> current_apolon);

void print_apolons(std::shared_ptr<Apolon> &apolon_list);

void print_apolons_from_cycle(std::shared_ptr<Apolon> &apolon_list, int cycle);

std::shared_ptr<Apolon> find_apolon(std::shared_ptr<Apolon> &apolon_list,
	const char* first_name,
	const char* last_name);

std::shared_ptr<Apolon> remove_apolon(std::shared_ptr<Apolon> &apolon_list,
	std::string first_name,
	std::string last_name);