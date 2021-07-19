#include <NsCore/Noesis.h>
#include <NsCore/ReflectionImplementEmpty.h>
#include <NsCore/RegisterComponent.h>
#include <NsApp/EmbeddedXamlProvider.h>
#include <NsApp/EmbeddedFontProvider.h>
#include <NsApp/ApplicationLauncher.h>
#include <NsApp/EntryPoint.h>
#include <NsApp/Application.h>
#include <NsApp/Window.h>

#include "App.xaml.bin.h"
#include "MainWindow.xaml.bin.h"

using namespace Noesis;
using namespace NoesisApp;

namespace ExpenseReport
{
    class App final : public Application
    {
        NS_IMPLEMENT_INLINE_REFLECTION_(App, Application, "ExpenseReport.App")
    };

    class MainWindow final : public Window
    {
        NS_IMPLEMENT_INLINE_REFLECTION_(MainWindow, Window, "ExpenseReport.MainWindow")
    };
} // namespace ExpenseReport

class AppLauncher final : public ApplicationLauncher
{
    private:
        void RegisterComponents() const override
        {
            RegisterComponent<ExpenseReport::App>();
            RegisterComponent<ExpenseReport::MainWindow>();
        }

        Noesis::Ptr<XamlProvider> GetXamlProvider() const override
        {
            EmbeddedXaml xamls[2] =
            {
                { "App.xaml", App_xaml },
                { "MainWindow.xaml", MainWindow_xaml }
            };

            return *new EmbeddedXamlProvider(xamls);
        }

        // Noesis::Ptr<FontProvider> GetFontProvider() const override
        // {
        //     EmbeddedFont fonts[] =
        //     {
        //     };
        //     return *new EmbeddedFontProvider(fonts);
        // }
};

int NsMain(int argc, char **argv)
{
    AppLauncher launcher;
    launcher.SetArguments(argc, argv);
    launcher.SetApplicationFile("App.xaml");
    return launcher.Run();
}
