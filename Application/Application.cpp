//
// Created by Neil Ketteringham on 11/22/23.
//

#include "Application.h"

Application* Application::instance = nullptr;;
Application *Application::GetInstance() {
    if(instance == nullptr){
        instance = new Application();
        Window::Print("Application framework", 15);
        Window::Print("-Neil Ketteringham CC-2023", 1);
        std::cin.get();
        Window::Clear_screen();

        std::shared_ptr<Window> mainMenu =  std::make_shared<Window>(Window("Application framework", false));
        std::shared_ptr<Window> About =  std::make_shared<Window>(Window("About", false));

        instance->windows.push_back(mainMenu);
        instance->windows.push_back(About);

        mainMenu->addInfo("-Neil Ketteringham CC-2024", 1);
        mainMenu->addPtr(instance->windows[1], "About");

        About->addInfo("Developed by Neil K.",1);
        About->addPtr(instance->windows[0], "Back");

        Application::instance->win = Window::LoadWindow(mainMenu);

        while(Application::instance->win != nullptr){
            Application::instance->win = Window::LoadWindow(Application::instance->win);
        }
    }

    return instance;
}
