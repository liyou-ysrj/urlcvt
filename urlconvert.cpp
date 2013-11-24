#include "urlconvert.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <netdb.h>
#include <stdlib.h>


int convert2queryurl(std::string& url)
{
  int id_pos=url.find(YOUTUBEIDSEPERATOR,0);
  url.replace(0,id_pos,YOUTUBEIDPREFIX);
  url.append(YOUTUBEIDSUFFIX);
  return 0;

}

int convertyoutubeurl(std::string& src_url)
{

  convert2queryurl(src_url);

  std::cout<<queryurl<<std::endl;

  int h_socket;
  if((h_socket=socket(AF_INET,SOCK_STREAM,0))<0)
    return NULL;

  struct sockaddr_in cvt_addr;
  memset(&cvt_addr,0,sizeof(cvt_addr));
  cvt_addr.sin_family=AF_INET;
  cvt_addr.sin_port=htons(80);
  struct hostent* r_host;
  r_host=gethostbyname(YOUTUBEURL);
  memcpy(&cvt_addr.sin_addr,r_host->h_addr_list[0],sizeof(cvt_addr.sin_addr));
  connect(h_socket,(struct sockaddr*)&cvt_addr,sizeof(cvt_addr));
  std::string header;
  header.append("GET /");
  header.append(queryurl.c_str()+queryurl.find("/"));
  header.append(" http/1.0\r\n");
  header.append("HOST:www.youtube.com\r\n\r\n");
  send(h_socket,header.c_str(),header.size(),0);
  char recvbuff[1000];
  std::string content_urlinfo;
  int b_end=1000;
  while(b_end==1000)
    {
      b_end=recv(h_socket,recvbuff,1000,NULL);
      content_urlinfo.append(recvbuff,1000);
    }

  std::string video_url;

  char* pos_http=strstr(strstr(content_urlinfo.c_str(),"\r\n\r\n"),"http");

  char* pos_itag=strstr(pos_http,"itag");
  char* pos_signature=strstr(pos_itag,"sig");
  char* end=strstr(pos_itag,URLEND);
  video_url.append(pos_http-4,pos_itag-pos_http);
  video_url.append(pos_itag-4,pos_signature+1-pos_itag);
  
  //todo add signature's content
  video_url=decodeurl(video_url);
  
  src_url=video_url;
 
  
  
 
}

std::string& decodeurl(std::string& url)
{
  if(url.find("%25",0)!=std::string::npos)
    {
      url.replace(url.find("%25",0),3,"%");
      decodeurl(url);
    }
  return url;
}

int main()
{
  //convertyoutube("www.youtube.com?v=123456");
  std::string mtest("www.youtube.com?v=123456");
  convert2queryurl(mtest);
  std::cout<<mtest<<std::endl;
  return 0;

}
	 



















