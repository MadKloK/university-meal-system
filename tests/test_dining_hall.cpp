#include "../src/dining_hall.cpp"

int main()
{
    std::string name1, name2, address1, address2;
    
    name1 = "aboozar";
    name2 = "tohid";
    address1 = "modares";
    address2 = "tohid";
    
    //testing constractor and print
    DiningHall d1(name1, address1,1);
    d1.print();

    //testing setters
    d1.set_name(name2);
    d1.set_address(address2);
    d1.set_capacity(50);
    d1.print();

    //testing getters
    if(d1.get_name() == "tohid")
        std::cout << "getname method works!\n";
    else
        std::cout << "getname method is fucked!\n";
    
    if(d1.get_address() == "tohid")
        std::cout << "getaddress method works!\n";
    else
        std::cout << "getaddress method is fucked!\n";
    
    if(d1.get_capacity() == 50)
        std::cout << "getcapacity method works!\n";
    else
        std::cout << "getcapacity method is fucked!\n";    
}
