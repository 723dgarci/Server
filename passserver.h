//
// Created by WorkD on 11/18/2017.
//

#ifndef ASSIGNMENT5_PASSSERVER_H
#define ASSIGNMENT5_PASSSERVER_H

#include "hashtable.h"
#include <iostream>
#include <cstring>
#include <crypt.h>
using namespace cop4530;

class PassServer {
public:
    ///my public member functions
    size_t cap()const ;

    ///public member functions
    //: constructor, create a hash table of the specified size. You just
    // need to pass this size parameter to the constructor of the HashTable.
    // Therefore, the real hash table size could be different from the
    // parameter size (because prime_below() will be called in the constructor
    // of the HashTable).
    PassServer(size_t size = 101);

    //: destructor. You need to decide what you should do based on your design
    // of PassServer (how you develop the adaptor class based on the adaptee
    // HashTable). In essence, we do not want to have memory leak.
    ~PassServer();

    //: load a password file into the HashTable object. Each line contains
    // a pair of username and encrypted password.
    bool load(const char *filename);

    //: add a new username and password.  The password passed in is in plaintext
    // , it should be encrypted before insertion.
    bool addUser(std::pair<std::string,  std::string> & kv);

    //: move version of addUser.
    bool addUser(std::pair<std::string, std::string> && kv);

    //: delete an existing user with username k.
    bool removeUser(const std::string & k);

    //: change an existing user's password. Note that both passwords passed
    // in are in plaintext. They should be encrypted before you interact with
    // the hash table. If the user is not in the hash table, return false. If
    // p.second does not match the current password, return false. Also return
    // false if the new password and the old password are the same (i.e., we
    // cannot update the password).
    bool changePassword(const std::pair<std::string, std::string> &p, const std::string & newpassword);

    //: check if a user exists (if user is in the hash table).
    bool find(const std::string & user);

    //: show the structure and contents of the HashTable object to the screen.
    // Same format as the dump() function in the HashTable class template.
    void dump() const;

    //: return the size of the HashTable (the number of username/password
    // pairs in the table).
    size_t size() const;

    //: save the username and password combination into a file. Same
    // format as the write_to_file() function in the HashTable class template.
    bool write_to_file(const char *filename) const;


private:
    HashTable<std::string,std::string> server;

    ///Private helper function:
    //: encrypt the parameter str and return the encrypted std::string.
    std::string encrypt(const std::string & str) const;

};


#endif //ASSIGNMENT5_PASSSERVER_H
