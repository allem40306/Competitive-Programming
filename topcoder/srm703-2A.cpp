#include <iostream> 
#include <string>

class AlternatingString{
	public:
		int maxLength(String S){
			int len=S.size(),c=0,mc=0;
			for(int i=1;i<len;i++){
				if(S[i]!=S[i-1])c++;
				else c=0;
				if(c>mc)mc=c;
			}
			return mc;
		}
};
