#include <iostream>
#include <vector>
#include <string>


void printmenu(){
    while (true){
        std::cout << "1-Sell İtem" << std::endl;
        std::cout << "2-Shop" << std::endl;
        std::cout << "3-Balance" << std::endl;
        std::cout << "4-Inventory" << std::endl;
        std::cout << "5-Win/Lose rates" << std::endl;
    }
}

class player{
    protected:
    int balance=50;

    int win_num;
    int lose_rate;
    int wr;
    std::vector<std::string> common_items;
    std::vector<std::string> rare_items;
    std::vector<std::string> epic_items;


    public:
    friend void create_player(std::string& playername){
    }
        
};





void create_player(std::string& playername){
    std::cout<<"Enter a name";
    std::cin>>playername;
    class playername:public player {
        public:
        int shop(int choice){
            std::cout<<"Choose item to buy"<<std::endl; 
            std::cout<<"1-common item---10 balance"<<std::endl;
            std::cout<<"2-rare item ---30 balance"<<std::endl;
            std::cout<<"3-epic_items ---50"<<std::endl;
            std::cin>>choice;
            if (choice==1 && balance>10){
               std::string citemname;
               std::cout<<"Give your item a name"<<std::endl;
               std::cout<<"WARNING:You cant use space if your item name include more than one word use _ instead of space";
               std::getline(std::cin,citemname);
               common_items.push_back(citemname);
               balance=balance-10;
               std::cout << "Press enter to return main menu" << std::endl;
               std::cin.ignore();
               std::cin.get();
               return 1;
             


            }

            if (choice==2 && balance>30){
               std::string ritemname;
               std::cout<<"Give your item a name"<<std::endl;
               std::cout<<"WARNING:You cant use space if your item name include more than one word use _ instead of space";
               std::getline(std::cin,ritemname);
               rare_items.push_back(ritemname);
               balance=balance-10;
               std::cout << "Press enter to return main menu" << std::endl;
               std::cin.ignore();
               std::cin.get();
               return 1;
                
            }

            if (choice==3 && balance>50){
               std::string eitemname;
               std::cout<<"Give your item a name"<<std::endl;
               std::cout<<"WARNING:You cant use space if your item name include more than one word use _ instead of space";
               std::getline(std::cin,eitemname);
               epic_items.push_back(eitemname);
               balance=balance-10;
               std::cout << "Press enter to return main menu" << std::endl;
               std::cin.ignore();
               std::cin.get();
               return 1;
                
            }

            else{
                std::cout<<"Invalid Input or insufficient balance";
                return 0;
            }
            
        }
       
    };
    
    }

