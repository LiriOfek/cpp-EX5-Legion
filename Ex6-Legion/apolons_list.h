/********************************************************\
File Name: apolons_list.h
Author: Liri (20/4/2020)
Purpose: This header file contain the declaration of the functions of
		 apolons list, and defines of constants
\********************************************************/

#pragma once

#include "apolon.h"

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
/**
* @brief  add apolon to the middle or the end of the list, such that
*		  the apolon will add in sorted ascending way of personal number
* @param  INOUT std::shared_ptr<Apolon> &apolons_list - the list of apolons
*		  IN std::shared_ptr<Apolon> &new_apolon - the new apolon
*		  OUT std::shared_ptr<Apolon> the list of apolons after add the
*			new apolon
* @return the sorted list by personal number after add the new apolon
* @notes  change the apolon list such that add the new apolon to it
* @author  Liri
*/

std::shared_ptr<Apolon> add_apolon_to_sort_list(std::shared_ptr<Apolon> &apolons_list,
	std::shared_ptr<Apolon> &new_apolon);
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

int length_of_list(std::shared_ptr<Apolon> apolons_list);
/**
* @brief  go through the list of the apolons and calculate the length
*		  of the list
* @param  IN std::shared_ptr<Apolon> &apolons_list - the list of apolons
*		  OUT int the length of the list
* @return the length of the given list
* @author  Liri
*/

std::shared_ptr<Apolon> create_and_add_apolon_to_list(std::shared_ptr<Apolon> &apolons_list,
														std::string first_name,
														std::string last_name,
														int personal_number,
														int age,
														const char* gender,
														const char* is_vegetrian,
														int cycle_number,
														Address address);
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

void print_current_apolon(std::shared_ptr<Apolon> current_apolon);
/**
* @brief  print the fields of current apolon
* @param  IN std::shared_ptr<Apolon> current_apolon - the current apolon
* @return  this function has no return value
* @author  Liri
*/

void print_apolons(std::shared_ptr<Apolon> &apolons_list);
/**
* @brief  print the fields of all the apolons that in the list
* @param  IN std::shared_ptr<Apolon> &apolons_list - the apolons list
* @return  this function has no return value
* @author  Liri
*/

void print_apolons_from_cycle(std::shared_ptr<Apolon> &apolons_list, int cycle);
/**
* @brief  print the apolons from the given cycle
* @param  IN std::shared_ptr<Apolon> &apolons_list - the apolons list
*		  IN int cycle - the given cycke
* @return  this function has no return value
* @author  Liri
*/

std::shared_ptr<Apolon> find_apolon(std::shared_ptr<Apolon> &apolons_list,
									const char* first_name,
									const char* last_name);
/**
* @brief  find the first apolon that mach the given first and last names,
*			if none of the apolons match return nullptr
* @param  IN std::shared_ptr<Apolon> &apolons_list - the apolons list
*		  IN const char* first_name - the first name of the apolon we search
*		  IN const char* last_name - the last name of the apolon we search
*		  OUT std::shared_ptr<Apolon> - the apolon that we searched
* @return  std::shared_ptr<Apolon> the apolon we that match to the given
*			first and last names, if none of the apolons match return nullptr
* @author  Liri
*/

std::shared_ptr<Apolon> remove_apolon(std::shared_ptr<Apolon> &apolons_list,
										std::string first_name,
										std::string last_name);
/**
* @brief  remove the first apolon that match to the given first and last names
* @param  INOUT std::shared_ptr<Apolon> &apolons_list - the apolons list
*		  IN const char* first_name - the first name of the apolon we want to remove
*		  IN const char* last_name - the last name of the apolon we want to remove
*	      OUT std::shared_ptr<Apolon> the apolon list after remove the apolon that
*		  match to  the first and last given names
* @return std::shared_ptr<Apolon> the apolon list after remove the apolon that
*		  match to the first and last given names
* @notes  change the list of apolons such that it remove the apolon with the
*		  given first and last names
* @author  Liri
*/

void remove_all_apolons_from_list(std::shared_ptr<Apolon> &apolons_list);
/**
* @brief  remove all apolons from list, reset the pointers
* @param  INOUT std::shared_ptr<Apolon> &apolons_list - the apolons list
*          after remove all the apolons from it
* @return this function has no return value
* @notes  change the list of apolons such that it remove all
*			the apolons from it
* @author  Liri
*/