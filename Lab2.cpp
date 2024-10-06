//Arda Barak 
//300129340
//Lab 2 


#include <iostream>
#include <vector>
#include <string>
#include <iomanip>


//Exercise 1
class Student {
private:
    int idNo;
    std::string name;
public:
    //Cons the IDs and names
    Student(int studentId, std::string stName) : idNo(studentId), name(stName) {}
    //Printing student details
    void printIDandName() const {
        std::cout << "ID  :     " << idNo << "\nName:     " << name << std::endl;}
};
void createAndPrintOut() {
    std::vector<Student> studs; //Students vector
    //Adding students
    studs.push_back(Student(123, "Jane Doe"));
    studs.push_back(Student(234, "Jack Buck"));
    studs.push_back(Student(345, "Ronnie Coleman"));
    studs.push_back(Student(456, "Sebastian Bach"));
    for (const auto& student : studs) {//Printing each student's details
        student.printIDandName();
    }
}



//Exercise 2
class DiaryEntry {
private:
    int id;
    std::string* content;  // Dynamically allocated memory for the entry content
public:
    // Constructor
    DiaryEntry(int entryId, const std::string& entryContent) {
        id = entryId;
        content = new std::string(entryContent);  // Allocate memory for content
    }
    ~DiaryEntry() {    //Destructing to free some memory
        delete content;}
    int getId() const {//return entryID
        return id;}
    //Print the entry details
    void printEntry() const {
        std::cout << "ID:       " << id << ", Content:      " << *content << std::endl;
    }
};
void addEntry(std::vector<DiaryEntry*>& diary, int id, const std::string& content) {    //Adding an entry to the diary
    DiaryEntry* newEntries = new DiaryEntry(id, content);  // Dynamically allocate memory for the new entry
    diary.push_back(newEntries);
}
void deleteEntryById(std::vector<DiaryEntry*>& diary, int id) { //Deleting entries by ID
    for (auto it = diary.begin(); it != diary.end(); ++it) {
        if ((*it)->getId() == id) {
            delete *it;
            diary.erase(it);
            std::cout << "Entry ID:     " << id << " deleted." << std::endl;
            return;
        }
    }
    std::cout << "Entry ID:    " << id << " not found." << std::endl;
}
void showEntries(const std::vector<DiaryEntry*>& diary) {//Print all entries
    for (const auto& entry : diary) {
        entry->printEntry();
    }
}
void cleanUpDiary(std::vector<DiaryEntry*>& diary) {//Opening memory when the diary is no longer needed
    for (auto entry : diary) {
        delete entry;  // Free memory for each entry
    }
    diary.clear();  // Clear the vector
}


//Exercise 3
class Animal {//Animal class
private:
    std::string name;
    std::string type;
public:
    Animal(const std::string& animalName, const std::string& animalType)  //Constructor name and type
        : name(animalName), type(animalType) {}

    std::string getAnimalName() const {//return name of the animal
        return name;}

    void printNameType() const {//print animal name and type
        std::cout << "Name:   " << name << ", Type:   " << type << std::endl;
    }
};
class AnimalShelter {//AnimalShelter
private:
    std::vector<Animal*> animals;  //List/Vector of pointers for Animal objects
public:
    ~AnimalShelter() {//Destructing free memory for animals
        for (auto animal : animals) {
            delete animal;  //deletingFree memory
        }
    }
    void addNewAnimal(const std::string& name, const std::string& type) {//Add a new animal
        Animal* newAnimal = new Animal(name, type);
        animals.push_back(newAnimal);  //Adding animal to the list
    }
    void removeAnimalByName(const std::string& name) {//Removing an animal by name
        for (auto it = animals.begin(); it != animals.end(); ++it) {
            if ((*it)->getAnimalName() == name) {
                delete *it;
                animals.erase(it);  //Removing its pointer from the vectorlist
                std::cout << "Animal named:    '" << name << "' is gone" << std::endl;
                return;}
        }
        std::cout << "Animal named:     '" << name << "' isn't here" << std::endl;
    }
    void displayAnimals() const {//Display animals in shelter list
        if (animals.empty()) {
            std::cout << "No animals in the shelter" << std::endl;
            return;
        }
        std::cout << "Animals in shelter:   " << std::endl;
        for (const auto& animal : animals) {
            animal->printNameType();  // Print details of each animal
        }
    }
};


