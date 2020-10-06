#ifndef FACTORY_HPP
# define FACTORY_HPP
#include "iikh.hpp"
#include "recipe_database.h"

class Database {
private:
    unique_ptr<RecipeDatabase> dbptr;
public:
    Database() {
        dbptr = make_unique<RecipeDatabase>();
    }
    unique_ptr<RecipeDatabase>& getDatabase() { return dbptr; }
};


#endif
