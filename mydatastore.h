#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <string>
#include <set>
#include <vector>
#include "product.h"
#include "user.h"
#include "datastore.h"
#include "util.h"


class MyDataStore: public DataStore {
public:
    MyDataStore() {

    }
    ~MyDataStore() { 

    }

    /**
     * Adds a product to the data store
     */
    void addProduct(Product* p) {
        products.push_back(p);
    }

    /**
     * Adds a user to the data store
     */
    void addUser(User* u) {
        users.push_back(u);
    }

    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
    std::vector<Product*> search(std::vector<std::string>& terms, int type) {
        std::vector<Product*> results;
        std::set<std::string> termsSet;

        // convert terms vector to set
         for(std::vector<std::string>::iterator it = terms.begin(); it != terms.end(); ++it) {
            termsSet.insert((*it));
         }

         for(std::vector<Product*>::iterator it = products.begin(); it != products.end(); ++it) {
            std::set<std::string> keywords = (*it)->keywords();
            if((setIntersection(keywords, termsSet).size() > 0 && type == 0) || (setUnion(keywords, termsSet).size() > 0 && type == 1)) {
                results.push_back((*it));
            }
        }
        return results;
    }

    /**
     * Reproduce the database file from the current Products and User values
     */
    void dump(std::ostream& ofile) {
        for(std::vector<Product*>::iterator it = products.begin(); it != products.end(); ++it) {
            (*it)->dump(ofile);
        }
    }

    protected:
        std::vector<User*> users;
        std::vector<Product*> products;

};

#endif
