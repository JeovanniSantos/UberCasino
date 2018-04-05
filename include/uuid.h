#ifndef UUID_H
#define UUID_H

#include <iostream>
#include <string>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

using namespace std;

const char * uuid_generator(void){
    string uuid;
    boost::uuids::random_generator generator;
    boost::uuids::uuid u=generator();
    uuid = boost::uuids::to_string(u).substr(0,16);
    const char * c = uuid.c_str();
    return c;
}
#endif
/*
int main(){

    string uuid;
    uuid = uuid_generator(); //return a string that has length of 16

    cout<<uuid<<endl;
    return 0;
}
*/

