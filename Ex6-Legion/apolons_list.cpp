/********************************************************\
File Name: apolons_list.cpp
Author: Liri (20/4/2020)
Purpose: This file contain functions of apolons list
\********************************************************/

#include "apolons_list.h"

std::shared_ptr<Apolon> add_apolon_to_middle_or_end_of_list(std::shared_ptr<Apolon> &apolons_list,
															std::shared_ptr<Apolon> &new_apolon) {
	std::shared_ptr<Apolon> current_apolon = apolons_list;
	while (nullptr != current_apolon->_next) {
		if (current_apolon->_next->personal_number > new_apolon->personal_number) {
			/*find the place for the new apolon*/
			std::shared_ptr<Apolon> apolon_to_swap = current_apolon->_next;
			current_apolon->_next = new_apolon;
			new_apolon->_next = apolon_to_swap;
			break;
		}
		current_apolon = current_apolon->_next;
	}
	if (nullptr == current_apolon->_next)
	{
		/*add apolon in the end of the list*/
		current_apolon->_next = new_apolon;
	}
	return apolons_list;
}

std::shared_ptr<Apolon> add_apolon_to_sort_list(std::shared_ptr<Apolon> &apolons_list,
												std::shared_ptr<Apolon> &new_apolon) {
	std::shared_ptr<Apolon> current_apolon = apolons_list;
	if (nullptr == apolons_list) {
		/*the apolon list is empty -> the new apolon is the head of the list*/
		apolons_list = new_apolon;
		return apolons_list;
	}

	if (current_apolon->personal_number > new_apolon->personal_number) {
		/*add apolon as the head of the list*/
		new_apolon->_next = current_apolon;
		apolons_list = new_apolon;
		return new_apolon;
	}

	return add_apolon_to_middle_or_end_of_list(apolons_list, new_apolon);
}

int length_of_list(std::shared_ptr<Apolon> apolons_list) {
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

void print_apolons(std::shared_ptr<Apolon> &apolons_list) {
	std::shared_ptr<Apolon> current_apolon;
	current_apolon = apolons_list;
	while (nullptr != current_apolon) {
		print_current_apolon(current_apolon);
		current_apolon = current_apolon->_next;
	}
	std::cout << std::endl;
}

void print_apolons_from_cycle(std::shared_ptr<Apolon> &apolons_list, int cycle) {
	std::shared_ptr<Apolon> current_apolon;
	current_apolon = apolons_list;
	while (nullptr != current_apolon) {
		if (current_apolon->cycle_number == cycle) {
			print_current_apolon(current_apolon);
		}
		current_apolon = current_apolon->_next;
	}
	std::cout << std::endl;
}

std::shared_ptr<Apolon> find_apolon(std::shared_ptr<Apolon> &apolons_list,
	const char* first_name,
	const char* last_name) {
	std::shared_ptr<Apolon> current_apolon;
	current_apolon = apolons_list;
	while (nullptr != current_apolon) {
		if (current_apolon->first_name == first_name &&
			current_apolon->last_name == last_name) {
			/*the apolon found*/
			break;
		}
		current_apolon = current_apolon->_next;
	}
	return current_apolon;
}

std::shared_ptr<Apolon> remove_apolon(std::shared_ptr<Apolon> &apolons_list,
										std::string first_name,
										std::string last_name) {
	std::shared_ptr<Apolon> current_apolon;
	current_apolon = apolons_list;
	if (apolons_list->first_name == first_name &&
		apolons_list->last_name == last_name) {
		/*remove first apolon*/
		current_apolon.reset();
		return apolons_list->_next;
	}
	while (nullptr != current_apolon->_next) {
		/*remove apolon from the middle or end of the list*/
		if (current_apolon->_next->first_name == first_name &&
			current_apolon->_next->last_name == last_name)
		{
			std::shared_ptr<Apolon> apolon_to_remove = current_apolon->_next;
			current_apolon->_next = apolon_to_remove->_next;
			apolon_to_remove.reset();
			break;
		}
		current_apolon = current_apolon->_next;
	}
	return apolons_list;
}

void remove_all_apolons_from_list(std::shared_ptr<Apolon> &apolons_list) {
	std::shared_ptr<Apolon> current_apolon;

	while (nullptr != apolons_list) {
		current_apolon = apolons_list;
		apolons_list = apolons_list->_next;
		current_apolon.reset();
	}
}