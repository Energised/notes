/*
 * AnimalsList.cpp
 * @author Dan Woolsey
 *
 * Examples of arrays of derived types using Animal classes
 */

// to compile:
// g++ Animal.cpp DomesticatedAnimal.cpp Dog.cpp Cat.cpp Crow.cpp Husky.cpp StBernard.cpp AnimalsList.cpp -o AnimalsList

#include <iostream>
using namespace std;

#include "Animal.h"
#include "DomesticatedAnimal.h"
#include "Dog.h"
#include "Cat.h"
#include "Crow.h"
#include "Husky.h"
#include "StBernard.h"

int main(int argc, char *argv[])
{
    std::cout << "Allocation Phase" << std::endl << std::endl;

    // make an array of pointers to individual animals
    const int num_animals = 5;
    Animal **animals = new Animal*[num_animals];

    animals[0] = new Crow("Kevin");
    animals[1] = new Cat("Garfield");
    animals[2] = new Dog("Odie");
    animals[3] = new Husky("Bolt");
    animals[4] = new StBernard("Sumo");

    std::cout << "Testing Phase" << std::endl << std::endl;

    for(int i=0; i<num_animals; i++)
    {
        std::cout << std::endl << "animal[" << i << "] ..." << std::endl << std::endl;
        // all animals can speak()
        animals[i]->speak();

        // attempt to promote Animal pointer to DomesticatedAnimal pointer
        // must use dynamic_cast to skip properly if cast fails
        if(DomesticatedAnimal *y = dynamic_cast<DomesticatedAnimal*>(animals[i]))
        {
            std::cout << "<< Type promoted from Animal to DomesticatedAnimal >>" << std::endl;
            // all domesticated animals can be petted
            y->pet();

            // attempt to promote DomesticatedAnimal pointer to StBernard pointer
            if(StBernard *z = dynamic_cast<StBernard*>(y))
            {
                std::cout << "<< Type promoted from DomesticatedAnimal to StBernard >>" << std::endl;
                // all st bernards can slobber
                z->slobber();
            }
        }

    }

    std::cout << "Deallocation Phase" << std::endl << std::endl;

    for(int i=0; i<num_animals; i++)
    {
        // individual allocation requires individual deallocation
        delete animals[i];
    }

    delete [] animals;

    return 0;
}
