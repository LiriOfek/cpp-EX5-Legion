/********************************************************\
File Name: main.cpp
Author: Liri (20/4/2020)
Purpose: This file contain functions that initiate apolons list and
		 test the functions of apolons list
\********************************************************/

#include "apolons_list.h"

const int NUMBER_OF_APOLONS = 5;
const char* THE_APOLONS = "The Apolons: ";
const char* LENGTH_APOLONS_LIST = "Length apolons list ";
const char* APOLONS_FROM_CYCLE =  "Apolons from cycle ";
const char* COLONS = ": ";
const char* FOUND_APOLON = "The apolon we searched: ";
const char* APOLONS_AFTER_REMOVE_APOLON = "The apolons after remove ";
const char* NUMBER_OF_APOLONS_AFTER_REMOVE_APOLON = "number of apolons after remove ";

void test_apolon_functions(std::shared_ptr<Apolon> &apolon_list) {
	/**
	* @brief  test the apolon functions
	* @param  INOUT std::shared_ptr<Apolon> &apolon_list - the apolons list
	* @return this function has no return value
	* @notes change the list of apolons such that in the end it remove all
	*			the apolons from it
	* @author  Liri
	*/
	int requested_cycle = 1;
	std::shared_ptr<Apolon> requested_apolon(new Apolon());

	/*length of apolons list*/
	std::cout << LENGTH_APOLONS_LIST << std::endl;
	std::cout << length_of_list(apolon_list) << std::endl << std::endl;

	/*print apolons from the requested cycle*/
	std::cout << APOLONS_FROM_CYCLE << requested_cycle << COLONS << std::endl;
	print_apolons_from_cycle(apolon_list, requested_cycle);

	/*print the requested apolon*/
	requested_apolon = find_apolon(apolon_list, "Liri", "Ofek");
	std::cout << FOUND_APOLON << std::endl;
	print_current_apolon(requested_apolon);
	std::cout << std::endl;

	/*remove apolon and print list after the remove*/
	apolon_list = remove_apolon(apolon_list, "Yaniv", "Mandel");
	std::cout << APOLONS_AFTER_REMOVE_APOLON << "Yaniv Mandel" << COLONS << std::endl;
	print_apolons(apolon_list);

	/*print number of apolons */
	std::cout << NUMBER_OF_APOLONS_AFTER_REMOVE_APOLON << "Yaniv Mandel" << COLONS << std::endl;
	std::cout << length_of_list(apolon_list) << std::endl;

	/*remove all apolons from list*/
	remove_all_apolons_from_list(apolon_list);
}

int main() {
	/**
	* @brief  init the list of the apolons and test the apolon functions
	* @param  OUT 0 for SUCCESS
	* @return return 0 for SUCCESS
	* @notes make list of apolons, test apolons functions, and in the end
	*		 call function that reset the pointers in the list
	* @author  Liri
	*/
	std::shared_ptr<Apolon> apolons_list(new Apolon());
	apolons_list = nullptr;

	std::string first_names[NUMBER_OF_APOLONS] = { "Liri", "Yaniv", "Orly", "Neta", "Oree" };

	std::string last_names[NUMBER_OF_APOLONS] = { "Ofek", "Mandel", "Nir", "Gedanski", "Barak" };

	int personal_numbers[NUMBER_OF_APOLONS] = { 1111111, 1111112, 1111110, 1111117, 1111119 };

	int ages[NUMBER_OF_APOLONS] = { 18, 19, 18, 20, 17 };

	const char* genders[NUMBER_OF_APOLONS] = { FEMALE, MALE, FEMALE, FEMALE, MALE };

	const char* are_vegeterians[NUMBER_OF_APOLONS] = { NO, NO, YES, NO, YES };

	int cycle_numbers[NUMBER_OF_APOLONS] = { 1, 1, 8, 11, 1 };

	Address addresses[NUMBER_OF_APOLONS] = { { 19, "Noorit", 611828 },
												{ 3, "Saloniki", 611025 },
												{ 0, "Beit el", 661828 },
												{ 32, "Vardia", 615727 },
												{ 11, "Calanit", 622028 } };

	for (int index = 0; index < NUMBER_OF_APOLONS; ++index) {
		apolons_list = create_and_add_apolon_to_list(apolons_list,
														first_names[index],
														last_names[index],
														personal_numbers[index],
														ages[index],
														genders[index],
														are_vegeterians[index],
														cycle_numbers[index],
														addresses[index]);
	}

	/*print the apolons*/
	std::cout << THE_APOLONS << std::endl;
	print_apolons(apolons_list);

	/*test the apolon functions*/
	test_apolon_functions(apolons_list);

	return 0;
}