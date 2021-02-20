//
// Created by Acer on 20.02.2021.
//

#include <iostream>
#include "../functions.h"
#include "doctest.h"

TEST_CASE("CHeck"){
    Functions functions;
    functions.clearFiles();
    Functions::defineId();
    CHECK(MessageLog::count == 0);

    functions.createNewElemAndAddToVector("hi");
    SUBCASE("createNewElement"){
            CHECK(functions.log[0].id == 0);
            CHECK(functions.log[0].countWords == 1);
            CHECK(functions.log[0].count == 1);
    };

    functions.saveToFile();
    functions.log.clear();
    functions.readingFromTxt();
    SUBCASE("saving and reading from file"){
                CHECK(functions.log[0].id == 0);
                CHECK(functions.log[0].countWords == 1);
                CHECK(functions.log[0].count == 1);
    };

    functions.log[0].typeOfError = "error";
    functions.log[0].loading = 0.15;
    functions.clearFiles();
    functions.saveToFile();
    SUBCASE("searching"){
        CHECK(functions.log[0].id == functions.searchingTypeAndLoading("error", 0.1).id);
        CHECK(functions.log[0].id == functions.searchingSubString("h").id);
    }

    functions.updateOneMessage(0, "hello");
    SUBCASE("updating"){
        CHECK(functions.log[0].text == "hello");
    }

    functions.deleteOneMessage(0);
    functions.log.clear();
    functions.readingFromTxt();
    CHECK(functions.log.empty());

};