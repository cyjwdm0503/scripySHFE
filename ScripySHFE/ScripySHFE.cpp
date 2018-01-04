#include "ScripySHFE.h"

int main(int ,char** g)
{
	int index = atoi(g[1]);
	cout<<index<<endl;
	//for (int index=1;index<300;index++)
	//	shfe.ReqSHFE(index);
	//for( int index = 0; index<=3000;index++)
	{
		CSHFE shfe;
		string href = shfe.GetHref("href.ini",index);
		if(href != "")
			shfe.ReqSHFENotice(href,"´º½Ú");
	}
	//system("pause");
	return 0;
}