#include "ScriptMgr.h"
#include "Player.h"
#include "Configuration/Config.h"
#include "World.h"
#include "LFGMgr.h"
#include "Chat.h"
#include "Opcodes.h"

class SoloLFG : public PlayerScript
{
public:
    SoloLFG() : PlayerScript("SoloLFG") { }

   void OnLogin(Player* /*player*/, bool /*firstLogin*/) override
   {
      if (sConfigMgr->GetIntDefault("SoloLFG.Enable", true))
        {
            if (!sLFGMgr->IsSoloLFG())
            {
            sLFGMgr->ToggleSoloLFG();
            }
        }
   }
};

void AddSoloLFG()
{
    new SoloLFG();
}