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


