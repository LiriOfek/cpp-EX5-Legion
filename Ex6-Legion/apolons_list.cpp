/********************************************************\
File Name: apolons_list.cpp
Author: Liri (20/4/2020)
Purpose: This file contain functions of apolons list
\********************************************************/

#include "apolons_list.h"

std::shared_ptr<Apolon> add_apolon_to_middle_or_end_of_list(std::shared_ptr<Apolon> &apolons_list,
	std::shared_ptr<Apolon> &new_apolon) {
	/**
	* @brief  add apolon to the middle or the end of the list, such that
	*		  the apolon will add in sorted ascending way of personal number
	* @param  IN std::shared_ptr<Apolon> &apolons_list - the list of apolons
	*		  IN std::shared_ptr<Apolon> &new_apolon - the new apolon
	* @return the sorted list by personal number after add the new apolon
	* @notes  change the apolon list such that add the new apolon to it
	* @author  Liri
	*/
	std::shared_ptr<Apolon> current_apolon = apolons_list;
	while (nullptr != current_apolon->_next) {
		if (current_apolon->_next->personal_number > new_apolon->personal_number) {
			std::shared_ptr<Apolon> apolon_to_swap = current_apolon->_next;
			current_apolon->_next = new_apolon;
			new_apolon->_next = apolon_to_swap;
			break;
		}
		current_apolon = current_apolon->_next;
	}
	if (nullptr == current_apolon->_next)
	{
		current_apolon->_next = new_apolon;
	}
	return apolons_list;
}

std::shared_ptr<Apolon> add_apolon_to_sort_list(std::shared_ptr<Apolon> &apolons_list,
	std::shared_ptr<Apolon> &new_apolon) {
	/**
	* @brief  add apolon to the list such that the list will be sorted
	*		  in ascending personal number
	* @param  INOUT std::shared_ptr<Apolon> &apolons_list - the list of apolons
	*		  IN std::shared_ptr<Apolon> &new_apolon - the new apolon
	*		  OUT std::shared_ptr<Apolon> the apolons list after add to it the
	*			new apolon
	* @return the sorted list by personal number after add the new apolon
	* @notes  change the apolon list, such that add to it the new apolon
	* @author Liri
	*/
	std::shared_ptr<Apolon> current_apolon = apolons_list;
	if (nullptr == apolons_list) {
		apolons_list = new_apolon;
		return apolons_list;
	}

	if (current_apolon->personal_number > new_apolon->personal_number) {
		new_apolon->_next = current_apolon;
		apolons_list = new_apolon;
		return new_apolon;
	}

	return add_apolon_to_middle_or_end_of_list(apolons_list, new_apolon);
}

int length_of_list(std::shared_ptr<Apolon> apolons_list) {
	/**
	* @brief  go through the list of the apolons and calculate the length
	*		  of the list
	* @param  IN std::shared_ptr<Apolon> &apolons_list - the list of apolons
	*		  OUT int the length of the list
	* @return the length of the given list
	* @author  Liri
	*/
	int length = 0;
	std::shared_ptr<Apolon> current_apolon;
	current_apolon = apolons_list;
	while (nullptr != current_apolon) {
		length++;
		current_apolon = current_apolon->_next;
	}
	return length;
}

std::shared_ptr<Apolon> create_and_add_apolon_to_list(std::shared_ptr<Apolon> &apolons_list,
	std::string first_name,
	std::string last_name,
	int personal_number,
	int age,
	const char* gender,
	const char* is_vegetrian,
	int cycle_number,
	Address address) {
	/**
	* @brief  create new apolon and add to the list of apolons
	* @param  INOUT std::shared_ptr<Apolon> &apolons_list - the list of apolons
	*		  IN std::string first_name - the first name of the new apolon
	*		  IN std::string last_name - the last name of the new apolon
	*		  IN int personal_number - the personal number of the new apolon
	*		  IN int age - the age of the new apolon
	*		  IN const char* gender - the gender of the new wapolon
	*		  IN const char* is_vegetrian - string that says if the new apolon
	*		  is vegetrian
	*		  IN int cycle_number - the cycle number of the course of the new apolon
	*		  IN Address address - the address of the new apolon
	*		  OUT std::shared_ptr<Apolon> - the apolon list
	* @return the sorted list by personal number after add the new apolon
	* @notes  change the apolon list such that add to it the new apolon
	* @author  Liri
	*/
	std::shared_ptr<Apolon> new_apolon(new Apolon());

	new_apolon->first_name = first_name;
	new_apolon->last_name = last_name;
	new_apolon->personal_number = personal_number;
	new_apolon->age = age;
	new_apolon->gender = gender;
	new_apolon->is_vegetrian = is_vegetrian;
	new_apolon->cycle_number = cycle_number;
	new_apolon->address = address;

	add_apolon_to_sort_list(apolons_list, new_apolon);
	return apolons_list;
}

void print_current_apolon(std::shared_ptr<Apolon> current_apolon) {
	/**
	* @brief  print the fields of current apolon
	* @param  IN std::shared_ptr<Apolon> current_apolon - the current apolon
	* @return  this function has no return value
	* @author  Liri
	*/
	std::cout << NAME
		<< current_apolon->first_name
		<< SPACE
		<< current_apolon->last_name
		<< PERSONAL_NUMBER
		<< current_apolon->personal_number
		<< AGE
		<< current_apolon->age
		<< GENDER
		<< current_apolon->gender
		<< IS_VEGETRIAN
		<< current_apolon->is_vegetrian
		<< CYCLE_NUMBER
		<< current_apolon->cycle_number
		<< APARTMENT_NUMBER
		<< current_apolon->address.apartment_number
		<< STREET
		<< current_apolon->address.street_name
		<< POSTAL_CODE
		<< current_apolon->address.postal_code
		<< std::endl;
}

void print_apolons(std::shared_ptr<Apolon> &apolon_list) {
	/**
	* @brief  print the fields of all the apolons that in the list
	* @param  IN std::shared_ptr<Apolon> &apolon_list - the apolons list
	* @return  this function has no return value
	* @author  Liri
	*/
	std::shared_ptr<Apolon> current_apolon;
	current_apolon = apolon_list;
	while (nullptr != current_apolon) {
		print_current_apolon(current_apolon);
		current_apolon = current_apolon->_next;
	}
	std::cout << std::endl;
}

void print_apolons_from_cycle(std::shared_ptr<Apolon> &apolon_list, int cycle) {
	/**
	* @brief  print the apolons from the given cycle
	* @param  IN std::shared_ptr<Apolon> &apolon_list - the apolons list
	*		  IN int cycle - the given cycke
	* @return  this function has no return value
	* @author  Liri
	*/
	std::shared_ptr<Apolon> current_apolon;
	current_apolon = apolon_list;
	while (nullptr != current_apolon) {
		if (current_apolon->cycle_number == cycle) {
			print_current_apolon(current_apolon);
		}
		current_apolon = current_apolon->_next;
	}
	std::cout << std::endl;
}