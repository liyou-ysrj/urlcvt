#ifndef _CYOUTUBEURLCVT_H_
#define _CYOUTUBEURLCVT_H_
/**************************************************************************
 *将视频的观看链接转换为下载链接的类
 *
 *
 *************************************************************************/

#include <iostream>
#include <list>
#include <string>
#include <curl/curl.h>

#define YOUTUBEQUERYURLPREFIX 
#define YOUTUBEQUERYURLSUFFIX 



//@class CYoutubeUrlCvt /* 将youtube的观看视频链接转换为下载链接 */
//@member
//@m_queryurl /* 存储查询视频信息的URL */
//@m_urlinfo /* 存储查询到的视频信息 */
//@m_url_list /* 存储转换出来的下载链接 */
//@function
//CYoutubeUrlCvt()
class CYoutubeUrlCvt
{

 private:
  std::string m_queryurl;
  std::string m_urlinfo;
  std::list<std::string> m_url_list;
  CURL* m_pcurl;
 public:
  CYoutubeUrlCvt();
  CYoutubeUrlCvt(std::string video_url);
  ~CYoutubeUrlCvt();

 public:
  int ParseUrl();

 public: 
  int SetVideoUrl(std::string video_url);


 public:

  std::list<std::string> GetDownloadUrl();

 private:
  int Cvt2QuryUrl();
  int DownLoadUrlInfo();
  int FindUrlList();
  int RegenateUrl();
  int CheckIfEmpty(std::string& dst);
  





};



#endif











