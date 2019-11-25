#include "UI.h"

UI::UI(Simulator s)
:simulator(s), mode(CONFIG)
{
}

void UI::switchMode()
{
	if (mode == CONFIG)
		mode = CHAMPIONSHIP;
	else
	{
		if (mode == CHAMPIONSHIP)
			mode = CONFIG;
		else
			mode = CONFIG;
	}
}
