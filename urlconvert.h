#ifndef _URLCONVERT_H
#define _URLCONVERT_H

#include <string>

#define YOUTUBEIDPREFIX "http://www.youtube.com/get_video_info?&video_id="
#define YOUTUBEIDSUFFIX "&el=detailpage&ps=default&eurl=&gl=US&hl=en"


#define YOUTUBEURL "www.youtube.com"
#define YOUTUBEURLHEAD ""
#define YOUTUBEIDSEPERATOR "v="
#define YOUTUBEIDREG "{0}"
#define URLEND "http"
char* convertyoutube(char* src_url);

std::string& decodeurl(std::string& url);
int convert2queryurl(std::string& url);
#endif



















