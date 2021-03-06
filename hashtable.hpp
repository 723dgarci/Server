//
// Created by WorkD on 11/13/2017.
//

#include "hashtable.h"

using namespace cop4530;
///public member functions
///additional functions
template<typename K,typename V>
std::size_t HashTable<K,V>::size()const{ return sz;}
template<typename K,typename V>
std::size_t HashTable<K,V>::cap()const{ return array.size();}

///given to define
//: constructor. Create a hash table, where the size of the
// vector is set to prime_below(size) (where size is default
// to 101), where prime_below() is a private member function
// of the HashTable and provided to you.
template <typename K, typename V>
HashTable<K, V>::HashTable(std::size_t size){
    array.resize(prime_below(size));
    sz = 0;
}


//: destructor. Delete all elements in hash table.
template <typename K, typename V>
HashTable<K, V>::~HashTable(){
    for(auto & x: array)
        x.clear();
    array.clear();
}


//: check if key k is in the hash table.
template<typename K,typename V>
bool HashTable<K, V>::contains(const K & k)const{
    auto & l = array[myhash(k)];
    for(auto & x:l){
        if(x.first == k)
            return true;
    }
    return false;
}


// : check if key-value pair is in the hash table.
template <typename K, typename V>
bool HashTable<K, V>::match(const std::pair<K, V> &kv)const{
    if(contains(kv.first)) {                    //if key value is in hash
        auto &l = array[myhash(kv.first)];      //then go to that list in array
        for(auto & x: l){                       //search through the list
            if(x.second == kv.second)           //if kv.second == x.second -> match found
                return true;
        }
    }
    return false;
}
/*
//: add  the key-value pair kv into the hash table. Don't add
// if kv is already in the hash table. If the key is the hash
// table but with a different value, the value should be updated
// to the new one with kv. Return true if kv is inserted or the
// value is updated; return false otherwise (i.e., if kv is in
// the hash table).
 */
template <typename K,typename V>
bool HashTable<K, V>::insert(const std::pair<K, V> & kv){
    //std::cout <<"start insert\n";
    //std::cout<< kv.first << ' ' << kv.second
    //        << std::endl;

    auto & l = array[myhash(kv.first)];
    if(match(kv))                   //if there duplicate trying to add duplicate
        return false;
    else if(contains(kv.first)){    //if key has a match but different V in the pair
        for(auto & x:l){            //search the nodes
            if(x.first == kv.first){        //get the one that matches
                x.second = kv.second;       //update that node
            }
        }
        return true;
    }

    //std::cout<< sz <<" array cap: "<<array.capacity()<< std::endl;

    l.push_back(kv);

    if(++sz > array.size())
        rehash();
    //std::cout <<"end insert\n";
    return true;
}

//: move version of insert.
template <typename K, typename V>
bool HashTable<K, V>::insert (std::pair<K,  V> && kv){
    auto & l = array[myhash(kv.first)];
    if(match(kv))                   //if there duplicate trying to add duplicate
        return false;
    else if(contains(kv.first)){    //if key has a match but different V in the pair
        for(auto & x:l){            //search the nodes
            if(x.first == kv.first){        //get the one that matches
                x.second = std::move(kv.second);       //update that node
            }
        }
        return true;
    }

    //std::cout<< sz <<" array cap: "<<array.capacity()<< std::endl;

    l.push_back(kv);

    if(++sz > array.size())
        rehash();
    //std::cout <<"end insert\n";
    return true;
}


//: delete the key k and the corresponding value if it is in the
// hash table. Return true if k is deleted, return false otherwise
// (i.e., if key k is not in the hash table).
template <typename K, typename V>
bool HashTable<K, V>::remove(const K & k){
    auto & l = array[myhash(k)];                    //find list that corresponds to k
    for(auto itr = l.begin();itr != l.end();itr++){ //search list for pair
        if(itr->first == k) {       //if pair is a match kill it and return true
            l.erase(itr);
            sz--;
            return true;
        }
    }
    return false;
}


//: delete all elements in the hash table
template <typename K, typename V>
void HashTable<K, V>::clear(){ makeEmpty(); }


