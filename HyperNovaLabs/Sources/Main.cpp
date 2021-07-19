#include <NoesisPCH.h>

#include <NsApp/ThemeProviders.h>
#include <NsApp/EmbeddedXamlProvider.h>
#include <NsApp/EmbeddedFontProvider.h>
#include <NsApp/ApplicationLauncher.h>
#include <NsApp/EntryPoint.h>
#include <NsApp/Application.h>
#include <NsApp/Window.h>

namespace
{
    // #include <NsTheme/Fonts/PT Root UI_Bold.otf.bin.h>
    // #include <NsTheme/Fonts/PT Root UI_Regular.otf.bin.h>
    
    // #include <NsTheme/NoesisTheme.Brushes.DarkAqua.xaml.bin.h>
    // #include <NsTheme/NoesisTheme.Brushes.DarkBlue.xaml.bin.h>
    // #include <NsTheme/NoesisTheme.Brushes.DarkCrimson.xaml.bin.h>
    // #include <NsTheme/NoesisTheme.Brushes.DarkEmerald.xaml.bin.h>
    // #include <NsTheme/NoesisTheme.Brushes.DarkGreen.xaml.bin.h>
    // #include <NsTheme/NoesisTheme.Brushes.DarkLime.xaml.bin.h>
    // #include <NsTheme/NoesisTheme.Brushes.DarkOrange.xaml.bin.h>
    // #include <NsTheme/NoesisTheme.Brushes.DarkPurple.xaml.bin.h>
    // #include <NsTheme/NoesisTheme.Brushes.DarkRed.xaml.bin.h>

    // #include <NsTheme/NoesisTheme.Brushes.LightAqua.xaml.bin.h>
    // #include <NsTheme/NoesisTheme.Brushes.LightBlue.xaml.bin.h>
    // #include <NsTheme/NoesisTheme.Brushes.LightCrimson.xaml.bin.h>
    // #include <NsTheme/NoesisTheme.Brushes.LightEmerald.xaml.bin.h>
    // #include <NsTheme/NoesisTheme.Brushes.LightGreen.xaml.bin.h>
    // #include <NsTheme/NoesisTheme.Brushes.LightLime.xaml.bin.h>
    // #include <NsTheme/NoesisTheme.Brushes.LightOrange.xaml.bin.h>
    // #include <NsTheme/NoesisTheme.Brushes.LightPurple.xaml.bin.h>
    // #include <NsTheme/NoesisTheme.Brushes.LightRed.xaml.bin.h>

    // #include <NsTheme/NoesisTheme.Colors.Dark.xaml.bin.h>
    // #include <NsTheme/NoesisTheme.Colors.Light.xaml.bin.h>

    // #include <NsTheme/NoesisTheme.DarkAqua.xaml.bin.h>
    // #include <NsTheme/NoesisTheme.DarkBlue.xaml.bin.h>
    // #include <NsTheme/NoesisTheme.DarkCrimson.xaml.bin.h>
    // #include <NsTheme/NoesisTheme.DarkEmerald.xaml.bin.h>
    // #include <NsTheme/NoesisTheme.DarkGreen.xaml.bin.h>
    // #include <NsTheme/NoesisTheme.DarkLime.xaml.bin.h>
    // #include <NsTheme/NoesisTheme.DarkOrange.xaml.bin.h>
    // #include <NsTheme/NoesisTheme.DarkPurple.xaml.bin.h>
    // #include <NsTheme/NoesisTheme.DarkRed.xaml.bin.h>

    // #include <NsTheme/NoesisTheme.LightAqua.xaml.bin.h>
    // #include <NsTheme/NoesisTheme.LightBlue.xaml.bin.h>
    // #include <NsTheme/NoesisTheme.LightCrimson.xaml.bin.h>
    // #include <NsTheme/NoesisTheme.LightEmerald.xaml.bin.h>
    // #include <NsTheme/NoesisTheme.LightGreen.xaml.bin.h>
    // #include <NsTheme/NoesisTheme.LightLime.xaml.bin.h>
    // #include <NsTheme/NoesisTheme.LightOrange.xaml.bin.h>
    // #include <NsTheme/NoesisTheme.LightPurple.xaml.bin.h>
    // #include <NsTheme/NoesisTheme.LightRed.xaml.bin.h>

    // #include <NsTheme/NoesisTheme.Fonts.xaml.bin.h>
    // #include <NsTheme/NoesisTheme.Styles.xaml.bin.h>

    #include "App.xaml.bin.h"
    #include "MainWindow.xaml.bin.h"
}

using namespace Noesis;
using namespace NoesisApp;

