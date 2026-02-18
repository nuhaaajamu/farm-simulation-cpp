#include "Vegetable.h"

enum vegetableLife{SEEDLING, MEDIUM, FULLY_MATURE}; // Defines stages of vegetable growth.

Vegetable::Vegetable(){}

void Vegetable::Harvest(int &money, int &food) {
    if (GetIsHarvestable() == true) {
        food += GetSize();
    }
}

void Vegetable::Tick(int &food) {
    // Ensure that size does not become out of bounds.
    if (GetSize() == MAX_VEG_SIZE) {
        SetIsHarvestable(true);
        return;
    }

    // Executes when vegetable has not reached full maturity yet.
    if (GetSize() < MAX_VEG_SIZE){
        int size = GetSize() + 1;
        SetSize(size);

        // Checks if vegetable is ready for harvest.
        if (GetSize() == MAX_VEG_SIZE) {
            SetIsHarvestable(true);
        }
        else {
            SetIsHarvestable(false);
        }
    }
}

string Vegetable::GetType() {return "Vegetable";}

ostream& Vegetable::operator<<(ostream& cout) {
    cout << GetType() << " " << CONCAT;

    // Determine harvest status.
    if (GetIsHarvestable() == true) {
        cout << " Harvestable " << CONCAT;
    }else {
        cout << " Not Harvestable " << CONCAT;
    }

    // Determine the status of the vegetable size.
    switch (GetSize()) {
        case SEEDLING:
            cout << " " << Veg_Size[0] << endl;
            break;
        case MEDIUM:
            cout << " " << Veg_Size[1] << endl;
            break;
        case FULLY_MATURE:
            cout << " " << Veg_Size[2] << endl;
            break;
        default:
            cout << " Unknown Size " << endl;
    }

    return cout;
}