//: load the content of the file with name filename into the hash
// table. In the file, each line contains a single pair of key and
// value, separated by a white space.
template <typename K, typename V>
bool HashTable<K, V>::load(const char *filename){

    std::ifstream file;
    K temp;
    V temp2;

    file.open(filename);
    if(file.is_open()){
        while(file >> temp) {
            //std::cout << temp << '\n';
            file >> temp2;
            //std::cout << temp2 << '\n';
            insert(std::pair<K,V>(temp,temp2));
        }
        file.close();
        return true;
    }
    return false;
}

//: display all entries in the hash table. If an entry contains
// multiple key-value pairs, separate them by a semicolon character
// (:) (see the provided executable for the exact output format).
template <typename K, typename V>
void HashTable<K, V>::dump() const{
    int i = 0;
    for (auto itr = array.begin(); itr != array.end(); itr++){
        std::cout << "\nv["<<i<<"]: ";
        for(auto  x = std::begin(*itr); x != std::end(*itr);++x){
            if(x != std::begin(*itr)){
                std::cout << " : ";
            }
            std::cout << x->first << " "<< x->second;
        }

        i++;
    }
    std::cout <<'\n';
}

//: write all elements in the hash table into a file with name filename.
// Similar to the file format in the load function, each line contains
// a pair of key-value pair, separated by a white space.
template <typename K, typename V>
bool HashTable<K, V>::write_to_file(const char *filename) const{
    std::ofstream file;
    file.open(filename);
    if(file.is_open()){
        for(auto & l:array){
            for(auto & x:l)
                file << x.first << ' '<< x.second << '\n';
        }
        file.close();
        return true;
    }
    return false;
}

///private member functions

///given private member functions
// returns largest prime number <= n or zero if input is too large
// This is likely to be more efficient than prime_above(), because
// it only needs a vector of size n

template <typename K, typename V>
unsigned long HashTable<K, V>::prime_below (unsigned long n)
{
    if (n > max_prime)
    {
        std::cerr << "** input too large for prime_below()\n";
        return 0;
    }
    if (n == max_prime)
    {
        return max_prime;
    }
    if (n <= 1)
    {
        std::cerr << "** input too small \n";
        return 0;
    }

    // now: 2 <= n < max_prime
    std::vector <unsigned long> v (n+1);
    setPrimes(v);
    while (n > 2)
    {
        if (v[n] == 1)
            return n;
        --n;
    }

    return 2;
}

//Sets all prime number indexes to 1. Called by method prime_below(n)
template <typename K, typename V>
void HashTable<K, V>::setPrimes(std::vector<unsigned long>& vprimes)
{
    int i = 0;
    int j = 0;

    vprimes[0] = 0;
    vprimes[1] = 0;
    int n = vprimes.capacity();

    for (i = 2; i < n; ++i)
        vprimes[i] = 1;

    for( i = 2; i*i < n; ++i)
    {
        if (vprimes[i] == 1)
            for(j = i + i ; j < n; j += i)
                vprimes[j] = 0;
    }
}


///my private member funcitons

//: delete all elements in the hash table. The public interface
// clear() will call this function.
template<typename K, typename V>
void HashTable<K,V>::makeEmpty(){
    for(auto & l : array){
        l.clear();
    }
}

//: Rehash function. Called when the number of elements in the hash
// table is greater than the size of the vector.
template<typename K, typename V>
void HashTable<K,V>::rehash(){
    auto oldarray = array;

    array.resize(prime_below(2 * array.size()));
    for(auto & l:array)
        l.clear();

    sz = 0;
    for(auto & l:oldarray)
        for(auto & x: l)
            insert(std::move(x));

}


//: return the index of the vector entry where k should be store
template<typename K, typename V >
size_t HashTable<K,V>::myhash(const K &k)const{
    //std:: cout <<"in myhash\n";
    static std::hash<K> h;
    //std::cout << "array size:"<< array.size()<<std::endl;
    //std::cout<< "std::hash output: "<< h(k) <<'\n';
    //std::cout<< "std::hash output % array.size(): "<< h(k) % array.size()<<'\n';
    return h(k) % array.size();

}
