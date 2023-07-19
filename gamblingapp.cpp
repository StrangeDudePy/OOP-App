#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>



 std::random_device rd;// ates
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);
    double probability1 = 0.4;//for common items/lose
    double probability2 = 0.6;//for common items/win
    double probabilityrare = 0.7;//for rare items/lose
    double probabilityrare2 = 0.3;//for rare items/win
    double probabilityepic = 0.7;//for epic items/lose
    double probabilityepic2 = 0.3;//for repic items/win

void printmenu(){
    while (true){
        std::cout << "1-Sell İtem" << std::endl;
        std::cout << "2-Shop" << std::endl;
        std::cout << "3-Balance" << std::endl;
        std::cout << "4-Inventory" << std::endl;
        std::cout << "5-Play" << std::endl;
    }
}

class player{
    protected:
    int balance=50;
    std::vector<std::string> common_items;
    std::vector<std::string> rare_items;
    std::vector<std::string> epic_items;


    public:
    friend void create_player(std::string& playername);
    
        
};





void create_player(std::string& playername){
    std::cout<<"Enter a name";
    std::cin>>playername;
    std::string PlayerDerived=playername;
    class PlayerDerived:public player {
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
       

        int checkbalance(){
            std::cout<<"your current balance: "<<balance;
            std::cout << "Press enter to return main menu" << std::endl;
            std::cin.ignore();
            std::cin.get();
            return 1;
       }

    int gamble(){
        std::string itemn;
        int rarity;
        std::cout<<"Choose where rarity of your item";
        std::cout << "1-common items" << std::endl;
        std::cout << "2-rare items" << std::endl;
        std::cout << "3-epic items" << std::endl;
        std::cin>>rarity;
        std::cout<<"Enter the item name you wanna put on bet ";
        std::getline(std::cin,itemn);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if(rarity==1){
            auto it = std::find(common_items.begin(), common_items.end(),itemn);

                if (it != common_items.end()) {
                    std::cout << "Item Found" <<std::endl;
                             
                if (dis(gen) < probability1) {
        common_items.erase(it);
        std::cout<<"You lost your item"<<std::endl;
        std::cout << "Press enter to return main menu" << std::endl;
        std::cin.ignore();
        std::cin.get();
        return 1;
    } 
        else if (dis(gen) < probability1 + probability2) {
        std::cout<<"You won your item rarity upgraded to next rarity"<<std::endl;
        std::cout << "Press enter to return main menu" << std::endl;
        std::cin.ignore();
        std::cin.get();
        return 1;

    } 
                } 
                
                else {
                    std::cout << "Item doesn't exist" << std::endl;
                }
                    
       
        }
         
                    

    if(rarity==2){
            auto itr = std::find(rare_items.begin(), rare_items.end(), itemn);

                if (itr != rare_items.end()) {
                    std::cout << "Item Found" <<std::endl;
                             
                if (dis(gen) < probabilityrare) {
        rare_items.erase(itr);
        std::cout<<"You lost your item"<<std::endl;
        std::cout << "Press enter to return main menu" << std::endl;
        std::cin.ignore();
        std::cin.get();
        return 1;
    } 
        else if (dis(gen) < probabilityrare + probabilityrare2) {
        std::cout<<"You won your item rarity upgraded to next rarity"<<std::endl;
        std::cout << "Press enter to return main menu" << std::endl;
        std::cin.ignore();
        std::cin.get();
        return 1;

    } 
                } 
                
                else {
                    std::cout << "Item doesn't exist" << std::endl;
                }
                    
       
        }


        if(rarity==3){
            auto itp = std::find(rare_items.begin(), rare_items.end(), itemn);

                if (itp != rare_items.end()) {
                    std::cout << "Item Found" <<std::endl;
                             
                if (dis(gen) < probabilityepic) {
        rare_items.erase(itp);
        std::cout<<"You lost your item"<<std::endl;
        std::cout << "Press enter to return main menu" << std::endl;
        std::cin.ignore();
        std::cin.get();
        return 1;
    } 
        else if (dis(gen) < probabilityepic + probabilityepic2) {
        std::cout<<"You won your item rarity upgraded to next rarity"<<std::endl;
        std::cout << "Press enter to return main menu" << std::endl;
        std::cin.ignore();
        std::cin.get();
        return 1;

    } 
                } 
                
                else {
                    std::cout << "Item doesn't exist" << std::endl;
                }
                    
       
        }
   
    }
    int inventory(){
        for(auto it=common_items.begin(); it !=common_items.end();++it){
            if(it==common_items.begin()){
                std::cout<<"Your Common Items are:"<<*it<<" ,";
                }

            else{
                std::cout<<","<<*it;
            }
            
        }
        std::cout<<std::endl;


        for(auto itr_=rare_items.begin(); itr_ !=rare_items.end();++itr_){
            if(itr_==rare_items.begin()){
                std::cout<<"Your Common Items are:"<<*itr_<<" ,";
                }

            else{
                std::cout<<","<<*itr_;
            }
            
        }
        std::cout<<std::endl;

        for(auto itp_=epic_items.begin(); itp_ !=epic_items.end();++itp_){
            if(itp_==epic_items.begin()){
                std::cout<<"Your Common Items are:"<<*itp_<<" ,";
                }

            else{
                std::cout<<","<<*itp_;
            }
          
        }
          std::cout<<std::endl;

        int total_balance=common_items.size()*10+rare_items.size()*30+epic_items.size()*50;
        std::cout<<"Your total inventory value is: "<<total_balance;

    std::cout << "Press enter to return main menu" << std::endl;
    std::cin.ignore();
    std::cin.get();
    return 1;
    
    
    
    }
    int sellitem(){
        std::string solditemname;
        bool found=false;
        std::cout<<"Satmak İstediğiniz İtemin İsmini Giriniz ;";
        std::getline(std::cin,solditemname);

        auto i = std::find(common_items.begin(), common_items.end(),solditemname);

                if (i != common_items.end()) {
                    std::cout << "Item Found" <<std::endl;
                    found=true;

    }

        auto ir = std::find(rare_items.begin(), rare_items.end(),solditemname);

                if (ir != rare_items.end()) {
                    std::cout << "Item Found" <<std::endl;
                    found=true;
     
    }

    
 auto ip = std::find(epic_items.begin(), epic_items.end(),solditemname);

                if (i != epic_items.end()) {
                    std::cout << "Item Sold" <<std::endl;
                    found=true;

        
    std::cout << "Press enter to return main menu" << std::endl;
    std::cin.ignore();
    std::cin.get();
    return 1;


}

    

    }
    };
}