/********************************************************\
File Name: apolons_list.h
Author: Liri (20/4/2020)
Purpose: This header file contain the declaration of the functions of
		 apolons list, and defines of constants
\********************************************************/

#pragma once

#include "apolon.h"

std::shared_ptr<Apolon> add_apolon_to_middle_or_end_of_list(std::shared_ptr<Apolon> &apolons_list,
	std::shared_ptr<Apolon> &new_apolon);

std::shared_ptr<Apolon> add_apolon_to_sort_list(std::shared_ptr<Apolon> &apolons_list,
	std::shared_ptr<Apolon> &new_apolon);

int length_of_list(std::shared_ptr<Apolon> apolons_list);