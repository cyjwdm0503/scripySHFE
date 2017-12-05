#include "ScripySHFE.h"

int main(int ,char**)
{
	CSHFE shfe;
	for (int index=1;index<300;index++)
		shfe.ReqSHFE(index);
	return 0;
}