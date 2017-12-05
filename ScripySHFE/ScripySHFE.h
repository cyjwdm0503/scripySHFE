#ifndef XUEQIU_H
#define XUEQIU_H

#include "RyeolHttpClient.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace  std;
using namespace  Ryeol;
class CSHFE
{
public:
	CHttpClient m_objHttpReq ;
	CHttpResponse* m_pobjHttpRes;
	CSHFE()
	{
		// Initialize the User Agent
		m_objHttpReq.SetInternet ("My Custom User Agent") ;

		// Specifies whether to use UTF-8 encoding. (This uses ANSI encoding)
		// Default is FALSE
		m_objHttpReq.SetUseUtf8 (FALSE) ;

		// Specifies a code page for ANSI strings. (This uses Korean)
		// Default is CP_ACP
		m_objHttpReq.SetAnsiCodePage (949) ;

		// Add user's custom HTTP headers
		m_objHttpReq.AddHeader("Host","xueqiu.com");
		m_objHttpReq.AddHeader("Connection","keep-alive");
		m_objHttpReq.AddHeader("User-Agent:","Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/59.0.3071.115 Safari/537.36");
		m_objHttpReq.AddHeader("Accept","text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8");
		m_objHttpReq.AddHeader("Accept-Encoding","gzip, deflate, br");
		m_objHttpReq.AddHeader("Accept-Language","zh-CN,zh;q=0.8,en;q=0.6");
		m_objHttpReq.AddHeader("Cookie","device_id=cd09d3e4179bfd82f8d76679bb15b990; s=fp124lnvk6; xq_a_token=82d9cefaa0793743cb186e53294ec0e61ac2abec; xq_a_token.sig=5N1bqGL6dBOdtpsJHPbhJk4l6_g; xq_r_token=11b86433a20d1d1eef63ecc12252297196a20e10; xq_r_token.sig=RPGspgHiNeURBrDthhch0e5_T0g; u=821502031883991; aliyungf_tc=AQAAAMx43xO7UQQACxPAt9ij3kNmTqV2; __utmt=1; Hm_lvt_1db88642e346389874251b5a1eded6e3=1501991095,1502031885; Hm_lpvt_1db88642e346389874251b5a1eded6e3=1502031898; __utma=1.333318667.1428032299.1502003255.1502031886.122; __utmb=1.4.10.1502031886; __utmc=1; __utmz=1.1502031886.122.3.utmcsr=xueqiu.com|utmccn=(referral)|utmcmd=referral|utmcct=/");
		//m_objHttpReq.AddHeader (("Ryeol-Magic"), ("My Magic Header")) ;
		//m_objHttpReq.AddHeader (("User-Magic"), ("User's Magic Header")) ;

		//m_objHttpReq.
		m_pobjHttpRes = NULL;

	}
	void ReqSHFE(int index)
	{
		char vale[10];
		sprintf(vale,"%d",index);
		string req= "";
		if(index >1)
		{
			req="http://www.shfe.com.cn/news/notice/index_";//2.html"
			req = req+vale;
		}

		else
			req="http://www.shfe.com.cn/news/notice/index";//2.html"

		req =  req+".html";
		m_pobjHttpRes  = m_objHttpReq.RequestGet(req.c_str());
		int length;
		if(m_pobjHttpRes != NULL)
		{
			char* content =  new char[1024*1000];
			length= m_pobjHttpRes->ReadContent((BYTE*)content,1024*1000);
			if(length >1000)
			{
				string str = content;
				size_t begin_ul = str.find("<ul");
				size_t end_ul = str.find("</ul");
				if(begin_ul != string::npos && end_ul !=string::npos)
				{
					string ul = str.substr(begin_ul,end_ul-begin_ul);
					ofstream file1;
					string file_name = vale;
					file_name +=".html";
					file1.open("SHFE.HTML",ios::out|ios::app|ios::ate);
					file1<<ul;
					file1.flush();
					file1.close();
				}

			}
		}

	}
};
#endif