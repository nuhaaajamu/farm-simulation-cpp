#include "Tree.h"

enum treeLife{SEEDLING, SAPLING, POLE, MATURE}; // Defines stages of tree growth.

Tree::Tree() : m_age(0) {}

Tree::~Tree() {
    // De-allocate all the pointers in the array.
    int size = (int) m_fruit.size();
    for (int i = 0; i < size; i++) {
        delete m_fruit[i];
    }

    // Clear the array.
    m_fruit.resize(0);
}

void Tree::Tick(int &food) {
    // Executes if tree has not yet reached maturity.
    if (m_age < SEASONS_TO_FRUIT) {
        m_age += 1;

        // Only increment size if four seasons have passed.
        if (m_age % SEASONS_TO_SIZE == 0) {
            int size = GetSize() + 1;
            SetSize(size);
        }

        return;
    }

    // Executes if tree has reached maturity but is not yet harvestable.
    if (m_age >= SEASONS_TO_FRUIT && m_age < SEASONS_TO_HARVEST) {
        m_age += 1;

        // Add a new fruit to the tree.
        Fruit* addFruit = new Fruit;
        m_fruit.push_back(addFruit);

        return;
    }

    // Executes when tree has approached the end of its life.
    if (m_age >= SEASONS_TO_HARVEST) {
        SetIsHarvestable(true);
    }
}

void Tree::Harvest(int &money, int &food) {
    int fruitCount = (int) m_fruit.size(); // Evaluate the number of fruit we have.

    // Executes when a tree has produced fruit.
    if (fruitCount > 0) {
        delete m_fruit[fruitCount - 1]; // De-allocate the last pointer in the array.
        m_fruit.resize(fruitCount - 1); // Remove the fruit from the array.
        food += 1;
    }
}

string Tree::GetType() {return "Tree";}

ostream& Tree::operator<<(ostream& cout) {
    cout << GetType() << " " << CONCAT;

    // Determine life stage of the tree.
    switch (GetSize()) {
        case SEEDLING:
            cout << " Seedling " << CONCAT;
            break;
        case SAPLING:
            cout << " Sapling " << CONCAT;
            break;
        case POLE:
            cout << " Pole " << CONCAT;
            break;
        case MATURE:
            cout << " Mature " << CONCAT;
            break;
        default:
            cout << " Unknown Size " << CONCAT;
            break;
    }

    // Determine harvest status.
    if (GetIsHarvestable() == true) {
        cout << " Harvestable " << CONCAT;
    }else {
        cout << " Not Harvestable " << CONCAT;
    }

    // Determine fruiting status.
    int fruitCount = (int) m_fruit.size();
    if (fruitCount > 0) {
        cout << " Fruiting " << CONCAT;
    }else {
        cout << " Not Fruiting " << CONCAT;
    }

    // Determine fruit count.
    cout << " Fruit Count: " << fruitCount << endl;

    return cout;
}

