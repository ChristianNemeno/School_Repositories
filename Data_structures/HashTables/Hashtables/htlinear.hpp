#include <cstdlib>
#include <iostream>
#include "hashtable.hpp"
using namespace std;
template <typename K>
class HTLinear : public HashTable<K> {
    // IMPLEMENT ME
    K* table;
    int N;
    int count;
    
    public:
    HTLinear(int s){
        N = s;
        table = (K*)calloc(N,sizeof(K));
        count = 0;
    }
    
    int hash_code(K key){
        return key;    
    }
    
    int compress(int code){
        return ((59*code + 17) % 509) % N;    
    }
    
    int hashfn(K key) {
        int code = hash_code(key);
        return compress(code);
    }
    
    int insert(K key){
        if(count == N){
            throw logic_error("Table already full");
        }
        
        int hash = hashfn(key);
        int collisions = 0;
        int start = hash;
        
        while(table[hash] != 0 && table[hash] != -1){
            if(table[hash] == key){
                throw logic_error("Already added key " + to_string(key));
            }
            
            hash = (hash + 1) % N;
            collisions++;
            if(start == hash){
                break;
            }
        }
        
        table[hash] = key; 
        count++;
        
        return collisions;
    }
    
    int search(K key){
        int hash = hashfn(key);
        int start = hash;
        int collisions = 0;
        
        while(table[hash] != 0){
            if(table[hash] == key){
                return collisions;
            }
            
            hash = (hash + 1) % N;
            collisions++;
            
            if(start == hash){
                break;
            }
        }
        
        return -1;
    }
    
    int remove(K key) {
        int hash = hashfn(key);
        int start = hash;
        int collisions = 0;
        
        while(table[hash] != 0){
            if(table[hash] == key){
                table[hash] = -1;
                count--;
                return collisions;
            }
            
            hash = (hash + 1) % N;
            collisions++;
            
            if(start == hash){
                break;
            }
        }
        
        return -1;
    }
    
    void print(){
        for(int i = 0; i < N; i++){
            cout << i << "\t";
        }
        cout << endl;
        for(int i = 0; i < N; i++){
            if(table[i] != -1){
                cout << table[i] << "\t";    
            }else{
                cout << 0 << "\t";
            }
        }
        cout << endl;
    }
};