#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>

template<typename T>
class ObjectManager{


public:
    std::vector<T*> Objects;


    ObjectManager(){
        Objects.clear();
    }


    void addObject(T* obj){
        Objects.push_back(obj);
    }


    T* getObjects(){ return *Objects;}


    T* getObjectById(int i){ return Objects[i];}


    T* getObjectByName(std::string name){

        const char * c = name.c_str();

        for(int i=0;Objects.size();i++){

            if(strcmp(c, Objects[i]->getName()) == 0){
                return Objects[i];
            }
        }
        return NULL;
    }


    int getObjCount(){
        return (int)Objects.size();
    }



};

#endif
