//
// Created by Neil Ketteringham on 11/22/23.
//

#ifndef APPLICATION_H
#define APPLICATION_H
#include "./Window/Window.h"
#include <string>
#include <algorithm>
#include <cmath>

class Application {
    private:
        std::vector<std::shared_ptr<Window>> windows;
        Application() {};

        const bool compact = false;
    protected:
        std::shared_ptr<Window> win;
        std::vector<std::shared_ptr<Window>> tempWindows;
        static Application* instance;
        void GenerateButtons();
    public:
        Application(Application &other) = delete;
        static Application *GetInstance();
        static void printNum(const std::string& ExamplePrint, unsigned int exampleNum, unsigned int exampleNum2);

};

#endif //APPLICATION_H
