#include "modding.h"
#include "recompconfig.h"
#include "eztr_api.h"

// Wir sagen dem Compiler, dass diese 4 Funktionen in anderen Dateien existieren
extern void Setup_Text_English(void);
extern void Setup_Text_German(void);
extern void Setup_Text_French(void);
extern void Setup_Text_Spanish(void);

// Dieser Befehl wird genau EINMAL ausgeführt, wenn die Text-Mod geladen wird
EZTR_ON_INIT void Apply_Selected_Language(void) {
    // Lese die aktuelle Einstellung aus dem Recomp Mod-Menü aus
    u32 selected_language = recomp_get_config_u32("language_selection");

    // Lade die entsprechende Sprache (0 = English, 1 = Deutsch, 2 = Französisch, 3 = Spanisch)
    switch (selected_language) {
        case 0:
            Setup_Text_English();
            break;
        case 1:
            Setup_Text_German();
            break;
        case 2:
            Setup_Text_French();
            break;
        case 3:
            Setup_Text_Spanish();
            break;
        default:
            Setup_Text_English(); // Fallback, falls etwas schiefgeht
            break;
    }
}