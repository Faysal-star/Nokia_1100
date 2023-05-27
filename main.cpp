/**
 * @author Md. Faysal Mahmud (2007068)
 * @date 27-05-2023
 * @brief This is the main file of this project . Run This .
**/

#include "everything.hpp"

int main(){
    int choice;
    do{
        system("cls") ;
        menu() ;
        cin >> choice ;
        
        if(choice == 1) contacts_operation() ;
        
        else if(choice == 2) toDoOperation() ;
        
        else if(choice == 3) gameOperation() ;
        
        else if(choice == 4) conversion() ;
        
        else if(choice == 5) break ;
        
        else cout << "Invalid choice\n" ;

    }while(choice != 5) ;
    
    return 0 ;
}