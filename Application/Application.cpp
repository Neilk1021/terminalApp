//
// Created by Neil Ketteringham on 11/22/23.
//

#include "Application.h"

Application* Application::instance = nullptr;;
Application *Application::GetInstance() {
    if(instance == nullptr){
        instance = new Application();
        Window::Clear_screen();
        Window::Print("Application framework", 15);
        Window::Print("-Neil Ketteringham CC-2023", 1);
        std::cin.get();
        Window::Clear_screen();

        std::shared_ptr<Window> mainMenu =  std::make_shared<Window>(Window("Application framework", false));
        std::shared_ptr<Window> About =  std::make_shared<Window>(Window("About", false));
        std::shared_ptr<Window> ExampleWindow =  std::make_shared<Window>(Window("Example Window", true));

        instance->windows.push_back(mainMenu);
        instance->windows.push_back(ExampleWindow);
        instance->windows.push_back(About);

        mainMenu->addInfo("-Neil Ketteringham CC-2024", 1);
        mainMenu->addPtr(instance->windows[1], "Example Window");
        mainMenu->addPtr(instance->windows[2], "About");

        About->addInfo("Developed by Neil K.",1);
        About->addPtr(instance->windows[0], "Back");

        ExampleWindow->addInput("Text to print: ", false);
        ExampleWindow->addFunc(printNum);
        ExampleWindow->addPtr(instance->windows[0], "Back");

        Application::instance->win = Window::LoadWindow(mainMenu);

        while(Application::instance->win != nullptr){
            Application::instance->win = Window::LoadWindow(Application::instance->win);
        }
    }

    return instance;
}

void Application::printNum(const std::string& ExamplePrint, unsigned int exampleNum, unsigned int exampleNum2){
    std::cout << ExamplePrint << std::endl;
}
