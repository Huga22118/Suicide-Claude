/*
  Suicide Claude for GTA III

  Plugins by Huga22118

  https://github.com/Huga22118
*/


#include "plugin.h"
#include "common.h"
#include "CTimer.h"
#include "CVehicle.h"

using namespace plugin;

class Suicide {
public:
    Suicide() 
	{
		static int keyPressTime = 0;
		Events::gameProcessEvent += []
		{
			CPed* suicide = FindPlayerPed();
			CVehicle* suicidevehicle = FindPlayerVehicle();

			if (suicide && KeyPressed(VK_LCONTROL) && KeyPressed(VK_NUMPAD4)
				&& CTimer::m_snTimeInMilliseconds - keyPressTime > 1000)
			{
				keyPressTime = CTimer::m_snTimeInMilliseconds;
				suicide->m_fHealth = 0.0f;
				suicide->m_fArmour = 0.0f;
			}
			if (suicidevehicle && KeyPressed(VK_LCONTROL) && KeyPressed(VK_NUMPAD5)
				&& CTimer::m_snTimeInMilliseconds - keyPressTime > 1000)
			{
				keyPressTime = CTimer::m_snTimeInMilliseconds;
				((CAutomobile*)suicidevehicle)->BlowUpCar(suicide);
			}

		};
		   
    }
} suicide;