namespace HyperNovaLabs::ExpenseReport
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
        RegisterComponent<HyperNovaLabs::ExpenseReport::App>();
        RegisterComponent<HyperNovaLabs::ExpenseReport::MainWindow>();
    }

    Noesis::Ptr<XamlProvider> GetXamlProvider() const override
    {
        EmbeddedXaml xamls[] =
        {
            // { "NoesisTheme.Fonts.xaml"       , NoesisTheme_Fonts_xaml        },
            // { "NoesisTheme.Styles.xaml"      , NoesisTheme_Styles_xaml       },
            // { "NoesisTheme.Colors.Light.xaml", NoesisTheme_Colors_Light_xaml },

            // { "NoesisTheme.Brushes.LightAqua.xaml"   , NoesisTheme_Brushes_LightAqua_xaml    },
            // { "NoesisTheme.Brushes.LightBlue.xaml"   , NoesisTheme_Brushes_LightBlue_xaml    },
            // { "NoesisTheme.Brushes.LightCrimson.xaml", NoesisTheme_Brushes_LightCrimson_xaml },
            // { "NoesisTheme.Brushes.LightEmerald.xaml", NoesisTheme_Brushes_LightEmerald_xaml },
            // { "NoesisTheme.Brushes.LightGreen.xaml"  , NoesisTheme_Brushes_LightGreen_xaml   },
            // { "NoesisTheme.Brushes.LightLime.xaml"   , NoesisTheme_Brushes_LightLime_xaml    },
            // { "NoesisTheme.Brushes.LightOrange.xaml" , NoesisTheme_Brushes_LightOrange_xaml  },
            // { "NoesisTheme.Brushes.LightPurple.xaml" , NoesisTheme_Brushes_LightPurple_xaml  },
            // { "NoesisTheme.Brushes.LightRed.xaml"    , NoesisTheme_Brushes_LightRed_xaml     },

            // { "NoesisTheme.Brushes.DarkAqua.xaml"   , NoesisTheme_Brushes_DarkAqua_xaml    },
            // { "NoesisTheme.Brushes.DarkBlue.xaml"   , NoesisTheme_Brushes_DarkBlue_xaml    },
            // { "NoesisTheme.Brushes.DarkCrimson.xaml", NoesisTheme_Brushes_DarkCrimson_xaml },
            // { "NoesisTheme.Brushes.DarkEmerald.xaml", NoesisTheme_Brushes_DarkEmerald_xaml },
            // { "NoesisTheme.Brushes.DarkGreen.xaml"  , NoesisTheme_Brushes_DarkGreen_xaml   },
            // { "NoesisTheme.Brushes.DarkLime.xaml"   , NoesisTheme_Brushes_DarkLime_xaml    },
            // { "NoesisTheme.Brushes.DarkOrange.xaml" , NoesisTheme_Brushes_DarkOrange_xaml  },
            // { "NoesisTheme.Brushes.DarkPurple.xaml" , NoesisTheme_Brushes_DarkPurple_xaml  },
            // { "NoesisTheme.Brushes.DarkRed.xaml"    , NoesisTheme_Brushes_DarkRed_xaml     },

            // { "Theme/NoesisTheme.LightAqua.xaml"   , NoesisTheme_LightAqua_xaml    },
            // { "Theme/NoesisTheme.LightBlue.xaml"   , NoesisTheme_LightBlue_xaml    },
            // { "Theme/NoesisTheme.LightCrimson.xaml", NoesisTheme_LightCrimson_xaml },
            // { "Theme/NoesisTheme.LightEmerald.xaml", NoesisTheme_LightEmerald_xaml },
            // { "Theme/NoesisTheme.LightGreen.xaml"  , NoesisTheme_LightGreen_xaml   },
            // { "Theme/NoesisTheme.LightLime.xaml"   , NoesisTheme_LightLime_xaml    },
            // { "Theme/NoesisTheme.LightOrange.xaml" , NoesisTheme_LightOrange_xaml  },
            // { "Theme/NoesisTheme.LightPurple.xaml" , NoesisTheme_LightPurple_xaml  },
            // { "Theme/NoesisTheme.LightRed.xaml"    , NoesisTheme_LightRed_xaml     },

            // { "Theme/NoesisTheme.DarkAqua.xaml"   , NoesisTheme_DarkAqua_xaml    },
            // { "Theme/NoesisTheme.DarkBlue.xaml"   , NoesisTheme_DarkBlue_xaml    },
            // { "Theme/NoesisTheme.DarkCrimson.xaml", NoesisTheme_DarkCrimson_xaml },
            // { "Theme/NoesisTheme.DarkEmerald.xaml", NoesisTheme_DarkEmerald_xaml },
            // { "Theme/NoesisTheme.DarkGreen.xaml"  , NoesisTheme_DarkGreen_xaml   },
            // { "Theme/NoesisTheme.DarkLime.xaml"   , NoesisTheme_DarkLime_xaml    },
            // { "Theme/NoesisTheme.DarkOrange.xaml" , NoesisTheme_DarkOrange_xaml  },
            // { "Theme/NoesisTheme.DarkPurple.xaml" , NoesisTheme_DarkPurple_xaml  },
            // { "Theme/NoesisTheme.DarkRed.xaml"    , NoesisTheme_DarkRed_xaml     },

            { "App.xaml"       , App_xaml        },
            { "MainWindow.xaml", MainWindow_xaml }
        };

        return *new EmbeddedXamlProvider(xamls);
    }

    // Noesis::Ptr<FontProvider> GetFontProvider() const override
    // {
    //     EmbeddedFont fonts[] = 
    //     {
    //         { "Fonts", PT_Root_UI_Bold_otf    },
    //         { "Fonts", PT_Root_UI_Regular_otf }
    //     };
    //     return *new EmbeddedFontProvider(fonts);
    // }
};

// https://noesisengine.com/trial/
// https://noesisengine.com/docs/Gui.Core.Licensing.html
// https://docs.microsoft.com/en-us/dotnet/desktop/wpf/app-development/pack-uris-in-wpf?view=netframeworkdesktop-4.8
// <ResourceDictionary Source="pack://application:,,,/Theme;component/Theme/NoesisTheme.LightOrange.xaml" />
// <ResourceDictionary Source="pack://application:,,,/Theme/NoesisTheme.LightOrange.xaml" />

int NsMain(int argc, char **argv)
{
    AppLauncher launcher;
    launcher.SetArguments(argc, argv);
    launcher.SetApplicationFile("App.xaml");
    return launcher.Run();
}
