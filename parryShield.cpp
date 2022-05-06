#include "parryShield.h"
#include "system.h"

void ParryShield::step()
{
	wait--;
	if (wait == 0) {
		System::scene->deleteObject(this);
	}
}
