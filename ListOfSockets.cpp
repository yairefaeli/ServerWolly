//
// Created by or on 17/01/18.
//



#include "ListOfSockets.h"
#include <iostream>

ListOfSockets* ListOfSockets::instance=0;
ListOfSockets* ListOfSockets::getInstance() {
    if(!instance){
        instance=new ListOfSockets();
        cout<< "getInstance():First instance\n";
        return instance;
    }
    else{

        cout<<"getInstance(): prevoius instance\n";
        return instance;
    }
}
