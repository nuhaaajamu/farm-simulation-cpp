// Description: Farm class that manages the simulation

#ifndef FARM_H
#define FARM_H
#include "AgItem.h" // Parent class of Vegetable, Tree, and Animal
#include "Vegetable.h" // Child class of AgItem
#include "Tree.h" // Child class of AgItem
#include "Animal.h" // Child class of AgItem
#include <iostream>
#include <string>
using namespace std;

class Farm {
public:
  // Name: Farm (Default constructor)
  // Desc: Creates a Farm (with 6 food, 0 money, season = 1)
  // Pre-conditions:  None
  // Post-conditions: A farm is created
  Farm();

  // Name: Farm (Destructor)
  // Desc: Deallocates everything in the farm
  // Pre-conditions:  None
  // Post-conditions: The farm is cleared out
  ~Farm();

  // Name: ChooseItem
  // Desc: Allows the user to choose either an animal, vegetable, or tree
  // Pre-conditions:  None
  // Post-conditions: returns 1 (animal), 2 (vegetable), or 3 (tree) (re-prompts for anything else)
  int ChooseItem();

  // Name: AddItem (int type, int quantity)
  // Desc: Dynamically allocates new animals, vegetables, or trees and adds to m_farm
  // Pre-conditions:  None
  // Post-conditions: Adds 1 (animal), 2 (vegetable), or 3 (tree) to m_farm
  void AddItem(int type, int quantity);

  // Name: Tick (int season)
  // Desc: Simulates a specific number of seasons
  // For each season:
  //   1. Calls Tick for each item in m_farm
  //   2. Tries to harvest mature items
  //   3. Removes anything harvested from m_farm
  //   4. Displays the status automatically
  // Pre-conditions:  None
  // Post-conditions: Changes season
  void Tick(int);

  // Name: Menu
  // Desc: Displays a menu with the following:
  //     1. Add Item to Farm (adds a single item to m_farm)
  //     2. Add Two of Each Item to Farm (Adds two of each item to m_farm)
  //     3. Simulate Time (Asks the user how many seasons to simulate)
  //     4. Farm Status (Displays the status of the farm)
  //     5. Quit (Quits the simulation)
  // Pre-conditions:  None
  // Post-conditions:  If returns 5, quits
  int Menu();

  // Name: StartSimulation
  // Desc: Manages the introduction, menu, and quitting
  // Pre-conditions:  Displays welcome message
  // Post-conditions: As long as menu doesn't return 5, keeps running
  void StartSimulation();

  // Name: Status
  // Desc: Displays farm food, money, season, and each agricultural item
  // Pre-conditions:  None
  // Post-conditions: Displays farm data
  void Status();

private:
  vector <AgItem*> m_farm; // Container for all AgItems (vegetables, trees, or animals)
  int m_food; // Food for the animals (from fruit and vegetables) - start with 6
  int m_money; // Money from selling animals
  int m_season; // Number of seasons elapsed (starts at 1)
};

#endif
