#include <iostream>
#include <string>
#include <list>
#define YOUTUBEURLHEADER "url_encoded_fmt_stream_map="
#define YOUTUBEURLSEPERATOR "%2C"
#define YOUTUBEURLNEW "%26url%3D"
#define YOUTUBEURLHOST "%26fallback_host%3D"
#define YOUTUBEURLSIG "%26sig%3D"


#define KEYPOS_OBJ(src,key) src.find(key,0)
#define KEYPOS_PTR(src,key) src->find(key,0)

#define KEYSIZE_OBJ(src,key) src.find("%26",src.find(key,0)+sizeof(key)-1)-src.find(key,0)
#define KEYSIZE_PTR(src,key) src->find("%26",src->find(key,0))-src->find(key,0),src->find(key,0)
#define YOUTUBEAPPENDKEY_PTR(dst,src,key) dst->append(src->c_str()+src->find(key,0),KEYSIZE_PTR(src,key))
#define YOUTUBEAPPENDKEY_OBJ(dst,src,key) dst.append(src.c_str(),src.find(key,0),KEYSIZE_OBJ(src,key))

#define YOUTUBEAPPENDKEY_PTR2OBJ(dst,src,key) dst.append(src->c_str()+src->find(key,0),KEYSIZE_PTR(src,key))

#define YOUTUBEAPPENDKEY_OBJ2PTR(dst,src,key) dst->append(src.c_str()+src.find(key,0),KEYSIZE_PTR(src,key))


#define RETURNNEWURL_OBJ(old_url) old_url.substr(KEYPOS_OBJ(old_url,YOUTUBEURLNEW)+sizeof(YOUTUBEURLNEW)-1,old_url.size()-KEYPOS_OBJ(old_url,YOUTUBEURLNEW)-sizeof(YOUTUBEURLNEW)+1)


#define RETURNNEWURL_PTR(old_url) old_url->substr(KEYPOS_PTR(old_url,YOUTUBEURLNEW)+sizeof(YOUTUBEURLNEW)-1,old_url->size()-KEYPOS_PTR(old_url,YOUTUBEURLNEW)-sizeof(YOUTUBEURLNEW)+1)

#define WRONG_VIDEO_URL 1

int findvideourl(std::string& url,std::list<std::string>& video_url);
int regenerateurl(std::list<std::string>& url_list);




















