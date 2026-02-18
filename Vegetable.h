// Description: Describes the child class Vegetable - Parent is AgItem

#ifndef VEGETABLE_H
#define VEGETABLE_H
#include "AgItem.h"

// Constants
const string Veg_Size[] {"Seedling", "Medium", "Fully Mature"}; //Names of the sizes
const int MAX_VEG_SIZE = 2; //1 = seedling 2 = medium 3 = fully mature

class Vegetable: public AgItem {
public:
  // Name: Vegetable (Default constructor)
  // Desc: Creates a vegetable with size 0
  // Pre-conditions:  Uses AgItem default constructor
  // Post-conditions: A vegetable is created.
  Vegetable();

  // Name: Harvest
  // Desc: If the vegetable is harvestable (fully mature), increases food by size
  // Pre-conditions:  IsHarvestable and passed money and food (to update)
  // Post-conditions: Increases food by vegetable size (if harvested)
  virtual void Harvest(int &money, int &food);

  // Name: Tick
  // Desc: A season passes in the vegetable's life if they are fully mature, IsHarvestable flipped. Food not used for vegetable (only used by Animal)
  // Pre-conditions:  If the size is less than the maximum vegetable size, increases size
  // Post-conditions: Vegetable either grows or becomes harvestable
  // Assume that a vegetable is always fed.
  virtual void Tick(int &food);

  // Name: GetType
  // Desc: Returns the name of the subtype (Vegetable)
  // Pre-conditions:  None
  // Post-conditions: Returns string name of the subtype (Vegetable)
  virtual string GetType();

  // Name: overloaded operator<<
  // Desc: Allows Vegetable objects to be outputted
  // Pre-conditions:  None
  // Post-conditions: Returns output stream with this format
  //                 Vegetable | Not Harvestable | Seedling
  virtual ostream& operator<<(ostream&);

};

#endif

