#include "CYoutubeUrlCvt.h"
CYoutubeUrlCvt::CYoutubeUrlCvt()
{
  m_pcurl=curl_easy_init();
}


CYoutubeUrlCvt::CYoutubeUrlCvt(std::string video_url)
{
  m_queryurl=video_url;
  m_pcurl=curl_easy_init();
}


CYoutubeUrlCvt::~CYoutubeUrlCvt()
{
  curl_easy_cleanup(m_pcurl);
}


int CYoutubeUrlCvt::PaserUrl()
{
  
  Cvt2QuryUrl();
  DownLoadUrlInfo();
  FindUrlList();
  RegenateUrl();
  return 0;
}

int CYoutubeUrlCvt::SetVideoUrl(std::string video_url)
{
  m_queryurl=video_url;
  return 0;
}

std::list<std::string> CYoutubeUrlCvt::GetDownloadUrl()
{
  return m_url_list;
}

int CYoutubeUrlCvt::Cvt2QuryUrl()
{
  std::string id=m_queryurl.substr(m_queryurl.find("v=",0));
  m_queryurl="";
  m_queryurl.append(YOUTUBEQUERYURLPREFIX);
  m_queryurl.append(id);
  m_queryurl.append(YOUTUBEQUERYURLSUFFIX);
  
  return 0;
}

int CYoutubeUrlCvt::DownLoadUrlInfo()
{

}

int CYoutubeUrlCvt::FindUrlList()
{

  return 0;
}


int CYoutubeUrlCvt::RegenateUrl()
{

  return 0;
}


int CheckIfEmpty(std::string& dst)
{

  return 0;
}




















