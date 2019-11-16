//#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Sorted_List.h"

TEST_CASE("Sum of ints") {


    Sorted_List empty_list{};
    Sorted_List lst1{5,3,7,2};
    Sorted_List lst2{99999};



/*
    //Skriver ut klockslaget t
    std::cout << t;

    //Be användaren mata in ett klockslag och lagra i t
    std::cin >> t;
    std::cout << t;
*/

 // empty
   CHECK(empty_list.empty() == true);
   CHECK(lst1.empty() == false);



// size
   CHECK(empty_list.size() == 0);
   CHECK(lst1.size() == 4);
   CHECK(lst2.size() == 1);



// at
   CHECK(lst1.at(0) == 2);
   CHECK(lst1.at(1) == 3);
   CHECK(lst1.at(2) == 5);
   CHECK(lst2.at(0) == 99999);


 //clear

   empty_list.clear();
   lst1.clear();
   lst2.clear();
   CHECK(lst1.empty() == true);
   CHECK(lst2.empty() == true);
   CHECK(empty_list.empty() == true);
   CHECK(lst1.size() == 0);
   CHECK(lst2.size() == 0);
   CHECK(empty_list.size() == 0);


  // insert










}
