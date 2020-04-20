/********************************************************\
File Name: main.cpp
Author: Liri (20/4/2020)
Purpose: This file contain functions that initiate apolons list and
		 test the functions of apolons list
\********************************************************/

#include "apolons_list.h"

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
	std::cout << "Length apolons list " << std::endl;
	std::cout << length_of_list(apolon_list) << std::endl << std::endl;

	/*print apolons from the requested cycle*/
	std::cout << "Apolons from cycle " << requested_cycle << ": " << std::endl;
	print_apolons_from_cycle(apolon_list, requested_cycle);

	/*print the requested apolon*/
	requested_apolon = find_apolon(apolon_list, "Liri", "Ofek");
	std::cout << "The apolon we searched: " << std::endl;
	print_current_apolon(requested_apolon);
	std::cout << std::endl;

	/*remove apolon and print list after the remove*/
	apolon_list = remove_apolon(apolon_list, "Yaniv", "Mandel");
	std::cout << "The apolons after remove Yaniv Mandel: " << std::endl;
	print_apolons(apolon_list);

	/*print number of apolons */
	std::cout << "number of apolons after remove Yaniv Mandel: " << std::endl;
	std::cout << length_of_list(apolon_list) << std::endl;

	/*remove all apolons from list*/
	remove_all_apolons_from_list(apolon_list);

}