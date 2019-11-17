//#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Sorted_List.h"
#include <utility>

TEST_CASE("Sum of ints") {


    Sorted_List empty_list{};
    Sorted_List empty_list2;
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
   CHECK(empty_list2.empty() == true);
   CHECK(lst1.empty() == false);



// size
   CHECK(empty_list.size() == 0);
   CHECK(lst1.size() == 4);
   CHECK(lst2.size() == 1);



// at (testa även kast av undantag då angivet index inte finns i listan)
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


   // insert godtyckligt antal argument
   Sorted_List lst333{-10,-7,-5,-3};
   lst333.insert({3,5,7,10,15});
   CHECK(lst333.at(0) == -10);
   CHECK(lst333.at(1) == -7);
   CHECK(lst333.at(2) == -5);
   CHECK(lst333.at(3) == -3);
   CHECK(lst333.at(4) == 3);
   CHECK(lst333.at(5) == 5);
   CHECK(lst333.at(6) == 7);
   CHECK(lst333.at(7) == 10);
   CHECK(lst333.at(8) == 15);
   CHECK(lst333.empty() == false);
   CHECK(lst333.size() == 9);


   // insert fyra olika fall (dubletter testas längre ned)
          // FALL 1: insättning i tom lista
   Sorted_List lst3{};
   lst3.insert({7});
   CHECK(lst3.at(0) == 7);
   CHECK(lst3.empty() == false);
   CHECK(lst3.size() == 1);

          // FALL 2: insatt element minst
   Sorted_List lst4{2,3,5,7,9};
   lst4.insert({1});
   CHECK(lst4.at(0) == 1);
   CHECK(lst4.at(1) == 2);
   CHECK(lst4.at(2) == 3);
   CHECK(lst4.at(3) == 5);
   CHECK(lst4.at(4) == 7);
   CHECK(lst4.at(5) == 9);
   CHECK(lst4.empty() == false);
   CHECK(lst4.size() == 6);


          // FALL 3: insatt element mellan två element
   Sorted_List lst5{2,3,5,7,9};
   lst5.insert({4});
   CHECK(lst5.at(0) == 2);
   CHECK(lst5.at(1) == 3);
   CHECK(lst5.at(2) == 4);
   CHECK(lst5.at(3) == 5);
   CHECK(lst5.at(4) == 7);
   CHECK(lst5.at(5) == 9);
   CHECK(lst5.empty() == false);
   CHECK(lst5.size() == 6);

          // FALL 4: insatt element störst
   Sorted_List lst6{2,3,5,7,9};
   lst6.insert({14});
   CHECK(lst6.at(0) == 2);
   CHECK(lst6.at(1) == 3);
   CHECK(lst6.at(2) == 5);
   CHECK(lst6.at(3) == 7);
   CHECK(lst6.at(4) == 9);
   CHECK(lst6.at(5) == 14);
   CHECK(lst6.empty() == false);
   CHECK(lst6.size() == 6);


      // insert DUBLETTER fyra olika fall
             // FALL 1: insättning i tom lista
      Sorted_List lst33{};
      lst33.insert({7,3});
      CHECK(lst33.at(0) == 3);
      CHECK(lst33.at(1) == 7);
      CHECK(lst33.empty() == false);
      CHECK(lst33.size() == 2);

             // FALL 2: insatta element minst
      Sorted_List lst44{2,3,5,7,9};
      lst44.insert({-5,1});
      CHECK(lst44.at(0) == -5);
      CHECK(lst44.at(1) == 1);
      CHECK(lst44.at(2) == 2);
      CHECK(lst44.at(3) == 3);
      CHECK(lst44.at(4) == 5);
      CHECK(lst44.at(5) == 7);
      CHECK(lst44.at(6) == 9);
      CHECK(lst44.empty() == false);
      CHECK(lst44.size() == 7);


             // FALL 3: insatta element mellan två element
      Sorted_List lst55{2,3,5,7,9};
      lst55.insert({4,8});
      CHECK(lst55.at(0) == 2);
      CHECK(lst55.at(1) == 3);
      CHECK(lst55.at(2) == 4);
      CHECK(lst55.at(3) == 5);
      CHECK(lst55.at(4) == 7);
      CHECK(lst55.at(5) == 8);
      CHECK(lst55.at(6) == 9);
      CHECK(lst55.empty() == false);
      CHECK(lst55.size() == 7);

             // FALL 4: insatta element störst
      Sorted_List lst66{2,3,5,7,9};
      lst66.insert({14,23});
      CHECK(lst66.at(0) == 2);
      CHECK(lst66.at(1) == 3);
      CHECK(lst66.at(2) == 5);
      CHECK(lst66.at(3) == 7);
      CHECK(lst66.at(4) == 9);
      CHECK(lst66.at(5) == 14);
      CHECK(lst66.at(6) == 23);
      CHECK(lst66.empty() == false);
      CHECK(lst66.size() == 7);






   // erase fyra olika fall (testa även kast av undantag då angivet index inte finns i listan)
          // FALL 1: borttagning i tom lista
          // testa kast av undantag

          // FALL 2: borttaget element minst av alla element i listan
   Sorted_List lst7{2,3,5,7,9};
   lst7.erase(0);
   CHECK(lst7.at(0) == 3);
   CHECK(lst7.at(1) == 5);
   CHECK(lst7.at(2) == 7);
   CHECK(lst7.at(3) == 9);
   CHECK(lst7.empty() == false);
   CHECK(lst7.size() == 4);



          // FALL 3: borttaget element mellan två element
   Sorted_List lst8{2,3,5,7,9};
   lst8.erase(2);
   CHECK(lst8.at(0) == 2);
   CHECK(lst8.at(1) == 3);
   CHECK(lst8.at(2) == 7);
   CHECK(lst8.at(3) == 9);
   CHECK(lst8.empty() == false);
   CHECK(lst8.size() == 4);


          // FALL 4: borttaget element störst
   Sorted_List lst9{2,3,5,7,9};
   lst9.erase(4);
   CHECK(lst9.at(0) == 2);
   CHECK(lst9.at(1) == 3);
   CHECK(lst9.at(2) == 5);
   CHECK(lst9.at(3) == 7);
   CHECK(lst9.empty() == false);
   CHECK(lst9.size() == 4);


   // Kopieringskonstruktor
   Sorted_List lst10{2,3};
   Sorted_List lst10_copy{lst10};
   Sorted_List lst100{2,3};
   Sorted_List lst100_copy{lst100};

          // FALL 1: ändring i lst10 ska inte ändra på lst10_copy
   lst10.insert({1});
   CHECK(lst10_copy.size() == 2);
   CHECK(lst10_copy.at(0) == 2);
   CHECK(lst10_copy.at(1) == 3);


          // FALL 2: ändring i lst100_copy ska inte ändra på lst100
    lst100_copy.insert({1});
    CHECK(lst100.size() == 2);
    CHECK(lst100.at(0) == 2);
    CHECK(lst100.at(1) == 3);


    // Kopieringstilldelning
    Sorted_List lst11{2,3};
    Sorted_List lst11_copy = lst11;
    Sorted_List lst111{2,3};
    Sorted_List lst111_copy = lst111;

           // FALL 1: ändring i lst11 ska inte ändra på lst11_copy
    lst11.insert({1});
    CHECK(lst11_copy.size() == 2);
    CHECK(lst11_copy.at(0) == 2);
    CHECK(lst11_copy.at(1) == 3);


           // FALL 2: ändring i lst111_copy ska inte ändra på lst111
     lst111_copy.insert({1});
     CHECK(lst111.size() == 2);
     CHECK(lst111.at(0) == 2);
     CHECK(lst111.at(1) == 3);


     // Flyttkonstruktor
     Sorted_List lst12{-6,-4,3,9};
     Sorted_List lst12_moved{std::move(lst12)};

          // Innehållet i lst12 skall ha flyttats till lst12_moved
      CHECK(lst12_moved.size() == 4);
      CHECK(lst12_moved.at(0) == -6);
      CHECK(lst12_moved.at(1) == -4);
      CHECK(lst12_moved.at(2) == 3);
      CHECK(lst12_moved.at(3) == 9);
      CHECK(lst12.empty() == true);

      // Flyttilldelning
      Sorted_List lst122{-6,-4,3,9};
      Sorted_List lst122_moved = std::move(lst122);

           // Innehållet i lst122 skall ha flyttats till lst122_moved
       CHECK(lst122_moved.size() == 4);
       CHECK(lst122_moved.at(0) == -6);
       CHECK(lst122_moved.at(1) == -4);
       CHECK(lst122_moved.at(2) == 3);
       CHECK(lst122_moved.at(3) == 9);
       CHECK(lst122.empty() == true);




}


TEST_CASE("Operator <<")
{

    // Fallet Icke-tom lista med ett element
    Sorted_List lst1 {5};
    std::ostringstream o_ss1{};
    o_ss1 << lst1;
    std::string string_lst1{o_ss1.str()};
    CHECK(string_lst1 == "{5}");

    // Fallet Icke-tom lista med fler än ett element
    Sorted_List lst {7,-4,9,-6};
    std::ostringstream o_ss{};
    o_ss << lst;
    std::string string_lst{o_ss.str()};
    CHECK(string_lst == "{-6, -4, 7, 9}");

    // Fallet tom lista
    Sorted_List empty_lst;
    std::ostringstream o_ss2{};
    o_ss2 << empty_lst;
    std::string string_lst2{o_ss2.str()};
    CHECK(string_lst2 == "{}");


}
