#include "Animal.h"

enum animalLife{BORN, INFANT, JUVENILE, ADULT}; // Defines stages of animal growth.

Animal::Animal() : m_name("Chicken"), m_IsHungry(true) {}

void Animal::Tick(int &food) {
    // If animal is at maximum size, it is harvestable.
    if (GetSize() == ANIMAL_MAX_SIZE) {
        SetIsHarvestable(true);
        return;
    }

    // Executes when food exists and animal is not yet harvestable.
    if (food > 0) {
        m_IsHungry = false;
        int size = GetSize() + 1; // Increment size and pass through to set.
        SetSize(size);
        food -= 1;

        // Check to see if it is harvestable.
        if (GetSize() == ANIMAL_MAX_SIZE) {
            SetIsHarvestable(true);
        }else {
            SetIsHarvestable(false);
        }
        return;
    }

    if (food == 0) {
        // Executes if the animal was not fed in the previous season. If so, becomes "harvested small."
        if (m_IsHungry == true) {
            SetIsHarvestable(true);

        // Executes when the animal has been fed the previous season but is unable to be fed in the current season due to lack of food.
        }else {
            m_IsHungry = true;
        }
    }
}

void Animal::Harvest(int &money, int &food) {
    if (GetIsHarvestable() == true) {
        money += GetWorth() * GetSize();
    }
}

string Animal::GetType() {return m_name;}

ostream& Animal::operator<<(ostream& cout) {
    cout << "Animal " << CONCAT << " " << m_name << " " << CONCAT;

    // Determine harvest status.
    if (GetIsHarvestable() == true) {
        cout << " Harvestable " << CONCAT;
    }else {
        cout << " Not Harvestable " << CONCAT;
    }

    // Determine the status of the animal size.
    switch (GetSize()) {
        case BORN:
            cout << " " << ANIMAL_SIZE[0] << " " << CONCAT;
            break;
        case INFANT:
            cout << " " << ANIMAL_SIZE[1] << " " << CONCAT;
            break;
        case JUVENILE:
            cout << " " << ANIMAL_SIZE[2] << " " << CONCAT;
            break;
        case ADULT:
            cout << " " << ANIMAL_SIZE[3] << " " << CONCAT;
            break;
        default:
            cout << " Unknown Size " << CONCAT;
            break;
    }

    // Determine hunger status.
    if (m_IsHungry == true) {
        cout << " Hungry" << endl;
    }else {
        cout << " Fed" << endl;
    }

    return cout;
}