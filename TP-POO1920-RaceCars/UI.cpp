#include "UI.h"

UI::UI()
{
}

UI::UI(Simulator s)
	:simulator(s)
{
}

void UI::switchMode()
{
	if (mode == CONFIG)
		mode = CHAMPIONSHIP;
	else
		mode = CONFIG;
}



void UI::run()
{
}