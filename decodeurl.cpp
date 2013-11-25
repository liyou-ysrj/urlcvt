

void decodeurl(std::string& src_url)
{
  std::string::size_type pos;
  while(src_url.find("%2F",0)!=std::string::npos || src_url.find("%3D",0)!=std::string::npos || src_url.find("%26",0)!=std::string::npos || \
	src_url.find("%2C",0)!=std::string::npos || src_url.find("%3F",0)!=std::string::npos || src_url.find("%25",0)!=std::string::npos)
    {
      if((pos=src_url.find("%2F",0))!=std::string::npos)
	src_url.replace(pos,3,CHAR_2F);
       if((pos=src_url.find("%3D",0))!=std::string::npos)
	src_url.replace(pos,3,CHAR_3D);
       if((pos=src_url.find("%26",0))!=std::string::npos)
	src_url.replace(pos,3,CHAR_26);
       if((pos=src_url.find("%2C",0))!=std::string::npos)
	src_url.replace(pos,3,CHAR_2C);
       if((pos=src_url.find("%3F",0))!=std::string::npos)
	src_url.replace(pos,3,CHAR_3F);
       if((pos=src_url.find("%25",0))!=std::string::npos)
	 src_url.replace(pos,3,CHAR_25);
       
    }
 

} 





















