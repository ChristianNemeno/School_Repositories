
#include <cstdlib>
#include <iostream>
#include <cmath>
#include "hashtable.hpp"
using namespace std;


// do quadratic
//template <typename K>
class HTQuadratic : public HashTable {
    string* table;
    int N;
    int size;
    public:
    HTQuadratic (int N){
      table = new string[N];
      this->N = N;
      size =0; 
    }
    //poly hash
    int hash_code(string key){
        int length = key.size();
        int hash = 0;
        //let a be 7
        for(int i=0;i < length; i++){
            hash += (int)(key[i] - 'a' + 1) * pow(7, length - i - 1);
        }
        return hash;
    }
    // Using the knowledge that a hash function is composed of two portions
    int hashfn(string key) {
    return compress(hash_code(key));
    }

    //  a = 59
    //  b = 17
    //  c = 509
    // ai + b % c % N

    int compress(int code){
        // ai + b % p % N 
        return ((59 * code) % 509 ) % N;
    }
    // quadratic
    int insert(string key){

        if(size == N){
            return -1;
            // full
        }

        int hash = this->hashfn(key);
        int collisions =0;
        int start = hash;
        while(collisions < N && table[hash] != ""){
            ++collisions;
            hash = (start + collisions*collisions) % N;
        }

        table[hash] = key;
        size++;

        return collisions;
    }

    int search(string key){
        if(size == N) return -1;
        int hash = this->hashfn(key);
        int collisions = 0;
        int start= hash;
        while(collisions < N  && table[hash] != key){
            ++collisions;
            hash = (start + collisions*collisions) % N;
           
        }

        return collisions;
    }
    int remove(string key){
        if(size == N) return -1;

        int hash = this->hashfn(key);
        int collisions =0;
        int start = hash;
        while(collisions < N && table[hash] != key){
            ++collisions;
            hash = (start + collisions * collisions) % N;
            
        }

        if(table[hash] != key) return -1;

        table[hash] = ""; // for now i didnt really put a tombstone just a mock up deletion setting it to empty.

        return collisions;
    
    }
    void print(){

        for(int i=0; i<N; i++){
            cout << i << "\t";
        }
        cout << endl;
        for(int i=0; i<N; i++){
            cout << table[i] << "\t";
        }
        cout << endl;
    }
};