//Exercise 4
int minCandies(const std::vector<int>& ratings) {//Calc minimum candies needed
    int n = ratings.size();
    if (n == 0) return 0;
    std::vector<int> candies(n, 1);//Creating a candies array for each kid
    for (int i = 1; i < n; ++i) {//checking
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }
    for (int i = n - 2; i >= 0; --i) {//checking
        if (ratings[i] > ratings[i + 1]) {
            candies[i] = std::max(candies[i], candies[i + 1] + 1);
        }
    }
    int totalCandies = 0;//Calc total number candies needed
    for (int i = 0; i < n; ++i) {
        totalCandies += candies[i];
    }
    return totalCandies;
}


//Exercise 5
class Colour {
public:
    // Nested structure to represent RGB values
    struct RGB {
        int red, green, blue;
        // int green;
        // int blue;
    };
    // Type alias for easy reference to the RGB structure
    using ColourValue = RGB;
private:
    ColourValue colour;  // Holds the RGB values of the colour
public:
    Colour(int r, int g, int b) : colour{r, g, b} {} //init RGB vals
    static Colour blend(const Colour& colour1, const Colour& colour2) {//Blend two colours by averaging RGBs
        int blendedRed = (colour1.colour.red + colour2.colour.red) / 2;
        int blendedGreen = (colour1.colour.green + colour2.colour.green) / 2;
        int blendedBlue = (colour1.colour.blue + colour2.colour.blue) / 2;
        return Colour(blendedRed, blendedGreen, blendedBlue);
    }
    void display() const {//Display the RGB vals
        std::cout << "RGB:  Red=" << colour.red << ", Green=" << colour.green << ", Blue=" << colour.blue << "\n" << std::endl;}
};


int main() {
    //exercise 1
    createAndPrintOut(); 

    std::cout << "\n \n";
    //Exercise 2
    std::vector<DiaryEntry*> diary;  // Vector of pointers to diary entries
    // Add some entries to the diary
    addEntry(diary, 1, "Snowed and cold ");
    addEntry(diary, 2, "Coded some C++  ");
    addEntry(diary, 3, "Cooked some food");

    std::cout << "\nAll diary entries:      " << std::endl;
    showEntries(diary);  // Print all entries
    deleteEntryById(diary, 2);
    std::cout << "\nDiary entries after deleting:       " << std::endl;
    showEntries(diary);  // Print remaining entries
    cleanUpDiary(diary);

    std::cout << "\n \n";
    //Exercise 3
    AnimalShelter shelter;
    //Adding animals to shelter;
    shelter.addNewAnimal("Tom", "Cat");
    shelter.addNewAnimal("Jerry", "Mouse");
    shelter.addNewAnimal("Ciko", "Budgie");
    std::cout << "Initial list of animals:" << std::endl;
    shelter.displayAnimals();
    shelter.removeAnimalByName("Jerry");//Remove Jerry by name
    std::cout << "List of animals after removal:" << std::endl;//animals after removal
    shelter.displayAnimals();


    std::cout << "\n \n";
    //Exercise 4
    std::vector<int> ratings1 = {1, 0, 2};
    std::vector<int> ratings2 = {1, 2, 3};
    //Calculate minimum candies
    std::cout << "Minimum candies needed:      " << minCandies(ratings1) << std::endl;
    std::cout << "Minimum candies needed:      " << minCandies(ratings2) << std::endl;

    std::cout << "\n \n";
    //Exercise 5
    //Testing with two colours
    Colour colour1(150, 0, 0);
    Colour colour2(0, 0, 150);
    std::cout << "First colour:     ";
    colour1.display();
    std::cout << "Second colour:    ";
    colour2.display();
    Colour blendedColour = Colour::blend(colour1, colour2);
    std::cout << "Blend of Colour:    ";
    blendedColour.display();

    
    return 0;
}
