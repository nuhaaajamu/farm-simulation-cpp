# Farm Simulation System (C++)

## Overview
Object-oriented farm simulation that models animals, vegetables, and trees using inheritance and polymorphism. The system simulates seasonal progression, harvest cycles, and resource management (food and money) through dynamic object interactions.

## Key Concepts Demonstrated
- Inheritance hierarchy (`AgItem` base class with derived `Animal`, `Vegetable`, and `Tree`)
- Virtual functions and dynamic dispatch (`tick()` and `harvest()` overrides)
- Polymorphism via base-class pointers (`vector<AgItem*>`)
- Dynamic memory management and destructor implementation
- State simulation across multiple seasons
- Menu-driven user interface with input validation

## System Design
- `AgItem` – Base class defining shared attributes (size, worth, harvestable state)
- `Animal`, `Vegetable`, `Tree` – Derived classes overriding seasonal behavior
- `Fruit` – Supporting class used by `Tree`
- `Farm` – Manages simulation state, resources, and time progression

## Features
- Add agricultural items to the farm
- Simulate seasonal time progression
- Automatic harvesting of mature items
- Track food supply, money, and farm status
- Display detailed farm state per season

## How to Compile
Compile all source files in the project directory:

g++ *.cpp -o farm_sim

Run:

./farm_sim

*(Compilation command may vary depending on system configuration.)*

