#include "Farm.h"

enum AgItems{ANIMAL_ITEM=1, VEGETABLE_ITEM, TREE_ITEM};  // Defines menu choice options for agricultural items.
enum Menu{ADD_ITEM=1, ADD_TWO_ITEMS, SIMULATE_TIME, DISPLAY_STATUS, QUIT}; // Defines menu choices for user actions.

Farm::Farm(): m_food(6), m_money(0), m_season(1) {}

Farm::~Farm() {
    // De-allocate all the pointers in the array.
    int size = (int) m_farm.size();
    for (int i = 0; i < size; i++) {
        delete m_farm[i];
    }

    // Clear the array.
    m_farm.resize(0);
}

int Farm::ChooseItem() {
    // User is re-prompted until they pick an invalid menu choice.
    int item = 0;
    do {
        cout << "Which agricultural item are you interested in?"
         << endl << "1. Animal"
         << endl << "2. Vegetable"
         << endl << "3. Tree"
         << endl;

        cin >> item;
    }while (item < ANIMAL_ITEM || item > TREE_ITEM); // Ensure item chosen is within bounds.

    // Determines value to record based on validated user input.
    switch (item) {
        case ANIMAL_ITEM:
            return ANIMAL_ITEM;
        case VEGETABLE_ITEM:
            return VEGETABLE_ITEM;
        case TREE_ITEM:
            return TREE_ITEM;
        default:
            return 1;
    }
}

void Farm::AddItem(int type, int quantity) {
    // Add animals to the farm.
    if (type == ANIMAL_ITEM) {

        for (int i = 0; i < quantity; i++) {
            Animal* addAnimal = new Animal;
            m_farm.push_back(addAnimal);
            cout << "New Animal added to the farm." << endl;
        }

    // Add vegetables to the farm.
    }else if (type == VEGETABLE_ITEM) {

        for (int i = 0; i < quantity; i++) {
            Vegetable* addVegetable = new Vegetable;
            m_farm.push_back(addVegetable);
            cout << "New Vegetable added to the farm." << endl;
        }

    // Add trees to the farm.
    }else if (type == TREE_ITEM) {

        for (int i = 0; i < quantity; i++) {
            Tree* addTree = new Tree;
            m_farm.push_back(addTree);
            cout << "New Tree added to the farm." << endl;
        }
    }
}

void Farm::Tick(int seasons) {
    for (int s = 0; s < seasons; s++) {

        // Initiate a season for each agricultural item in the farm.
        int size = (int) m_farm.size();
        for (int i = 0; i < size; i++ ) {
            m_farm[i]->Tick(m_food);
        }

        // Harvest any agricultural items that are mature.
        for (vector<AgItem*>::iterator it = m_farm.begin(); it != m_farm.end();) {

            if ((*it)->GetIsHarvestable() == true) {
                (*it)->Harvest(m_money, m_food); // Harvest the items.
                cout << (*it)->GetType() << " was harvested!" << endl; // Communicate this to user.

                delete *it;  // Ensure that harvested items are removed from farm.
                it = m_farm.erase(it);
            }

            // Move on to next item in farm if not ready for harvest.
            else {
                ++it;
            }
        }

        // Display farm status.
        Status();

        // Season changes.
        m_season++;
    }
}

int Farm::Menu() {

    int menuChoice;
    do {
        cout << "1. Add Item to Farm" << endl
             << "2. Add Two of Each Item to Farm" << endl
             << "3. Simulate Time" << endl
             << "4. Farm Status" << endl
             << "5. Quit" << endl;

        cin >> menuChoice;

    } while (menuChoice < ADD_ITEM || menuChoice > QUIT); // Validate user input.

    return menuChoice;
}

void Farm::StartSimulation() {
    cout << "Welcome to Farm Together Simulator" << endl;
    int menuChoice = 0; // Initialize condition.

    while (menuChoice != QUIT) {
        menuChoice = Menu();

        // One specific agricultural item is added to the farm.
        if (menuChoice == ADD_ITEM) {
            int itemType = ChooseItem();
            AddItem(itemType, 1);
        }

        // Two specific agricultural items are added to the farm.
        else if (menuChoice == ADD_TWO_ITEMS){
            int itemType = ChooseItem();
            AddItem(itemType, 2);
        }

        // Some number of seasons pass based on the user input.
        else if (menuChoice == SIMULATE_TIME) {
            int time;
            cout << "How many seasons to simulate?" << endl;
            cin >> time;

            if (time >= 1) {  // Validate user input.
                Tick(time);
            }

        }

        // Show updated farm data.
        else if (menuChoice == DISPLAY_STATUS) {
            Status();
        }

        // Exit the game.
        else if (menuChoice == QUIT) {
            return;
        }
    }
}

void Farm::Status() {
    cout << "SEASON: " << m_season << endl;
    cout << "**** Farm Status ****" << endl;

    cout << "Food: " << m_food << endl;
    cout << "Money: " << m_money << endl;
    cout << "Season: " << m_season << endl;

    // Display status for each farm item.
    cout << "Agricultural Items:" << endl;
    int size = (int) m_farm.size();
    for (int i = 0; i < size; i++) {
        *m_farm[i] << cout;
    }
}