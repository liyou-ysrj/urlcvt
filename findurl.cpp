#include "findurl.h"
int findvideourl(std::string& url,std::list<std::string>& video_url)
{
  int begin=url.find(YOUTUBEURLHEADER,0);
  begin+=sizeof(YOUTUBEURLHEADER)-1;
  int end=url.find(YOUTUBEURLSEPERATOR,begin);
  std::string url_get;
  while(end!=std::string::npos)
    {
      url_get.assign(url.c_str()+begin,end-begin);
      video_url.push_back(url_get);
      begin=end+sizeof(YOUTUBEURLSEPERATOR)-1;
      end=url.find(YOUTUBEURLSEPERATOR,begin);
    }
  return 0;

}

int regenerateurl(std::list<std::string>& url_list)
{
  std::list<std::string>::iterator old_url; 
  std::string new_url;
  std::string fallback_host;
  std::string sig;
  for(old_url=url_list.begin();old_url!=url_list.end();old_url++)
    {
      if(old_url->find(YOUTUBEURLHOST,0)==std::string::npos || old_url->find(YOUTUBEURLSIG,0)==std::string::npos)
	return WRONG_VIDEO_URL;
      new_url=RETURNNEWURL_PTR(old_url);
      std::cout<<"new_url is "<<new_url<<std::endl;
      YOUTUBEAPPENDKEY_PTR2OBJ(fallback_host,old_url,YOUTUBEURLHOST);
      std::cout<<"host is "<<fallback_host<<std::endl;
      YOUTUBEAPPENDKEY_PTR2OBJ(sig,old_url,YOUTUBEURLSIG);
      std::cout<<"sig is "<<sig<<std::endl;
      old_url->assign("");
      old_url->append(new_url);
      old_url->append(fallback_host);
      old_url->append(sig);
      new_url="";
      fallback_host="";
      sig="";

    }
  return 0;
}




















